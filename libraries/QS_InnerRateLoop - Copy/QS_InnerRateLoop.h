//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: QS_InnerRateLoop.h
//
// Code generated for Simulink model 'QS_InnerRateLoop'.
//
// Model version                  : 1.526
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Fri Nov 22 11:47:45 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
//    3. ROM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_QS_InnerRateLoop_h_
#define RTW_HEADER_QS_InnerRateLoop_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <AP_Math/AP_Math.h>
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

// Block signals (default storage)
typedef struct {
  real32_T col;                        // '<S94>/col'
  real32_T lon;                        // '<S92>/lon'
  real32_T lat;                        // '<S92>/lat'
  real32_T col_h;                      // '<S92>/col'
  real32_T ped;                        // '<S92>/ped'
  real32_T In1[4];                     // '<S5>/In1'
  real32_T Gain;                       // '<S3>/Gain'
} BlockIO_QS_InnerRateLoop_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T Delay2_DSTATE;                // '<S90>/Delay2'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S54>/Discrete-Time Integrator'
  real32_T Delay1_DSTATE;              // '<S90>/Delay1'
  real32_T DiscreteTimeIntegrator_DSTATE_a;// '<S89>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_m;// '<S64>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_h;// '<S86>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTATE;// '<S64>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTATE_c;// '<S83>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator2_DSTATE;// '<S64>/Discrete-Time Integrator2'
  real32_T UnitDelay_DSTATE;           // '<S11>/Unit Delay'
  real32_T UnitDelay1_DSTATE;          // '<S98>/Unit Delay1'
  real32_T UnitDelay2_DSTATE;          // '<S98>/Unit Delay2'
  real32_T UnitDelay_DSTATE_a;         // '<S34>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTAT_hq;// '<S26>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_b;// '<S25>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTAT_o;// '<S27>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTAT_mk;// '<S42>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_o;// '<S41>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator1_DSTAT_m;// '<S43>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTATE_d;// '<S52>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_mr;// '<S53>/Discrete-Time Integrator'
  real32_T Delay_DSTATE;               // '<S12>/Delay'
  real32_T DiscreteTimeIntegrator_DSTAT_mz;// '<S12>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_f;// '<S35>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_fs;// '<S34>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_c4;// '<S36>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_o2;// '<S28>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_bw;// '<S29>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_j;// '<S44>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_di;// '<S45>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_l;// '<S55>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_hv;// '<S56>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_co;// '<S60>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_i;// '<S61>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_ch;// '<S62>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_a5;// '<S63>/Discrete-Time Integrator'
  real32_T UnitDelay_DSTATE_f;         // '<S60>/Unit Delay'
  real32_T UnitDelay_DSTATE_av;        // '<S61>/Unit Delay'
  real32_T UnitDelay_DSTATE_d;         // '<S62>/Unit Delay'
  real32_T UnitDelay_DSTATE_e;         // '<S63>/Unit Delay'
  real32_T UnitDelay_DSTATE_o;         // '<S56>/Unit Delay'
  real32_T UnitDelay_DSTATE_eo;        // '<S45>/Unit Delay'
  real32_T UnitDelay_DSTATE_b;         // '<S29>/Unit Delay'
  real32_T UnitDelay_DSTATE_h;         // '<S36>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTATE_n;// '<S79>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_g;// '<S80>/Discrete-Time Integrator'
  real32_T UnitDelay2_DSTATE_k;        // '<S96>/Unit Delay2'
  real32_T UnitDelay1_DSTATE_f;        // '<S96>/Unit Delay1'
  real32_T UnitDelay1_DSTATE_c;        // '<S43>/Unit Delay1'
  real32_T UnitDelay_DSTATE_j;         // '<S43>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTAT_cf;// '<S75>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_cc;// '<S76>/Discrete-Time Integrator'
  real32_T UnitDelay2_DSTATE_a;        // '<S97>/Unit Delay2'
  real32_T UnitDelay1_DSTATE_fj;       // '<S97>/Unit Delay1'
  real32_T UnitDelay1_DSTATE_a;        // '<S27>/Unit Delay1'
  real32_T UnitDelay_DSTATE_g;         // '<S27>/Unit Delay'
  real32_T UnitDelay_DSTATE_gi;        // '<S76>/Unit Delay'
  real32_T UnitDelay_DSTATE_oc;        // '<S80>/Unit Delay'
  real32_T UnitDelay_DSTATE_j2;        // '<S14>/Unit Delay'
  real32_T UnitDelay_DSTATE_da;        // '<S15>/Unit Delay'
  real32_T UnitDelay_DSTATE_ag;        // '<S16>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTATE_e;// '<S16>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_cg;// '<S17>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_o3;// '<S15>/Discrete-Time Integrator'
  real32_T UnitDelay1_DSTATE_a1;       // '<S13>/Unit Delay1'
  real32_T UnitDelay_DSTATE_ak;        // '<S13>/Unit Delay'
  real32_T DiscreteTimeIntegrator1_DSTAT_g;// '<S13>/Discrete-Time Integrator1'
  real32_T DiscreteTimeIntegrator_DSTAT_nv;// '<S14>/Discrete-Time Integrator'
  real32_T UnitDelay_DSTATE_o1;        // '<S17>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTAT_gh;// '<S13>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_dn;// '<S27>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_nq;// '<S43>/Discrete-Time Integrator'
  real32_T UnitDelay_DSTATE_k;         // '<S95>/Unit Delay'
  real32_T DiscreteTimeIntegrator_DSTAT_gy;// '<S95>/Discrete-Time Integrator'
  real32_T PrevY;                      // '<S11>/Rate Limiter'
  boolean_T UnitDelay_DSTATE_ax;       // '<S98>/Unit Delay'
  boolean_T Delay1_DSTATE_j[2];        // '<S12>/Delay1'
  boolean_T UnitDelay_DSTATE_e2;       // '<S96>/Unit Delay'
  boolean_T UnitDelay_DSTATE_j1;       // '<S97>/Unit Delay'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S89>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_a;// '<S64>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_o;// '<S86>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S64>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevRe_b;// '<S83>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator2_PrevRes;// '<S64>/Discrete-Time Integrator2'
  int8_T DiscreteTimeIntegrator1_PrevR_g;// '<S27>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator1_PrevR_j;// '<S43>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevRe_p;// '<S12>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_bp;// '<S54>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_m;// '<S35>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_n;// '<S34>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_by;// '<S36>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_e;// '<S28>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_d;// '<S44>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_j;// '<S55>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_h;// '<S79>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_dc;// '<S75>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_l;// '<S16>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_em;// '<S17>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_hn;// '<S15>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_Prev_gs;// '<S13>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevR_pr;// '<S14>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_lm;// '<S13>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_f;// '<S27>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_f0;// '<S43>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_bv;// '<S95>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S64>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// '<S64>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator2_IC_LOAD;// '<S64>/Discrete-Time Integrator2'
  uint8_T icLoad;                      // '<S12>/Delay'
  uint8_T DiscreteTimeIntegrator_IC_LOA_b;// '<S12>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOA_j;// '<S16>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOA_m;// '<S15>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator1_IC_LO_e;// '<S13>/Discrete-Time Integrator1'
} D_Work_QS_InnerRateLoop_T;

// Invariant block signals (default storage)
typedef const struct tag_ConstBlockIO_QS_InnerRate_T {
  real32_T TrigonometricFunction2;     // '<S8>/Trigonometric Function2'
  real32_T TrigonometricFunction5;     // '<S8>/Trigonometric Function5'
  real32_T TrigonometricFunction4;     // '<S8>/Trigonometric Function4'
  real32_T TrigonometricFunction1;     // '<S8>/Trigonometric Function1'
  real32_T TrigonometricFunction3;     // '<S7>/Trigonometric Function3'
  real32_T TrigonometricFunction6;     // '<S7>/Trigonometric Function6'
  real32_T TrigonometricFunction1_g;   // '<S67>/Trigonometric Function1'
  real32_T TrigonometricFunction5_j;   // '<S67>/Trigonometric Function5'
  real32_T TrigonometricFunction4_k;   // '<S67>/Trigonometric Function4'
  real32_T TrigonometricFunction2_a;   // '<S67>/Trigonometric Function2'
  real32_T TrigonometricFunction1_k;   // '<S93>/Trigonometric Function1'
  real32_T TrigonometricFunction5_o;   // '<S93>/Trigonometric Function5'
  real32_T TrigonometricFunction4_n;   // '<S93>/Trigonometric Function4'
  real32_T TrigonometricFunction2_l;   // '<S93>/Trigonometric Function2'
  real32_T TrigonometricFunction4_km;  // '<S66>/Trigonometric Function4'
  real32_T TrigonometricFunction5_f;   // '<S66>/Trigonometric Function5'
  real32_T TrigonometricFunction1_m;   // '<S66>/Trigonometric Function1'
  real32_T TrigonometricFunction2_ag;  // '<S66>/Trigonometric Function2'
  real32_T Sum2;                       // '<S11>/Sum2'
  real32_T Sum1;                       // '<S11>/Sum1'
} ConstBlockIO_QS_InnerRateLoop_T;

// Constant parameters (default storage)
typedef struct {
  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S24>/1-D Lookup Table2'
  //    '<S50>/1-D Lookup Table2'

  real32_T pooled6[5];

  // Pooled Parameter (Expression: bpV)
  //  Referenced by:
  //    '<S18>/1-D Lookup Table'
  //    '<S18>/1-D Lookup Table1'
  //    '<S19>/1-D Lookup Table'
  //    '<S19>/1-D Lookup Table1'
  //    '<S20>/1-D Lookup Table'
  //    '<S20>/1-D Lookup Table1'
  //    '<S21>/1-D Lookup Table'
  //    '<S21>/1-D Lookup Table1'
  //    '<S58>/1-D Lookup Table2'
  //    '<S59>/1-D Lookup Table2'
  //    '<S22>/1-D Lookup Table2'
  //    '<S23>/1-D Lookup Table2'
  //    '<S24>/1-D Lookup Table2'
  //    '<S32>/1-D Lookup Table2'
  //    '<S33>/1-D Lookup Table2'
  //    '<S38>/1-D Lookup Table2'
  //    '<S39>/1-D Lookup Table2'
  //    '<S40>/1-D Lookup Table2'
  //    '<S49>/1-D Lookup Table2'
  //    '<S50>/1-D Lookup Table2'
  //    '<S51>/1-D Lookup Table2'
  //    '<S68>/1-D Lookup Table'
  //    '<S68>/1-D Lookup Table1'
  //    '<S69>/1-D Lookup Table'
  //    '<S69>/1-D Lookup Table1'
  //    '<S30>/1-D Lookup Table2'
  //    '<S31>/1-D Lookup Table2'
  //    '<S37>/1-D Lookup Table2'
  //    '<S46>/1-D Lookup Table2'
  //    '<S47>/1-D Lookup Table2'
  //    '<S73>/1-D Lookup Table2'
  //    '<S74>/1-D Lookup Table2'
  //    '<S77>/1-D Lookup Table2'
  //    '<S78>/1-D Lookup Table2'
  //    '<S81>/1-D Lookup Table2'
  //    '<S82>/1-D Lookup Table2'
  //    '<S84>/1-D Lookup Table2'
  //    '<S85>/1-D Lookup Table2'
  //    '<S87>/1-D Lookup Table2'
  //    '<S88>/1-D Lookup Table2'

  real32_T pooled7[5];

  // Computed Parameter: uDLookupTable2_tableData
  //  Referenced by: '<S33>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData[5];

  // Computed Parameter: uDLookupTable2_tableData_e
  //  Referenced by: '<S40>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_e[5];

  // Computed Parameter: uDLookupTable2_tableData_o
  //  Referenced by: '<S74>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_o[5];

  // Computed Parameter: uDLookupTable2_tableData_f
  //  Referenced by: '<S78>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_f[5];

  // Computed Parameter: uDLookupTable2_tableData_ej
  //  Referenced by: '<S81>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_ej[5];

  // Pooled Parameter (Expression: KlatlonI)
  //  Referenced by:
  //    '<S85>/1-D Lookup Table2'
  //    '<S88>/1-D Lookup Table2'

  real32_T pooled12[5];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S59>/Constant'
  //    '<S59>/1-D Lookup Table2'

  real32_T pooled16[36];

  // Computed Parameter: uDLookupTable2_tableData_g
  //  Referenced by: '<S59>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_g[180];

  // Pooled Parameter (Expression: [1:16])
  //  Referenced by:
  //    '<S58>/Constant'
  //    '<S58>/1-D Lookup Table2'

  real32_T pooled17[16];

  // Computed Parameter: uDLookupTable2_tableData_b
  //  Referenced by: '<S58>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_b[80];

  // Pooled Parameter (Expression: Klatlon)
  //  Referenced by:
  //    '<S84>/1-D Lookup Table2'
  //    '<S87>/1-D Lookup Table2'

  real32_T pooled19[5];

  // Computed Parameter: uDLookupTable2_tableData_k
  //  Referenced by: '<S82>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_k[5];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S11>/1-D Lookup Table'
  //    '<S11>/1-D Lookup Table2'
  //    '<S11>/1-D Lookup Table3'

  real32_T pooled25[38];

  // Expression: VYdata'
  //  Referenced by: '<S11>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData[38];

  // Computed Parameter: uDLookupTable2_tableData_j
  //  Referenced by: '<S37>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_j[5];

  // Computed Parameter: uDLookupTable2_tableData_ok
  //  Referenced by: '<S32>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_ok[5];

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S19>/1-D Lookup Table'

  real32_T uDLookupTable_tableData[5];

  // Computed Parameter: uDLookupTable1_tableData_g
  //  Referenced by: '<S19>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData_g[5];

  // Computed Parameter: uDLookupTable2_tableData_a
  //  Referenced by: '<S23>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_a[5];

  // Computed Parameter: uDLookupTable2_tableData_fu
  //  Referenced by: '<S22>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_fu[5];

  // Computed Parameter: uDLookupTable_tableData_l
  //  Referenced by: '<S18>/1-D Lookup Table'

  real32_T uDLookupTable_tableData_l[5];

  // Computed Parameter: uDLookupTable1_tableData_n
  //  Referenced by: '<S18>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData_n[5];

  // Computed Parameter: uDLookupTable2_tableData_ex
  //  Referenced by: '<S39>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_ex[5];

  // Computed Parameter: uDLookupTable2_tableData_c
  //  Referenced by: '<S38>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_c[5];

  // Computed Parameter: uDLookupTable_tableData_m
  //  Referenced by: '<S20>/1-D Lookup Table'

  real32_T uDLookupTable_tableData_m[5];

  // Computed Parameter: uDLookupTable1_tableData_d
  //  Referenced by: '<S20>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData_d[5];

  // Computed Parameter: uDLookupTable2_tableData_au
  //  Referenced by: '<S49>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_au[5];

  // Computed Parameter: uDLookupTable2_tableData_c0
  //  Referenced by: '<S51>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_c0[5];

  // Computed Parameter: uDLookupTable_tableData_h
  //  Referenced by: '<S21>/1-D Lookup Table'

  real32_T uDLookupTable_tableData_h[5];

  // Computed Parameter: uDLookupTable1_tableData_f
  //  Referenced by: '<S21>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData_f[5];

  // Computed Parameter: uDLookupTable2_tableData_kg
  //  Referenced by: '<S77>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_kg[5];

  // Computed Parameter: uDLookupTable_tableData_d
  //  Referenced by: '<S69>/1-D Lookup Table'

  real32_T uDLookupTable_tableData_d[5];

  // Computed Parameter: uDLookupTable1_tableData_m
  //  Referenced by: '<S69>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData_m[5];

  // Computed Parameter: uDLookupTable2_tableData_or
  //  Referenced by: '<S46>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_or[5];

  // Computed Parameter: uDLookupTable2_tableData_gp
  //  Referenced by: '<S47>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_gp[5];

  // Computed Parameter: uDLookupTable2_tableData_n
  //  Referenced by: '<S73>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_n[5];

  // Computed Parameter: uDLookupTable_tableData_hs
  //  Referenced by: '<S68>/1-D Lookup Table'

  real32_T uDLookupTable_tableData_hs[5];

  // Computed Parameter: uDLookupTable1_tableData_p
  //  Referenced by: '<S68>/1-D Lookup Table1'

  real32_T uDLookupTable1_tableData_p[5];

  // Computed Parameter: uDLookupTable2_tableData_ob
  //  Referenced by: '<S30>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_ob[5];

  // Computed Parameter: uDLookupTable2_tableData_l
  //  Referenced by: '<S31>/1-D Lookup Table2'

  real32_T uDLookupTable2_tableData_l[5];
} ConstParam_QS_InnerRateLoop_T;

// External inputs (root inport signals with default storage)
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
  real32_T Baro_Alt_m;                 // '<Root>/Baro_Alt_m'
  real32_T Ax_mpss;                    // '<Root>/Ax_mpss'
  real32_T Ay_mpss;                    // '<Root>/Ay_mpss'
  real32_T Az_mpss;                    // '<Root>/Az_mpss'
} ExternalInputs_QS_InnerRateLo_T;

// External outputs (root outports fed by signals with default storage)
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
  boolean_T ScoreDisplay;              // '<Root>/ScoreDisplay'
  real32_T vehheadingcmd;              // '<Root>/vehheadingcmd'
  boolean_T ScoreOn;                   // '<Root>/ScoreOn'
  real32_T CF_Alt;                     // '<Root>/CF_Alt'
  real32_T CF_Vz;                      // '<Root>/CF_Vz'
} ExternalOutputs_QS_InnerRateL_T;

// Real-time Model Data Structure
struct tag_RTM_QS_InnerRateLoop_T {
  const char_T * volatile errorStatus;
};

extern const ConstBlockIO_QS_InnerRateLoop_T QS_InnerRateLoop_ConstB;// constant block i/o 

// Constant parameters (default storage)
extern const ConstParam_QS_InnerRateLoop_T QS_InnerRateLoop_ConstP;

// Class declaration for model QS_InnerRateLoop
class untitledModelClass {
  // public data and function members
 public:
  // External inputs
  ExternalInputs_QS_InnerRateLo_T QS_InnerRateLoop_U;

  // External outputs
  ExternalOutputs_QS_InnerRateL_T QS_InnerRateLoop_Y;

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
//  '<S1>'   : 'QS_InnerRateLoop/Altitude Complimentary Filter1'
//  '<S2>'   : 'QS_InnerRateLoop/Attitude Control Loop1'
//  '<S3>'   : 'QS_InnerRateLoop/Determine Heading at Start of Manuever  All trajectories relative to this heading'
//  '<S4>'   : 'QS_InnerRateLoop/Dynamic Inverse1'
//  '<S5>'   : 'QS_InnerRateLoop/Enabled Subsystem Grab and Freeze Value Upon Engagement'
//  '<S6>'   : 'QS_InnerRateLoop/LocalVertical 2 Inertial'
//  '<S7>'   : 'QS_InnerRateLoop/LocalVertical2Body '
//  '<S8>'   : 'QS_InnerRateLoop/NED to Local Vertical'
//  '<S9>'   : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1'
//  '<S10>'  : 'QS_InnerRateLoop/Subsystem'
//  '<S11>'  : 'QS_InnerRateLoop/Subsystem1'
//  '<S12>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command1'
//  '<S13>'  : 'QS_InnerRateLoop/Altitude Complimentary Filter1/2 rad//s Filter'
//  '<S14>'  : 'QS_InnerRateLoop/Altitude Complimentary Filter1/Subsystem'
//  '<S15>'  : 'QS_InnerRateLoop/Altitude Complimentary Filter1/Subsystem1'
//  '<S16>'  : 'QS_InnerRateLoop/Altitude Complimentary Filter1/Subsystem2'
//  '<S17>'  : 'QS_InnerRateLoop/Altitude Complimentary Filter1/Subsystem3'
//  '<S18>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem'
//  '<S19>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem1'
//  '<S20>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2'
//  '<S21>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3'
//  '<S22>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/Kp Gain Schedule'
//  '<S23>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/Kphi Gain Schedule'
//  '<S24>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/KphiI Gain Schedule'
//  '<S25>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/Psuedo Derivative 100*s//(s+100)'
//  '<S26>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/Psuedo Derivative 2 100*s//(s+100)'
//  '<S27>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/Subsystem'
//  '<S28>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/integrator no windup'
//  '<S29>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/lead-lag1'
//  '<S30>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/Subsystem/k1 Gain Schedule'
//  '<S31>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem/Subsystem/k2 Gain Schedule1'
//  '<S32>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem1/KvZ Gain Schedule'
//  '<S33>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem1/KvZ Gain Schedule1'
//  '<S34>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem1/Subsystem'
//  '<S35>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem1/integrator no windup'
//  '<S36>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem1/lead-lag1'
//  '<S37>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem1/Subsystem/wcmd Gain Schedule'
//  '<S38>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/Kq Gain Schedule'
//  '<S39>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/Ktht Gain Schedule'
//  '<S40>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/KthtI Gain Schedule'
//  '<S41>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/Psuedo Derivative 100*s//(s+100)'
//  '<S42>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/Psuedo Derivative 2 100*s//(s+100)'
//  '<S43>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/Subsystem'
//  '<S44>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/integrator no windup'
//  '<S45>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/lead-lag1'
//  '<S46>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/Subsystem/k1 Gain Schedule'
//  '<S47>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem2/Subsystem/k2 Gain Schedule1'
//  '<S48>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/-pi <= psi <= pi4'
//  '<S49>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/Kpsi Gain Schedule'
//  '<S50>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/KpsiI Gain Schedule'
//  '<S51>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/Kr Gain Schedule'
//  '<S52>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/Psuedo Derivative 100*s//(s+100)'
//  '<S53>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/Psuedo Derivative 100*s//(s+100)1'
//  '<S54>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/counter'
//  '<S55>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/integrator no windup'
//  '<S56>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/lead-lag1'
//  '<S57>'  : 'QS_InnerRateLoop/Attitude Control Loop1/Subsystem3/-pi <= psi <= pi4/0 <= psi <= 2*pi'
//  '<S58>'  : 'QS_InnerRateLoop/Dynamic Inverse1/(Cinv*Binv)^-1 Gain Schedule'
//  '<S59>'  : 'QS_InnerRateLoop/Dynamic Inverse1/Cinv*Ainv Gain Schedule'
//  '<S60>'  : 'QS_InnerRateLoop/Dynamic Inverse1/lead-lag'
//  '<S61>'  : 'QS_InnerRateLoop/Dynamic Inverse1/lead-lag1'
//  '<S62>'  : 'QS_InnerRateLoop/Dynamic Inverse1/lead-lag2'
//  '<S63>'  : 'QS_InnerRateLoop/Dynamic Inverse1/lead-lag3'
//  '<S64>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Command Transforms '
//  '<S65>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control'
//  '<S66>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Command Transforms /LocalVertical 2 Inertial'
//  '<S67>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Inertial2LocalVertical'
//  '<S68>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lat Velocity Controller1'
//  '<S69>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lon Velocity Controller1'
//  '<S70>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller Down1'
//  '<S71>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller East1'
//  '<S72>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller North1'
//  '<S73>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lat Velocity Controller1/Kv Gain Schedule'
//  '<S74>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lat Velocity Controller1/KvI Gain Schedule'
//  '<S75>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lat Velocity Controller1/integrator no windup'
//  '<S76>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lat Velocity Controller1/lead-lag1'
//  '<S77>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lon Velocity Controller1/Ku Gain Schedule'
//  '<S78>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lon Velocity Controller1/KuI Gain Schedule'
//  '<S79>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lon Velocity Controller1/integrator no windup'
//  '<S80>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/Lon Velocity Controller1/lead-lag1'
//  '<S81>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller Down1/Kdown Gain Schedule'
//  '<S82>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller Down1/Kldown Gain Schedule'
//  '<S83>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller Down1/integrator no windup'
//  '<S84>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller East1/Klatlon Gain Schedule'
//  '<S85>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller East1/KlatlonI Gain Schedule'
//  '<S86>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller East1/integrator no windup'
//  '<S87>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller North1/Klatlon Gain Schedule'
//  '<S88>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller North1/KlatlonI Gain Schedule'
//  '<S89>'  : 'QS_InnerRateLoop/Outer Loop//Trajectory Control1/Position and Velocity Control/PI controller North1/integrator no windup'
//  '<S90>'  : 'QS_InnerRateLoop/Subsystem/Determine if Traj Switch Has  Been Cycled since last trajectory'
//  '<S91>'  : 'QS_InnerRateLoop/Subsystem/Determine if still in position when switch was flipped to ON'
//  '<S92>'  : 'QS_InnerRateLoop/Subsystem/Enabled Subsystem1'
//  '<S93>'  : 'QS_InnerRateLoop/Subsystem1/NED to Local Vertical'
//  '<S94>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command1/Enabled Subsystem1'
//  '<S95>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command1/Generic first order collective command model'
//  '<S96>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command1/TFSWIT Transient Free Switch'
//  '<S97>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command1/TFSWIT Transient Free Switch1'
//  '<S98>'  : 'QS_InnerRateLoop/Switch Between Pilot Command and Trajectory Command1/TFSWIT Transient Free Switch2'

#endif                                 // RTW_HEADER_QS_InnerRateLoop_h_

//
// File trailer for generated code.
//
// [EOF]
//
