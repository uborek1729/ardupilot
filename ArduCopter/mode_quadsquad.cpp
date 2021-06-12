#include "Copter.h"

const AP_Param::GroupInfo ModeQuadsquad::var_info[] = {

    // @Param: _ALPHA
    // @DisplayName: Agressiveness of trajectory
    // @Description: More aggressive maneuver as alpha gets bigger
    // @Range: 0 3
    // @User: Standard
    AP_GROUPINFO("ALPHA", 1, ModeQuadsquad, alpha, 0.5f),

    AP_GROUPEND
};

ModeQuadsquad::ModeQuadsquad(void) : Mode()
{
    AP_Param::setup_object_defaults(this, var_info);
}

/*
 * Init and run calls for QuadSquad flight mode
 */
// quadsquad_init - initialise quadsquad controller
bool ModeQuadsquad::init(bool ignore_checks)
{
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

 //   trajGen.setRp(5);
 //   trajGen.setRv(5);
//    trajGen.setManeuver(7);


    // stabilize should never be made to fail
    return true;
}


// QuadSquad_run - runs the main QuadSquad controller
// should be called at 100hz or more
void ModeQuadsquad::run()
{
  //  int16_t target_roll, target_pitch;
 //    float target_yaw_rate;
 //    int16_t pilot_throttle_scaled;
     float mix_x, mix_y, mix_z, throttle;

 //    float normInnov; // normalised innovation variance ratio for optical flow observations fused by the main nav filter
 //    float gndOffset; // estimated vertical position of the terrain relative to the nav filter zero datum
 //    float flowInnovX, flowInnovY; // optical flow LOS rate vector innovations from the main nav filter
//     float auxFlowInnov; // optical flow LOS rate innovation from terrain offset estimator
//     float HAGL; // height above ground level
 //    float rngInnov; // range finder innovations
 //    float range; // measured range
//     float gndOffsetErr; // filter ground offset state error
     //ahrs.get_NavEKF().getFlowDebug(normInnov, gndOffset, flowInnovX, flowInnovY, auxFlowInnov, HAGL, rngInnov, range, gndOffsetErr);
 //    float alpha = 0;
 //    float epsilon = 0;

     const Vector3f &accel = copter.ins.get_accel();
     const Vector3f &gyro = copter.ins.get_gyro();

 //    Vector3f posNED
 //    Vector3f velNED;
//     ahrs.get_NavEKF2().getVelNED(0,velNED);
//     ahrs.get_NavEKF2().getPosNED(0,posNED);
     const Vector3f &curr_pos = inertial_nav.get_position();
     const Vector3f &curr_vel = inertial_nav.get_velocity();
     //const Vector2f &flowRate = optflow.flowRate();
     //const Vector2f &bodyRate = optflow.bodyRate();

    // apply simple mode transform to pilot inputs
    update_simple_mode();

/*    // convert pilot input to lean angles
    float target_roll, target_pitch;
    get_pilot_desired_lean_angles(target_roll, target_pitch, copter.aparm.angle_max, copter.aparm.angle_max);

    // get pilot's desired yaw rate
    float target_yaw_rate = get_pilot_desired_yaw_rate(channel_yaw->get_control_in());
*/


    if (!motors->armed()) {
        // Motors should be Stopped
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::SHUT_DOWN);
    } else if (copter.ap.throttle_zero) {
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
        attitude_control->set_yaw_target_to_current_heading();
        attitude_control->reset_rate_controller_I_terms_smoothly();
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

/*    // call attitude controller
    attitude_control->input_euler_angle_roll_pitch_euler_rate_yaw(target_roll, target_pitch, target_yaw_rate);

    // output pilot's throttle
    attitude_control->set_throttle_out(get_pilot_desired_throttle(),
                                       true,
                                       g.throttle_filt);
*/
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_lat = channel_roll->get_control_in()/float(4500); //
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_lon = channel_pitch->get_control_in()/float(4500); //
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_col = channel_throttle->get_control_in()/float(1000); //
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.input_ped = channel_yaw->get_control_in()/float(4500); //

        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vN_fpsKF = curr_vel.x / float(100); //convert cm/s to m/s
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vE_fpsKF = curr_vel.y / float(100); // convert cm/s to m/s
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vD_fpsKF = curr_vel.z / float(-100); // convert cm/s to m/s

         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.p_rps = gyro.x; //rad/s
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.q_rps = gyro.y; //rad/s
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.r_rps = gyro.z ; //rad/s

         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.phi_rad = QSahrs.roll_sensor / (57.3f*100.0f); //convert to rad
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.theta_rad = QSahrs.pitch_sensor / (57.3f*100.0f); //convert to rad
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_rad = QSahrs.yaw_sensor / (57.3f*100.0f); //convert to rad

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


//*****Commented out to get working*********
//     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.CH8_flag = read_3pos_switch(CH_6);
 //    QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.rc_6 = read_3pos_switch(CH_6);

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

//*****Commented out to get working*********
 //    QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.TrajectorySwitch = read_3pos_switch(CH_6);
     /*
     if(GSInputs.ch2==0){
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.TrajectorySwitch = 0;
 //        trajGen.enabled(false);
 //        trajGen.reset();
     }
     else{
        QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.TrajectorySwitch = 1;
  //       trajGen.enabled(true);
     }
     */
     //Scale RV
         if(alpha <= 0 || alpha > 3 ){
             QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rv = 2;
         }
             else {
                 QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rv = 1/alpha;
         }
    //Scale Rp (actually don't)
             QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rp = 1;


//
//     trajGen.step();
//
//     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vel        = trajGen.getVel();
// //    QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_flight = trajGen.getHdg();GSInputs.ch3
//     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_flight = GSInputs.ch3;
//     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.gamma      = trajGen.getGS();
//     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_quad   = trajGen.getvHdg();

     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vel        = 0.0f;
      //  QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_flight = trajGen.getHdg();GSInputs.ch3
     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_flight_path = 0.0f;
     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.gamma      =  0.0f;
     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.psi_quad   =  0.0f;

    //  QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.climbrate_fps = baro_climbrate *  (float)0.032808; //convert cm to fps

     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.engage = engage;

     QS_InnerRateLoop_Obj.step();

     engage = 1;

    /* if (QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.ScoreOn==1){
     trajectorycount = trajectorycount+1;
     alpha = (float)1/QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rv;
     VeSqrSum = VeSqrSum +
             (QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vnorth_cmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vN_fpsKF)*(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vnorth_cmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vN_fpsKF) +
             (QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Veast_cmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vE_fpsKF)*(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Veast_cmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vE_fpsKF) +
             (QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vdown_cmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vD_fpsKF)*(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vdown_cmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.vD_fpsKF);
     pNcmd = pNcmd+QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vnorth_cmd*0.0025;
     pEcmd = pEcmd+QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Veast_cmd*0.0025;
     pDcmd = pDcmd+QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vdown_cmd*0.0025;
     if (vmax < sqrt(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vnorth_cmd*QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vnorth_cmd+QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Veast_cmd*QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Veast_cmd+QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vdown_cmd*QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vdown_cmd)){
     vmax = sqrt(QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vnorth_cmd*QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vnorth_cmd+QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Veast_cmd*QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Veast_cmd+QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vdown_cmd*QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.Vdown_cmd);
     }
     if (pmax < sqrt(pNcmd*pNcmd+pEcmd*pEcmd+pDcmd*pDcmd)){
     pmax = sqrt(pNcmd*pNcmd+pEcmd*pEcmd+pDcmd*pDcmd);
     }
     PeSqrSum = PeSqrSum +
             (pNcmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posNorthKF)*(pNcmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posNorthKF) +
             (pEcmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posEastKF)*(pEcmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posEastKF) +
             (pDcmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posDownKF)*(pDcmd-QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posDownKF);
     epsilon = 0.7*sqrt(VeSqrSum/trajectorycount)/vmax + 0.3*sqrt(PeSqrSum/trajectorycount)/pmax;
     score = 200/(1+exp(0.6*(alpha-3)/(0-3)+0.4*(epsilon-0)/(0.6-0)));
     }
     else{
         alpha = 0;
         epsilon=0;
         VeSqrSum= 0;
         PeSqrSum= 0;
         pNcmd= 0;
         pEcmd= 0;
         pDcmd= 0;
         vmax = 1;
         pmax = 1;
         trajectorycount = 0;

}

*/

     mix_x = QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_x;
     mix_y = QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_y;
     mix_z = QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_z;
     throttle = QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_throttle;

//     gcs_send_text_fmt(MAV_SEVERITY_WARNING, "lat=%.6f col=%.6f",
//                                       (double)mix_x,
//                                       (double)throttle);

     //     motors->set_stabilizing(true); old version of code used this.
     motors->set_roll(mix_x);
     motors->set_pitch(mix_y);
     motors->set_yaw(mix_z);
     motors->set_throttle(throttle);



}
