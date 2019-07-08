//
// File: QS_InnerRateLoop_private.h
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
#ifndef RTW_HEADER_QS_InnerRateLoop_private_h_
#define RTW_HEADER_QS_InnerRateLoop_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 // __RTWTYPES_H__

extern real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
extern real32_T look1_iflf_pbinlcapw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T prevIndex[], uint32_T maxIndex);

#endif                                 // RTW_HEADER_QS_InnerRateLoop_private_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
