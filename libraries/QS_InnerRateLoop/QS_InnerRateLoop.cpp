//
// File: QS_InnerRateLoop.cpp
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

real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Interpolation 1-D
  // Interpolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real32_T look1_iflf_pbinlcapw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  real32_T y;
  real32_T frac;
  uint32_T startIndex;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T found;

  // Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'on'
  // Interpolation method: 'Linear'
  // Extrapolation method: 'Clip'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'on'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    startIndex = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    startIndex = prevIndex[0U];

    // Binary Search using Previous Index
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[startIndex]) {
        iRght = startIndex - 1U;
        startIndex = (iRght + iLeft) >> 1U;
      } else if (u0 < bp0[startIndex + 1U]) {
        found = 1U;
      } else {
        iLeft = startIndex + 1U;
        startIndex = (iRght + iLeft) >> 1U;
      }
    }

    frac = (u0 - bp0[startIndex]) / (bp0[startIndex + 1U] - bp0[startIndex]);
  } else {
    startIndex = maxIndex;
    frac = 0.0F;
  }

  prevIndex[0U] = startIndex;

  // Interpolation 1-D
  // Interpolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Overflow mode: 'portable wrapping'

  if (startIndex == maxIndex) {
    y = table[startIndex];
  } else {
    y = (table[startIndex + 1U] - table[startIndex]) * frac + table[startIndex];
  }

  return y;
}

// Model step function
void untitledModelClass::step()
{
  // local block i/o variables
  real32_T rtb_Gain1_h;
  real32_T rtb_Gain1_c;
  real32_T rtb_DataTypeConversion17;
  real32_T rtb_Gain1_n;
  boolean_T rtb_LogicalOperator1_f;
  real32_T rtb_TrigonometricFunction3;
  real32_T rtb_TrigonometricFunction6;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator2;
  real_T rtb_Sum2;
  real32_T rtb_ProportionalGain;
  real32_T rtb_TrigonometricFunction3_i;
  real32_T rtb_TrigonometricFunction6_f;
  real32_T rtb_Sqrt;
  real32_T rtb_DLookupTable1;
  real32_T rtb_Saturation;
  real32_T rtb_ProportionalGain_o;
  real32_T rtb_DLookupTable1_mp;
  real32_T rtb_Saturation1;
  real32_T rtb_Saturation2;
  real32_T rtb_Product2_d;
  real32_T rtb_Gain2;
  real32_T rtb_Divide1_o;
  real32_T rtb_DLookupTable3;
  real32_T rtb_Gain1;
  real32_T rtb_TrigonometricFunction3_j;
  real32_T rtb_Divide4_f;
  real32_T rtb_TrigonometricFunction6_k;
  real32_T rtb_Divide5_k;
  real32_T rtb_DLookupTable1_j;
  real32_T rtb_Divide3_h;
  real32_T rtb_Divide9_lo;
  real32_T rtb_Divide10_f;
  real32_T rtb_DLookupTable;
  real32_T rtb_Divide2_c;
  real32_T rtb_DLookupTable2;
  real32_T rtb_Divide4_l;
  real32_T rtb_mstofts2;
  real32_T rtb_Switch1_k;
  real32_T rtb_Gain;
  real32_T rtb_DiscreteTimeIntegrator1_m;
  real32_T rtb_derivativecutofffrequency1;
  real32_T rtb_mstofts;
  real32_T rtb_DLookupTable2_o;
  real32_T rtb_Product2_n;
  real32_T rtb_Switch1_a;
  real32_T rtb_derivativecutofffrequenc_ap;
  real32_T rtb_Sum4_i;
  real32_T rtb_deg2rad2;
  real32_T rtb_derivativecutofffrequenc_nd;
  real32_T rtb_Sum2_cl;
  real32_T rtb_Gain_bw;
  real32_T rtb_Gain_fc;
  real32_T rtb_Switch_if;
  real32_T rtb_Product;
  real32_T rtb_Switch_b5;
  real32_T rtb_Product_n;
  real32_T rtb_Switch_ao;
  real32_T rtb_Product_d;
  real32_T rtb_Switch_gw;
  real32_T rtb_Gain3_a;
  real32_T rtb_TrigonometricFunction2;
  real32_T rtb_Add5;
  real32_T rtb_Add6;
  real32_T rtb_TrigonometricFunction5;
  real32_T rtb_Add7;
  real32_T rtb_TrigonometricFunction4;
  real32_T rtb_TrigonometricFunction1;
  real32_T rtb_Binv1[4];
  real32_T rtb_Product1;
  int32_T rtb_Sum_dv;
  real32_T rtb_MultiportSwitch1;
  real32_T rtb_Saturation_m;
  real32_T rtb_Product2_l4;
  real32_T rtb_Product_jq;
  real32_T rtb_Product1_p;
  real32_T rtb_Product3;
  real32_T rtb_DiscreteTimeIntegrator_ab;
  real32_T rtb_mstofts1;
  real32_T rtb_DLookupTable5;
  real32_T rtb_Product1_i;
  real32_T rtb_Switch1_kj;
  real32_T rtb_TrigonometricFunction3_c;
  real32_T rtb_TrigonometricFunction6_fg;
  real32_T rtb_Sum_m;
  real32_T rtb_MultiportSwitch2;
  real32_T rtb_DiscreteTimeIntegrator_ph;
  real32_T rtb_Switch_e;
  real32_T rtb_Add5_j;
  real32_T rtb_Add6_h;
  real32_T rtb_Add7_g;
  real32_T rtb_Sum1;
  real32_T rtb_Sum2_im;
  real32_T rtb_Sum3;
  real32_T rtb_Sum4;
  real32_T rtb_Switch_gx;
  real32_T rtb_Sum_e;
  real32_T rtb_Sum2_d;
  real32_T rtb_Sum4_k;
  real32_T rtb_Switch_p;
  real32_T rtb_Sum_as;
  real32_T rtb_Sum2_b;
  real32_T rtb_Switch_ba;
  real32_T rtb_Switch_g;
  real32_T rtb_Sum4_d;
  real32_T rtb_Sum4_px;
  real32_T rtb_Switch_d;
  real32_T rtb_Sum_ds;
  real32_T rtb_Sum2_l;
  real32_T rtb_derivativecutofffrequenc_ib;
  real32_T rtb_DLookupTable3_m;
  real32_T rtb_DLookupTable1_mh;
  real32_T rtb_derivativecutofffrequenc_m5;
  real32_T rtb_DLookupTable6;
  real32_T rtb_DLookupTable4;
  real32_T rtb_Sum2_o;
  real32_T DiscreteTimeIntegrator1;
  real32_T DiscreteTimeIntegrator;
  real32_T DiscreteTimeIntegrator1_j;
  real32_T DiscreteTimeIntegrator1_e;
  real32_T DiscreteTimeIntegrator_h;
  real32_T DiscreteTransferFcn_tmp;
  real32_T DiscreteTransferFcn1_tmp;
  real32_T DiscreteTransferFcn2_tmp;
  real32_T rtb_Gain_4[4];
  real32_T tmp[4];
  real32_T rtb_TrigonometricFunction2_0[9];
  real32_T rtb_Gain_5[4];
  int32_T i;
  int32_T rtb_Switch_m;
  real32_T rtb_Sum1_0;

  // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem Grab and Freeze Value Upon Engagement' incorporates:
  //   EnablePort: '<S4>/Enable'

  // Logic: '<Root>/Logical Operator' incorporates:
  //   Inport: '<Root>/engage'
  //   Inport: '<Root>/mixer_in_throttle'
  //   Inport: '<Root>/mixer_in_x'
  //   Inport: '<Root>/mixer_in_y'
  //   Inport: '<Root>/mixer_in_z'
  //   Inport: '<S4>/In1'

  if (!QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_B.In1[0] = QS_InnerRateLoop_U.mixer_in_throttle;
    QS_InnerRateLoop_B.In1[1] = QS_InnerRateLoop_U.mixer_in_y;
    QS_InnerRateLoop_B.In1[2] = QS_InnerRateLoop_U.mixer_in_x;
    QS_InnerRateLoop_B.In1[3] = QS_InnerRateLoop_U.mixer_in_z;
  }

  // End of Logic: '<Root>/Logical Operator'
  // End of Outputs for SubSystem: '<Root>/Enabled Subsystem Grab and Freeze Value Upon Engagement' 

  // Trigonometry: '<S34>/Trigonometric Function3' incorporates:
  //   Inport: '<Root>/psi_rad'

  rtb_TrigonometricFunction3 = (real32_T)cos(QS_InnerRateLoop_U.psi_rad);

  // Trigonometry: '<S34>/Trigonometric Function6' incorporates:
  //   Inport: '<Root>/psi_rad'

  rtb_TrigonometricFunction6 = (real32_T)sin(QS_InnerRateLoop_U.psi_rad);

  // Sum: '<S46>/Sum2' incorporates:
  //   Delay: '<S46>/Delay1'
  //   Delay: '<S46>/Delay2'
  //   Inport: '<Root>/CH8_flag'
  //   RelationalOperator: '<S46>/Relational Operator2'

  rtb_Sum2 = (real_T)(QS_InnerRateLoop_U.CH8_flag >
                      QS_InnerRateLoop_DWork.Delay1_DSTATE) +
    QS_InnerRateLoop_DWork.Delay2_DSTATE;

  // Logic: '<Root>/Logical Operator1' incorporates:
  //   Inport: '<Root>/CH8_flag'
  //   Inport: '<Root>/Trajectory Switch'

  rtb_LogicalOperator1 = (QS_InnerRateLoop_U.TrajectorySwitch &&
    (QS_InnerRateLoop_U.CH8_flag != 0.0F));

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem1' incorporates:
  //   EnablePort: '<S48>/Enable'

  // Logic: '<S8>/Logical Operator3' incorporates:
  //   Inport: '<Root>/input_col'
  //   Inport: '<Root>/input_lat'
  //   Inport: '<Root>/input_lon'
  //   Inport: '<Root>/input_ped'
  //   Inport: '<S48>/col'
  //   Inport: '<S48>/lat'
  //   Inport: '<S48>/lon'
  //   Inport: '<S48>/ped'

  if (!rtb_LogicalOperator1) {
    QS_InnerRateLoop_B.lon = QS_InnerRateLoop_U.input_lon;
    QS_InnerRateLoop_B.lat = QS_InnerRateLoop_U.input_lat;
    QS_InnerRateLoop_B.col_f = QS_InnerRateLoop_U.input_col;
    QS_InnerRateLoop_B.ped = QS_InnerRateLoop_U.input_ped;
  }

  // End of Logic: '<S8>/Logical Operator3'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem1'

  // Sum: '<S8>/Sum1' incorporates:
  //   Inport: '<Root>/input_lon'

  rtb_Sum1 = QS_InnerRateLoop_U.input_lon - QS_InnerRateLoop_B.lon;

  // Sum: '<S8>/Sum2' incorporates:
  //   Inport: '<Root>/input_lat'

  rtb_Sum2_im = QS_InnerRateLoop_U.input_lat - QS_InnerRateLoop_B.lat;

  // Sum: '<S8>/Sum3' incorporates:
  //   Inport: '<Root>/input_col'

  rtb_Sum3 = QS_InnerRateLoop_U.input_col - QS_InnerRateLoop_B.col_f;

  // Sum: '<S8>/Sum4' incorporates:
  //   Inport: '<Root>/input_ped'

  rtb_Sum4 = QS_InnerRateLoop_U.input_ped - QS_InnerRateLoop_B.ped;

  // DeadZone: '<S47>/Dead Zone2'
  if (rtb_Sum1 > 135.0F) {
    rtb_Sum1_0 = rtb_Sum1 - 135.0F;
  } else if (rtb_Sum1 >= -135.0F) {
    rtb_Sum1_0 = 0.0F;
  } else {
    rtb_Sum1_0 = rtb_Sum1 - -135.0F;
  }

  // End of DeadZone: '<S47>/Dead Zone2'

  // DeadZone: '<S47>/Dead Zone1'
  if (rtb_Sum2_im > 135.0F) {
    DiscreteTransferFcn_tmp = rtb_Sum2_im - 135.0F;
  } else if (rtb_Sum2_im >= -135.0F) {
    DiscreteTransferFcn_tmp = 0.0F;
  } else {
    DiscreteTransferFcn_tmp = rtb_Sum2_im - -135.0F;
  }

  // End of DeadZone: '<S47>/Dead Zone1'

  // DeadZone: '<S47>/Dead Zone3'
  if (rtb_Sum3 > 50.0F) {
    DiscreteTransferFcn1_tmp = rtb_Sum3 - 50.0F;
  } else if (rtb_Sum3 >= -50.0F) {
    DiscreteTransferFcn1_tmp = 0.0F;
  } else {
    DiscreteTransferFcn1_tmp = rtb_Sum3 - -50.0F;
  }

  // End of DeadZone: '<S47>/Dead Zone3'

  // DeadZone: '<S47>/Dead Zone4'
  if (rtb_Sum4 > 135.0F) {
    DiscreteTransferFcn2_tmp = rtb_Sum4 - 135.0F;
  } else if (rtb_Sum4 >= -135.0F) {
    DiscreteTransferFcn2_tmp = 0.0F;
  } else {
    DiscreteTransferFcn2_tmp = rtb_Sum4 - -135.0F;
  }

  // End of DeadZone: '<S47>/Dead Zone4'

  // Logic: '<S8>/Logical Operator2' incorporates:
  //   Abs: '<S47>/Abs'
  //   Abs: '<S47>/Abs1'
  //   Abs: '<S47>/Abs2'
  //   Abs: '<S47>/Abs3'
  //   Logic: '<S47>/Logical Operator'
  //   Logic: '<S47>/Logical Operator1'

  rtb_LogicalOperator2 = ((!(((real32_T)fabs(rtb_Sum1_0) != 0.0F) || ((real32_T)
    fabs(DiscreteTransferFcn_tmp) != 0.0F) || ((real32_T)fabs
    (DiscreteTransferFcn1_tmp) != 0.0F) || ((real32_T)fabs
    (DiscreteTransferFcn2_tmp) != 0.0F))) && rtb_LogicalOperator1);

  // Logic: '<S8>/Logical Operator1'
  rtb_LogicalOperator1_f = ((rtb_Sum2 != 0.0) && rtb_LogicalOperator2);

  // DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRese == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE =
      QS_InnerRateLoop_ConstB.Constant;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE >= 5.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE = 5.0F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE <= -5.0F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE = -5.0F;
      }
    }
  }

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE >= 5.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE = 5.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE <= -5.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE = -5.0F;
    }
  }

  // DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_IC_LOADI != 0) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_n = 0.0F;
  }

  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_h <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_h == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_n = 0.0F;
  }

  // Gain: '<S39>/Proportional Gain' incorporates:
  //   DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
  //   Inport: '<Root>/pos North (KF)'
  //   Sum: '<S39>/Sum'

  rtb_ProportionalGain = (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_n
    - QS_InnerRateLoop_U.posNorthKF) * 2.0F;

  // Trigonometry: '<S6>/Trigonometric Function3' incorporates:
  //   Inport: '<Root>/psi_rad'

  rtb_TrigonometricFunction3_i = (real32_T)cos(QS_InnerRateLoop_U.psi_rad);

  // Trigonometry: '<S6>/Trigonometric Function6' incorporates:
  //   Inport: '<Root>/psi_rad'

  rtb_TrigonometricFunction6_f = (real32_T)sin(QS_InnerRateLoop_U.psi_rad);

  // Sum: '<S6>/Add5' incorporates:
  //   Inport: '<Root>/vD_fps (KF)'
  //   Inport: '<Root>/vE_fps (KF)'
  //   Inport: '<Root>/vN_fps (KF)'
  //   Product: '<S6>/Divide'
  //   Product: '<S6>/Divide2'
  //   Product: '<S6>/Divide6'

  rtb_Add5 = (QS_InnerRateLoop_ConstB.TrigonometricFunction2 *
              rtb_TrigonometricFunction3_i * QS_InnerRateLoop_U.vN_fpsKF +
              QS_InnerRateLoop_ConstB.TrigonometricFunction2 *
              rtb_TrigonometricFunction6_f * QS_InnerRateLoop_U.vE_fpsKF) +
    -QS_InnerRateLoop_ConstB.TrigonometricFunction5_m *
    QS_InnerRateLoop_U.vD_fpsKF;

  // Sum: '<S6>/Add6' incorporates:
  //   Inport: '<Root>/vD_fps (KF)'
  //   Inport: '<Root>/vE_fps (KF)'
  //   Inport: '<Root>/vN_fps (KF)'
  //   Product: '<S6>/Divide1'
  //   Product: '<S6>/Divide11'
  //   Product: '<S6>/Divide13'
  //   Product: '<S6>/Divide15'
  //   Product: '<S6>/Divide3'
  //   Product: '<S6>/Divide7'
  //   Product: '<S6>/Divide8'
  //   Sum: '<S6>/Add1'
  //   Sum: '<S6>/Add3'

  rtb_Add6 = ((QS_InnerRateLoop_ConstB.TrigonometricFunction4_m *
               QS_InnerRateLoop_ConstB.TrigonometricFunction5_m *
               rtb_TrigonometricFunction3_i -
               QS_InnerRateLoop_ConstB.TrigonometricFunction1_o *
               rtb_TrigonometricFunction6_f) * QS_InnerRateLoop_U.vN_fpsKF +
              (QS_InnerRateLoop_ConstB.TrigonometricFunction4_m *
               QS_InnerRateLoop_ConstB.TrigonometricFunction5_m *
               rtb_TrigonometricFunction6_f +
               QS_InnerRateLoop_ConstB.TrigonometricFunction1_o *
               rtb_TrigonometricFunction3_i) * QS_InnerRateLoop_U.vE_fpsKF) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction4_m *
    QS_InnerRateLoop_ConstB.TrigonometricFunction2 * QS_InnerRateLoop_U.vD_fpsKF;

  // Sum: '<S6>/Add7' incorporates:
  //   Inport: '<Root>/vD_fps (KF)'
  //   Inport: '<Root>/vE_fps (KF)'
  //   Inport: '<Root>/vN_fps (KF)'
  //   Product: '<S6>/Divide10'
  //   Product: '<S6>/Divide12'
  //   Product: '<S6>/Divide14'
  //   Product: '<S6>/Divide16'
  //   Product: '<S6>/Divide4'
  //   Product: '<S6>/Divide5'
  //   Product: '<S6>/Divide9'
  //   Sum: '<S6>/Add2'
  //   Sum: '<S6>/Add4'

  rtb_Add7 = ((QS_InnerRateLoop_ConstB.TrigonometricFunction1_o *
               QS_InnerRateLoop_ConstB.TrigonometricFunction5_m *
               rtb_TrigonometricFunction3_i +
               QS_InnerRateLoop_ConstB.TrigonometricFunction4_m *
               rtb_TrigonometricFunction6_f) * QS_InnerRateLoop_U.vN_fpsKF +
              (QS_InnerRateLoop_ConstB.TrigonometricFunction1_o *
               QS_InnerRateLoop_ConstB.TrigonometricFunction5_m *
               rtb_TrigonometricFunction6_f -
               QS_InnerRateLoop_ConstB.TrigonometricFunction4_m *
               rtb_TrigonometricFunction3_i) * QS_InnerRateLoop_U.vE_fpsKF) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction1_o *
    QS_InnerRateLoop_ConstB.TrigonometricFunction2 * QS_InnerRateLoop_U.vD_fpsKF;

  // Sqrt: '<Root>/Sqrt' incorporates:
  //   Math: '<Root>/Math Function'
  //   Math: '<Root>/Math Function1'
  //   Math: '<Root>/Math Function2'
  //   Sum: '<Root>/Add'
  //
  //  About '<Root>/Math Function':
  //   Operator: magnitude^2
  //
  //  About '<Root>/Math Function1':
  //   Operator: magnitude^2
  //
  //  About '<Root>/Math Function2':
  //   Operator: magnitude^2

  rtb_Sqrt = (real32_T)sqrt((rtb_Add5 * rtb_Add5 + rtb_Add6 * rtb_Add6) +
    rtb_Add7 * rtb_Add7);

  // Lookup_n-D: '<S39>/1-D Lookup Table1'
  rtb_DLookupTable1 = look1_iflf_binlxpw(rtb_Sqrt, *(real32_T (*)[7])&
    QS_InnerRateLoop_ConstP.pooled11[0], *(real32_T (*)[7])&
    QS_InnerRateLoop_ConstP.pooled24[0], 6U);

  // Product: '<S39>/Product2' incorporates:
  //   DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
  //   Sum: '<S39>/Sum1'

  rtb_Sum1_0 = (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE +
                rtb_ProportionalGain) * rtb_DLookupTable1;

  // Saturate: '<S32>/Saturation'
  if (rtb_Sum1_0 > 10.0F) {
    rtb_Saturation = 10.0F;
  } else if (rtb_Sum1_0 < -10.0F) {
    rtb_Saturation = -10.0F;
  } else {
    rtb_Saturation = rtb_Sum1_0;
  }

  // End of Saturate: '<S32>/Saturation'

  // DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_e <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_e == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g =
      QS_InnerRateLoop_ConstB.Constant_o;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g >= 5.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g = 5.0F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g <= -5.0F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g = -5.0F;
      }
    }
  }

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g >= 5.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g = 5.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g <= -5.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g = -5.0F;
    }
  }

  // DiscreteIntegrator: '<S31>/Discrete-Time Integrator1'
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevRes <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevRes == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  // Gain: '<S38>/Proportional Gain' incorporates:
  //   DiscreteIntegrator: '<S31>/Discrete-Time Integrator1'
  //   Inport: '<Root>/pos East (KF)'
  //   Sum: '<S38>/Sum'

  rtb_ProportionalGain_o =
    (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTATE -
     QS_InnerRateLoop_U.posEastKF) * 2.0F;

  // Lookup_n-D: '<S38>/1-D Lookup Table1'
  rtb_DLookupTable1_mp = look1_iflf_binlxpw(rtb_Sqrt, *(real32_T (*)[7])&
    QS_InnerRateLoop_ConstP.pooled11[0], *(real32_T (*)[7])&
    QS_InnerRateLoop_ConstP.pooled24[0], 6U);

  // Product: '<S38>/Product2' incorporates:
  //   DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
  //   Sum: '<S38>/Sum1'

  rtb_Sum1_0 = (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g +
                rtb_ProportionalGain_o) * rtb_DLookupTable1_mp;

  // Saturate: '<S32>/Saturation1'
  if (rtb_Sum1_0 > 10.0F) {
    rtb_Saturation1 = 10.0F;
  } else if (rtb_Sum1_0 < -10.0F) {
    rtb_Saturation1 = -10.0F;
  } else {
    rtb_Saturation1 = rtb_Sum1_0;
  }

  // End of Saturate: '<S32>/Saturation1'

  // DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_h3 <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_h3 == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c =
      QS_InnerRateLoop_ConstB.Constant_p;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c >= 10.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c = 10.0F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c <= -10.0F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c = -10.0F;
      }
    }
  }

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c >= 10.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c = 10.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c <= -10.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c = -10.0F;
    }
  }

  // DiscreteIntegrator: '<S31>/Discrete-Time Integrator2' incorporates:
  //   Inport: '<Root>/pos Down (KF)'

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_IC_LOAD != 0) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_DSTATE =
      QS_InnerRateLoop_U.posDownKF;
  }

  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_PrevRes <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_PrevRes == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_DSTATE =
      QS_InnerRateLoop_U.posDownKF;
  }

  // Sum: '<S37>/Sum' incorporates:
  //   DiscreteIntegrator: '<S31>/Discrete-Time Integrator2'
  //   Inport: '<Root>/pos Down (KF)'

  rtb_Sum_m = QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_DSTATE -
    QS_InnerRateLoop_U.posDownKF;

  // Sum: '<S37>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S37>/Discrete-Time Integrator'

  rtb_Sum1_0 = QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c +
    rtb_Sum_m;

  // Saturate: '<S32>/Saturation2'
  if (rtb_Sum1_0 > 15.0F) {
    rtb_Saturation2 = 15.0F;
  } else if (rtb_Sum1_0 < -15.0F) {
    rtb_Saturation2 = -15.0F;
  } else {
    rtb_Saturation2 = rtb_Sum1_0;
  }

  // End of Saturate: '<S32>/Saturation2'

  // Product: '<S9>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   Sum: '<S9>/Sum21'
  //   UnitDelay: '<S9>/Unit Delay'

  rtb_Product2_d = ((real32_T)rtb_LogicalOperator1_f +
                    QS_InnerRateLoop_DWork.UnitDelay_DSTATE) * (real32_T)
    rtb_LogicalOperator1_f;

  // Gain: '<S9>/Gain2'
  rtb_Gain2 = 0.0025F * rtb_Product2_d;

  // Switch: '<S9>/Switch1' incorporates:
  //   Constant: '<S9>/Constant'
  //   Constant: '<S9>/Constant1'
  //   Sum: '<S9>/Sum'

  if (rtb_Gain2 >= 10.0F) {
    rtb_Sum1_0 = rtb_Gain2 - 10.0F;
  } else {
    rtb_Sum1_0 = 0.0F;
  }

  // End of Switch: '<S9>/Switch1'

  // Product: '<S9>/Divide1' incorporates:
  //   Inport: '<Root>/Rp'
  //   Inport: '<Root>/Rv'

  rtb_Divide1_o = rtb_Sum1_0 / QS_InnerRateLoop_U.Rv * QS_InnerRateLoop_U.Rp;

  // Lookup_n-D: '<S9>/1-D Lookup Table3'
  rtb_DLookupTable3 = look1_iflf_pbinlcapw(rtb_Divide1_o, *(real32_T (*)[101])&
    QS_InnerRateLoop_ConstP.pooled25[0], *(real32_T (*)[101])&
    QS_InnerRateLoop_ConstP.DLookupTable3_table[0],
    &QS_InnerRateLoop_DWork.m_bpIndex, 100U);

  // Gain: '<S9>/Gain1'
  rtb_Gain1 = 0.0174532924F * rtb_DLookupTable3;

  // Trigonometry: '<S49>/Trigonometric Function3'
  rtb_TrigonometricFunction3_j = (real32_T)cos(rtb_Gain1);

  // Product: '<S49>/Divide4'
  rtb_Divide4_f = QS_InnerRateLoop_ConstB.TrigonometricFunction1_b *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5_d *
    rtb_TrigonometricFunction3_j;

  // Trigonometry: '<S49>/Trigonometric Function6'
  rtb_TrigonometricFunction6_k = (real32_T)sin(rtb_Gain1);

  // Product: '<S49>/Divide5'
  rtb_Divide5_k = QS_InnerRateLoop_ConstB.TrigonometricFunction4_m2 *
    rtb_TrigonometricFunction6_k;

  // Lookup_n-D: '<S9>/1-D Lookup Table1'
  rtb_DLookupTable1_j = look1_iflf_pbinlcapw(rtb_Divide1_o, *(real32_T (*)[101])
    &QS_InnerRateLoop_ConstP.pooled25[0], *(real32_T (*)[101])&
    QS_InnerRateLoop_ConstP.pooled27[0], &QS_InnerRateLoop_DWork.m_bpIndex_k,
    100U);

  // Product: '<S9>/Divide3' incorporates:
  //   Inport: '<Root>/Rv'

  rtb_Divide3_h = rtb_DLookupTable1_j / QS_InnerRateLoop_U.Rv;

  // Product: '<S49>/Divide9'
  rtb_Divide9_lo = QS_InnerRateLoop_ConstB.TrigonometricFunction1_b *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5_d *
    rtb_TrigonometricFunction6_k;

  // Product: '<S49>/Divide10'
  rtb_Divide10_f = QS_InnerRateLoop_ConstB.TrigonometricFunction4_m2 *
    rtb_TrigonometricFunction3_j;

  // Lookup_n-D: '<S9>/1-D Lookup Table'
  rtb_DLookupTable = look1_iflf_pbinlcapw(rtb_Divide1_o, *(real32_T (*)[101])&
    QS_InnerRateLoop_ConstP.pooled25[0], *(real32_T (*)[101])&
    QS_InnerRateLoop_ConstP.pooled27[0], &QS_InnerRateLoop_DWork.m_bpIndex_p,
    100U);

  // Product: '<S9>/Divide2' incorporates:
  //   Inport: '<Root>/Rv'

  rtb_Divide2_c = rtb_DLookupTable / QS_InnerRateLoop_U.Rv;

  // Lookup_n-D: '<S9>/1-D Lookup Table2'
  rtb_DLookupTable2 = look1_iflf_pbinlcapw(rtb_Divide1_o, *(real32_T (*)[101])&
    QS_InnerRateLoop_ConstP.pooled25[0], *(real32_T (*)[101])&
    QS_InnerRateLoop_ConstP.pooled27[0], &QS_InnerRateLoop_DWork.m_bpIndex_k4,
    100U);

  // Product: '<S9>/Divide4' incorporates:
  //   Inport: '<Root>/Rv'

  rtb_Divide4_l = rtb_DLookupTable2 / QS_InnerRateLoop_U.Rv;

  // Gain: '<S31>/m//s to ft//s2' incorporates:
  //   Product: '<S49>/Divide12'
  //   Product: '<S49>/Divide14'
  //   Product: '<S49>/Divide16'
  //   Sum: '<S49>/Add2'
  //   Sum: '<S49>/Add4'
  //   Sum: '<S49>/Add7'

  rtb_mstofts2 = (((rtb_Divide4_f + rtb_Divide5_k) * rtb_Divide3_h +
                   (rtb_Divide9_lo - rtb_Divide10_f) * rtb_Divide2_c) +
                  QS_InnerRateLoop_ConstB.TrigonometricFunction1_b *
                  QS_InnerRateLoop_ConstB.TrigonometricFunction2_m *
                  rtb_Divide4_l) * 3.28084F;

  // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem1' incorporates:
  //   EnablePort: '<S57>/Enable'

  // Logic: '<S11>/Logical Operator2' incorporates:
  //   Inport: '<Root>/engage'
  //   Inport: '<Root>/input_col'
  //   Inport: '<S57>/col'

  if (!QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_B.col = QS_InnerRateLoop_U.input_col;
  }

  // End of Logic: '<S11>/Logical Operator2'
  // End of Outputs for SubSystem: '<S11>/Enabled Subsystem1'

  // Switch: '<S61>/Switch' incorporates:
  //   Gain: '<S11>/wcmd'

  if (rtb_LogicalOperator1_f) {
    // Sum: '<S32>/Sum2' incorporates:
    //   Product: '<S34>/Divide10'
    //   Product: '<S34>/Divide12'
    //   Product: '<S34>/Divide14'
    //   Product: '<S34>/Divide16'
    //   Product: '<S34>/Divide4'
    //   Product: '<S34>/Divide5'
    //   Product: '<S34>/Divide9'
    //   Sum: '<S34>/Add2'
    //   Sum: '<S34>/Add4'
    //   Sum: '<S34>/Add7'

    rtb_Sum1_0 = (((QS_InnerRateLoop_ConstB.TrigonometricFunction1 *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction5 *
                    rtb_TrigonometricFunction3 +
                    QS_InnerRateLoop_ConstB.TrigonometricFunction4 *
                    rtb_TrigonometricFunction6) * rtb_Saturation +
                   (QS_InnerRateLoop_ConstB.TrigonometricFunction1 *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction5 *
                    rtb_TrigonometricFunction6 -
                    QS_InnerRateLoop_ConstB.TrigonometricFunction4 *
                    rtb_TrigonometricFunction3) * rtb_Saturation1) +
                  QS_InnerRateLoop_ConstB.TrigonometricFunction1 *
                  QS_InnerRateLoop_ConstB.TrigonometricFunction2_d *
                  rtb_Saturation2) + rtb_mstofts2;

    // Saturate: '<S11>/Saturation2'
    if (rtb_Sum1_0 > 10.0F) {
      rtb_Switch_gx = 10.0F;
    } else if (rtb_Sum1_0 < -10.0F) {
      rtb_Switch_gx = -10.0F;
    } else {
      rtb_Switch_gx = rtb_Sum1_0;
    }

    // End of Saturate: '<S11>/Saturation2'
  } else {
    // Sum: '<S11>/Sum2' incorporates:
    //   Inport: '<Root>/input_col'

    rtb_Sum2_o = QS_InnerRateLoop_U.input_col - QS_InnerRateLoop_B.col;

    // DeadZone: '<S11>/Dead Zone'
    if (rtb_Sum2_o > 30.0F) {
      rtb_Sum1_0 = rtb_Sum2_o - 30.0F;
    } else if (rtb_Sum2_o >= -30.0F) {
      rtb_Sum1_0 = 0.0F;
    } else {
      rtb_Sum1_0 = rtb_Sum2_o - -30.0F;
    }

    // End of DeadZone: '<S11>/Dead Zone'
    rtb_Switch_gx = -0.02F * rtb_Sum1_0;
  }

  // End of Switch: '<S61>/Switch'

  // Switch: '<S61>/Switch1' incorporates:
  //   RelationalOperator: '<S61>/Relational Operator'
  //   Sum: '<S61>/Sum1'
  //   UnitDelay: '<S61>/Unit Delay'
  //   UnitDelay: '<S61>/Unit Delay1'
  //   UnitDelay: '<S61>/Unit Delay2'

  if (QS_InnerRateLoop_DWork.UnitDelay_DSTATE_mj == rtb_LogicalOperator1_f) {
    rtb_Switch1_k = QS_InnerRateLoop_DWork.UnitDelay1_DSTATE;
  } else {
    rtb_Switch1_k = QS_InnerRateLoop_DWork.UnitDelay2_DSTATE - rtb_Switch_gx;
  }

  // End of Switch: '<S61>/Switch1'

  // Saturate: '<S61>/Saturation'
  if (rtb_Switch1_k > 0.0025F) {
    rtb_Sum1_0 = 0.0025F;
  } else if (rtb_Switch1_k < -0.0025F) {
    rtb_Sum1_0 = -0.0025F;
  } else {
    rtb_Sum1_0 = rtb_Switch1_k;
  }

  // Sum: '<S61>/Sum' incorporates:
  //   Saturate: '<S61>/Saturation'

  rtb_Sum_e = rtb_Switch1_k - rtb_Sum1_0;

  // Sum: '<S61>/Sum2'
  rtb_Sum2_d = rtb_Switch_gx + rtb_Sum_e;

  // Gain: '<S19>/Gain' incorporates:
  //   Sum: '<S19>/Sum'
  //   UnitDelay: '<S19>/Unit Delay'

  rtb_Gain = (rtb_Sum2_d - QS_InnerRateLoop_DWork.UnitDelay_DSTATE_e) * 4.0F;

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_i <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k = 0.0F;
  }

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k >= 1.57068062F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k = 1.57068062F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k <= -1.57068062F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k = -1.57068062F;
    }
  }

  rtb_DiscreteTimeIntegrator1_m =
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k;

  // Gain: '<S17>/derivative cutoff frequency 1' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
  //   Sum: '<S17>/Sum1'

  rtb_derivativecutofffrequency1 =
    (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k -
     QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_m) * 100.0F;

  // DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_g <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_g == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d =
      QS_InnerRateLoop_ConstB.Constant_g;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d >= 0.261780113F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.261780113F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d <=
          -0.261780113F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d = -0.261780113F;
      }
    }
  }

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d >= 0.261780113F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.261780113F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d <= -0.261780113F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d = -0.261780113F;
    }
  }

  // Lookup_n-D: '<S36>/1-D Lookup Table2'
  rtb_DLookupTable2_o = look1_iflf_binlxpw(rtb_Sqrt, *(real32_T (*)[7])&
    QS_InnerRateLoop_ConstP.pooled11[0], *(real32_T (*)[7])&
    QS_InnerRateLoop_ConstP.pooled35[0], 6U);

  // Gain: '<S31>/m//s to ft//s' incorporates:
  //   Product: '<S49>/Divide'
  //   Product: '<S49>/Divide2'
  //   Product: '<S49>/Divide6'
  //   Sum: '<S49>/Add5'

  rtb_mstofts = ((QS_InnerRateLoop_ConstB.TrigonometricFunction2_m *
                  rtb_TrigonometricFunction3_j * rtb_Divide3_h +
                  QS_InnerRateLoop_ConstB.TrigonometricFunction2_m *
                  rtb_TrigonometricFunction6_k * rtb_Divide2_c) +
                 -QS_InnerRateLoop_ConstB.TrigonometricFunction5_d *
                 rtb_Divide4_l) * 3.28084F;

  // Gain: '<S43>/Gain1' incorporates:
  //   Gain: '<S43>/Gain'
  //   Product: '<S34>/Divide'
  //   Product: '<S34>/Divide2'
  //   Product: '<S34>/Divide6'
  //   Sum: '<S32>/Sum1'
  //   Sum: '<S34>/Add5'
  //   Sum: '<S43>/Sum'
  //   Sum: '<S43>/Sum1'
  //   UnitDelay: '<S43>/Unit Delay'
  //   UnitDelay: '<S43>/Unit Delay1'

  rtb_Gain1_h = (((((QS_InnerRateLoop_ConstB.TrigonometricFunction2_d *
                     rtb_TrigonometricFunction3 * rtb_Saturation +
                     QS_InnerRateLoop_ConstB.TrigonometricFunction2_d *
                     rtb_TrigonometricFunction6 * rtb_Saturation1) +
                    -QS_InnerRateLoop_ConstB.TrigonometricFunction5 *
                    rtb_Saturation2) + 0.0F) -
                  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_b) * 4.0F -
                 QS_InnerRateLoop_DWork.UnitDelay_DSTATE_ei) * 16.0F;

  // DiscreteIntegrator: '<S43>/Discrete-Time Integrator1'
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTEM_ != 0) {
    DiscreteTimeIntegrator1 =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a;
  } else if ((rtb_LogicalOperator1_f &&
              (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_g <= 0)) ||
             ((!rtb_LogicalOperator1_f) &&
              (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_g == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a =
      QS_InnerRateLoop_ConstB.Constant_k;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a >= 25.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a = 25.0F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a <= -25.0F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a = -25.0F;
      }
    }

    DiscreteTimeIntegrator1 =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a;
  } else {
    DiscreteTimeIntegrator1 = 0.00125F * rtb_Gain1_h +
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a;
  }

  if (DiscreteTimeIntegrator1 >= 25.0F) {
    DiscreteTimeIntegrator1 = 25.0F;
  } else {
    if (DiscreteTimeIntegrator1 <= -25.0F) {
      DiscreteTimeIntegrator1 = -25.0F;
    }
  }

  // End of DiscreteIntegrator: '<S43>/Discrete-Time Integrator1'

  // DiscreteIntegrator: '<S43>/Discrete-Time Integrator'
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_E != 0) {
    DiscreteTimeIntegrator =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go;
  } else if ((rtb_LogicalOperator1_f &&
              (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_i <= 0)) ||
             ((!rtb_LogicalOperator1_f) &&
              (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_i == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go =
      QS_InnerRateLoop_ConstB.Constant1;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go >= 50.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go = 50.0F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go <= -50.0F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go = -50.0F;
      }
    }

    DiscreteTimeIntegrator =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go;
  } else {
    DiscreteTimeIntegrator = 0.00125F * DiscreteTimeIntegrator1 +
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go;
  }

  if (DiscreteTimeIntegrator >= 50.0F) {
    DiscreteTimeIntegrator = 50.0F;
  } else {
    if (DiscreteTimeIntegrator <= -50.0F) {
      DiscreteTimeIntegrator = -50.0F;
    }
  }

  // End of DiscreteIntegrator: '<S43>/Discrete-Time Integrator'

  // Switch: '<S43>/Switch' incorporates:
  //   Constant: '<S43>/Constant2'

  if (rtb_LogicalOperator1_f) {
    rtb_Sum1_0 = DiscreteTimeIntegrator;
  } else {
    rtb_Sum1_0 = 0.0F;
  }

  // End of Switch: '<S43>/Switch'

  // Sum: '<S36>/Sum4'
  rtb_Sum4_k = rtb_mstofts + rtb_Sum1_0;

  // Product: '<S36>/Product2' incorporates:
  //   Gain: '<S36>/Gain'
  //   Sum: '<S36>/Sum'

  rtb_Product2_n = (rtb_Sum4_k - rtb_Add5) * 0.020745486F * rtb_DLookupTable2_o;

  // DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_hj <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_hj == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_h = 0.0F;
  }

  // Switch: '<S59>/Switch' incorporates:
  //   DeadZone: '<S11>/Dead Zone2'
  //   Gain: '<S11>/thetacmd'
  //   Inport: '<Root>/input_lon'

  if (rtb_LogicalOperator1_f) {
    // Lookup_n-D: '<S36>/1-D Lookup Table3'
    rtb_DLookupTable3_m = look1_iflf_binlxpw(rtb_Sqrt, *(real32_T (*)[7])&
      QS_InnerRateLoop_ConstP.pooled11[0], *(real32_T (*)[7])&
      QS_InnerRateLoop_ConstP.pooled10[0], 6U);

    // Gain: '<S45>/derivative cutoff frequency 1' incorporates:
    //   DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
    //   Sum: '<S45>/Sum1'

    rtb_derivativecutofffrequenc_ib = (rtb_Sum4_k -
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_h) * 10.0F;

    // Lookup_n-D: '<S36>/1-D Lookup Table1'
    rtb_DLookupTable1_mh = look1_iflf_binlxpw(rtb_Sqrt, *(real32_T (*)[7])&
      QS_InnerRateLoop_ConstP.pooled11[0], *(real32_T (*)[7])&
      QS_InnerRateLoop_ConstP.pooled10[0], 6U);

    // Gain: '<S36>/Gain5' incorporates:
    //   DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
    //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
    //   Gain: '<S36>/Gain1'
    //   Gain: '<S36>/Gain4'
    //   Gain: '<S44>/derivative cutoff frequency 1'
    //   Product: '<S36>/Product'
    //   Product: '<S36>/Product1'
    //   Sum: '<S36>/Sum1'
    //   Sum: '<S36>/Sum2'
    //   Sum: '<S36>/Sum3'
    //   Sum: '<S44>/Sum1'

    rtb_Sum1_0 = -(((rtb_derivativecutofffrequenc_ib - (rtb_Add5 -
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_i) * 15.0F) *
                    0.0829289779F * rtb_DLookupTable1_mh +
                    (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d +
                     rtb_Product2_n)) + 0.031F * rtb_derivativecutofffrequenc_ib
                   * rtb_DLookupTable3_m);

    // Saturate: '<S11>/Saturation'
    if (rtb_Sum1_0 > 0.523560226F) {
      rtb_Switch_p = 0.523560226F;
    } else if (rtb_Sum1_0 < -0.523560226F) {
      rtb_Switch_p = -0.523560226F;
    } else {
      rtb_Switch_p = rtb_Sum1_0;
    }

    // End of Saturate: '<S11>/Saturation'
  } else {
    if (QS_InnerRateLoop_U.input_lon > 135.0F) {
      // DeadZone: '<S11>/Dead Zone2' incorporates:
      //   Inport: '<Root>/input_lon'

      rtb_Sum1_0 = QS_InnerRateLoop_U.input_lon - 135.0F;
    } else if (QS_InnerRateLoop_U.input_lon >= -135.0F) {
      // DeadZone: '<S11>/Dead Zone2'
      rtb_Sum1_0 = 0.0F;
    } else {
      // DeadZone: '<S11>/Dead Zone2' incorporates:
      //   Inport: '<Root>/input_lon'

      rtb_Sum1_0 = QS_InnerRateLoop_U.input_lon - -135.0F;
    }

    rtb_Switch_p = 0.000116F * rtb_Sum1_0;
  }

  // End of Switch: '<S59>/Switch'

  // Switch: '<S59>/Switch1' incorporates:
  //   RelationalOperator: '<S59>/Relational Operator'
  //   Sum: '<S59>/Sum1'
  //   UnitDelay: '<S59>/Unit Delay'
  //   UnitDelay: '<S59>/Unit Delay1'
  //   UnitDelay: '<S59>/Unit Delay2'

  if (QS_InnerRateLoop_DWork.UnitDelay_DSTATE_ap == rtb_LogicalOperator1_f) {
    rtb_Switch1_a = QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_m;
  } else {
    rtb_Switch1_a = QS_InnerRateLoop_DWork.UnitDelay2_DSTATE_k - rtb_Switch_p;
  }

  // End of Switch: '<S59>/Switch1'

  // Saturate: '<S59>/Saturation'
  if (rtb_Switch1_a > 0.0025F) {
    rtb_Sum1_0 = 0.0025F;
  } else if (rtb_Switch1_a < -0.0025F) {
    rtb_Sum1_0 = -0.0025F;
  } else {
    rtb_Sum1_0 = rtb_Switch1_a;
  }

  // Sum: '<S59>/Sum' incorporates:
  //   Saturate: '<S59>/Saturation'

  rtb_Sum_as = rtb_Switch1_a - rtb_Sum1_0;

  // Sum: '<S59>/Sum2'
  rtb_Sum2_b = rtb_Switch_p + rtb_Sum_as;

  // Gain: '<S20>/Gain1' incorporates:
  //   Gain: '<S20>/Gain'
  //   Sum: '<S20>/Sum'
  //   Sum: '<S20>/Sum1'
  //   UnitDelay: '<S20>/Unit Delay'
  //   UnitDelay: '<S20>/Unit Delay1'

  rtb_Gain1_c = ((rtb_Sum2_b - QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_h) *
                 8.0F - QS_InnerRateLoop_DWork.UnitDelay_DSTATE_i) * 32.0F;

  // DiscreteIntegrator: '<S20>/Discrete-Time Integrator1' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTE_n != 0) {
    DiscreteTimeIntegrator1_j =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l;
  } else if (QS_InnerRateLoop_U.engage &&
             (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_n <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l = 0.0F;
    DiscreteTimeIntegrator1_j =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l;
  } else {
    DiscreteTimeIntegrator1_j = 0.00125F * rtb_Gain1_c +
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l;
  }

  if (DiscreteTimeIntegrator1_j >= 3.14136124F) {
    DiscreteTimeIntegrator1_j = 3.14136124F;
  } else {
    if (DiscreteTimeIntegrator1_j <= -3.14136124F) {
      DiscreteTimeIntegrator1_j = -3.14136124F;
    }
  }

  // End of DiscreteIntegrator: '<S20>/Discrete-Time Integrator1'

  // DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_c != 0) {
    // Outport: '<Root>/theta_cmd'
    QS_InnerRateLoop_Y.theta_cmd =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba;
  } else if (QS_InnerRateLoop_U.engage &&
             (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_l <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba = 0.0F;

    // Outport: '<Root>/theta_cmd'
    QS_InnerRateLoop_Y.theta_cmd =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba;
  } else {
    // Outport: '<Root>/theta_cmd'
    QS_InnerRateLoop_Y.theta_cmd = 0.00125F * DiscreteTimeIntegrator1_j +
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba;
  }

  if (QS_InnerRateLoop_Y.theta_cmd >= 1.57068062F) {
    // Outport: '<Root>/theta_cmd'
    QS_InnerRateLoop_Y.theta_cmd = 1.57068062F;
  } else {
    if (QS_InnerRateLoop_Y.theta_cmd <= -1.57068062F) {
      // Outport: '<Root>/theta_cmd'
      QS_InnerRateLoop_Y.theta_cmd = -1.57068062F;
    }
  }

  // End of DiscreteIntegrator: '<S20>/Discrete-Time Integrator'

  // Gain: '<S21>/derivative cutoff frequency 1' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
  //   Sum: '<S21>/Sum1'

  rtb_derivativecutofffrequenc_ap = (QS_InnerRateLoop_Y.theta_cmd -
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_k) * 100.0F;

  // Outputs for Enabled SubSystem: '<Root>/Determine Heading at Start of Manuever  All trajectories relative to this heading' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Logic: '<Root>/Logical Operator2'
  if (!rtb_LogicalOperator1_f) {
    // Gain: '<S2>/Gain' incorporates:
    //   Inport: '<Root>/psi_rad'

    QS_InnerRateLoop_B.Gain = 57.2957802F * QS_InnerRateLoop_U.psi_rad;
  }

  // End of Logic: '<Root>/Logical Operator2'
  // End of Outputs for SubSystem: '<Root>/Determine Heading at Start of Manuever  All trajectories relative to this heading' 

  // Switch: '<S9>/Switch'
  if (rtb_LogicalOperator1_f) {
    rtb_Sum1_0 = rtb_DLookupTable3;
  } else {
    rtb_Sum1_0 = 0.0F;
  }

  // End of Switch: '<S9>/Switch'

  // Sum: '<Root>/Sum4'
  rtb_Sum4_i = rtb_Sum1_0 + QS_InnerRateLoop_B.Gain;

  // Gain: '<S31>/deg2rad 2'
  rtb_deg2rad2 = 0.0174532924F * rtb_Sum4_i;

  // DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
  //   UnitDelay: '<S11>/Unit Delay'

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_IC_LOA_f != 0) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_a =
      QS_InnerRateLoop_DWork.UnitDelay_DSTATE_l;
  }

  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_b <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_b == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_a =
      QS_InnerRateLoop_DWork.UnitDelay_DSTATE_l;
  }

  // Switch: '<S11>/Switch' incorporates:
  //   DiscreteIntegrator: '<S11>/Discrete-Time Integrator'

  if (rtb_LogicalOperator1_f) {
    rtb_Switch_e = rtb_deg2rad2;
  } else {
    rtb_Switch_e = QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_a;
  }

  // End of Switch: '<S11>/Switch'

  // Gain: '<S27>/derivative cutoff frequency 1' incorporates:
  //   DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
  //   Sum: '<S27>/Sum1'

  rtb_derivativecutofffrequenc_nd = (rtb_Switch_e -
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_mn) * 100.0F;

  // DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_o <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_h4 = 0.0F;
  }

  // DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_p <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_iz = 0.0F;
  }

  // Sum: '<S13>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator'

  rtb_Sum2_cl = QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_iz -
    rtb_Add7;

  // DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_bj <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_gi = 0.0F;
  }

  // Gain: '<S12>/Gain' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
  //   Inport: '<Root>/phi_rad'
  //   Sum: '<S12>/Sum'

  rtb_Gain_bw = (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k -
                 QS_InnerRateLoop_U.phi_rad) * 474.69104F;

  // DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_c <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ia = 0.0F;
  }

  // Gain: '<S14>/Gain' incorporates:
  //   Inport: '<Root>/theta_rad'
  //   Sum: '<S14>/Sum'

  rtb_Gain_fc = (QS_InnerRateLoop_Y.theta_cmd - QS_InnerRateLoop_U.theta_rad) *
    460.130463F;

  // DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_m <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_kt = 0.0F;
  }

  // Switch: '<S28>/Switch' incorporates:
  //   Constant: '<S28>/Constant1'
  //   Constant: '<S28>/Constant2'
  //   Gain: '<S28>/Gain1'
  //   Switch: '<S28>/Switch1'

  if (rtb_Switch_e >= 0.0F) {
    rtb_Switch_if = rtb_Switch_e;
    rtb_Switch_m = 1;
  } else {
    rtb_Switch_if = -rtb_Switch_e;
    rtb_Switch_m = -1;
  }

  // End of Switch: '<S28>/Switch'

  // Product: '<S28>/Product' incorporates:
  //   Constant: '<S28>/Constant'
  //   Gain: '<S28>/Gain'
  //   Product: '<S28>/Divide'
  //   Rounding: '<S28>/Rounding Function'
  //   Sum: '<S28>/Subtract'

  rtb_Product = (rtb_Switch_if - (real32_T)floor(rtb_Switch_if * 0.159154937F) *
                 6.28318548F) * (real32_T)rtb_Switch_m;

  // Switch: '<S23>/Switch' incorporates:
  //   Abs: '<S23>/Abs'

  if ((real32_T)fabs(rtb_Product) > 3.14159274F) {
    // Switch: '<S23>/Switch1' incorporates:
    //   Constant: '<S23>/Constant1'
    //   Constant: '<S23>/Constant2'
    //   Sum: '<S23>/Add'
    //   Sum: '<S23>/Subtract'

    if (rtb_Product >= 0.0F) {
      rtb_Switch_ba = rtb_Product - 6.28318548F;
    } else {
      rtb_Switch_ba = 6.28318548F + rtb_Product;
    }

    // End of Switch: '<S23>/Switch1'
  } else {
    rtb_Switch_ba = rtb_Product;
  }

  // End of Switch: '<S23>/Switch'

  // Switch: '<S29>/Switch' incorporates:
  //   Constant: '<S29>/Constant1'
  //   Constant: '<S29>/Constant2'
  //   Gain: '<S29>/Gain1'
  //   Inport: '<Root>/psi_rad'
  //   Switch: '<S29>/Switch1'

  if (QS_InnerRateLoop_U.psi_rad >= 0.0F) {
    rtb_Switch_b5 = QS_InnerRateLoop_U.psi_rad;
    rtb_Switch_m = 1;
  } else {
    rtb_Switch_b5 = -QS_InnerRateLoop_U.psi_rad;
    rtb_Switch_m = -1;
  }

  // End of Switch: '<S29>/Switch'

  // Product: '<S29>/Product' incorporates:
  //   Constant: '<S29>/Constant'
  //   Gain: '<S29>/Gain'
  //   Product: '<S29>/Divide'
  //   Rounding: '<S29>/Rounding Function'
  //   Sum: '<S29>/Subtract'

  rtb_Product_n = (rtb_Switch_b5 - (real32_T)floor(rtb_Switch_b5 * 0.159154937F)
                   * 6.28318548F) * (real32_T)rtb_Switch_m;

  // Switch: '<S24>/Switch' incorporates:
  //   Abs: '<S24>/Abs'

  if ((real32_T)fabs(rtb_Product_n) > 3.14159274F) {
    // Switch: '<S24>/Switch1' incorporates:
    //   Constant: '<S24>/Constant1'
    //   Constant: '<S24>/Constant2'
    //   Sum: '<S24>/Add'
    //   Sum: '<S24>/Subtract'

    if (rtb_Product_n >= 0.0F) {
      rtb_Switch_g = rtb_Product_n - 6.28318548F;
    } else {
      rtb_Switch_g = 6.28318548F + rtb_Product_n;
    }

    // End of Switch: '<S24>/Switch1'
  } else {
    rtb_Switch_g = rtb_Product_n;
  }

  // End of Switch: '<S24>/Switch'

  // Sum: '<S15>/Sum4'
  rtb_Sum4_d = rtb_Switch_ba - rtb_Switch_g;

  // Switch: '<S30>/Switch' incorporates:
  //   Constant: '<S30>/Constant1'
  //   Constant: '<S30>/Constant2'
  //   Gain: '<S30>/Gain1'
  //   Switch: '<S30>/Switch1'

  if (rtb_Sum4_d >= 0.0F) {
    rtb_Switch_ao = rtb_Sum4_d;
    rtb_Switch_m = 1;
  } else {
    rtb_Switch_ao = -rtb_Sum4_d;
    rtb_Switch_m = -1;
  }

  // End of Switch: '<S30>/Switch'

  // Product: '<S30>/Product' incorporates:
  //   Constant: '<S30>/Constant'
  //   Gain: '<S30>/Gain'
  //   Product: '<S30>/Divide'
  //   Rounding: '<S30>/Rounding Function'
  //   Sum: '<S30>/Subtract'

  rtb_Product_d = (rtb_Switch_ao - (real32_T)floor(rtb_Switch_ao * 0.159154937F)
                   * 6.28318548F) * (real32_T)rtb_Switch_m;

  // Switch: '<S25>/Switch' incorporates:
  //   Abs: '<S25>/Abs'

  if ((real32_T)fabs(rtb_Product_d) > 3.14159274F) {
    // Switch: '<S25>/Switch1' incorporates:
    //   Constant: '<S25>/Constant1'
    //   Constant: '<S25>/Constant2'
    //   Sum: '<S25>/Add'
    //   Sum: '<S25>/Subtract'

    if (rtb_Product_d >= 0.0F) {
      rtb_Switch_gw = rtb_Product_d - 6.28318548F;
    } else {
      rtb_Switch_gw = 6.28318548F + rtb_Product_d;
    }

    // End of Switch: '<S25>/Switch1'
  } else {
    rtb_Switch_gw = rtb_Product_d;
  }

  // End of Switch: '<S25>/Switch'

  // Gain: '<S15>/Gain3'
  rtb_Gain3_a = 49.311615F * rtb_Switch_gw;

  // Trigonometry: '<S5>/Trigonometric Function2' incorporates:
  //   Inport: '<Root>/theta_rad'

  rtb_TrigonometricFunction2 = (real32_T)cos(QS_InnerRateLoop_U.theta_rad);

  // Trigonometry: '<S5>/Trigonometric Function5' incorporates:
  //   Inport: '<Root>/theta_rad'

  rtb_TrigonometricFunction5 = (real32_T)sin(QS_InnerRateLoop_U.theta_rad);

  // Trigonometry: '<S5>/Trigonometric Function4' incorporates:
  //   Inport: '<Root>/phi_rad'

  rtb_TrigonometricFunction4 = (real32_T)sin(QS_InnerRateLoop_U.phi_rad);

  // Trigonometry: '<S5>/Trigonometric Function1' incorporates:
  //   Inport: '<Root>/phi_rad'

  rtb_TrigonometricFunction1 = (real32_T)cos(QS_InnerRateLoop_U.phi_rad);

  // Sum: '<S3>/Sum' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
  //   Gain: '<S12>/Gain1'
  //   Gain: '<S13>/Gain1'
  //   Gain: '<S13>/Gain3'
  //   Gain: '<S14>/Gain1'
  //   Gain: '<S15>/Gain2'
  //   Gain: '<S18>/derivative cutoff frequency 1'
  //   Gain: '<S22>/derivative cutoff frequency 1'
  //   Gain: '<S26>/derivative cutoff frequency 1'
  //   Inport: '<Root>/p_rps'
  //   Inport: '<Root>/q_rps'
  //   Inport: '<Root>/r_rps'
  //   Sum: '<S12>/Sum1'
  //   Sum: '<S12>/Sum2'
  //   Sum: '<S13>/Sum1'
  //   Sum: '<S14>/Sum1'
  //   Sum: '<S14>/Sum2'
  //   Sum: '<S15>/Sum3'
  //   Sum: '<S15>/Sum5'
  //   Sum: '<S18>/Sum1'
  //   Sum: '<S22>/Sum1'
  //   Sum: '<S26>/Sum1'

  rtb_Gain_4[0] = rtb_Gain;
  rtb_Gain_4[1] = (rtb_derivativecutofffrequency1 -
                   QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_b) *
    100.0F;
  rtb_Gain_4[2] = (rtb_derivativecutofffrequenc_ap -
                   QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_cl) *
    100.0F;
  rtb_Gain_4[3] = (rtb_derivativecutofffrequenc_nd -
                   QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_l) *
    100.0F;
  tmp[0] = (8.35246086F * rtb_Sum2_cl +
            QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_h4) * 1.5F;
  tmp[1] = (rtb_derivativecutofffrequency1 - QS_InnerRateLoop_U.p_rps) *
    12.4024372F + (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_gi +
                   rtb_Gain_bw);
  tmp[2] = (rtb_derivativecutofffrequenc_ap - QS_InnerRateLoop_U.q_rps) *
    10.3416967F + (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ia +
                   rtb_Gain_fc);
  tmp[3] = (rtb_derivativecutofffrequenc_nd - QS_InnerRateLoop_U.r_rps) *
    4.27515078F + (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_kt +
                   rtb_Gain3_a);

  // SignalConversion: '<S3>/TmpSignal ConversionAtCinv*AinvInport1' incorporates:
  //   Inport: '<Root>/p_rps'
  //   Inport: '<Root>/phi_rad'
  //   Inport: '<Root>/psi_rad'
  //   Inport: '<Root>/q_rps'
  //   Inport: '<Root>/r_rps'
  //   Inport: '<Root>/theta_rad'
  //   Product: '<S5>/Divide'
  //   Product: '<S5>/Divide1'
  //   Product: '<S5>/Divide10'
  //   Product: '<S5>/Divide11'
  //   Product: '<S5>/Divide12'
  //   Product: '<S5>/Divide13'
  //   Product: '<S5>/Divide14'
  //   Product: '<S5>/Divide15'
  //   Product: '<S5>/Divide16'
  //   Product: '<S5>/Divide2'
  //   Product: '<S5>/Divide3'
  //   Product: '<S5>/Divide4'
  //   Product: '<S5>/Divide5'
  //   Product: '<S5>/Divide6'
  //   Product: '<S5>/Divide7'
  //   Product: '<S5>/Divide8'
  //   Product: '<S5>/Divide9'
  //   Sum: '<S5>/Add1'
  //   Sum: '<S5>/Add2'
  //   Sum: '<S5>/Add3'
  //   Sum: '<S5>/Add4'
  //   Sum: '<S5>/Add5'
  //   Sum: '<S5>/Add6'
  //   Sum: '<S5>/Add7'

  rtb_TrigonometricFunction2_0[0] = (rtb_TrigonometricFunction2 *
    QS_InnerRateLoop_ConstB.TrigonometricFunction3 * rtb_Add5 +
    rtb_TrigonometricFunction2 * QS_InnerRateLoop_ConstB.TrigonometricFunction6 *
    rtb_Add6) + -rtb_TrigonometricFunction5 * rtb_Add7;
  rtb_TrigonometricFunction2_0[1] = ((rtb_TrigonometricFunction4 *
    rtb_TrigonometricFunction5 * QS_InnerRateLoop_ConstB.TrigonometricFunction3
    - rtb_TrigonometricFunction1 *
    QS_InnerRateLoop_ConstB.TrigonometricFunction6) * rtb_Add5 +
    (rtb_TrigonometricFunction4 * rtb_TrigonometricFunction5 *
     QS_InnerRateLoop_ConstB.TrigonometricFunction6 + rtb_TrigonometricFunction1
     * QS_InnerRateLoop_ConstB.TrigonometricFunction3) * rtb_Add6) +
    rtb_TrigonometricFunction4 * rtb_TrigonometricFunction2 * rtb_Add7;
  rtb_TrigonometricFunction2_0[2] = ((rtb_TrigonometricFunction1 *
    rtb_TrigonometricFunction5 * QS_InnerRateLoop_ConstB.TrigonometricFunction3
    + rtb_TrigonometricFunction4 *
    QS_InnerRateLoop_ConstB.TrigonometricFunction6) * rtb_Add5 +
    (rtb_TrigonometricFunction1 * rtb_TrigonometricFunction5 *
     QS_InnerRateLoop_ConstB.TrigonometricFunction6 - rtb_TrigonometricFunction4
     * QS_InnerRateLoop_ConstB.TrigonometricFunction3) * rtb_Add6) +
    rtb_TrigonometricFunction1 * rtb_TrigonometricFunction2 * rtb_Add7;
  rtb_TrigonometricFunction2_0[3] = QS_InnerRateLoop_U.p_rps;
  rtb_TrigonometricFunction2_0[4] = QS_InnerRateLoop_U.q_rps;
  rtb_TrigonometricFunction2_0[5] = QS_InnerRateLoop_U.r_rps;
  rtb_TrigonometricFunction2_0[6] = QS_InnerRateLoop_U.phi_rad;
  rtb_TrigonometricFunction2_0[7] = QS_InnerRateLoop_U.theta_rad;
  rtb_TrigonometricFunction2_0[8] = QS_InnerRateLoop_U.psi_rad;

  // Sum: '<S3>/Sum' incorporates:
  //   Gain: '<S3>/(Binv)^-1'
  //   Gain: '<S3>/Cinv*Ainv'

  for (rtb_Switch_m = 0; rtb_Switch_m < 4; rtb_Switch_m++) {
    rtb_Sum1_0 = 0.0F;
    for (i = 0; i < 9; i++) {
      rtb_Sum1_0 += QS_InnerRateLoop_ConstP.CinvAinv_Gain[(i << 2) +
        rtb_Switch_m] * rtb_TrigonometricFunction2_0[i];
    }

    rtb_Gain_5[rtb_Switch_m] = (rtb_Gain_4[rtb_Switch_m] + tmp[rtb_Switch_m]) -
      rtb_Sum1_0;
  }

  // Gain: '<S3>/(Binv)^-1'
  for (rtb_Switch_m = 0; rtb_Switch_m < 4; rtb_Switch_m++) {
    rtb_Sum1_0 = QS_InnerRateLoop_ConstP.Binv1_Gain[rtb_Switch_m + 12] *
      rtb_Gain_5[3] + (QS_InnerRateLoop_ConstP.Binv1_Gain[rtb_Switch_m + 8] *
                       rtb_Gain_5[2] +
                       (QS_InnerRateLoop_ConstP.Binv1_Gain[rtb_Switch_m + 4] *
                        rtb_Gain_5[1] +
                        QS_InnerRateLoop_ConstP.Binv1_Gain[rtb_Switch_m] *
                        rtb_Gain_5[0]));
    rtb_Binv1[rtb_Switch_m] = rtb_Sum1_0;
  }

  // DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
  DiscreteTransferFcn_tmp = rtb_Binv1[0] - -0.6842F *
    QS_InnerRateLoop_DWork.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1'
  DiscreteTransferFcn1_tmp = rtb_Binv1[1] - -0.6F *
    QS_InnerRateLoop_DWork.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2'
  DiscreteTransferFcn2_tmp = rtb_Binv1[2] - -0.6F *
    QS_InnerRateLoop_DWork.DiscreteTransferFcn2_states;

  // DataTypeConversion: '<S10>/Data Type Conversion17' incorporates:
  //   Constant: '<S10>/Constant10'
  //   Inport: '<Root>/CH8_flag'
  //   Inport: '<Root>/Trajectory Switch'
  //   Logic: '<Root>/Logical Operator3'
  //   Logic: '<Root>/Logical Operator4'
  //   RelationalOperator: '<S10>/Relational Operator6'

  rtb_DataTypeConversion17 = ((int32_T)((!QS_InnerRateLoop_U.TrajectorySwitch) &&
                               (QS_InnerRateLoop_U.CH8_flag != 0.0F)) >= 1);

  // Product: '<S50>/Product1' incorporates:
  //   Gain: '<S50>/Gain2'
  //   Sum: '<S50>/Sum'
  //   UnitDelay: '<S50>/Unit Delay'

  rtb_Product1 = (0.0025F * rtb_DataTypeConversion17 +
                  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_a) *
    rtb_DataTypeConversion17;

  // Sum: '<S54>/Sum' incorporates:
  //   Constant: '<S50>/Constant3'
  //   Constant: '<S54>/Constant'
  //   DataTypeConversion: '<S54>/Data Type Conversion'
  //   DataTypeConversion: '<S54>/Data Type Conversion1'
  //   DataTypeConversion: '<S54>/Data Type Conversion2'
  //   DataTypeConversion: '<S54>/Data Type Conversion3'
  //   DataTypeConversion: '<S54>/Data Type Conversion4'
  //   DataTypeConversion: '<S54>/Data Type Conversion5'
  //   RelationalOperator: '<S54>/Relational Operator'
  //   RelationalOperator: '<S54>/Relational Operator1'
  //   RelationalOperator: '<S54>/Relational Operator2'
  //   RelationalOperator: '<S54>/Relational Operator3'
  //   RelationalOperator: '<S54>/Relational Operator4'
  //   RelationalOperator: '<S54>/Relational Operator5'

  rtb_Sum_dv = (((((rtb_Product1 >= 0.0F) + (rtb_Product1 >= 5.0F)) +
                  (rtb_Product1 >= QS_InnerRateLoop_ConstB.Sum1)) +
                 (rtb_Product1 >= QS_InnerRateLoop_ConstB.Sum3)) + (rtb_Product1
    >= QS_InnerRateLoop_ConstB.Sum2)) + (rtb_Product1 >=
    QS_InnerRateLoop_ConstB.Sum4);

  // MultiPortSwitch: '<S50>/Multiport Switch1' incorporates:
  //   Constant: '<S50>/Constant10'
  //   Constant: '<S50>/Constant14'
  //   Constant: '<S50>/Constant15'
  //   Constant: '<S50>/Constant16'
  //   Constant: '<S50>/Constant3'
  //   Constant: '<S50>/Constant6'
  //   Constant: '<S50>/Constant8'
  //   Gain: '<S50>/Gain'
  //   Gain: '<S50>/Gain1'
  //   Sum: '<S50>/Sum1'
  //   Sum: '<S50>/Sum2'
  //   Sum: '<S50>/Sum3'

  switch (rtb_Sum_dv) {
   case 1:
    rtb_MultiportSwitch1 = 0.0F;
    break;

   case 2:
    rtb_MultiportSwitch1 = (rtb_Product1 - 5.0F) * 0.2F;
    break;

   case 3:
    rtb_MultiportSwitch1 = 1.0F;
    break;

   case 4:
    rtb_MultiportSwitch1 = 1.0F;
    break;

   case 5:
    rtb_MultiportSwitch1 = 1.0F - (((rtb_Product1 - 60.0F) + 5.0F) + 5.0F) *
      0.2F;
    break;

   default:
    rtb_MultiportSwitch1 = 0.0F;
    break;
  }

  // End of MultiPortSwitch: '<S50>/Multiport Switch1'

  // DiscreteIntegrator: '<S51>/Discrete-Time Integrator'
  if ((rtb_DataTypeConversion17 > 0.0F) &&
      (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_a <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_dn = 0.0F;
  }

  // Product: '<S50>/Product4' incorporates:
  //   DiscreteIntegrator: '<S51>/Discrete-Time Integrator'
  //   Trigonometry: '<S51>/Trigonometric Function'

  rtb_Sum1_0 = rtb_MultiportSwitch1 * (real32_T)sin
    (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_dn);

  // Saturate: '<S50>/Saturation'
  if (rtb_Sum1_0 > 1.0F) {
    rtb_Saturation_m = 1.0F;
  } else if (rtb_Sum1_0 < -1.0F) {
    rtb_Saturation_m = -1.0F;
  } else {
    rtb_Saturation_m = rtb_Sum1_0;
  }

  // End of Saturate: '<S50>/Saturation'

  // Switch: '<S10>/Switch1' incorporates:
  //   Constant: '<S10>/Constant3'
  //   Constant: '<S10>/Constant5'
  //   Constant: '<S10>/Constant8'
  //   Inport: '<Root>/rc_6'
  //   Logic: '<S10>/Logical Operator1'
  //   RelationalOperator: '<S10>/Relational Operator3'
  //   RelationalOperator: '<S10>/Relational Operator4'

  if ((QS_InnerRateLoop_U.rc_6 >= 500.0F) && (QS_InnerRateLoop_U.rc_6 < 750.0F))
  {
    rtb_Sum1_0 = rtb_Saturation_m;
  } else {
    rtb_Sum1_0 = 0.0F;
  }

  // End of Switch: '<S10>/Switch1'

  // Product: '<S10>/Product2' incorporates:
  //   Gain: '<S10>/Gain2'
  //   Inport: '<Root>/sweep_multiplier'

  rtb_Product2_l4 = 200.0F * rtb_Sum1_0 * QS_InnerRateLoop_U.sweep_multiplier;

  // Switch: '<S10>/Switch' incorporates:
  //   Constant: '<S10>/Constant'
  //   Constant: '<S10>/Constant1'
  //   Inport: '<Root>/rc_6'
  //   RelationalOperator: '<S10>/Relational Operator'

  if (QS_InnerRateLoop_U.rc_6 < 250.0F) {
    rtb_Sum1_0 = rtb_Saturation_m;
  } else {
    rtb_Sum1_0 = 0.0F;
  }

  // End of Switch: '<S10>/Switch'

  // Product: '<S10>/Product' incorporates:
  //   Gain: '<S10>/Gain'
  //   Inport: '<Root>/sweep_multiplier'

  rtb_Product_jq = 450.0F * rtb_Sum1_0 * QS_InnerRateLoop_U.sweep_multiplier;

  // Switch: '<S10>/Switch2' incorporates:
  //   Constant: '<S10>/Constant2'
  //   Constant: '<S10>/Constant4'
  //   Constant: '<S10>/Constant7'
  //   Inport: '<Root>/rc_6'
  //   Logic: '<S10>/Logical Operator'
  //   RelationalOperator: '<S10>/Relational Operator1'
  //   RelationalOperator: '<S10>/Relational Operator2'

  if ((QS_InnerRateLoop_U.rc_6 >= 250.0F) && (QS_InnerRateLoop_U.rc_6 < 500.0F))
  {
    rtb_Sum1_0 = rtb_Saturation_m;
  } else {
    rtb_Sum1_0 = 0.0F;
  }

  // End of Switch: '<S10>/Switch2'

  // Product: '<S10>/Product1' incorporates:
  //   Gain: '<S10>/Gain1'
  //   Inport: '<Root>/sweep_multiplier'

  rtb_Product1_p = 450.0F * rtb_Sum1_0 * QS_InnerRateLoop_U.sweep_multiplier;

  // Switch: '<S10>/Switch3' incorporates:
  //   Constant: '<S10>/Constant6'
  //   Constant: '<S10>/Constant9'
  //   Inport: '<Root>/rc_6'
  //   RelationalOperator: '<S10>/Relational Operator5'

  if (QS_InnerRateLoop_U.rc_6 >= 750.0F) {
    rtb_Sum1_0 = rtb_Saturation_m;
  } else {
    rtb_Sum1_0 = 0.0F;
  }

  // End of Switch: '<S10>/Switch3'

  // Product: '<S10>/Product3' incorporates:
  //   Gain: '<S10>/Gain3'
  //   Inport: '<Root>/sweep_multiplier'

  rtb_Product3 = 450.0F * rtb_Sum1_0 * QS_InnerRateLoop_U.sweep_multiplier;

  // Outport: '<Root>/mixer_throttle' incorporates:
  //   DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
  //   Sum: '<Root>/Sum1'

  QS_InnerRateLoop_Y.mixer_throttle = ((4.368F * DiscreteTransferFcn_tmp +
    -4.053F * QS_InnerRateLoop_DWork.DiscreteTransferFcn_states) +
    QS_InnerRateLoop_B.In1[0]) + rtb_Product2_l4;

  // Outport: '<Root>/mixer_x' incorporates:
  //   DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1'
  //   Sum: '<Root>/Sum1'

  QS_InnerRateLoop_Y.mixer_x = ((6.425F * DiscreteTransferFcn1_tmp + -6.375F *
    QS_InnerRateLoop_DWork.DiscreteTransferFcn1_states) +
    QS_InnerRateLoop_B.In1[1]) + rtb_Product_jq;

  // Outport: '<Root>/mixer_y' incorporates:
  //   DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2'
  //   Sum: '<Root>/Sum1'

  QS_InnerRateLoop_Y.mixer_y = ((6.425F * DiscreteTransferFcn2_tmp + -6.375F *
    QS_InnerRateLoop_DWork.DiscreteTransferFcn2_states) +
    QS_InnerRateLoop_B.In1[2]) + rtb_Product1_p;

  // Outport: '<Root>/mixer_z' incorporates:
  //   Sum: '<Root>/Sum1'

  QS_InnerRateLoop_Y.mixer_z = (QS_InnerRateLoop_B.In1[3] + rtb_Binv1[3]) +
    rtb_Product3;

  // Outport: '<Root>/roll_sweep'
  QS_InnerRateLoop_Y.roll_sweep = rtb_Product_jq;

  // Outport: '<Root>/pitch_sweep'
  QS_InnerRateLoop_Y.pitch_sweep = rtb_Product1_p;

  // Outport: '<Root>/yaw_sweep'
  QS_InnerRateLoop_Y.yaw_sweep = rtb_Product3;

  // Outport: '<Root>/coll_sweep'
  QS_InnerRateLoop_Y.coll_sweep = rtb_Product2_l4;

  // Outport: '<Root>/TrajectoryON'
  QS_InnerRateLoop_Y.TrajectoryON = rtb_LogicalOperator1_f;

  // Outport: '<Root>/vehheadingcmd'
  QS_InnerRateLoop_Y.vehheadingcmd = rtb_Sum4_i;

  // DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ez <= 0)) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 = 0.0F;
  }

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 >= 3.14136124F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 = 3.14136124F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 <= -3.14136124F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 = -3.14136124F;
    }
  }

  rtb_DiscreteTimeIntegrator_ab =
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1;

  // DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_gi <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_gi == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e =
      QS_InnerRateLoop_ConstB.Constant_i;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e >= 0.261780113F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e = 0.261780113F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e <=
          -0.261780113F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e = -0.261780113F;
      }
    }
  }

  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e >= 0.261780113F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e = 0.261780113F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e <= -0.261780113F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e = -0.261780113F;
    }
  }

  // Lookup_n-D: '<S35>/1-D Lookup Table5'
  rtb_DLookupTable5 = look1_iflf_binlxpw(rtb_Sqrt, *(real32_T (*)[7])&
    QS_InnerRateLoop_ConstP.pooled11[0], *(real32_T (*)[7])&
    QS_InnerRateLoop_ConstP.pooled35[0], 6U);

  // Gain: '<S31>/m//s to ft//s1' incorporates:
  //   Product: '<S49>/Divide1'
  //   Product: '<S49>/Divide11'
  //   Product: '<S49>/Divide13'
  //   Product: '<S49>/Divide15'
  //   Product: '<S49>/Divide3'
  //   Product: '<S49>/Divide7'
  //   Product: '<S49>/Divide8'
  //   Sum: '<S49>/Add1'
  //   Sum: '<S49>/Add3'
  //   Sum: '<S49>/Add6'

  rtb_mstofts1 = (((QS_InnerRateLoop_ConstB.TrigonometricFunction4_m2 *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction5_d *
                    rtb_TrigonometricFunction3_j -
                    QS_InnerRateLoop_ConstB.TrigonometricFunction1_b *
                    rtb_TrigonometricFunction6_k) * rtb_Divide3_h +
                   (QS_InnerRateLoop_ConstB.TrigonometricFunction4_m2 *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction5_d *
                    rtb_TrigonometricFunction6_k +
                    QS_InnerRateLoop_ConstB.TrigonometricFunction1_b *
                    rtb_TrigonometricFunction3_j) * rtb_Divide2_c) +
                  QS_InnerRateLoop_ConstB.TrigonometricFunction4_m2 *
                  QS_InnerRateLoop_ConstB.TrigonometricFunction2_m *
                  rtb_Divide4_l) * 3.28084F;

  // Gain: '<S40>/Gain1' incorporates:
  //   Gain: '<S40>/Gain'
  //   Product: '<S34>/Divide1'
  //   Product: '<S34>/Divide11'
  //   Product: '<S34>/Divide13'
  //   Product: '<S34>/Divide15'
  //   Product: '<S34>/Divide3'
  //   Product: '<S34>/Divide7'
  //   Product: '<S34>/Divide8'
  //   Sum: '<S32>/Sum3'
  //   Sum: '<S34>/Add1'
  //   Sum: '<S34>/Add3'
  //   Sum: '<S34>/Add6'
  //   Sum: '<S40>/Sum'
  //   Sum: '<S40>/Sum1'
  //   UnitDelay: '<S40>/Unit Delay'
  //   UnitDelay: '<S40>/Unit Delay1'

  rtb_Gain1_n = ((((((QS_InnerRateLoop_ConstB.TrigonometricFunction4 *
                      QS_InnerRateLoop_ConstB.TrigonometricFunction5 *
                      rtb_TrigonometricFunction3 -
                      QS_InnerRateLoop_ConstB.TrigonometricFunction1 *
                      rtb_TrigonometricFunction6) * rtb_Saturation +
                     (QS_InnerRateLoop_ConstB.TrigonometricFunction4 *
                      QS_InnerRateLoop_ConstB.TrigonometricFunction5 *
                      rtb_TrigonometricFunction6 +
                      QS_InnerRateLoop_ConstB.TrigonometricFunction1 *
                      rtb_TrigonometricFunction3) * rtb_Saturation1) +
                    QS_InnerRateLoop_ConstB.TrigonometricFunction4 *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction2_d *
                    rtb_Saturation2) + 0.0F) -
                  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_o) * 4.0F -
                 QS_InnerRateLoop_DWork.UnitDelay_DSTATE_d) * 16.0F;

  // DiscreteIntegrator: '<S40>/Discrete-Time Integrator1'
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTE_j != 0) {
    DiscreteTimeIntegrator1_e =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b;
  } else if ((rtb_LogicalOperator1_f &&
              (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_b <= 0)) ||
             ((!rtb_LogicalOperator1_f) &&
              (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_b == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b =
      QS_InnerRateLoop_ConstB.Constant_n;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b >= 25.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b = 25.0F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b <= -25.0F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b = -25.0F;
      }
    }

    DiscreteTimeIntegrator1_e =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b;
  } else {
    DiscreteTimeIntegrator1_e = 0.00125F * rtb_Gain1_n +
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b;
  }

  if (DiscreteTimeIntegrator1_e >= 25.0F) {
    DiscreteTimeIntegrator1_e = 25.0F;
  } else {
    if (DiscreteTimeIntegrator1_e <= -25.0F) {
      DiscreteTimeIntegrator1_e = -25.0F;
    }
  }

  // End of DiscreteIntegrator: '<S40>/Discrete-Time Integrator1'

  // DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_j != 0) {
    DiscreteTimeIntegrator_h =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p;
  } else if ((rtb_LogicalOperator1_f &&
              (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_f <= 0)) ||
             ((!rtb_LogicalOperator1_f) &&
              (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_f == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p =
      QS_InnerRateLoop_ConstB.Constant1_m;
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p >= 50.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p = 50.0F;
    } else {
      if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p <= -50.0F) {
        QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p = -50.0F;
      }
    }

    DiscreteTimeIntegrator_h =
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p;
  } else {
    DiscreteTimeIntegrator_h = 0.00125F * DiscreteTimeIntegrator1_e +
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p;
  }

  if (DiscreteTimeIntegrator_h >= 50.0F) {
    DiscreteTimeIntegrator_h = 50.0F;
  } else {
    if (DiscreteTimeIntegrator_h <= -50.0F) {
      DiscreteTimeIntegrator_h = -50.0F;
    }
  }

  // End of DiscreteIntegrator: '<S40>/Discrete-Time Integrator'

  // Switch: '<S40>/Switch' incorporates:
  //   Constant: '<S40>/Constant2'

  if (rtb_LogicalOperator1_f) {
    rtb_Sum1_0 = DiscreteTimeIntegrator_h;
  } else {
    rtb_Sum1_0 = 0.0F;
  }

  // End of Switch: '<S40>/Switch'

  // Sum: '<S35>/Sum4'
  rtb_Sum4_px = rtb_mstofts1 + rtb_Sum1_0;

  // Product: '<S35>/Product1' incorporates:
  //   Gain: '<S35>/Gain'
  //   Sum: '<S35>/Sum'

  rtb_Product1_i = (rtb_Sum4_px - rtb_Add6) * 0.0376329683F * rtb_DLookupTable5;

  // DiscreteIntegrator: '<S42>/Discrete-Time Integrator'
  if ((rtb_LogicalOperator1_f &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ab <= 0)) ||
      ((!rtb_LogicalOperator1_f) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ab == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_mi = 0.0F;
  }

  // Switch: '<S60>/Switch' incorporates:
  //   DeadZone: '<S11>/Dead Zone1'
  //   Gain: '<S11>/phicmd'
  //   Inport: '<Root>/input_lat'

  if (rtb_LogicalOperator1_f) {
    // Lookup_n-D: '<S35>/1-D Lookup Table6'
    rtb_DLookupTable6 = look1_iflf_binlxpw(rtb_Sqrt, *(real32_T (*)[7])&
      QS_InnerRateLoop_ConstP.pooled11[0], *(real32_T (*)[7])&
      QS_InnerRateLoop_ConstP.pooled10[0], 6U);

    // Gain: '<S42>/derivative cutoff frequency 1' incorporates:
    //   DiscreteIntegrator: '<S42>/Discrete-Time Integrator'
    //   Sum: '<S42>/Sum1'

    rtb_derivativecutofffrequenc_m5 = (rtb_Sum4_px -
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_mi) * 10.0F;

    // Lookup_n-D: '<S35>/1-D Lookup Table4'
    rtb_DLookupTable4 = look1_iflf_binlxpw(rtb_Sqrt, *(real32_T (*)[7])&
      QS_InnerRateLoop_ConstP.pooled11[0], *(real32_T (*)[7])&
      QS_InnerRateLoop_ConstP.pooled10[0], 6U);

    // Sum: '<S35>/Sum2' incorporates:
    //   DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
    //   DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
    //   Gain: '<S35>/Gain1'
    //   Gain: '<S35>/Gain3'
    //   Gain: '<S41>/derivative cutoff frequency 1'
    //   Product: '<S35>/Product'
    //   Product: '<S35>/Product2'
    //   Sum: '<S35>/Sum1'
    //   Sum: '<S35>/Sum3'
    //   Sum: '<S41>/Sum1'

    rtb_Sum1_0 = ((rtb_derivativecutofffrequenc_m5 - (rtb_Add6 -
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_kw) * 15.0F) *
                  0.0837969482F * rtb_DLookupTable4 +
                  (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e +
                   rtb_Product1_i)) + 0.031F * rtb_derivativecutofffrequenc_m5 *
      rtb_DLookupTable6;

    // Saturate: '<S11>/Saturation1'
    if (rtb_Sum1_0 > 0.523560226F) {
      rtb_Switch_d = 0.523560226F;
    } else if (rtb_Sum1_0 < -0.523560226F) {
      rtb_Switch_d = -0.523560226F;
    } else {
      rtb_Switch_d = rtb_Sum1_0;
    }

    // End of Saturate: '<S11>/Saturation1'
  } else {
    if (QS_InnerRateLoop_U.input_lat > 135.0F) {
      // DeadZone: '<S11>/Dead Zone1' incorporates:
      //   Inport: '<Root>/input_lat'

      rtb_Sum1_0 = QS_InnerRateLoop_U.input_lat - 135.0F;
    } else if (QS_InnerRateLoop_U.input_lat >= -135.0F) {
      // DeadZone: '<S11>/Dead Zone1'
      rtb_Sum1_0 = 0.0F;
    } else {
      // DeadZone: '<S11>/Dead Zone1' incorporates:
      //   Inport: '<Root>/input_lat'

      rtb_Sum1_0 = QS_InnerRateLoop_U.input_lat - -135.0F;
    }

    rtb_Switch_d = 0.000116F * rtb_Sum1_0;
  }

  // End of Switch: '<S60>/Switch'

  // Switch: '<S60>/Switch1' incorporates:
  //   RelationalOperator: '<S60>/Relational Operator'
  //   Sum: '<S60>/Sum1'
  //   UnitDelay: '<S60>/Unit Delay'
  //   UnitDelay: '<S60>/Unit Delay1'
  //   UnitDelay: '<S60>/Unit Delay2'

  if (QS_InnerRateLoop_DWork.UnitDelay_DSTATE_f == rtb_LogicalOperator1_f) {
    rtb_Switch1_kj = QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_g;
  } else {
    rtb_Switch1_kj = QS_InnerRateLoop_DWork.UnitDelay2_DSTATE_k5 - rtb_Switch_d;
  }

  // End of Switch: '<S60>/Switch1'

  // Saturate: '<S60>/Saturation'
  if (rtb_Switch1_kj > 0.0025F) {
    rtb_Sum1_0 = 0.0025F;
  } else if (rtb_Switch1_kj < -0.0025F) {
    rtb_Sum1_0 = -0.0025F;
  } else {
    rtb_Sum1_0 = rtb_Switch1_kj;
  }

  // Sum: '<S60>/Sum' incorporates:
  //   Saturate: '<S60>/Saturation'

  rtb_Sum_ds = rtb_Switch1_kj - rtb_Sum1_0;

  // Sum: '<S60>/Sum2'
  rtb_Sum2_l = rtb_Switch_d + rtb_Sum_ds;

  // Trigonometry: '<S33>/Trigonometric Function3'
  rtb_TrigonometricFunction3_c = (real32_T)cos(rtb_deg2rad2);

  // Trigonometry: '<S33>/Trigonometric Function6'
  rtb_TrigonometricFunction6_fg = (real32_T)sin(rtb_deg2rad2);

  // Sum: '<S33>/Add5' incorporates:
  //   Product: '<S33>/Divide'
  //   Product: '<S33>/Divide1'
  //   Product: '<S33>/Divide13'
  //   Product: '<S33>/Divide14'
  //   Product: '<S33>/Divide3'
  //   Product: '<S33>/Divide4'
  //   Product: '<S33>/Divide5'
  //   Sum: '<S33>/Add1'
  //   Sum: '<S33>/Add2'

  rtb_Add5_j = ((QS_InnerRateLoop_ConstB.TrigonometricFunction1_e *
                 QS_InnerRateLoop_ConstB.TrigonometricFunction5_k *
                 rtb_TrigonometricFunction3_c +
                 QS_InnerRateLoop_ConstB.TrigonometricFunction4_h *
                 rtb_TrigonometricFunction6_fg) * rtb_mstofts2 +
                (QS_InnerRateLoop_ConstB.TrigonometricFunction4_h *
                 QS_InnerRateLoop_ConstB.TrigonometricFunction5_k *
                 rtb_TrigonometricFunction3_c -
                 QS_InnerRateLoop_ConstB.TrigonometricFunction1_e *
                 rtb_TrigonometricFunction6_fg) * rtb_mstofts1) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction2_k *
    rtb_TrigonometricFunction3_c * rtb_mstofts;

  // Sum: '<S33>/Add6' incorporates:
  //   Product: '<S33>/Divide10'
  //   Product: '<S33>/Divide15'
  //   Product: '<S33>/Divide16'
  //   Product: '<S33>/Divide6'
  //   Product: '<S33>/Divide7'
  //   Product: '<S33>/Divide8'
  //   Product: '<S33>/Divide9'
  //   Sum: '<S33>/Add3'
  //   Sum: '<S33>/Add4'

  rtb_Add6_h = ((QS_InnerRateLoop_ConstB.TrigonometricFunction1_e *
                 QS_InnerRateLoop_ConstB.TrigonometricFunction5_k *
                 rtb_TrigonometricFunction6_fg -
                 QS_InnerRateLoop_ConstB.TrigonometricFunction4_h *
                 rtb_TrigonometricFunction3_c) * rtb_mstofts2 +
                (QS_InnerRateLoop_ConstB.TrigonometricFunction4_h *
                 QS_InnerRateLoop_ConstB.TrigonometricFunction5_k *
                 rtb_TrigonometricFunction6_fg +
                 QS_InnerRateLoop_ConstB.TrigonometricFunction1_e *
                 rtb_TrigonometricFunction3_c) * rtb_mstofts1) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction2_k *
    rtb_TrigonometricFunction6_fg * rtb_mstofts;

  // Sum: '<S33>/Add7' incorporates:
  //   Product: '<S33>/Divide11'
  //   Product: '<S33>/Divide12'
  //   Product: '<S33>/Divide2'

  rtb_Add7_g = (QS_InnerRateLoop_ConstB.TrigonometricFunction1_e *
                QS_InnerRateLoop_ConstB.TrigonometricFunction2_k * rtb_mstofts2
                + QS_InnerRateLoop_ConstB.TrigonometricFunction4_h *
                QS_InnerRateLoop_ConstB.TrigonometricFunction2_k * rtb_mstofts1)
    + -QS_InnerRateLoop_ConstB.TrigonometricFunction5_k * rtb_mstofts;

  // MultiPortSwitch: '<S50>/Multiport Switch2' incorporates:
  //   Constant: '<S52>/Constant'
  //   Constant: '<S53>/Constant1'
  //   Constant: '<S53>/Constant17'
  //   Constant: '<S53>/Constant2'
  //   Constant: '<S55>/Constant14'
  //   Constant: '<S55>/Constant7'
  //   Constant: '<S55>/Constant9'
  //   Constant: '<S56>/Constant10'
  //   Constant: '<S56>/Constant12'
  //   Constant: '<S56>/Constant13'
  //   DataTypeConversion: '<S53>/Data Type Conversion'
  //   DataTypeConversion: '<S53>/Data Type Conversion1'
  //   DataTypeConversion: '<S53>/Data Type Conversion2'
  //   Gain: '<S55>/1//tot'
  //   Gain: '<S55>/C1'
  //   Gain: '<S55>/C2'
  //   Gain: '<S56>/1//tot1'
  //   Gain: '<S56>/C3'
  //   Gain: '<S56>/C4'
  //   Math: '<S55>/Math Function'
  //   Math: '<S56>/Math Function1'
  //   Product: '<S55>/Product'
  //   Product: '<S56>/Product1'
  //   RelationalOperator: '<S53>/Relational Operator'
  //   RelationalOperator: '<S53>/Relational Operator1'
  //   RelationalOperator: '<S53>/Relational Operator2'
  //   Sum: '<S53>/Sum'
  //   Sum: '<S55>/Sum1'
  //   Sum: '<S55>/Sum3'
  //   Sum: '<S55>/Sum8'
  //   Sum: '<S56>/Sum4'
  //   Sum: '<S56>/Sum6'
  //   Sum: '<S56>/Sum7'
  //
  //  About '<S55>/Math Function':
  //   Operator: exp
  //
  //  About '<S56>/Math Function1':
  //   Operator: exp

  switch (((rtb_Sum_dv > 0) + (rtb_Sum_dv > 1)) + (rtb_Sum_dv > 3)) {
   case 1:
    rtb_MultiportSwitch2 = 0.0F;
    break;

   case 2:
    rtb_MultiportSwitch2 = ((real32_T)exp((rtb_Product1 - 5.0F) * 4.0F *
      0.0166666675F) - 1.0F) * 0.0187F * QS_InnerRateLoop_ConstB.Sum2_b + 1.0F;
    break;

   default:
    rtb_MultiportSwitch2 = ((real32_T)exp((rtb_Product1 - 17.56637F) * 4.0F *
      0.0267139468F) - 1.0F) * 0.0187F * QS_InnerRateLoop_ConstB.Sum5 + 1.0F;
    break;
  }

  // End of MultiPortSwitch: '<S50>/Multiport Switch2'

  // DiscreteIntegrator: '<S58>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  if ((QS_InnerRateLoop_U.engage &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_k <= 0)) ||
      ((!QS_InnerRateLoop_U.engage) &&
       (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_k == 1))) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_er = 0.0F;
  }

  rtb_DiscreteTimeIntegrator_ph =
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_er;

  // Outport: '<Root>/phi_cmd' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'

  QS_InnerRateLoop_Y.phi_cmd =
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k;

  // Outport: '<Root>/vz_cmd' incorporates:
  //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator'

  QS_InnerRateLoop_Y.vz_cmd =
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_iz;

  // Outport: '<Root>/psi_cmd'
  QS_InnerRateLoop_Y.psi_cmd = rtb_Switch_e;

  // Outport: '<Root>/Vnorth_cmd'
  QS_InnerRateLoop_Y.Vnorth_cmd = rtb_Add5_j;

  // Outport: '<Root>/Veast_cmd'
  QS_InnerRateLoop_Y.Veast_cmd = rtb_Add6_h;

  // Outport: '<Root>/Vdown_cmd'
  QS_InnerRateLoop_Y.Vdown_cmd = rtb_Add7_g;

  // Outport: '<Root>/Vnorth_corr'
  QS_InnerRateLoop_Y.Vnorth_corr = rtb_Saturation;

  // Outport: '<Root>/Veast_corr'
  QS_InnerRateLoop_Y.Veast_corr = rtb_Saturation1;

  // Outport: '<Root>/Vdown_corr'
  QS_InnerRateLoop_Y.Vdown_corr = rtb_Saturation2;

  // Update for Delay: '<S46>/Delay1' incorporates:
  //   Inport: '<Root>/CH8_flag'

  QS_InnerRateLoop_DWork.Delay1_DSTATE = QS_InnerRateLoop_U.CH8_flag;

  // Switch: '<S46>/Switch'
  if (rtb_LogicalOperator2) {
    // Update for Delay: '<S46>/Delay2'
    QS_InnerRateLoop_DWork.Delay2_DSTATE = rtb_Sum2;
  } else {
    // Update for Delay: '<S46>/Delay2' incorporates:
    //   Constant: '<S46>/Constant1'

    QS_InnerRateLoop_DWork.Delay2_DSTATE = 0.0;
  }

  // End of Switch: '<S46>/Switch'

  // Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S39>/Integral Gain'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE += 0.0F *
    rtb_ProportionalGain * 0.0025F;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE >= 5.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE = 5.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE <= -5.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE = -5.0F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRese = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRese = 0;
  }

  // End of Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_IC_LOADI = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_n += 0.0025F * rtb_Add5_j;
  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_h = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_h = 0;
  }

  // End of Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S38>/Integral Gain'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g += 0.0F *
    rtb_ProportionalGain_o * 0.0025F;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g >= 5.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g = 5.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g <= -5.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g = -5.0F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_e = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_e = 0;
  }

  // End of Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator1'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTATE += 0.0025F * rtb_Add6_h;
  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevRes = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevRes = 0;
  }

  // End of Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S37>/Integral Gain'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c += 0.25F * rtb_Sum_m *
    0.0025F;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c >= 10.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c = 10.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c <= -10.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c = -10.0F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_h3 = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_h3 = 0;
  }

  // End of Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator2'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_IC_LOAD = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_DSTATE += 0.0025F * rtb_Add7_g;
  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_PrevRes = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_PrevRes = 0;
  }

  // End of Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator2'

  // Update for UnitDelay: '<S9>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE = rtb_Product2_d;

  // Update for UnitDelay: '<S61>/Unit Delay1'
  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE = rtb_Sum_e;

  // Update for UnitDelay: '<S61>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_mj = rtb_LogicalOperator1_f;

  // Update for UnitDelay: '<S61>/Unit Delay2'
  QS_InnerRateLoop_DWork.UnitDelay2_DSTATE = rtb_Sum2_d;

  // Update for UnitDelay: '<S19>/Unit Delay' incorporates:
  //   DiscreteIntegrator: '<S19>/Discrete-Time Integrator'

  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_e =
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_iz;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
  //   Gain: '<S18>/derivative cutoff frequency '
  //   Sum: '<S18>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_b +=
    (rtb_derivativecutofffrequency1 -
     QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_b) * 100.0F * 0.0025F;

  // Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
  //   Gain: '<S17>/derivative cutoff frequency '
  //   Sum: '<S17>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_m +=
    (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k -
     QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_m) * 100.0F * 0.0025F;

  // Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
  //   Inport: '<Root>/engage'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k += 0.0025F *
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k >= 1.57068062F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k = 1.57068062F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k <= -1.57068062F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_k = -1.57068062F;
    }
  }

  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_i = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_i = 0;
  }

  // End of Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
  //   Gain: '<S22>/derivative cutoff frequency '
  //   Sum: '<S22>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_cl +=
    (rtb_derivativecutofffrequenc_ap -
     QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_cl) * 100.0F * 0.0025F;

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
  //   Gain: '<S21>/derivative cutoff frequency '
  //   Sum: '<S21>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_k +=
    (QS_InnerRateLoop_Y.theta_cmd -
     QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_k) * 100.0F * 0.0025F;

  // Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S36>/Gain2'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d += 2.0F *
    rtb_Product2_n * 0.0025F;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d >= 0.261780113F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.261780113F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d <= -0.261780113F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d = -0.261780113F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_g = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_g = 0;
  }

  // End of Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S43>/Unit Delay1'
  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_b = DiscreteTimeIntegrator;

  // Update for UnitDelay: '<S43>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_ei = DiscreteTimeIntegrator1;

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a = 0.00125F *
    rtb_Gain1_h + DiscreteTimeIntegrator1;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a >= 25.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a = 25.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a <= -25.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a = -25.0F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_g = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_g = 0;
  }

  // End of Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_E = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go = 0.00125F *
    DiscreteTimeIntegrator1 + DiscreteTimeIntegrator;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go >= 50.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go = 50.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go <= -50.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go = -50.0F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_i = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_i = 0;
  }

  // End of Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S45>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
  //   Gain: '<S45>/derivative cutoff frequency '
  //   Sum: '<S45>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_h += (rtb_Sum4_k -
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_h) * 10.0F * 0.0025F;
  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_hj = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_hj = 0;
  }

  // End of Update for DiscreteIntegrator: '<S45>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
  //   Gain: '<S44>/derivative cutoff frequency '
  //   Sum: '<S44>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_i += (rtb_Add5 -
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_i) * 15.0F * 0.0025F;

  // Update for UnitDelay: '<S59>/Unit Delay1'
  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_m = rtb_Sum_as;

  // Update for UnitDelay: '<S59>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_ap = rtb_LogicalOperator1_f;

  // Update for UnitDelay: '<S59>/Unit Delay2'
  QS_InnerRateLoop_DWork.UnitDelay2_DSTATE_k = rtb_Sum2_b;

  // Update for UnitDelay: '<S20>/Unit Delay1'
  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_h = QS_InnerRateLoop_Y.theta_cmd;

  // Update for UnitDelay: '<S20>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_i = DiscreteTimeIntegrator1_j;

  // Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator1' incorporates:
  //   Inport: '<Root>/engage'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTE_n = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l = 0.00125F *
    rtb_Gain1_c + DiscreteTimeIntegrator1_j;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l >= 3.14136124F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l = 3.14136124F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l <= -3.14136124F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_l = -3.14136124F;
    }
  }

  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_n = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_n = 0;
  }

  // End of Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_c = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba = 0.00125F *
    DiscreteTimeIntegrator1_j + QS_InnerRateLoop_Y.theta_cmd;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba >= 1.57068062F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba = 1.57068062F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba <= -1.57068062F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ba = -1.57068062F;
    }
  }

  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_l = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_l = 0;
  }

  // End of Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
  //   Gain: '<S26>/derivative cutoff frequency '
  //   Sum: '<S26>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_l +=
    (rtb_derivativecutofffrequenc_nd -
     QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_l) * 100.0F * 0.0025F;

  // Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
  //   Gain: '<S27>/derivative cutoff frequency '
  //   Sum: '<S27>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_mn += (rtb_Switch_e -
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_mn) * 100.0F * 0.0025F;

  // Update for UnitDelay: '<S11>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_l = rtb_deg2rad2;

  // Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S58>/Discrete-Time Integrator'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_IC_LOA_f = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_a += 0.0025F *
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_er;
  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_b = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_b = 0;
  }

  // End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S13>/Gain2'
  //   Inport: '<Root>/engage'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_h4 += 12.5286913F *
    rtb_Sum2_cl * 0.0025F;
  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_o = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_o = 0;
  }

  // End of Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_iz += 0.0025F * rtb_Gain;
  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_p = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_p = 0;
  }

  // End of Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S12>/Gain2'
  //   Inport: '<Root>/engage'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_gi += 2.0F * rtb_Gain_bw *
    0.0025F;
  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_bj = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_bj = 0;
  }

  // End of Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S14>/Gain2'
  //   Inport: '<Root>/engage'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_ia += 2.0F * rtb_Gain_fc *
    0.0025F;
  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_c = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_c = 0;
  }

  // End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/engage'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_kt += 0.0025F *
    rtb_Gain3_a;
  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_m = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_m = 0;
  }

  // End of Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator'

  // Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
  QS_InnerRateLoop_DWork.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

  // Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1'
  QS_InnerRateLoop_DWork.DiscreteTransferFcn1_states = DiscreteTransferFcn1_tmp;

  // Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2'
  QS_InnerRateLoop_DWork.DiscreteTransferFcn2_states = DiscreteTransferFcn2_tmp;

  // Update for UnitDelay: '<S50>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_a = rtb_Product1;

  // Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_dn += 0.0025F *
    rtb_MultiportSwitch2;
  if (rtb_DataTypeConversion17 > 0.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_a = 1;
  } else if (rtb_DataTypeConversion17 < 0.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_a = -1;
  } else if (rtb_DataTypeConversion17 == 0.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_a = 0;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_a = 2;
  }

  // End of Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S16>/Gain'
  //   Gain: '<S16>/Gain1'
  //   Inport: '<Root>/engage'
  //   Sum: '<S16>/Sum'
  //   Sum: '<S16>/Sum1'
  //   UnitDelay: '<S16>/Unit Delay'
  //   UnitDelay: '<S16>/Unit Delay1'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 += ((rtb_Sum2_l -
    QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_bm) * 8.0F -
    QS_InnerRateLoop_DWork.UnitDelay_DSTATE_g) * 32.0F * 0.0025F;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 >= 3.14136124F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 = 3.14136124F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 <= -3.14136124F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_c1 = -3.14136124F;
    }
  }

  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ez = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ez = 0;
  }

  // End of Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S35>/Gain2'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e += 2.0F *
    rtb_Product1_i * 0.0025F;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e >= 0.261780113F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e = 0.261780113F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e <= -0.261780113F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e = -0.261780113F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_gi = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_gi = 0;
  }

  // End of Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S40>/Unit Delay1'
  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_o = DiscreteTimeIntegrator_h;

  // Update for UnitDelay: '<S40>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_d = DiscreteTimeIntegrator1_e;

  // Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTE_j = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b = 0.00125F *
    rtb_Gain1_n + DiscreteTimeIntegrator1_e;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b >= 25.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b = 25.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b <= -25.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b = -25.0F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_b = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_b = 0;
  }

  // End of Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_j = 0U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p = 0.00125F *
    DiscreteTimeIntegrator1_e + DiscreteTimeIntegrator_h;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p >= 50.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p = 50.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p <= -50.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p = -50.0F;
    }
  }

  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_f = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_f = 0;
  }

  // End of Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S42>/Discrete-Time Integrator'
  //   Gain: '<S42>/derivative cutoff frequency '
  //   Sum: '<S42>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_mi += (rtb_Sum4_px -
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_mi) * 10.0F * 0.0025F;
  if (rtb_LogicalOperator1_f) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ab = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ab = 0;
  }

  // End of Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
  //   Gain: '<S41>/derivative cutoff frequency '
  //   Sum: '<S41>/Sum'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_kw += (rtb_Add6 -
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_kw) * 15.0F * 0.0025F;

  // Update for UnitDelay: '<S60>/Unit Delay1'
  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_g = rtb_Sum_ds;

  // Update for UnitDelay: '<S60>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_f = rtb_LogicalOperator1_f;

  // Update for UnitDelay: '<S60>/Unit Delay2'
  QS_InnerRateLoop_DWork.UnitDelay2_DSTATE_k5 = rtb_Sum2_l;

  // Update for UnitDelay: '<S16>/Unit Delay1'
  QS_InnerRateLoop_DWork.UnitDelay1_DSTATE_bm = rtb_DiscreteTimeIntegrator1_m;

  // Update for UnitDelay: '<S16>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_g = rtb_DiscreteTimeIntegrator_ab;

  // DeadZone: '<S11>/Dead Zone3' incorporates:
  //   Inport: '<Root>/input_ped'

  if (QS_InnerRateLoop_U.input_ped > 135.0F) {
    rtb_Sum1_0 = QS_InnerRateLoop_U.input_ped - 135.0F;
  } else if (QS_InnerRateLoop_U.input_ped >= -135.0F) {
    rtb_Sum1_0 = 0.0F;
  } else {
    rtb_Sum1_0 = QS_InnerRateLoop_U.input_ped - -135.0F;
  }

  // End of DeadZone: '<S11>/Dead Zone3'

  // Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S11>/rcmd'
  //   Gain: '<S58>/Gain'
  //   Inport: '<Root>/engage'
  //   Sum: '<S58>/Sum'
  //   UnitDelay: '<S58>/Unit Delay'

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_er += (0.000698F *
    rtb_Sum1_0 - QS_InnerRateLoop_DWork.UnitDelay_DSTATE_m) * 10.0F * 0.0025F;
  if (QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_k = 1;
  } else {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_k = 0;
  }

  // End of Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S58>/Unit Delay'
  QS_InnerRateLoop_DWork.UnitDelay_DSTATE_m = rtb_DiscreteTimeIntegrator_ph;
}

// Model initialize function
void untitledModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus((&QS_InnerRateLoop_M), (NULL));

  // block I/O
  (void) memset(((void *) &QS_InnerRateLoop_B), 0,
                sizeof(BlockIO_QS_InnerRateLoop_T));

  // states (dwork)
  (void) memset((void *)&QS_InnerRateLoop_DWork, 0,
                sizeof(D_Work_QS_InnerRateLoop_T));

  // external inputs
  (void) memset((void *)&QS_InnerRateLoop_U, 0,
                sizeof(ExternalInputs_QS_InnerRateLo_T));

  // external outputs
  (void) memset((void *)&QS_InnerRateLoop_Y, 0,
                sizeof(ExternalOutputs_QS_InnerRateL_T));

  // InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE =
    QS_InnerRateLoop_ConstB.Constant;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE >= 5.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE = 5.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE <= -5.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE = -5.0F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRese = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' 

  // InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_IC_LOADI = 1U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_h = 2;

  // InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g =
    QS_InnerRateLoop_ConstB.Constant_o;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g >= 5.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g = 5.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g <= -5.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_g = -5.0F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_e = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' 

  // InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator1' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevRes = 2;

  // InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c =
    QS_InnerRateLoop_ConstB.Constant_p;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c >= 10.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c = 10.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c <= -10.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_c = -10.0F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_h3 = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' 

  // InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator2' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_IC_LOAD = 1U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator2_PrevRes = 2;

  // InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_i = 2;

  // InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d =
    QS_InnerRateLoop_ConstB.Constant_g;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d >= 0.261780113F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.261780113F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d <= -0.261780113F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_d = -0.261780113F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_g = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' 

  // InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a =
    QS_InnerRateLoop_ConstB.Constant_k;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a >= 25.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a = 25.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a <= -25.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_a = -25.0F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_g = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' 

  // InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go =
    QS_InnerRateLoop_ConstB.Constant1;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go >= 50.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go = 50.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go <= -50.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTAT_go = -50.0F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_i = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' 

  // InitializeConditions for DiscreteIntegrator: '<S45>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_hj = 2;

  // InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator1' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_n = 2;

  // InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_l = 2;

  // InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_IC_LOA_f = 1U;
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_b = 2;

  // InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_o = 2;

  // InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_p = 2;

  // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_bj = 2;

  // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_c = 2;

  // InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_m = 2;

  // InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_a = 2;

  // InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ez = 2;

  // InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e =
    QS_InnerRateLoop_ConstB.Constant_i;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e >= 0.261780113F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e = 0.261780113F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e <= -0.261780113F)
    {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_e = -0.261780113F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_gi = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' 

  // InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b =
    QS_InnerRateLoop_ConstB.Constant_n;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b >= 25.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b = 25.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b <= -25.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_DSTAT_b = -25.0F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_PrevR_b = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' 

  // InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p =
    QS_InnerRateLoop_ConstB.Constant1_m;
  if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p >= 50.0F) {
    QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p = 50.0F;
  } else {
    if (QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p <= -50.0F) {
      QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_DSTATE_p = -50.0F;
    }
  }

  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_f = 2;

  // End of InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' 

  // InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevR_ab = 2;

  // InitializeConditions for DiscreteIntegrator: '<S58>/Discrete-Time Integrator' 
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_PrevRe_k = 2;

  // Enable for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTEM_ = 1U;

  // Enable for DiscreteIntegrator: '<S43>/Discrete-Time Integrator'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  // Enable for DiscreteIntegrator: '<S20>/Discrete-Time Integrator1'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTE_n = 1U;

  // Enable for DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_c = 1U;

  // Enable for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator1_SYSTE_j = 1U;

  // Enable for DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
  QS_InnerRateLoop_DWork.DiscreteTimeIntegrator_SYSTEM_j = 1U;
}

// Constructor
untitledModelClass::untitledModelClass()
{
}

// Destructor
untitledModelClass::~untitledModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_QS_InnerRateLoop_T * untitledModelClass::getRTM()
{
  return (&QS_InnerRateLoop_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
