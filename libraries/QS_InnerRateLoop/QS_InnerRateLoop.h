//
// File: QS_InnerRateLoop.h
//
// Code generated for Simulink model 'QS_InnerRateLoop'.
//
// Model version                  : 1.287
// Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
// C/C++ source code generated on : Thu Jun 08 14:44:18 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_QS_InnerRateLoop_h_
#define RTW_HEADER_QS_InnerRateLoop_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef QS_InnerRateLoop_COMMON_INCLUDES_
# define QS_InnerRateLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // QS_InnerRateLoop_COMMON_INCLUDES_

#include "QS_InnerRateLoop_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  real32_T col;                        // '<S57>/col'
  real32_T lon;                        // '<S48>/lon'
  real32_T lat;                        // '<S48>/lat'
  real32_T col_f;                      // '<S48>/col'
  real32_T ped;                        // '<S48>/ped'
  real32_T In1[4];                     // '<S4>/In1'
  real32_T Gain;                       // '<S2>/Gain'
} BlockIO_QS_InnerRateLoop_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T Delay2_DSTATE;                // '<S46>/Delay2'
  real32_T Delay1_DSTATE;              // '<S46>/Delay1'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S39>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_n;// '<S31>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_g;// '<S38>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTATE;// '<S31>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTATE_c;// '<S37>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator2_DSTATE;// '<S31>/Discrete-Time Integrator2'
  real32_T UnitDelay_DSTATE;           // '<S9>/Unit Delay'
  real32_T UnitDelay1_DSTATE;          // '<S61>/Unit Delay1'
  real32_T UnitDelay2_DSTATE;          // '<S61>/Unit Delay2'
  real32_T UnitDelay_DSTATE_e;         // '<S19>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTATE_b;// '<S18>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_m;// '<S17>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTAT_k;// '<S16>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTAT_cl;// '<S22>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_k;// '<S21>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_d;// '<S36>/Discrete-Time Integrator'
  real32_T UnitDelay1_DSTATE_b;        // '<S43>/Unit Delay1'
  real32_T UnitDelay_DSTATE_ei;        // '<S43>/Unit Delay'
  real32_T DiscreteTimeIntegrator1_DSTAT_a;// '<S43>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTAT_go;// '<S43>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_h;// '<S45>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_i;// '<S44>/Discrete-Time Integrator'
  real32_T UnitDelay1_DSTATE_m;        // '<S59>/Unit Delay1'
  real32_T UnitDelay2_DSTATE_k;        // '<S59>/Unit Delay2'
  real32_T UnitDelay1_DSTATE_h;        // '<S20>/Unit Delay1'
  real32_T UnitDelay_DSTATE_i;         // '<S20>/Unit Delay'
  real32_T DiscreteTimeIntegrator1_DSTAT_l;// '<S20>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTAT_ba;// '<S20>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_l;// '<S26>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_mn;// '<S27>/Discrete-Time Integrator'
  real32_T UnitDelay_DSTATE_l;         // '<S11>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTATE_a;// '<S11>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_h4;// '<S13>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_iz;// '<S19>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_gi;// '<S12>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_ia;// '<S14>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_kt;// '<S15>/Discrete-Time Integrator'
  real32_T DiscreteTransferFcn_states; // '<S3>/Discrete Transfer Fcn'
  real32_T DiscreteTransferFcn1_states;// '<S3>/Discrete Transfer Fcn1'
  real32_T DiscreteTransferFcn2_states;// '<S3>/Discrete Transfer Fcn2'
  real32_T UnitDelay_DSTATE_a;         // '<S50>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTAT_dn;// '<S51>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_c1;// '<S16>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_e;// '<S35>/Discrete-Time Integrator'
  real32_T UnitDelay1_DSTATE_o;        // '<S40>/Unit Delay1'
  real32_T UnitDelay_DSTATE_d;         // '<S40>/Unit Delay'
  real32_T DiscreteTimeIntegrator1_DSTAT_b;// '<S40>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTATE_p;// '<S40>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_mi;// '<S42>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_kw;// '<S41>/Discrete-Time Integrator'
  real32_T UnitDelay1_DSTATE_g;        // '<S60>/Unit Delay1'
  real32_T UnitDelay2_DSTATE_k5;       // '<S60>/Unit Delay2'
  real32_T UnitDelay1_DSTATE_bm;       // '<S16>/Unit Delay1'
  real32_T UnitDelay_DSTATE_g;         // '<S16>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTAT_er;// '<S58>/Discrete-Time Integrator'
  real32_T UnitDelay_DSTATE_m;         // '<S58>/Unit Delay'
  uint32_T m_bpIndex;                  // '<S9>/1-D Lookup Table3'
  uint32_T m_bpIndex_k;                // '<S9>/1-D Lookup Table1'
  uint32_T m_bpIndex_p;                // '<S9>/1-D Lookup Table'
  uint32_T m_bpIndex_k4;               // '<S9>/1-D Lookup Table2'
  boolean_T UnitDelay_DSTATE_mj;       // '<S61>/Unit Delay'
  boolean_T UnitDelay_DSTATE_ap;       // '<S59>/Unit Delay'
  boolean_T UnitDelay_DSTATE_f;        // '<S60>/Unit Delay'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S39>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_h;// '<S31>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_e;// '<S38>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S31>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevR_h3;// '<S37>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator2_PrevRes;// '<S31>/Discrete-Time Integrator2'
  int8_T DiscreteTimeIntegrator1_PrevR_i;// '<S16>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevRe_g;// '<S36>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevR_g;// '<S43>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevRe_i;// '<S43>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_hj;// '<S45>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevR_n;// '<S20>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevRe_l;// '<S20>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_b;// '<S11>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_o;// '<S13>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_p;// '<S19>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_bj;// '<S12>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_c;// '<S14>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_m;// '<S15>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_a;// '<S51>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_ez;// '<S16>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_gi;// '<S35>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevR_b;// '<S40>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevRe_f;// '<S40>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_ab;// '<S42>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_k;// '<S58>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S31>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// '<S31>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator2_IC_LOAD;// '<S31>/Discrete-Time Integrator2'
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;// '<S43>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;// '<S43>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_SYSTE_n;// '<S20>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator_SYSTEM_c;// '<S20>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOA_f;// '<S11>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_SYSTE_j;// '<S40>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator_SYSTEM_j;// '<S40>/Discrete-Time Integrator'
} D_Work_QS_InnerRateLoop_T;

// Invariant block signals (auto storage)
typedef const struct tag_ConstBlockIO_QS_InnerRate_T {
  real32_T TrigonometricFunction1;     // '<S34>/Trigonometric Function1'
  real32_T TrigonometricFunction5;     // '<S34>/Trigonometric Function5'
  real32_T TrigonometricFunction4;     // '<S34>/Trigonometric Function4'
  real32_T Constant;                   // '<S39>/Constant'
  real32_T TrigonometricFunction2;     // '<S6>/Trigonometric Function2'
  real32_T TrigonometricFunction5_m;   // '<S6>/Trigonometric Function5'
  real32_T TrigonometricFunction4_m;   // '<S6>/Trigonometric Function4'
  real32_T TrigonometricFunction1_o;   // '<S6>/Trigonometric Function1'
  real32_T Constant_o;                 // '<S38>/Constant'
  real32_T TrigonometricFunction2_d;   // '<S34>/Trigonometric Function2'
  real32_T Constant_p;                 // '<S37>/Constant'
  real32_T TrigonometricFunction1_b;   // '<S49>/Trigonometric Function1'
  real32_T TrigonometricFunction5_d;   // '<S49>/Trigonometric Function5'
  real32_T TrigonometricFunction4_m2;  // '<S49>/Trigonometric Function4'
  real32_T TrigonometricFunction2_m;   // '<S49>/Trigonometric Function2'
  real32_T Constant_g;                 // '<S36>/Constant'
  real32_T Constant_k;                 // '<S43>/Constant'
  real32_T Constant1;                  // '<S43>/Constant1'
  real32_T TrigonometricFunction3;     // '<S5>/Trigonometric Function3'
  real32_T TrigonometricFunction6;     // '<S5>/Trigonometric Function6'
  real32_T Sum1;                       // '<S54>/Sum1'
  real32_T Sum3;                       // '<S54>/Sum3'
  real32_T Sum2;                       // '<S54>/Sum2'
  real32_T Sum4;                       // '<S54>/Sum4'
  real32_T Constant_i;                 // '<S35>/Constant'
  real32_T Constant_n;                 // '<S40>/Constant'
  real32_T Constant1_m;                // '<S40>/Constant1'
  real32_T TrigonometricFunction4_h;   // '<S33>/Trigonometric Function4'
  real32_T TrigonometricFunction5_k;   // '<S33>/Trigonometric Function5'
  real32_T TrigonometricFunction1_e;   // '<S33>/Trigonometric Function1'
  real32_T TrigonometricFunction2_k;   // '<S33>/Trigonometric Function2'
  real32_T Sum2_b;                     // '<S55>/Sum2'
  real32_T Sum5;                       // '<S56>/Sum5'
} ConstBlockIO_QS_InnerRateLoop_T;

// Constant parameters (auto storage)
typedef struct {
  // Pooled Parameter (Expression: [0 0.1 1 1 1 0.1 0])
  //  Referenced by:
  //    '<S35>/1-D Lookup Table4'
  //    '<S35>/1-D Lookup Table6'
  //    '<S36>/1-D Lookup Table1'
  //    '<S36>/1-D Lookup Table3'

  real32_T pooled10[7];

  // Pooled Parameter (Expression: [-50 -30 -5 0 5 30 50])
  //  Referenced by:
  //    '<S35>/1-D Lookup Table4'
  //    '<S35>/1-D Lookup Table5'
  //    '<S35>/1-D Lookup Table6'
  //    '<S36>/1-D Lookup Table1'
  //    '<S36>/1-D Lookup Table2'
  //    '<S36>/1-D Lookup Table3'
  //    '<S38>/1-D Lookup Table1'
  //    '<S39>/1-D Lookup Table1'

  real32_T pooled11[7];

  // Pooled Parameter (Expression: [0.1 0.3 .9 1.5 .9 0.3 0.1])
  //  Referenced by:
  //    '<S38>/1-D Lookup Table1'
  //    '<S39>/1-D Lookup Table1'

  real32_T pooled24[7];

  // Expression: vhdg5
  //  Referenced by: '<S9>/1-D Lookup Table3'

  real32_T DLookupTable3_table[101];

  // Pooled Parameter (Expression: bp)
  //  Referenced by:
  //    '<S9>/1-D Lookup Table'
  //    '<S9>/1-D Lookup Table1'
  //    '<S9>/1-D Lookup Table2'
  //    '<S9>/1-D Lookup Table3'

  real32_T pooled25[101];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S9>/1-D Lookup Table'
  //    '<S9>/1-D Lookup Table1'
  //    '<S9>/1-D Lookup Table2'

  real32_T pooled27[101];

  // Pooled Parameter (Expression: [.3 .3 1 1 1 .3 .3])
  //  Referenced by:
  //    '<S35>/1-D Lookup Table5'
  //    '<S36>/1-D Lookup Table2'

  real32_T pooled35[7];

  // Computed Parameter: CinvAinv_Gain
  //  Referenced by: '<S3>/Cinv*Ainv'

  real32_T CinvAinv_Gain[36];

  // Computed Parameter: Binv1_Gain
  //  Referenced by: '<S3>/(Binv)^-1'

  real32_T Binv1_Gain[16];
} ConstParam_QS_InnerRateLoop_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  boolean_T engage;                    // '<Root>/engage'
  real32_T input_lat;                  // '<Root>/input_lat'
  real32_T input_lon;                  // '<Root>/input_lon'
  real32_T input_col;                  // '<Root>/input_col'
  real32_T input_ped;                  // '<Root>/input_ped'
  real32_T vN_fpsKF;                   // '<Root>/vN_fps (KF)'
  real32_T vE_fpsKF;                   // '<Root>/vE_fps (KF)'
  real32_T vD_fpsKF;                   // '<Root>/vD_fps (KF)'
  real32_T p_rps;                      // '<Root>/p_rps'
  real32_T q_rps;                      // '<Root>/q_rps'
  real32_T r_rps;                      // '<Root>/r_rps'
  real32_T phi_rad;                    // '<Root>/phi_rad'
  real32_T theta_rad;                  // '<Root>/theta_rad'
  real32_T psi_rad;                    // '<Root>/psi_rad'
  real32_T posNorthKF;                 // '<Root>/pos North (KF)'
  real32_T posEastKF;                  // '<Root>/pos East (KF)'
  real32_T posDownKF;                  // '<Root>/pos Down (KF)'
  real32_T mixer_in_x;                 // '<Root>/mixer_in_x'
  real32_T mixer_in_y;                 // '<Root>/mixer_in_y'
  real32_T mixer_in_z;                 // '<Root>/mixer_in_z'
  real32_T mixer_in_throttle;          // '<Root>/mixer_in_throttle'
  real32_T CH8_flag;                   // '<Root>/CH8_flag'
  real32_T rc_6;                       // '<Root>/rc_6'
  real32_T sweep_multiplier;           // '<Root>/sweep_multiplier'
  real32_T vel;                        // '<Root>/vel'
  real32_T psi_flight_path;            // '<Root>/psi_flight_path'
  real_T gamma;                        // '<Root>/gamma'
  real32_T psi_quad;                   // '<Root>/psi_quad'
  boolean_T TrajectorySwitch;          // '<Root>/Trajectory Switch'
  real32_T Rv;                         // '<Root>/Rv'
  real32_T Rp;                         // '<Root>/Rp'
} ExternalInputs_QS_InnerRateLo_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real32_T mixer_throttle;             // '<Root>/mixer_throttle'
  real32_T mixer_x;                    // '<Root>/mixer_x'
  real32_T mixer_y;                    // '<Root>/mixer_y'
  real32_T mixer_z;                    // '<Root>/mixer_z'
  real32_T roll_sweep;                 // '<Root>/roll_sweep'
  real32_T pitch_sweep;                // '<Root>/pitch_sweep'
  real32_T yaw_sweep;                  // '<Root>/yaw_sweep'
  real32_T coll_sweep;                 // '<Root>/coll_sweep'
  boolean_T TrajectoryON;              // '<Root>/TrajectoryON'
  real32_T phi_cmd;                    // '<Root>/phi_cmd'
  real32_T theta_cmd;                  // '<Root>/theta_cmd'
  real32_T vz_cmd;                     // '<Root>/vz_cmd'
  real32_T psi_cmd;                    // '<Root>/psi_cmd'
  real32_T Vnorth_cmd;                 // '<Root>/Vnorth_cmd'
  real32_T Veast_cmd;                  // '<Root>/Veast_cmd'
  real32_T Vdown_cmd;                  // '<Root>/Vdown_cmd'
  real32_T Vnorth_corr;                // '<Root>/Vnorth_corr'
  real32_T Veast_corr;                 // '<Root>/Veast_corr'
  real32_T Vdown_corr;                 // '<Root>/Vdown_corr'
  real32_T vehheadingcmd;              // '<Root>/vehheadingcmd'
} ExternalOutputs_QS_InnerRateL_T;

// Real-time Model Data Structure
struct tag_RTM_QS_InnerRateLoop_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

extern const ConstBlockIO_QS_InnerRateLoop_T QS_InnerRateLoop_ConstB;// constant block i/o 

// Constant parameters (auto storage)
extern const ConstParam_QS_InnerRateLoop_T QS_InnerRateLoop_ConstP;

// Class declaration for model QS_InnerRateLoop
class untitledModelClass {
  // public data and function members
 public:
  // External inputs
  ExternalInputs_QS_InnerRateLo_T QS_InnerRateLoop_U;

  // External outputs
  ExternalOutputs_QS_InnerRateL_T QS_InnerRateLoop_Y;

  // Model entry point functions

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  untitledModelClass();

  // Destructor
  ~untitledModelClass();

  // Real-Time Model get method
  RT_MODEL_QS_InnerRateLoop_T * getRTM();

  // private data and function members
 private:
  // Block signals
  BlockIO_QS_InnerRateLoop_T QS_InnerRateLoop_B;

  // Block states
  D_Work_QS_InnerRateLoop_T QS_InnerRateLoop_DWork;

  // Real-Time Model
  RT_MODEL_QS_InnerRateLoop_T QS_InnerRateLoop_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'QS_InnerRateLoop'
//  '<S1>'   : 'QS_InnerRateLoop/Attitude Control Loop'
//  '<S2>'   : 'QS_InnerRateLoop/Determine Heading at Start of Manuever  All trajectories relative to this heading'
//  '<S3>'   : 'QS_InnerRateLoop/Dynamic Inverse'
//  '<S4>'   : 'QS_InnerRateLoop/Enabled Subsystem Grab and Freeze Value Upon Engagement'
//  '<S5>'   : 'QS_InnerRateLoop/LocalVertical2Body '
//  '<S6>'   : 'QS_InnerRateLoop/NED to Local Vertical'
//  '<S7>'   : 'QS_InnerRateLoop/Outer Loop//Trajectory Control'
//  '<S8>'   : 'QS_InnerRateLoop/Subsystem'
//  '<S9>'   : 'QS_InnerRateLoop/Subsystem1'
//  '<S10>'  : 'QS_InnerRateLoop/Sweep Generator Broken Loop Sweeps'
//  '<S11>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command'
//  '<S12>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem'
//  '<S13>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem1'
//  '<S14>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem2'
//  '<S15>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3'
//  '<S16>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem/Generic second order lateral command model with limits'
//  '<S17>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem/Psuedo Derivative 100*s//(s+100)'
//  '<S18>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem/Psuedo Derivative 2 100*s//(s+100)'
//  '<S19>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem1/Generic first order collective command model'
//  '<S20>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem2/Generic second order longitudinal command model with limits'
//  '<S21>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem2/Psuedo Derivative 100*s//(s+100)'
//  '<S22>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem2/Psuedo Derivative 2 100*s//(s+100)'
//  '<S23>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3/-pi <= psi <= pi1'
//  '<S24>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3/-pi <= psi <= pi2'
//  '<S25>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3/-pi <= psi <= pi4'
//  '<S26>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3/Psuedo Derivative 100*s//(s+100)'
//  '<S27>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3/Psuedo Derivative 100*s//(s+100)1'
//  '<S28>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3/-pi <= psi <= pi1/0 <= psi <= 2*pi'
//  '<S29>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3/-pi <= psi <= pi2/0 <= psi <= 2*pi'
//  '<S30>'  : 'QS_InnerRateLoop/Attitude Control Loop/Subsystem3/-pi <= psi <= pi4/0 <= psi <= 2*pi'
//  '<S31>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Command Transforms '
//  '<S32>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control'
//  '<S33>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Command Transforms /LocalVertical 2 Inertial'
//  '<S34>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Inertial2LocalVertical'
//  '<S35>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Lat Velocity Controller'
//  '<S36>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Lon Velocity Controller'
//  '<S37>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/PI controller Down'
//  '<S38>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/PI controller East'
//  '<S39>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/PI controller North'
//  '<S40>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Lat Velocity Controller/Generic second order longitudinal command model with limits'
//  '<S41>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Lat Velocity Controller/Psuedo Derivative 10*s//(s+10)'
//  '<S42>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Lat Velocity Controller/Psuedo Derivative 100*s//(s+100)'
//  '<S43>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Lon Velocity Controller/Generic second order longitudinal command model with limits'
//  '<S44>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Lon Velocity Controller/Psuedo Derivative 10*s//(s+10)'
//  '<S45>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control/Position and Velocity Control/Lon Velocity Controller/Psuedo Derivative 100*s//(s+100)'
//  '<S46>'  : 'QS_InnerRateLoop/Subsystem/Determine if Traj Switch Has  Been Cycled since last trajectory'
//  '<S47>'  : 'QS_InnerRateLoop/Subsystem/Determine if still in position when switch was flipped to ON'
//  '<S48>'  : 'QS_InnerRateLoop/Subsystem/Enabled Subsystem1'
//  '<S49>'  : 'QS_InnerRateLoop/Subsystem1/NED to Local Vertical'
//  '<S50>'  : 'QS_InnerRateLoop/Sweep Generator Broken Loop Sweeps/chirp generator (Modified with reset capability)'
//  '<S51>'  : 'QS_InnerRateLoop/Sweep Generator Broken Loop Sweeps/chirp generator (Modified with reset capability)/Create Sweep'
//  '<S52>'  : 'QS_InnerRateLoop/Sweep Generator Broken Loop Sweeps/chirp generator (Modified with reset capability)/Create omega'
//  '<S53>'  : 'QS_InnerRateLoop/Sweep Generator Broken Loop Sweeps/chirp generator (Modified with reset capability)/Determine Freq Count'
//  '<S54>'  : 'QS_InnerRateLoop/Sweep Generator Broken Loop Sweeps/chirp generator (Modified with reset capability)/Event Counter'
//  '<S55>'  : 'QS_InnerRateLoop/Sweep Generator Broken Loop Sweeps/chirp generator (Modified with reset capability)/Create omega/Subsystem1'
//  '<S56>'  : 'QS_InnerRateLoop/Sweep Generator Broken Loop Sweeps/chirp generator (Modified with reset capability)/Create omega/Subsystem2'
//  '<S57>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command/Enabled Subsystem1'
//  '<S58>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command/Generic first order collective command model'
//  '<S59>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command/TFSWIT Transient Free Switch'
//  '<S60>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command/TFSWIT Transient Free Switch1'
//  '<S61>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command/TFSWIT Transient Free Switch2'

#endif                                 // RTW_HEADER_QS_InnerRateLoop_h_

//
// File trailer for generated code.
//
// [EOF]
//
