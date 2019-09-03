//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: QS_InnerRateLoop_private.h
//
// Code generated for Simulink model 'QS_InnerRateLoop'.
//
// Model version                  : 1.488
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Wed Jul 31 11:16:21 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
//    3. ROM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_QS_InnerRateLoop_private_h_
#define RTW_HEADER_QS_InnerRateLoop_private_h_
#include "rtwtypes.h"

extern uint32_T plook_u32ff_evencg(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex, real32_T *fraction);
extern real32_T intrp1d_fu32fl_pw(uint32_T bpIndex, real32_T frac, const
  real32_T table[]);
extern uint32_T plook_u32ff_evenca(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex, real32_T *fraction);
extern real32_T intrp1d_fu32fla_pw(uint32_T bpIndex, real32_T frac, const
  real32_T table[], uint32_T maxIndex);
extern uint32_T plook_u32ff_evenxg(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex, real32_T *fraction);
extern uint32_T plook_u32ff_bincg(real32_T u, const real32_T bp[], uint32_T
  maxIndex, real32_T *fraction);
extern real32_T intrp2d_fu32fl_pw(const uint32_T bpIndex[], const real32_T frac[],
  const real32_T table[], const uint32_T stride);

#endif                                // RTW_HEADER_QS_InnerRateLoop_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
