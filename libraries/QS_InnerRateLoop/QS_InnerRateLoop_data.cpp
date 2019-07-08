//
// File: QS_InnerRateLoop_data.cpp
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
#include "QS_InnerRateLoop.h"
#include "QS_InnerRateLoop_private.h"

// Invariant block signals (auto storage)
const ConstBlockIO_QS_InnerRateLoop_T QS_InnerRateLoop_ConstB = {
  1.0F
  ,                                    // '<S34>/Trigonometric Function1'
  0.0F
  ,                                    // '<S34>/Trigonometric Function5'
  0.0F
  ,                                    // '<S34>/Trigonometric Function4'
  0.0F
  ,                                    // '<S39>/Constant'
  1.0F
  ,                                    // '<S6>/Trigonometric Function2'
  0.0F
  ,                                    // '<S6>/Trigonometric Function5'
  0.0F
  ,                                    // '<S6>/Trigonometric Function4'
  1.0F
  ,                                    // '<S6>/Trigonometric Function1'
  0.0F
  ,                                    // '<S38>/Constant'
  1.0F
  ,                                    // '<S34>/Trigonometric Function2'
  0.0F
  ,                                    // '<S37>/Constant'
  1.0F
  ,                                    // '<S49>/Trigonometric Function1'
  0.0F
  ,                                    // '<S49>/Trigonometric Function5'
  0.0F
  ,                                    // '<S49>/Trigonometric Function4'
  1.0F
  ,                                    // '<S49>/Trigonometric Function2'
  0.0F
  ,                                    // '<S36>/Constant'
  0.0F
  ,                                    // '<S43>/Constant'
  0.0F
  ,                                    // '<S43>/Constant1'
  1.0F
  ,                                    // '<S5>/Trigonometric Function3'
  0.0F
  ,                                    // '<S5>/Trigonometric Function6'
  10.0F
  ,                                    // '<S54>/Sum1'
  17.5663719F
  ,                                    // '<S54>/Sum3'
  50.0F
  ,                                    // '<S54>/Sum2'
  55.0F
  ,                                    // '<S54>/Sum4'
  0.0F
  ,                                    // '<S35>/Constant'
  0.0F
  ,                                    // '<S40>/Constant'
  0.0F
  ,                                    // '<S40>/Constant1'
  0.0F
  ,                                    // '<S33>/Trigonometric Function4'
  0.0F
  ,                                    // '<S33>/Trigonometric Function5'
  1.0F
  ,                                    // '<S33>/Trigonometric Function1'
  1.0F
  ,                                    // '<S33>/Trigonometric Function2'
  0.0F
  ,                                    // '<S55>/Sum2'
  59.0F
  // '<S56>/Sum5'
};

// Constant parameters (auto storage)
const ConstParam_QS_InnerRateLoop_T QS_InnerRateLoop_ConstP = {
  // Pooled Parameter (Expression: [0 0.1 1 1 1 0.1 0])
  //  Referenced by:
  //    '<S35>/1-D Lookup Table4'
  //    '<S35>/1-D Lookup Table6'
  //    '<S36>/1-D Lookup Table1'
  //    '<S36>/1-D Lookup Table3'

  { 0.0F, 0.1F, 1.0F, 1.0F, 1.0F, 0.1F, 0.0F },

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

  { -50.0F, -30.0F, -5.0F, 0.0F, 5.0F, 30.0F, 50.0F },

  // Pooled Parameter (Expression: [0.1 0.3 .9 1.5 .9 0.3 0.1])
  //  Referenced by:
  //    '<S38>/1-D Lookup Table1'
  //    '<S39>/1-D Lookup Table1'

  { 0.1F, 0.3F, 0.9F, 1.5F, 0.9F, 0.3F, 0.1F },

  // Expression: vhdg5
  //  Referenced by: '<S9>/1-D Lookup Table3'

  { 0.0F, 6.0F, 12.0F, 18.0F, 24.0F, 30.0F, 36.0F, 42.0F, 48.0F, 54.0F, 60.0F,
    66.0F, 72.0F, 78.0F, 84.0F, 90.0F, 96.0F, 102.0F, 108.0F, 114.0F, 120.0F,
    126.0F, 132.0F, 138.0F, 144.0F, 150.0F, 156.0F, 162.0F, 168.0F, 174.0F,
    180.0F, 180.0F, 180.0F, 180.0F, 180.0F, 180.0F, 180.0F, 180.0F, 180.0F,
    180.0F, 180.0F, 180.0F, 180.0F, 180.0F, 180.0F, 180.0F, 180.0F, 180.0F,
    180.0F, 180.0F, 180.0F, 174.0F, 168.0F, 162.0F, 156.0F, 150.0F, 144.0F,
    138.0F, 132.0F, 126.0F, 120.0F, 114.0F, 108.0F, 102.0F, 96.0F, 90.0F, 84.0F,
    78.0F, 72.0F, 66.0F, 60.0F, 54.0F, 48.0F, 42.0F, 36.0F, 30.0F, 24.0F, 18.0F,
    12.0F, 6.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Pooled Parameter (Expression: bp)
  //  Referenced by:
  //    '<S9>/1-D Lookup Table'
  //    '<S9>/1-D Lookup Table1'
  //    '<S9>/1-D Lookup Table2'
  //    '<S9>/1-D Lookup Table3'

  { 0.0F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F, 1.1F, 1.2F,
    1.3F, 1.4F, 1.5F, 1.6F, 1.7F, 1.8F, 1.9F, 2.0F, 2.1F, 2.2F, 2.3F, 2.4F, 2.5F,
    2.6F, 2.7F, 2.8F, 2.9F, 3.0F, 3.1F, 3.2F, 3.3F, 3.4F, 3.5F, 3.6F, 3.7F, 3.8F,
    3.9F, 4.0F, 4.1F, 4.2F, 4.3F, 4.4F, 4.5F, 4.6F, 4.7F, 4.8F, 4.9F, 5.0F, 5.1F,
    5.2F, 5.3F, 5.4F, 5.5F, 5.6F, 5.7F, 5.8F, 5.9F, 6.0F, 6.1F, 6.2F, 6.3F, 6.4F,
    6.5F, 6.6F, 6.7F, 6.8F, 6.9F, 7.0F, 7.1F, 7.2F, 7.3F, 7.4F, 7.5F, 7.6F, 7.7F,
    7.8F, 7.9F, 8.0F, 8.1F, 8.2F, 8.3F, 8.4F, 8.5F, 8.6F, 8.7F, 8.8F, 8.9F, 9.0F,
    9.1F, 9.2F, 9.3F, 9.4F, 9.5F, 9.6F, 9.7F, 9.8F, 9.9F, 10.0F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S9>/1-D Lookup Table'
  //    '<S9>/1-D Lookup Table1'
  //    '<S9>/1-D Lookup Table2'

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Pooled Parameter (Expression: [.3 .3 1 1 1 .3 .3])
  //  Referenced by:
  //    '<S35>/1-D Lookup Table5'
  //    '<S36>/1-D Lookup Table2'

  { 0.3F, 0.3F, 1.0F, 1.0F, 1.0F, 0.3F, 0.3F },

  // Computed Parameter: CinvAinv_Gain
  //  Referenced by: '<S3>/Cinv*Ainv'

  { 0.0F, 0.0F, 1.10181344F, 0.0F, 0.0F, -0.905259F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },

  // Computed Parameter: Binv1_Gain
  //  Referenced by: '<S3>/(Binv)^-1'

  { -15.8744297F, 0.0F, 0.0F, 0.0F, 0.0F, 68.00383F, 0.0F, 0.0F, 0.0F, 0.0F,
    73.4250107F, 0.0F, 0.0F, 0.0F, 0.0F, 568.504822F }
};

//
// File trailer for generated code.
//
// [EOF]
//
