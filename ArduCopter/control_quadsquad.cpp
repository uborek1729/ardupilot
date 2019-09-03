/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include "Copter.h"



/*
 * control_stabilize.pde - init and run calls for stabilize flight mode
 */

// stabilize_init - initialise stabilize controller
bool Copter::quadsquad_init(bool ignore_checks)
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

// stabilize_run - runs the main stabilize controller
// should be called at 100hz or more
void Copter::quadsquad_run()
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

   //  const Vector3f &accel = ins.get_accel();
     const Vector3f &gyro = ins.get_gyro();


       if (log_counter_qs ++ % 10 == 0){
       DataFlash_Class::instance()->Log_Write("QS", "TimeUS,p,q,r,ph,th,psi,lat,lon,col,pd,mx,my,mz,mth" , "Qffffffffffffff",
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
                                               (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_x,
                                               (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_y,
                                               (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_z,
                                               (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.mixer_throttle);


       DataFlash_Class::instance()->Log_Write("QS2", "TimeUS,swpx,swpy,swpz,swpth,eng,phic,thtc,psic,vzc,tst,tstt" , "Qfffffffffff",
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
                                               (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.test1,
                                               (double)QS_InnerRateLoop_Obj.QS_InnerRateLoop_Y.test2);

       DataFlash_Class::instance()->Log_Write("QS3", "TimeUS,pN,pE,pD,vN,vE,vD,tSW,tON,pNc,pEc,pDc,psc" , "Qffffffffffff",
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



 //    Vector3f posNED
 //    Vector3f velNED;
//     ahrs.get_NavEKF2().getVelNED(0,velNED);
//     ahrs.get_NavEKF2().getPosNED(0,posNED);
     const Vector3f &curr_pos = inertial_nav.get_position();
     const Vector3f &curr_vel = inertial_nav.get_velocity();
     //const Vector2f &flowRate = optflow.flowRate();
     //const Vector2f &bodyRate = optflow.bodyRate();


     const float &input_throttle = attitude_control->get_throttle_mix();
    // if not armed or throttle at zero, set throttle to zero and exit immediately
    if(!motors->armed()) {
        attitude_control->set_throttle_out(0,true,g.throttle_filt);
        // slow start if landed
        if (ap.land_complete) {
        	motors->set_desired_spool_state(AP_Motors::DESIRED_SPIN_WHEN_ARMED);
        }
        return;
    }

    // apply SIMPLE mode transform to pilot inputs
    update_simple_mode();

    // convert pilot input to lean angles
     // To-Do: convert get_pilot_desired_lean_angles to return angles as floats
//     get_pilot_desired_lean_angles(g.rc_1.control_in, g.rc_2.control_in, target_roll, target_pitch);

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
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.posDownKF = curr_pos.z / float(-100);  //convert cm to m

         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.mixer_in_x = attitude_control->mixer_roll();
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.mixer_in_y = attitude_control->mixer_pitch();
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.mixer_in_z = attitude_control->mixer_yaw();
         QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.mixer_in_throttle = attitude_control->get_throttle_in();



     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.CH8_flag = read_3pos_switch(CH_6);
     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.rc_6 = read_3pos_switch(CH_6);

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

     QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.TrajectorySwitch = read_3pos_switch(CH_6);
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
         if(g.alpha <= 0 || g.alpha > 3 ){
             QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rv = 2;
         }
             else {
                 QS_InnerRateLoop_Obj.QS_InnerRateLoop_U.Rv = 1/g.alpha;
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

 //    attitude_control.qs_controller_set(mix_x, mix_y, mix_z, throttle);
 //    attitude_control.qs_controller_run;

     //     motors->set_stabilizing(true); old version of code used this.
     motors->set_roll(mix_x);
     motors->set_pitch(mix_y);
     motors->set_yaw(mix_z);
     motors->set_throttle(throttle);


}
