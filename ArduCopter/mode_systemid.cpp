#include "Copter.h"

#if MODE_SYSTEMID_ENABLED == ENABLED

/*
 * Init and run calls for systemId, flight mode
 */

const AP_Param::GroupInfo ModeSystemId::var_info[] = {

    // @Param: _AXIS
    // @DisplayName: System identification axis
    // @Description: Controls which axis are being excited.  Set to non-zero to see more parameters
    // @User: Standard
    // @Values: 0:None, 1:Input Roll Angle, 2:Input Pitch Angle, 3:Input Yaw Angle, 4:Recovery Roll Angle, 5:Recovery Pitch Angle, 6:Recovery Yaw Angle, 7:Rate Roll, 8:Rate Pitch, 9:Rate Yaw, 10:Mixer Roll, 11:Mixer Pitch, 12:Mixer Yaw, 13:Mixer Thrust
    AP_GROUPINFO_FLAGS("_AXIS", 1, ModeSystemId, axis, 0, AP_PARAM_FLAG_ENABLE),

    // @Param: _MAGNITUDE
    // @DisplayName: System identification Chirp Magnitude
    // @Description: Magnitude of sweep in deg, deg/s and 0-1 for mixer outputs.
    // @User: Standard
    AP_GROUPINFO("_MAGNITUDE", 2, ModeSystemId, waveform_magnitude, 15),

    // @Param: _F_START_HZ
    // @DisplayName: System identification Start Frequency
    // @Description: Frequency at the start of the sweep
    // @Range: 0.01 100
    // @Units: Hz
    // @User: Standard
    AP_GROUPINFO("_F_START_HZ", 3, ModeSystemId, frequency_start, 0.5f),

    // @Param: _F_STOP_HZ
    // @DisplayName: System identification Stop Frequency
    // @Description: Frequency at the end of the sweep
    // @Range: 0.01 100
    // @Units: Hz
    // @User: Standard
    AP_GROUPINFO("_F_STOP_HZ", 4, ModeSystemId, frequency_stop, 40),

    // @Param: _T_FADE_IN
    // @DisplayName: System identification Fade in time
    // @Description: Time to reach maximum amplitude of sweep
    // @Range: 0 20
    // @Units: s
    // @User: Standard
    AP_GROUPINFO("_T_FADE_IN", 5, ModeSystemId, time_fade_in, 15),

    // @Param: _T_REC
    // @DisplayName: System identification Total Sweep length
    // @Description: Time taken to complete the sweep
    // @Range: 0 255
    // @Units: s
    // @User: Standard
    AP_GROUPINFO("_T_REC", 6, ModeSystemId, time_record, 70),

    // @Param: _T_FADE_OUT
    // @DisplayName: System identification Fade out time
    // @Description: Time to reach zero amplitude at the end of the sweep
    // @Range: 0 5
    // @Units: s
    // @User: Standard
    AP_GROUPINFO("_T_FADE_OUT", 7, ModeSystemId, time_fade_out, 2),

    AP_GROUPEND
};

ModeSystemId::ModeSystemId(void) : Mode()
{
    AP_Param::setup_object_defaults(this, var_info);
}

#define SYSTEM_ID_DELAY     1.0f      // speed below which it is always safe to switch to loiter

// systemId_init - initialise systemId controller
bool ModeSystemId::init(bool ignore_checks)
{
    // check if enabled
    if (axis == 0) {
        gcs().send_text(MAV_SEVERITY_WARNING, "No axis selected, SID_AXIS = 0");
        return false;
    }

    // if landed and the mode we're switching from does not have manual throttle and the throttle stick is too high
    if (motors->armed() && copter.ap.land_complete && !copter.flightmode->has_manual_throttle()) {
        return false;
    }

#if FRAME_CONFIG == HELI_FRAME
    copter.input_manager.set_use_stab_col(true);
#endif

    waveform_time = 0.0f;
    time_const_freq = 2.0f / frequency_start; // Two full cycles at the starting frequency
    systemid_state = SystemIDModeState::SYSTEMID_STATE_TESTING;
    log_subsample = 0;



    copter.Log_Write_SysID_Setup(axis, waveform_magnitude, frequency_start, frequency_stop, time_fade_in, time_const_freq, time_record, time_fade_out);

    gcs().send_text(MAV_SEVERITY_INFO, "SystemID Starting: axis=%d", (unsigned)axis);

    // set target altitude to zero for reporting
    pos_control->set_alt_target(0);
    QS_InnerRateLoop_Obj.initialize();
    engage=0;
    VeSqrSum=0;
    PeSqrSum=0;
    pNcmd=0;
    pEcmd=0;
    pDcmd=0;
    vmax=1;
    pmax=1;
    score = 0;
    trajectorycount=1;
    log_counter_qs=0;

    return true;
}

// systemId_run - runs the systemId controller
// should be called at 100hz or more
void ModeSystemId::run()
{
    float mix_x, mix_y, mix_z, throttle;

    const Vector3f &accel = copter.ins.get_accel();
    const Vector3f &gyro = copter.ins.get_gyro();

    const Vector3f &curr_pos = inertial_nav.get_position();
    const Vector3f &curr_vel = inertial_nav.get_velocity();

    // system ID inputs
    float input_pitch = 0.0f;
    float input_roll = 0.0f;
    float input_yaw = 0.0f;
    float recovery_pitch = 0.0f;
    float recovery_roll = 0.0f;
    float recovery_yaw = 0.0f;
    float mix_pitch = 0.0f;
    float mix_roll = 0.0f;
    float mix_yaw = 0.0f;
    float mix_throttle = 0.0f;


    // apply simple mode transform to pilot inputs
    update_simple_mode();

    if (!motors->armed()) {
        // Motors should be Stopped
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::SHUT_DOWN);
    // Tradheli doesn't set spool state to ground idle when throttle stick is zero.  Ground idle only set when
    // motor interlock is disabled.
    } else if (copter.ap.throttle_zero && !copter.is_tradheli()) {
        // Attempting to Land
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::GROUND_IDLE);
    } else {
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::THROTTLE_UNLIMITED);
    }

    switch (motors->get_spool_state()) {
    case AP_Motors::SpoolState::SHUT_DOWN:
        // Motors Stopped
        attitude_control->set_yaw_target_to_current_heading();
        attitude_control->reset_rate_controller_I_terms();
        break;

    case AP_Motors::SpoolState::GROUND_IDLE:
        // Landed
        // Tradheli initializes targets when going from disarmed to armed state. 
        // init_targets_on_arming is always set true for multicopter.
        if (motors->init_targets_on_arming()) {
            attitude_control->set_yaw_target_to_current_heading();
            attitude_control->reset_rate_controller_I_terms_smoothly();
        }
        break;

    case AP_Motors::SpoolState::THROTTLE_UNLIMITED:
        // clear landing flag above zero throttle
        if (!motors->limit.throttle_lower) {
            set_land_complete(false);
        }
        break;

    case AP_Motors::SpoolState::SPOOLING_UP:
    case AP_Motors::SpoolState::SPOOLING_DOWN:
        // do nothing
        break;
    }


    if ((systemid_state == SystemIDModeState::SYSTEMID_STATE_TESTING) &&
        (!is_positive(frequency_start) || !is_positive(frequency_stop) || is_negative(time_fade_in) || !is_positive(time_record) || is_negative(time_fade_out) || (time_record <= time_const_freq))) {
        systemid_state = SystemIDModeState::SYSTEMID_STATE_STOPPED;
        gcs().send_text(MAV_SEVERITY_INFO, "SystemID Parameter Error");
    }

    waveform_time += G_Dt;
    waveform_sample = waveform(waveform_time - SYSTEM_ID_DELAY);

    switch (systemid_state) {
        case SystemIDModeState::SYSTEMID_STATE_STOPPED:
            break;
        case SystemIDModeState::SYSTEMID_STATE_TESTING:

            if (copter.ap.land_complete) {
                systemid_state = SystemIDModeState::SYSTEMID_STATE_STOPPED;
                gcs().send_text(MAV_SEVERITY_INFO, "SystemID Stopped: Landed");
                break;
            }
            if (attitude_control->lean_angle()*100 > attitude_control->lean_angle_max()) {
                systemid_state = SystemIDModeState::SYSTEMID_STATE_STOPPED;
                gcs().send_text(MAV_SEVERITY_INFO, "SystemID Stopped: lean=%f max=%f", (double)attitude_control->lean_angle(), (double)attitude_control->lean_angle_max());
                break;
            }
            if (waveform_time > SYSTEM_ID_DELAY + time_fade_in + time_const_freq + time_record + time_fade_out) {
                systemid_state = SystemIDModeState::SYSTEMID_STATE_STOPPED;
                gcs().send_text(MAV_SEVERITY_INFO, "SystemID Finished");
                break;
            }

            switch ((AxisType)axis.get()) {
                case AxisType::NONE:
                    systemid_state = SystemIDModeState::SYSTEMID_STATE_STOPPED;
                    gcs().send_text(MAV_SEVERITY_INFO, "SystemID Stopped: axis = 0");
                    break;
                case AxisType::INPUT_ROLL:
                    input_roll = waveform_sample * 100.0f;
                    break;
                case AxisType::INPUT_PITCH:
                    input_pitch = waveform_sample * 100.0f;
                    break;
                case AxisType::INPUT_YAW:
                    input_yaw = waveform_sample * 100.0f;
                    break;
                case AxisType::RECOVER_ROLL:
                    recovery_roll = waveform_sample;
                    break;
                case AxisType::RECOVER_PITCH:
                    recovery_pitch = waveform_sample;
                    break;
                case AxisType::RECOVER_YAW:
                    recovery_yaw = waveform_sample;
                    break;
                case AxisType::RATE_ROLL:
                    break;
                case AxisType::RATE_PITCH:
                    break;
                case AxisType::RATE_YAW:
                    break;
                case AxisType::MIX_ROLL:
                    mix_roll = waveform_sample;
                    break;
                case AxisType::MIX_PITCH:
                    mix_pitch = waveform_sample;
                    break;
                case AxisType::MIX_YAW:
                    mix_yaw = waveform_sample;
                    break;
                case AxisType::MIX_THROTTLE:
                    mix_throttle = waveform_sample;
                    break;
            }
            break;
    }

       int16_t combined_roll = channel_roll->get_control_in() + (int16_t) input_roll;
       QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_lat = combined_roll/float(4500); //
       int16_t combined_pitch = channel_pitch->get_control_in() + (int16_t) input_pitch;
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_lon = combined_pitch/float(4500); //
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_col = channel_throttle->get_control_in()/float(1000); //
       int16_t combined_yaw = channel_yaw->get_control_in() + (int16_t) input_yaw;
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_ped = combined_yaw/float(4500); //

        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vN_fpsKF = curr_vel.x / float(100); //convert cm/s to m/s
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vE_fpsKF = curr_vel.y / float(100); // convert cm/s to m/s
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vD_fpsKF = curr_vel.z / float(-100); // convert cm/s to m/s

         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.p_rps = gyro.x; //rad/s
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.q_rps = gyro.y; //rad/s
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.r_rps = gyro.z ; //rad/s

         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.phi_rad = (QSahrs.roll_sensor + recovery_roll) / (57.3f*100.0f); //convert to rad
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.theta_rad = (QSahrs.pitch_sensor + recovery_pitch) / (57.3f*100.0f); //convert to rad
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_rad = (QSahrs.yaw_sensor + recovery_yaw) / (57.3f*100.0f); //convert to rad

         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posNorthKF = curr_pos.x / float(100);  //convert cm to m
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posEastKF = curr_pos.y / float(100);  //convert cm to m
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posDownKF =  curr_pos.z / float(-100);  //convert cm to m
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Baro_Alt_m = copter.barometer.get_altitude();  //baro altitude in meters
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Ax_mpss =  accel.x; //m/s^2
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Ay_mpss =  accel.y; //m/s^2
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Az_mpss =  accel.z; //m/s^2
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.mixer_in_x = motors->get_roll();
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.mixer_in_y = motors->get_pitch();
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.mixer_in_z = motors->get_yaw();
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.mixer_in_throttle = attitude_control->get_throttle_in();


     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.CH8_flag = traj_sw; // this was set to channel 6
     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.rc_6 = traj_sw;  // this was set to channel 6

     //     Scale Sweep Size
     if(GSInputs.ch1 == 0){
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.sweep_multiplier = 1;
     }
     else if(GSInputs.ch1 < 0){
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.sweep_multiplier = 1/abs(GSInputs.ch1);
     }
     else{
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.sweep_multiplier = GSInputs.ch1;
     }


//
 //    Trajectory on or off

     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.TrajectorySwitch = traj_sw;

     alpha = 1.0; // hard coding alpha
     //Scale RV
         if(alpha <= 0 || alpha > 3 ){
             QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rv = 2;
         }
             else {
                 QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rv = 1/alpha;
         }
    //Scale Rp (actually don't)
             QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rp = 1;



     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vel        = 0.0f;
     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_flight_path = 0.0f;
     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.gamma      =  0.0f;
     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_quad   =  0.0f;

     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.engage = engage;

     QS_InnerRateLoop_Obj.step();

     engage = 1;
	 	 
	 // Logging
     if (log_counter_qs ++ % 10 == 0){
            AP::logger().Write("QSS", "TimeUS,p,q,r,ph,th,psi,lat,lon,col,pd,mx,my,mz,mth" , "Qffffffffffffff",
                                                    AP_HAL::micros64(),
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.p_rps,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.q_rps,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.r_rps,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.phi_rad,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.theta_rad,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_rad,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_lat,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_lon,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_col,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_ped,
                                                    (double)(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_x + mix_roll),
                                                    (double)(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_y + mix_pitch),
                                                    (double)(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_z + mix_yaw),
                                                    (double)(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_throttle + mix_throttle));


            AP::logger().Write("QSS2", "TimeUS,swpx,swpy,swpz,swpth,eng,phic,thtc,psic,vzc,CFz,CFvz" , "Qfffffffffff",
                                                    AP_HAL::micros64(),
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.pitch_sweep,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.roll_sweep,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.yaw_sweep,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.coll_sweep,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.engage,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.phi_cmd,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.theta_cmd,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.psi_cmd,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.vz_cmd,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.CF_Alt,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.CF_Vz);

            AP::logger().Write("QSS3", "TimeUS,pN,pE,pD,vN,vE,vD,tSW,tON,pNc,pEc,pDc,psc" , "Qffffffffffff",
                                                    AP_HAL::micros64(),
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posNorthKF,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posEastKF,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posDownKF,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vN_fpsKF,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vE_fpsKF,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vD_fpsKF,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.TrajectorySwitch,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.TrajectoryON,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vnorth_cmd,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Veast_cmd,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vdown_cmd,
                                                    (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.vehheadingcmd);
                                  }


     mix_x = (QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_x + mix_roll)*.9;
     mix_y = (QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_y + mix_pitch)*.9;
     mix_z = QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_z + mix_yaw;
     throttle = QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_throttle + mix_throttle;


     motors->set_roll(constrain_float(mix_x,-1.0f,1.0f));
     motors->set_pitch(constrain_float(mix_y,-1.0f,1.0f));
     motors->set_yaw(constrain_float(mix_z,-1.0f,1.0f));
     motors->set_throttle(constrain_float(throttle,0.0f,1.0f));

/*
     motors->set_roll(mix_x);
     motors->set_pitch(mix_y);
     motors->set_yaw(mix_z);
     motors->set_throttle(throttle);
*/

}


// init_test - initialises the test
float ModeSystemId::waveform(float time)
{
    float wMin = 2 * M_PI * frequency_start;
    float wMax = 2 * M_PI * frequency_stop;

    float window;
    float output;

    float B = logf(wMax / wMin);

    if (time <= 0.0f) {
        window = 0.0f;
    } else if (time <= time_fade_in) {
        window = 0.5 - 0.5 * cosf(M_PI * time / time_fade_in);
    } else if (time <= time_record - time_fade_out) {
        window = 1.0;
    } else if (time <= time_record) {
        window = 0.5 - 0.5 * cosf(M_PI * (time - (time_record - time_fade_out)) / time_fade_out + M_PI);
    } else {
        window = 0.0;
    }

    if (time <= 0.0f) {
        waveform_freq_rads = wMin;
        output = 0.0f;
    } else if (time <= time_const_freq) {
        waveform_freq_rads = wMin;
        output = window * waveform_magnitude * sinf(wMin * time - wMin * time_const_freq);
    } else if (time <= time_record) {
        waveform_freq_rads = wMin * expf(B * (time - time_const_freq) / (time_record - time_const_freq));
        output = window * waveform_magnitude * sinf((wMin * (time_record - time_const_freq) / B) * (expf(B * (time - time_const_freq) / (time_record - time_const_freq)) - 1));
    } else {
        waveform_freq_rads = wMax;
        output = 0.0f;
    }
    return output;
}

#endif
