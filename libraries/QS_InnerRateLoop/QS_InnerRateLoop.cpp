/*
 * QS_InnerRateLoop.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "QS_InnerRateLoop".
 *
 * Model version              : 5.20
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Wed Jun 23 17:24:24 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "QS_InnerRateLoop.h"
#include "QS_InnerRateLoop_private.h"

uint32_T plook_u32ff_evencg(real32_T u, real32_T bp0, real32_T bpSpace, uint32_T
  maxIndex, real32_T *fraction)
{
  real32_T fbpIndex;
  real32_T invSpc;
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  invSpc = 1.0F / bpSpace;
  fbpIndex = (u - bp0) * invSpc;
  if (fbpIndex < maxIndex) {
    bpIndex = static_cast<uint32_T>(fbpIndex);
    *fraction = (u - (static_cast<real32_T>(static_cast<uint32_T>(fbpIndex)) *
                      bpSpace + bp0)) * invSpc;
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0F;
  }

  return bpIndex;
}

real32_T intrp1d_fu32fl_pw(uint32_T bpIndex, real32_T frac, const real32_T
  table[])
{
  real32_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
}

uint32_T plook_u32ff_evenca(real32_T u, real32_T bp0, real32_T bpSpace, uint32_T
  maxIndex, real32_T *fraction)
{
  real32_T fbpIndex;
  real32_T invSpc;
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = 0.0F;
  } else {
    invSpc = 1.0F / bpSpace;
    fbpIndex = (u - bp0) * invSpc;
    if (fbpIndex < maxIndex) {
      bpIndex = static_cast<uint32_T>(fbpIndex);
      *fraction = (u - (static_cast<real32_T>(static_cast<uint32_T>(fbpIndex)) *
                        bpSpace + bp0)) * invSpc;
    } else {
      bpIndex = maxIndex;
      *fraction = 0.0F;
    }
  }

  return bpIndex;
}

real32_T intrp1d_fu32fla_pw(uint32_T bpIndex, real32_T frac, const real32_T
  table[], uint32_T maxIndex)
{
  real32_T y;
  real32_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (bpIndex == maxIndex) {
    y = table[bpIndex];
  } else {
    yL_0d0 = table[bpIndex];
    y = (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

uint32_T plook_u32ff_evenxg(real32_T u, real32_T bp0, real32_T bpSpace, uint32_T
  maxIndex, real32_T *fraction)
{
  real32_T fbpIndex;
  real32_T invSpc;
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  invSpc = 1.0F / bpSpace;
  fbpIndex = (u - bp0) * invSpc;
  if (fbpIndex < maxIndex) {
    bpIndex = static_cast<uint32_T>(fbpIndex);
    *fraction = (u - (static_cast<real32_T>(static_cast<uint32_T>(fbpIndex)) *
                      bpSpace + bp0)) * invSpc;
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - (static_cast<real32_T>(maxIndex - 1U) * bpSpace + bp0)) *
      invSpc;
  }

  return bpIndex;
}

uint32_T plook_u32ff_bincg(real32_T u, const real32_T bp[], uint32_T maxIndex,
  real32_T *fraction)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Binary Search */
  bpIdx = maxIndex >> 1U;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  return bpIndex;
}

real32_T intrp2d_fu32fl_pw(const uint32_T bpIndex[], const real32_T frac[],
  const real32_T table[], const uint32_T stride)
{
  real32_T yL_0d0;
  real32_T yL_0d1;
  uint32_T offset_1d;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  yL_0d0 = table[offset_1d];
  yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
  offset_1d += stride;
  yL_0d1 = table[offset_1d];
  return (((table[offset_1d + 1U] - yL_0d1) * frac[0U] + yL_0d1) - yL_0d0) *
    frac[1U] + yL_0d0;
}

/* Model step function */
void QS_InnerRateLoopModelClass::step()
{
  real_T rtb_Gain_on;
  real_T rtb_Sum;
  int32_T i;
  int32_T iU;
  real32_T rtb_uDLookupTable2[36];
  real32_T rtb_uDLookupTable2_k5[16];
  real32_T rtb_Add5_3[9];
  real32_T rtb_Product_b_0[4];
  real32_T rtb_Product_j[4];
  real32_T rtb_Sum1_f[4];
  real32_T fractions[2];
  real32_T fractions_0[2];
  real32_T rtb_Abs;
  real32_T rtb_Abs_i;
  real32_T rtb_Add5_e;
  real32_T rtb_Add5_ky;
  real32_T rtb_Add6_a;
  real32_T rtb_Add6_i;
  real32_T rtb_Add7_d;
  real32_T rtb_DiscreteTimeIntegrator1;
  real32_T rtb_DiscreteTimeIntegrator_bl;
  real32_T rtb_DiscreteTimeIntegrator_cv;
  real32_T rtb_DiscreteTimeIntegrator_di;
  real32_T rtb_DiscreteTimeIntegrator_hs;
  real32_T rtb_DiscreteTimeIntegrator_ia;
  real32_T rtb_DiscreteTimeIntegrator_jh;
  real32_T rtb_DiscreteTimeIntegrator_k0;
  real32_T rtb_DiscreteTimeIntegrator_l;
  real32_T rtb_DiscreteTimeIntegrator_nt;
  real32_T rtb_Gain1;
  real32_T rtb_Gain2;
  real32_T rtb_Gain_ed;
  real32_T rtb_Product;
  real32_T rtb_Product_b_tmp;
  real32_T rtb_Product_b_tmp_0;
  real32_T rtb_Product_b_tmp_1;
  real32_T rtb_Product_ee;
  real32_T rtb_Product_h;
  real32_T rtb_Product_jw;
  real32_T rtb_Product_ke;
  real32_T rtb_Product_ng;
  real32_T rtb_Product_nk;
  real32_T rtb_Product_o;
  real32_T rtb_Product_p;
  real32_T rtb_Saturation8;
  real32_T rtb_Saturation_c;
  real32_T rtb_Sum1_bq;
  real32_T rtb_Sum1_c0;
  real32_T rtb_Sum1_dm;
  real32_T rtb_Sum1_fe;
  real32_T rtb_Sum1_j_idx_0;
  real32_T rtb_Sum1_j_idx_1;
  real32_T rtb_Sum1_j_idx_2;
  real32_T rtb_Sum1_j_idx_3;
  real32_T rtb_Sum2_pj;
  real32_T rtb_Sum3_f;
  real32_T rtb_Sum_of;
  real32_T rtb_Switch2_cz;
  real32_T rtb_Switch_ep;
  real32_T rtb_TrigonometricFunction3;
  real32_T rtb_derivativecutofffrequency_0;
  real32_T rtb_derivativecutofffrequency_b;
  real32_T rtb_uDLookupTable;
  real32_T rtb_uDLookupTable1;
  real32_T rtb_uDLookupTable1_l;
  real32_T rtb_uDLookupTable1_p;
  real32_T rtb_uDLookupTable2_n;
  real32_T rtb_uDLookupTable3;
  real32_T rtb_uDLookupTable_a;
  real32_T rtb_uDLookupTable_cs;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  uint32_T bpIdx;
  uint32_T bpIdx_0;
  boolean_T rtb_Compare_m;
  boolean_T rtb_LogicalOperator2_e;
  boolean_T rtb_LogicalOperator2_g;
  boolean_T rtb_RelationalOperator_b1;

  /* Trigonometry: '<S8>/Trigonometric Function3' incorporates:
   *  Inport: '<Root>/psi_rad'
   *  Trigonometry: '<S71>/Trigonometric Function3'
   */
  rtb_DiscreteTimeIntegrator_l = static_cast<real32_T>(cos(static_cast<real_T>
    (QS_InnerRateLoop_U.psi_rad)));

  /* Trigonometry: '<S8>/Trigonometric Function6' incorporates:
   *  Inport: '<Root>/psi_rad'
   *  Trigonometry: '<S71>/Trigonometric Function6'
   */
  rtb_Product_nk = static_cast<real32_T>(sin(static_cast<real_T>
    (QS_InnerRateLoop_U.psi_rad)));

  /* Sum: '<S8>/Add5' incorporates:
   *  Inport: '<Root>/vD_fps (KF)'
   *  Inport: '<Root>/vE_fps (KF)'
   *  Inport: '<Root>/vN_fps (KF)'
   *  Product: '<S8>/Divide'
   *  Product: '<S8>/Divide2'
   *  Product: '<S8>/Divide6'
   *  Trigonometry: '<S8>/Trigonometric Function3'
   *  Trigonometry: '<S8>/Trigonometric Function6'
   */
  rtb_Add5_e = (QS_InnerRateLoop_ConstB.TrigonometricFunction2 *
                rtb_DiscreteTimeIntegrator_l * QS_InnerRateLoop_U.vN_fpsKF +
                QS_InnerRateLoop_ConstB.TrigonometricFunction2 * rtb_Product_nk *
                QS_InnerRateLoop_U.vE_fpsKF) +
    -QS_InnerRateLoop_ConstB.TrigonometricFunction5 *
    QS_InnerRateLoop_U.vD_fpsKF;

  /* Product: '<S8>/Divide1' incorporates:
   *  Product: '<S8>/Divide7'
   */
  rtb_uDLookupTable_cs = QS_InnerRateLoop_ConstB.TrigonometricFunction4 *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5;

  /* Sum: '<S8>/Add6' incorporates:
   *  Inport: '<Root>/vD_fps (KF)'
   *  Inport: '<Root>/vE_fps (KF)'
   *  Inport: '<Root>/vN_fps (KF)'
   *  Product: '<S8>/Divide1'
   *  Product: '<S8>/Divide11'
   *  Product: '<S8>/Divide13'
   *  Product: '<S8>/Divide15'
   *  Product: '<S8>/Divide3'
   *  Product: '<S8>/Divide7'
   *  Product: '<S8>/Divide8'
   *  Sum: '<S8>/Add1'
   *  Sum: '<S8>/Add3'
   *  Trigonometry: '<S8>/Trigonometric Function3'
   *  Trigonometry: '<S8>/Trigonometric Function6'
   */
  rtb_Add6_i = ((rtb_uDLookupTable_cs * rtb_DiscreteTimeIntegrator_l -
                 QS_InnerRateLoop_ConstB.TrigonometricFunction1 * rtb_Product_nk)
                * QS_InnerRateLoop_U.vN_fpsKF + (rtb_uDLookupTable_cs *
    rtb_Product_nk + QS_InnerRateLoop_ConstB.TrigonometricFunction1 *
    rtb_DiscreteTimeIntegrator_l) * QS_InnerRateLoop_U.vE_fpsKF) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction4 *
    QS_InnerRateLoop_ConstB.TrigonometricFunction2 * QS_InnerRateLoop_U.vD_fpsKF;

  /* Sqrt: '<Root>/Sqrt1' incorporates:
   *  Math: '<Root>/Math Function3'
   *  Math: '<Root>/Math Function4'
   *  Sum: '<Root>/Add1'
   *
   * About '<Root>/Math Function3':
   *  Operator: magnitude^2
   *
   * About '<Root>/Math Function4':
   *  Operator: magnitude^2
   */
  rtb_Saturation8 = static_cast<real32_T>(sqrt(static_cast<real_T>(rtb_Add5_e *
    rtb_Add5_e + rtb_Add6_i * rtb_Add6_i)));

  /* Saturate: '<Root>/Saturation8' */
  if (rtb_Saturation8 > 6.5F) {
    rtb_Saturation8 = 6.5F;
  } else if (rtb_Saturation8 < 0.0F) {
    rtb_Saturation8 = 0.0F;
  }

  /* End of Saturate: '<Root>/Saturation8' */

  /* Lookup_n-D: '<S63>/1-D Lookup Table2' incorporates:
   *  Constant: '<S63>/Constant'
   *  Saturate: '<Root>/Saturation8'
   */
  bpIndices[0U] = plook_u32ff_bincg(rtb_Saturation8,
    QS_InnerRateLoop_ConstP.pooled7, 4U, &rtb_Abs_i);
  fractions[0U] = rtb_Abs_i;
  for (iU = 0; iU < 36; iU++) {
    bpIndices[1U] = plook_u32ff_bincg(QS_InnerRateLoop_ConstP.pooled17[iU],
      QS_InnerRateLoop_ConstP.pooled17, 35U, &rtb_Abs_i);
    fractions[1U] = rtb_Abs_i;
    rtb_uDLookupTable2[iU] = intrp2d_fu32fl_pw(bpIndices, fractions,
      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_g, 5U);
  }

  /* End of Lookup_n-D: '<S63>/1-D Lookup Table2' */

  /* Lookup_n-D: '<S62>/1-D Lookup Table2' incorporates:
   *  Constant: '<S62>/Constant'
   *  Saturate: '<Root>/Saturation8'
   */
  bpIndices_0[0U] = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U,
    &rtb_Abs_i);
  fractions_0[0U] = rtb_Abs_i;
  for (iU = 0; iU < 16; iU++) {
    bpIndices_0[1U] = plook_u32ff_evencg(QS_InnerRateLoop_ConstP.pooled18[iU],
      1.0F, 1.0F, 15U, &rtb_Abs_i);
    fractions_0[1U] = rtb_Abs_i;
    rtb_uDLookupTable2_k5[iU] = intrp2d_fu32fl_pw(bpIndices_0, fractions_0,
      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_b, 5U);
  }

  /* End of Lookup_n-D: '<S62>/1-D Lookup Table2' */

  /* Trigonometry: '<S7>/Trigonometric Function2' incorporates:
   *  Inport: '<Root>/theta_rad'
   *  Trigonometry: '<S6>/Trigonometric Function2'
   */
  rtb_DiscreteTimeIntegrator_jh = static_cast<real32_T>(cos(static_cast<real_T>
    (QS_InnerRateLoop_U.theta_rad)));

  /* Product: '<S8>/Divide4' incorporates:
   *  Product: '<S8>/Divide9'
   */
  rtb_uDLookupTable_cs = QS_InnerRateLoop_ConstB.TrigonometricFunction1 *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5;

  /* Sum: '<S8>/Add7' incorporates:
   *  Inport: '<Root>/vD_fps (KF)'
   *  Inport: '<Root>/vE_fps (KF)'
   *  Inport: '<Root>/vN_fps (KF)'
   *  Product: '<S8>/Divide10'
   *  Product: '<S8>/Divide12'
   *  Product: '<S8>/Divide14'
   *  Product: '<S8>/Divide16'
   *  Product: '<S8>/Divide4'
   *  Product: '<S8>/Divide5'
   *  Product: '<S8>/Divide9'
   *  Sum: '<S8>/Add2'
   *  Sum: '<S8>/Add4'
   *  Trigonometry: '<S8>/Trigonometric Function3'
   *  Trigonometry: '<S8>/Trigonometric Function6'
   */
  rtb_uDLookupTable_cs = ((rtb_uDLookupTable_cs * rtb_DiscreteTimeIntegrator_l +
    QS_InnerRateLoop_ConstB.TrigonometricFunction4 * rtb_Product_nk) *
    QS_InnerRateLoop_U.vN_fpsKF + (rtb_uDLookupTable_cs * rtb_Product_nk -
    QS_InnerRateLoop_ConstB.TrigonometricFunction4 *
    rtb_DiscreteTimeIntegrator_l) * QS_InnerRateLoop_U.vE_fpsKF) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction1 *
    QS_InnerRateLoop_ConstB.TrigonometricFunction2 * QS_InnerRateLoop_U.vD_fpsKF;

  /* Saturate: '<S69>/Saturation' incorporates:
   *  Inport: '<Root>/theta_rad'
   *  Trigonometry: '<S7>/Trigonometric Function5'
   */
  QS_InnerRateLoop_Y.Vnorth_corr = static_cast<real32_T>(sin(static_cast<real_T>
    (QS_InnerRateLoop_U.theta_rad)));

  /* SignalConversion generated from: '<S63>/Product' incorporates:
   *  Product: '<S7>/Divide'
   *  Product: '<S7>/Divide2'
   *  Product: '<S7>/Divide6'
   *  Sum: '<S7>/Add5'
   *  Trigonometry: '<S7>/Trigonometric Function2'
   */
  rtb_Add5_3[0] = (rtb_DiscreteTimeIntegrator_jh *
                   QS_InnerRateLoop_ConstB.TrigonometricFunction3 * rtb_Add5_e +
                   rtb_DiscreteTimeIntegrator_jh *
                   QS_InnerRateLoop_ConstB.TrigonometricFunction6 * rtb_Add6_i)
    + -QS_InnerRateLoop_Y.Vnorth_corr * rtb_uDLookupTable_cs;

  /* Trigonometry: '<S7>/Trigonometric Function4' incorporates:
   *  Inport: '<Root>/phi_rad'
   *  Trigonometry: '<S6>/Trigonometric Function4'
   */
  rtb_TrigonometricFunction3 = static_cast<real32_T>(sin(static_cast<real_T>
    (QS_InnerRateLoop_U.phi_rad)));

  /* Trigonometry: '<S7>/Trigonometric Function1' incorporates:
   *  Inport: '<Root>/phi_rad'
   *  Trigonometry: '<S6>/Trigonometric Function1'
   */
  rtb_Gain2 = static_cast<real32_T>(cos(static_cast<real_T>
    (QS_InnerRateLoop_U.phi_rad)));

  /* Product: '<S7>/Divide1' incorporates:
   *  Product: '<S7>/Divide7'
   *  Trigonometry: '<S7>/Trigonometric Function4'
   */
  rtb_Switch_ep = rtb_TrigonometricFunction3 * QS_InnerRateLoop_Y.Vnorth_corr;

  /* Product: '<S7>/Divide11' incorporates:
   *  Product: '<S6>/Divide11'
   *  Trigonometry: '<S7>/Trigonometric Function2'
   *  Trigonometry: '<S7>/Trigonometric Function4'
   */
  rtb_Sum_of = rtb_TrigonometricFunction3 * rtb_DiscreteTimeIntegrator_jh;

  /* SignalConversion generated from: '<S63>/Product' incorporates:
   *  Product: '<S7>/Divide1'
   *  Product: '<S7>/Divide11'
   *  Product: '<S7>/Divide13'
   *  Product: '<S7>/Divide15'
   *  Product: '<S7>/Divide3'
   *  Product: '<S7>/Divide7'
   *  Product: '<S7>/Divide8'
   *  Sum: '<S7>/Add1'
   *  Sum: '<S7>/Add3'
   *  Sum: '<S7>/Add6'
   *  Trigonometry: '<S7>/Trigonometric Function1'
   */
  rtb_Add5_3[1] = ((rtb_Switch_ep *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction3 - rtb_Gain2 *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction6) * rtb_Add5_e
                   + (rtb_Switch_ep *
                      QS_InnerRateLoop_ConstB.TrigonometricFunction6 + rtb_Gain2
                      * QS_InnerRateLoop_ConstB.TrigonometricFunction3) *
                   rtb_Add6_i) + rtb_Sum_of * rtb_uDLookupTable_cs;

  /* Product: '<S7>/Divide4' incorporates:
   *  Product: '<S7>/Divide9'
   *  Trigonometry: '<S7>/Trigonometric Function1'
   */
  rtb_Switch_ep = rtb_Gain2 * QS_InnerRateLoop_Y.Vnorth_corr;

  /* Product: '<S7>/Divide12' incorporates:
   *  Product: '<S6>/Divide12'
   *  Trigonometry: '<S7>/Trigonometric Function1'
   *  Trigonometry: '<S7>/Trigonometric Function2'
   */
  rtb_DiscreteTimeIntegrator_jh *= rtb_Gain2;

  /* SignalConversion generated from: '<S63>/Product' incorporates:
   *  Product: '<S7>/Divide10'
   *  Product: '<S7>/Divide12'
   *  Product: '<S7>/Divide14'
   *  Product: '<S7>/Divide16'
   *  Product: '<S7>/Divide4'
   *  Product: '<S7>/Divide5'
   *  Product: '<S7>/Divide9'
   *  Sum: '<S7>/Add2'
   *  Sum: '<S7>/Add4'
   *  Sum: '<S7>/Add7'
   *  Trigonometry: '<S7>/Trigonometric Function4'
   */
  rtb_Add5_3[2] = ((rtb_Switch_ep *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction3 +
                    rtb_TrigonometricFunction3 *
                    QS_InnerRateLoop_ConstB.TrigonometricFunction6) * rtb_Add5_e
                   + (rtb_Switch_ep *
                      QS_InnerRateLoop_ConstB.TrigonometricFunction6 -
                      rtb_TrigonometricFunction3 *
                      QS_InnerRateLoop_ConstB.TrigonometricFunction3) *
                   rtb_Add6_i) + rtb_DiscreteTimeIntegrator_jh *
    rtb_uDLookupTable_cs;

  /* Sum: '<S99>/Sum2' incorporates:
   *  Delay: '<S99>/Delay1'
   *  Delay: '<S99>/Delay2'
   *  Inport: '<Root>/CH8_flag'
   *  RelationalOperator: '<S99>/Relational Operator2'
   */
  QS_InnerRateLoop_DW.Delay2_DSTATE += static_cast<real32_T>(static_cast<int32_T>
    (QS_InnerRateLoop_U.CH8_flag) > static_cast<int32_T>
    (QS_InnerRateLoop_DW.Delay1_DSTATE));

  /* Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S101>/Enable'
   */
  /* Logic: '<S14>/Logical Operator3' incorporates:
   *  Inport: '<Root>/CH8_flag'
   *  Inport: '<Root>/input_col'
   *  Inport: '<Root>/input_lat'
   *  Inport: '<Root>/input_lon'
   *  Inport: '<Root>/input_ped'
   *  Inport: '<S101>/col'
   *  Inport: '<S101>/lat'
   *  Inport: '<S101>/lon'
   *  Inport: '<S101>/ped'
   */
  if (!QS_InnerRateLoop_U.CH8_flag) {
    QS_InnerRateLoop_B.lon = QS_InnerRateLoop_U.input_lon;
    QS_InnerRateLoop_B.lat = QS_InnerRateLoop_U.input_lat;
    QS_InnerRateLoop_B.col_h = QS_InnerRateLoop_U.input_col;
    QS_InnerRateLoop_B.ped = QS_InnerRateLoop_U.input_ped;
  }

  /* End of Logic: '<S14>/Logical Operator3' */
  /* End of Outputs for SubSystem: '<S14>/Enabled Subsystem1' */

  /* Sum: '<S14>/Sum1' incorporates:
   *  Inport: '<Root>/input_lon'
   */
  rtb_TrigonometricFunction3 = QS_InnerRateLoop_U.input_lon -
    QS_InnerRateLoop_B.lon;

  /* DeadZone: '<S100>/Dead Zone2' */
  if (rtb_TrigonometricFunction3 > 0.05F) {
    rtb_Switch_ep = rtb_TrigonometricFunction3 - 0.05F;
  } else if (rtb_TrigonometricFunction3 >= -0.05F) {
    rtb_Switch_ep = 0.0F;
  } else {
    rtb_Switch_ep = rtb_TrigonometricFunction3 - -0.05F;
  }

  /* End of DeadZone: '<S100>/Dead Zone2' */

  /* Sum: '<S14>/Sum2' incorporates:
   *  Inport: '<Root>/input_lat'
   */
  rtb_TrigonometricFunction3 = QS_InnerRateLoop_U.input_lat -
    QS_InnerRateLoop_B.lat;

  /* DeadZone: '<S100>/Dead Zone1' */
  if (rtb_TrigonometricFunction3 > 0.05F) {
    rtb_Gain2 = rtb_TrigonometricFunction3 - 0.05F;
  } else if (rtb_TrigonometricFunction3 >= -0.05F) {
    rtb_Gain2 = 0.0F;
  } else {
    rtb_Gain2 = rtb_TrigonometricFunction3 - -0.05F;
  }

  /* End of DeadZone: '<S100>/Dead Zone1' */

  /* Sum: '<S14>/Sum3' incorporates:
   *  Inport: '<Root>/input_col'
   */
  rtb_TrigonometricFunction3 = QS_InnerRateLoop_U.input_col -
    QS_InnerRateLoop_B.col_h;

  /* DeadZone: '<S100>/Dead Zone3' */
  if (rtb_TrigonometricFunction3 > 0.05F) {
    rtb_DiscreteTimeIntegrator1 = rtb_TrigonometricFunction3 - 0.05F;
  } else if (rtb_TrigonometricFunction3 >= -0.05F) {
    rtb_DiscreteTimeIntegrator1 = 0.0F;
  } else {
    rtb_DiscreteTimeIntegrator1 = rtb_TrigonometricFunction3 - -0.05F;
  }

  /* End of DeadZone: '<S100>/Dead Zone3' */

  /* Sum: '<S14>/Sum4' incorporates:
   *  Inport: '<Root>/input_ped'
   */
  rtb_TrigonometricFunction3 = QS_InnerRateLoop_U.input_ped -
    QS_InnerRateLoop_B.ped;

  /* DeadZone: '<S100>/Dead Zone4' */
  if (rtb_TrigonometricFunction3 > 0.05F) {
    rtb_TrigonometricFunction3 -= 0.05F;
  } else if (rtb_TrigonometricFunction3 >= -0.05F) {
    rtb_TrigonometricFunction3 = 0.0F;
  } else {
    rtb_TrigonometricFunction3 -= -0.05F;
  }

  /* End of DeadZone: '<S100>/Dead Zone4' */

  /* Logic: '<S14>/Logical Operator2' incorporates:
   *  Abs: '<S100>/Abs'
   *  Abs: '<S100>/Abs1'
   *  Abs: '<S100>/Abs2'
   *  Abs: '<S100>/Abs3'
   *  Constant: '<S102>/Constant'
   *  Constant: '<S103>/Constant'
   *  Constant: '<S104>/Constant'
   *  Constant: '<S105>/Constant'
   *  Inport: '<Root>/CH8_flag'
   *  Logic: '<S100>/Logical Operator'
   *  Logic: '<S100>/Logical Operator1'
   *  RelationalOperator: '<S102>/Compare'
   *  RelationalOperator: '<S103>/Compare'
   *  RelationalOperator: '<S104>/Compare'
   *  RelationalOperator: '<S105>/Compare'
   */
  rtb_LogicalOperator2_g = ((!(static_cast<real32_T>(fabs(static_cast<real_T>
    (rtb_Switch_ep))) > 0.0F)) && (!(static_cast<real32_T>(fabs
    (static_cast<real_T>(rtb_Gain2))) > 0.0F)) && (!(static_cast<real32_T>(fabs(
    static_cast<real_T>(rtb_DiscreteTimeIntegrator1))) > 0.0F)) && (!(
    static_cast<real32_T>(fabs(static_cast<real_T>(rtb_TrigonometricFunction3)))
    > 0.0F)) && QS_InnerRateLoop_U.CH8_flag);

  /* Logic: '<S14>/Logical Operator1' incorporates:
   *  Abs: '<S14>/Abs'
   *  Constant: '<S98>/Constant'
   *  RelationalOperator: '<S98>/Compare'
   */
  QS_InnerRateLoop_Y.TrajectoryON = ((static_cast<real32_T>(fabs
    (static_cast<real_T>(QS_InnerRateLoop_DW.Delay2_DSTATE))) > 0.0F) &&
    rtb_LogicalOperator2_g);

  /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
  if (QS_InnerRateLoop_Y.TrajectoryON &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Lookup_n-D: '<S91>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* DiscreteIntegrator: '<S68>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator2'
   *  Inport: '<Root>/pos North (KF)'
   */
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_m =
      QS_InnerRateLoop_U.posNorthKF;
  }

  rtb_RelationalOperator_b1 = !QS_InnerRateLoop_Y.TrajectoryON;
  if ((QS_InnerRateLoop_Y.TrajectoryON &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_a <= 0)) ||
      (rtb_RelationalOperator_b1 &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_a == 1))) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_m =
      QS_InnerRateLoop_U.posNorthKF;
  }

  /* Product: '<S91>/Product' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
   *  Inport: '<Root>/pos North (KF)'
   *  Lookup_n-D: '<S91>/1-D Lookup Table2'
   *  Sum: '<S76>/Sum'
   */
  rtb_Product = (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_m -
                 QS_InnerRateLoop_U.posNorthKF) * intrp1d_fu32fl_pw(bpIdx,
    rtb_Abs_i, QS_InnerRateLoop_ConstP.pooled20);

  /* Saturate: '<S69>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator'
   *  Sum: '<S76>/Sum1'
   */
  QS_InnerRateLoop_Y.Vnorth_corr =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_a + rtb_Product;

  /* Saturate: '<S69>/Saturation' */
  if (QS_InnerRateLoop_Y.Vnorth_corr > 10.0F) {
    /* Saturate: '<S69>/Saturation' */
    QS_InnerRateLoop_Y.Vnorth_corr = 10.0F;
  } else if (QS_InnerRateLoop_Y.Vnorth_corr < -10.0F) {
    /* Saturate: '<S69>/Saturation' */
    QS_InnerRateLoop_Y.Vnorth_corr = -10.0F;
  }

  /* End of Saturate: '<S69>/Saturation' */

  /* DiscreteIntegrator: '<S90>/Discrete-Time Integrator' */
  if (QS_InnerRateLoop_Y.TrajectoryON &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_o <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_h = 0.0F;
  }

  /* Lookup_n-D: '<S88>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* DiscreteIntegrator: '<S68>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/pos East (KF)'
   */
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTATE =
      QS_InnerRateLoop_U.posEastKF;
  }

  if ((QS_InnerRateLoop_Y.TrajectoryON &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevRes <= 0)) ||
      (rtb_RelationalOperator_b1 &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevRes == 1))) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTATE =
      QS_InnerRateLoop_U.posEastKF;
  }

  /* Product: '<S88>/Product' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator1'
   *  Inport: '<Root>/pos East (KF)'
   *  Lookup_n-D: '<S88>/1-D Lookup Table2'
   *  Sum: '<S75>/Sum'
   */
  rtb_Product_ng = (QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTATE -
                    QS_InnerRateLoop_U.posEastKF) * intrp1d_fu32fl_pw(bpIdx,
    rtb_Abs_i, QS_InnerRateLoop_ConstP.pooled20);

  /* Saturate: '<S69>/Saturation1' incorporates:
   *  DiscreteIntegrator: '<S90>/Discrete-Time Integrator'
   *  Sum: '<S75>/Sum1'
   */
  QS_InnerRateLoop_Y.Veast_corr =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_h + rtb_Product_ng;

  /* Saturate: '<S69>/Saturation1' */
  if (QS_InnerRateLoop_Y.Veast_corr > 10.0F) {
    /* Saturate: '<S69>/Saturation1' */
    QS_InnerRateLoop_Y.Veast_corr = 10.0F;
  } else if (QS_InnerRateLoop_Y.Veast_corr < -10.0F) {
    /* Saturate: '<S69>/Saturation1' */
    QS_InnerRateLoop_Y.Veast_corr = -10.0F;
  }

  /* End of Saturate: '<S69>/Saturation1' */

  /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  if (QS_InnerRateLoop_Y.TrajectoryON &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_b <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_c = 0.0F;
  }

  /* Lookup_n-D: '<S86>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* DiscreteIntegrator: '<S68>/Discrete-Time Integrator2' incorporates:
   *  Inport: '<Root>/pos Down (KF)'
   */
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_IC_LOAD != 0) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_DSTATE =
      QS_InnerRateLoop_U.posDownKF;
  }

  if ((QS_InnerRateLoop_Y.TrajectoryON &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_PrevRes <= 0)) ||
      (rtb_RelationalOperator_b1 &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_PrevRes == 1))) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_DSTATE =
      QS_InnerRateLoop_U.posDownKF;
  }

  /* Product: '<S86>/Product' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator2'
   *  Inport: '<Root>/pos Down (KF)'
   *  Lookup_n-D: '<S86>/1-D Lookup Table2'
   *  Sum: '<S74>/Sum'
   */
  rtb_Product_ee = (QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_DSTATE -
                    QS_InnerRateLoop_U.posDownKF) * intrp1d_fu32fl_pw(bpIdx,
    rtb_Abs_i, QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_k);

  /* Saturate: '<S69>/Saturation2' incorporates:
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Sum: '<S74>/Sum1'
   */
  QS_InnerRateLoop_Y.Vdown_corr =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_c + rtb_Product_ee;

  /* Saturate: '<S69>/Saturation2' */
  if (QS_InnerRateLoop_Y.Vdown_corr > 15.0F) {
    /* Saturate: '<S69>/Saturation2' */
    QS_InnerRateLoop_Y.Vdown_corr = 15.0F;
  } else if (QS_InnerRateLoop_Y.Vdown_corr < -15.0F) {
    /* Saturate: '<S69>/Saturation2' */
    QS_InnerRateLoop_Y.Vdown_corr = -15.0F;
  }

  /* End of Saturate: '<S69>/Saturation2' */

  /* Product: '<S15>/Product2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Sum: '<S15>/Sum21'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE = (static_cast<real32_T>
    (QS_InnerRateLoop_Y.TrajectoryON) + QS_InnerRateLoop_DW.UnitDelay_DSTATE) *
    static_cast<real32_T>(QS_InnerRateLoop_Y.TrajectoryON);

  /* Gain: '<S15>/Gain2' */
  rtb_Gain2 = 0.0025F * QS_InnerRateLoop_DW.UnitDelay_DSTATE;

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   *  Sum: '<S15>/Sum'
   */
  if (rtb_Gain2 >= 20.0F) {
    rtb_TrigonometricFunction3 = rtb_Gain2 - 20.0F;
  } else {
    rtb_TrigonometricFunction3 = 0.0F;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Sum: '<Root>/Sum4' incorporates:
   *  Inport: '<Root>/Rp'
   *  Inport: '<Root>/Rv'
   *  Product: '<S15>/Divide1'
   */
  QS_InnerRateLoop_Y.vehheadingcmd = rtb_TrigonometricFunction3 /
    QS_InnerRateLoop_U.Rv * QS_InnerRateLoop_U.Rp;

  /* Lookup_n-D: '<S15>/1-D Lookup Table3' incorporates:
   *  Sum: '<Root>/Sum4'
   */
  bpIdx = plook_u32ff_evenca(QS_InnerRateLoop_Y.vehheadingcmd, 0.0F, 0.2F, 64U,
    &rtb_Abs_i);
  rtb_uDLookupTable3 = intrp1d_fu32fla_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.pooled26, 64U);

  /* Gain: '<S15>/Gain1' */
  rtb_Sum3_f = 0.0174532924F * rtb_uDLookupTable3;

  /* Trigonometry: '<S106>/Trigonometric Function3' */
  rtb_derivativecutofffrequency_b = static_cast<real32_T>(cos(static_cast<real_T>
    (rtb_Sum3_f)));

  /* Trigonometry: '<S106>/Trigonometric Function6' */
  rtb_Sum3_f = static_cast<real32_T>(sin(static_cast<real_T>(rtb_Sum3_f)));

  /* Lookup_n-D: '<S15>/1-D Lookup Table1' incorporates:
   *  Sum: '<Root>/Sum4'
   */
  bpIdx = plook_u32ff_evenca(QS_InnerRateLoop_Y.vehheadingcmd, 0.0F, 0.2F, 64U,
    &rtb_Abs_i);

  /* Sum: '<S24>/Sum4' incorporates:
   *  Inport: '<Root>/Rv'
   *  Lookup_n-D: '<S15>/1-D Lookup Table1'
   *  Product: '<S15>/Divide3'
   */
  QS_InnerRateLoop_Y.theta_cmd = intrp1d_fu32fla_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable1_tableData, 64U) /
    QS_InnerRateLoop_U.Rv;

  /* Lookup_n-D: '<S15>/1-D Lookup Table' incorporates:
   *  Sum: '<Root>/Sum4'
   */
  bpIdx = plook_u32ff_evenca(QS_InnerRateLoop_Y.vehheadingcmd, 0.0F, 0.2F, 64U,
    &rtb_Abs_i);

  /* Product: '<S15>/Divide2' incorporates:
   *  Inport: '<Root>/Rv'
   *  Lookup_n-D: '<S15>/1-D Lookup Table'
   */
  rtb_Add5_ky = intrp1d_fu32fla_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.pooled26, 64U) / QS_InnerRateLoop_U.Rv;

  /* Lookup_n-D: '<S15>/1-D Lookup Table2' incorporates:
   *  Sum: '<Root>/Sum4'
   */
  bpIdx = plook_u32ff_evenca(QS_InnerRateLoop_Y.vehheadingcmd, 0.0F, 0.2F, 64U,
    &rtb_Abs_i);

  /* Sum: '<Root>/Sum4' incorporates:
   *  Inport: '<Root>/Rv'
   *  Lookup_n-D: '<S15>/1-D Lookup Table2'
   *  Product: '<S15>/Divide4'
   */
  QS_InnerRateLoop_Y.vehheadingcmd = intrp1d_fu32fla_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_bf, 64U) /
    QS_InnerRateLoop_U.Rv;

  /* Product: '<S106>/Divide4' incorporates:
   *  Product: '<S106>/Divide9'
   */
  rtb_TrigonometricFunction3 = QS_InnerRateLoop_ConstB.TrigonometricFunction1_k *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5_o;

  /* Sum: '<S106>/Add7' incorporates:
   *  Product: '<S106>/Divide10'
   *  Product: '<S106>/Divide12'
   *  Product: '<S106>/Divide14'
   *  Product: '<S106>/Divide16'
   *  Product: '<S106>/Divide4'
   *  Product: '<S106>/Divide5'
   *  Product: '<S106>/Divide9'
   *  Sum: '<S106>/Add2'
   *  Sum: '<S106>/Add4'
   */
  rtb_Add7_d = ((rtb_TrigonometricFunction3 * rtb_derivativecutofffrequency_b +
                 QS_InnerRateLoop_ConstB.TrigonometricFunction4_n * rtb_Sum3_f) *
                QS_InnerRateLoop_Y.theta_cmd + (rtb_TrigonometricFunction3 *
    rtb_Sum3_f - QS_InnerRateLoop_ConstB.TrigonometricFunction4_n *
    rtb_derivativecutofffrequency_b) * rtb_Add5_ky) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction1_k *
    QS_InnerRateLoop_ConstB.TrigonometricFunction2_l *
    QS_InnerRateLoop_Y.vehheadingcmd;

  /* Product: '<S71>/Divide4' incorporates:
   *  Product: '<S71>/Divide9'
   */
  rtb_TrigonometricFunction3 = QS_InnerRateLoop_ConstB.TrigonometricFunction1_g *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5_j;

  /* Sum: '<S69>/Sum2' incorporates:
   *  Product: '<S71>/Divide10'
   *  Product: '<S71>/Divide12'
   *  Product: '<S71>/Divide14'
   *  Product: '<S71>/Divide16'
   *  Product: '<S71>/Divide4'
   *  Product: '<S71>/Divide5'
   *  Product: '<S71>/Divide9'
   *  Sum: '<S71>/Add2'
   *  Sum: '<S71>/Add4'
   *  Sum: '<S71>/Add7'
   */
  rtb_Sum2_pj = (((rtb_TrigonometricFunction3 * rtb_DiscreteTimeIntegrator_l +
                   QS_InnerRateLoop_ConstB.TrigonometricFunction4_km *
                   rtb_Product_nk) * QS_InnerRateLoop_Y.Vnorth_corr +
                  (rtb_TrigonometricFunction3 * rtb_Product_nk -
                   QS_InnerRateLoop_ConstB.TrigonometricFunction4_km *
                   rtb_DiscreteTimeIntegrator_l) * QS_InnerRateLoop_Y.Veast_corr)
                 + QS_InnerRateLoop_ConstB.TrigonometricFunction1_g *
                 QS_InnerRateLoop_ConstB.TrigonometricFunction2_ak *
                 QS_InnerRateLoop_Y.Vdown_corr) + rtb_Add7_d;

  /* Saturate: '<S16>/Saturation2' */
  if (rtb_Sum2_pj > 15.0F) {
    rtb_Abs = 15.0F;
  } else if (rtb_Sum2_pj < -15.0F) {
    rtb_Abs = -15.0F;
  } else {
    rtb_Abs = rtb_Sum2_pj;
  }

  /* End of Saturate: '<S16>/Saturation2' */

  /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S107>/Enable'
   */
  /* Logic: '<S16>/Logical Operator2' incorporates:
   *  Inport: '<Root>/engage'
   *  Inport: '<Root>/input_col'
   *  Inport: '<S107>/col'
   */
  if (!QS_InnerRateLoop_U.engage) {
    QS_InnerRateLoop_B.col = QS_InnerRateLoop_U.input_col;
  }

  /* End of Logic: '<S16>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem1' */

  /* Switch: '<S114>/Switch' incorporates:
   *  Gain: '<S16>/wcmd'
   */
  if (QS_InnerRateLoop_Y.TrajectoryON) {
    rtb_Switch_ep = rtb_Abs;
  } else {
    /* Sum: '<S16>/Sum2' incorporates:
     *  Inport: '<Root>/input_col'
     */
    rtb_TrigonometricFunction3 = QS_InnerRateLoop_U.input_col -
      QS_InnerRateLoop_B.col;

    /* DeadZone: '<S16>/Dead Zone' */
    if (rtb_TrigonometricFunction3 > 0.05F) {
      rtb_TrigonometricFunction3 -= 0.05F;
    } else if (rtb_TrigonometricFunction3 >= -0.05F) {
      rtb_TrigonometricFunction3 = 0.0F;
    } else {
      rtb_TrigonometricFunction3 -= -0.05F;
    }

    /* End of DeadZone: '<S16>/Dead Zone' */
    rtb_Switch_ep = -6.0F * rtb_TrigonometricFunction3;
  }

  /* End of Switch: '<S114>/Switch' */

  /* Switch: '<S114>/Switch1' incorporates:
   *  RelationalOperator: '<S114>/Relational Operator'
   *  UnitDelay: '<S114>/Unit Delay'
   */
  if (QS_InnerRateLoop_DW.UnitDelay_DSTATE_ax != QS_InnerRateLoop_Y.TrajectoryON)
  {
    /* Sum: '<S22>/Sum3' incorporates:
     *  Sum: '<S114>/Sum1'
     *  UnitDelay: '<S114>/Unit Delay2'
     */
    QS_InnerRateLoop_DW.UnitDelay1_DSTATE =
      QS_InnerRateLoop_DW.UnitDelay2_DSTATE - rtb_Switch_ep;
  }

  /* End of Switch: '<S114>/Switch1' */

  /* Saturate: '<S114>/Saturation' */
  if (QS_InnerRateLoop_DW.UnitDelay1_DSTATE > 0.0025F) {
    rtb_TrigonometricFunction3 = 0.0025F;
  } else if (QS_InnerRateLoop_DW.UnitDelay1_DSTATE < -0.0025F) {
    rtb_TrigonometricFunction3 = -0.0025F;
  } else {
    rtb_TrigonometricFunction3 = QS_InnerRateLoop_DW.UnitDelay1_DSTATE;
  }

  /* End of Saturate: '<S114>/Saturation' */

  /* Sum: '<S114>/Sum' */
  rtb_TrigonometricFunction3 = QS_InnerRateLoop_DW.UnitDelay1_DSTATE -
    rtb_TrigonometricFunction3;

  /* Sum: '<S114>/Sum2' */
  QS_InnerRateLoop_DW.UnitDelay2_DSTATE = rtb_Switch_ep +
    rtb_TrigonometricFunction3;

  /* Lookup_n-D: '<S41>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Product: '<S41>/Product' incorporates:
   *  Lookup_n-D: '<S41>/1-D Lookup Table2'
   *  Sum: '<S38>/Sum'
   *  UnitDelay: '<S38>/Unit Delay'
   */
  rtb_Switch_ep = (QS_InnerRateLoop_DW.UnitDelay2_DSTATE -
                   QS_InnerRateLoop_DW.UnitDelay_DSTATE_a) / intrp1d_fu32fl_pw
    (bpIdx, rtb_Abs_i, QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_j);

  /* Product: '<S106>/Divide1' incorporates:
   *  Product: '<S106>/Divide7'
   */
  rtb_DiscreteTimeIntegrator1 = QS_InnerRateLoop_ConstB.TrigonometricFunction4_n
    * QS_InnerRateLoop_ConstB.TrigonometricFunction5_o;

  /* Sum: '<S106>/Add6' incorporates:
   *  Product: '<S106>/Divide1'
   *  Product: '<S106>/Divide11'
   *  Product: '<S106>/Divide13'
   *  Product: '<S106>/Divide15'
   *  Product: '<S106>/Divide3'
   *  Product: '<S106>/Divide7'
   *  Product: '<S106>/Divide8'
   *  Sum: '<S106>/Add1'
   *  Sum: '<S106>/Add3'
   */
  rtb_Add6_a = ((rtb_DiscreteTimeIntegrator1 * rtb_derivativecutofffrequency_b -
                 QS_InnerRateLoop_ConstB.TrigonometricFunction1_k * rtb_Sum3_f) *
                QS_InnerRateLoop_Y.theta_cmd + (rtb_DiscreteTimeIntegrator1 *
    rtb_Sum3_f + QS_InnerRateLoop_ConstB.TrigonometricFunction1_k *
    rtb_derivativecutofffrequency_b) * rtb_Add5_ky) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction4_n *
    QS_InnerRateLoop_ConstB.TrigonometricFunction2_l *
    QS_InnerRateLoop_Y.vehheadingcmd;

  /* Gain: '<S69>/Gain1' */
  rtb_Gain1 = 0.0F * rtb_Add6_a;

  /* DiscreteIntegrator: '<S31>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevR_g <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_o = 0.0F;
  }

  rtb_DiscreteTimeIntegrator1 =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_o;

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Constant'
   */
  if (QS_InnerRateLoop_Y.TrajectoryON) {
    rtb_Sum1_c0 = rtb_Gain1;
  } else {
    rtb_Sum1_c0 = 0.0F;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Sum: '<S22>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S31>/Discrete-Time Integrator1'
   */
  QS_InnerRateLoop_DW.UnitDelay1_DSTATE = rtb_Sum1_c0 +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_o;

  /* Gain: '<S29>/derivative cutoff frequency 1' incorporates:
   *  DiscreteIntegrator: '<S29>/Discrete-Time Integrator'
   *  Gain: '<S29>/derivative cutoff frequency '
   *  Sum: '<S29>/Sum1'
   */
  rtb_derivativecutofffrequency_0 = (QS_InnerRateLoop_DW.UnitDelay1_DSTATE -
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_b) * 100.0F;

  /* Sum: '<S106>/Add5' incorporates:
   *  Product: '<S106>/Divide'
   *  Product: '<S106>/Divide2'
   *  Product: '<S106>/Divide6'
   */
  rtb_Add5_ky = (QS_InnerRateLoop_ConstB.TrigonometricFunction2_l *
                 rtb_derivativecutofffrequency_b * QS_InnerRateLoop_Y.theta_cmd
                 + QS_InnerRateLoop_ConstB.TrigonometricFunction2_l * rtb_Sum3_f
                 * rtb_Add5_ky) +
    -QS_InnerRateLoop_ConstB.TrigonometricFunction5_o *
    QS_InnerRateLoop_Y.vehheadingcmd;

  /* Gain: '<S69>/Gain' */
  rtb_Gain_ed = 0.0F * rtb_Add5_ky;

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevR_j <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_m = 0.0F;
  }

  rtb_Sum3_f = QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_m;

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   */
  if (QS_InnerRateLoop_Y.TrajectoryON) {
    rtb_Sum1_c0 = rtb_Gain_ed;
  } else {
    rtb_Sum1_c0 = 0.0F;
  }

  /* End of Switch: '<S24>/Switch' */

  /* Sum: '<S24>/Sum4' incorporates:
   *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator1'
   */
  QS_InnerRateLoop_Y.theta_cmd = rtb_Sum1_c0 +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_m;

  /* Gain: '<S45>/derivative cutoff frequency 1' incorporates:
   *  DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
   *  Gain: '<S45>/derivative cutoff frequency '
   *  Sum: '<S45>/Sum1'
   */
  rtb_derivativecutofffrequency_b = (QS_InnerRateLoop_Y.theta_cmd -
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_o) * 100.0F;

  /* Logic: '<S15>/Logical Operator2' incorporates:
   *  Constant: '<S15>/Constant7'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  RelationalOperator: '<S15>/Relational Operator4'
   */
  rtb_LogicalOperator2_e = (QS_InnerRateLoop_Y.TrajectoryON && (rtb_Gain2 <=
    18.0F));

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant5'
   *  RelationalOperator: '<S15>/Relational Operator3'
   */
  if (rtb_Gain2 >= 12.0F) {
    /* Sum: '<Root>/Sum4' incorporates:
     *  Sum: '<S15>/Sum3'
     */
    QS_InnerRateLoop_Y.vehheadingcmd = rtb_uDLookupTable3;
  } else {
    /* Sum: '<Root>/Sum4' */
    QS_InnerRateLoop_Y.vehheadingcmd = 0.0F;
  }

  /* End of Switch: '<S15>/Switch' */

  /* RateLimiter: '<S15>/Rate Limiter' */
  rtb_uDLookupTable3 = QS_InnerRateLoop_Y.vehheadingcmd -
    QS_InnerRateLoop_DW.PrevY;
  if (rtb_uDLookupTable3 > 0.25F) {
    /* Sum: '<Root>/Sum4' */
    QS_InnerRateLoop_Y.vehheadingcmd = QS_InnerRateLoop_DW.PrevY + 0.25F;
  } else if (rtb_uDLookupTable3 < -0.25F) {
    /* Sum: '<Root>/Sum4' */
    QS_InnerRateLoop_Y.vehheadingcmd = QS_InnerRateLoop_DW.PrevY + -0.25F;
  }

  QS_InnerRateLoop_DW.PrevY = QS_InnerRateLoop_Y.vehheadingcmd;

  /* End of RateLimiter: '<S15>/Rate Limiter' */

  /* Outputs for Enabled SubSystem: '<Root>/Determine Heading at Start of Manuever  All trajectories relative to this heading' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* Logic: '<Root>/Logical Operator2' */
  if (!QS_InnerRateLoop_Y.TrajectoryON) {
    /* Gain: '<S3>/Gain' incorporates:
     *  Inport: '<Root>/psi_rad'
     */
    QS_InnerRateLoop_B.Gain = 57.2957802F * QS_InnerRateLoop_U.psi_rad;
  }

  /* End of Logic: '<Root>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<Root>/Determine Heading at Start of Manuever  All trajectories relative to this heading' */

  /* Sum: '<Root>/Sum4' */
  QS_InnerRateLoop_Y.vehheadingcmd += QS_InnerRateLoop_B.Gain;

  /* Gain: '<S68>/Gain' */
  rtb_uDLookupTable3 = 0.0174532924F * QS_InnerRateLoop_Y.vehheadingcmd;

  /* Delay: '<S16>/Delay' */
  if (QS_InnerRateLoop_DW.icLoad) {
    /* Switch: '<S16>/Switch3' */
    QS_InnerRateLoop_DW.Delay_DSTATE = rtb_uDLookupTable3;
  }

  /* End of Delay: '<S16>/Delay' */

  /* Switch: '<S16>/Switch3' incorporates:
   *  Delay: '<S16>/Delay1'
   */
  if (!QS_InnerRateLoop_DW.Delay1_DSTATE_j[0]) {
    /* Switch: '<S16>/Switch3' incorporates:
     *  Inport: '<Root>/psi_rad'
     */
    QS_InnerRateLoop_DW.Delay_DSTATE = QS_InnerRateLoop_U.psi_rad;
  }

  /* End of Switch: '<S16>/Switch3' */

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_b != 0) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mz =
      QS_InnerRateLoop_DW.Delay_DSTATE;
  }

  if ((QS_InnerRateLoop_Y.TrajectoryON &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_p <= 0)) ||
      (rtb_RelationalOperator_b1 &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_p == 1))) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mz =
      QS_InnerRateLoop_DW.Delay_DSTATE;
  }

  /* Switch: '<S16>/Switch' */
  if (QS_InnerRateLoop_Y.TrajectoryON) {
    /* Switch: '<S16>/Switch' */
    QS_InnerRateLoop_Y.psi_cmd = rtb_uDLookupTable3;
  } else {
    /* Switch: '<S16>/Switch' incorporates:
     *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
     */
    QS_InnerRateLoop_Y.psi_cmd =
      QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mz;
  }

  /* End of Switch: '<S16>/Switch' */

  /* DiscreteIntegrator: '<S58>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_bp <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* Gain: '<S58>/Gain' incorporates:
   *  DiscreteIntegrator: '<S58>/Discrete-Time Integrator'
   */
  rtb_Gain_on = 400.0 * QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE;

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S25>/Constant1'
   */
  if (rtb_Gain_on >= 100.0) {
    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/Constant'
     *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
     *  Gain: '<S57>/derivative cutoff frequency 1'
     *  Sum: '<S57>/Sum1'
     */
    if (rtb_LogicalOperator2_e) {
      rtb_Switch2_cz = 0.0F;
    } else {
      rtb_Switch2_cz = (QS_InnerRateLoop_Y.psi_cmd -
                        QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mr) *
        100.0F;
    }

    /* End of Switch: '<S25>/Switch' */
  } else {
    rtb_Switch2_cz = 0.0F;
  }

  /* End of Switch: '<S25>/Switch2' */

  /* DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_m <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f = 0.0F;
  }

  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f >= 0.1F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f = 0.1F;
  } else if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f <= -0.1F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f = -0.1F;
  }

  /* Lookup_n-D: '<S36>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_n <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_fs = 0.0F;
  }

  /* Product: '<S36>/Product' incorporates:
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
   *  Lookup_n-D: '<S36>/1-D Lookup Table2'
   *  Sum: '<S23>/Sum2'
   */
  rtb_Product_o = (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_fs -
                   rtb_uDLookupTable_cs) * intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_ok);

  /* Sum: '<S23>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
   */
  rtb_Sum1_c0 = QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f +
    rtb_Product_o;

  /* Lookup_n-D: '<S23>/1-D Lookup Table' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_uDLookupTable_cs = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable_tableData);

  /* Lookup_n-D: '<S23>/1-D Lookup Table1' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_uDLookupTable1 = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable1_tableData_g);

  /* DiscreteIntegrator: '<S40>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_by <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_c4 = 0.0F;
  }

  rtb_DiscreteTimeIntegrator_hs =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_c4;

  /* DiscreteIntegrator: '<S32>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_e <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_o2 = 0.0F;
  }

  /* Lookup_n-D: '<S27>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Product: '<S27>/Product' incorporates:
   *  Inport: '<Root>/phi_rad'
   *  Lookup_n-D: '<S27>/1-D Lookup Table2'
   *  Sum: '<S22>/Sum'
   */
  rtb_Product_ke = (QS_InnerRateLoop_DW.UnitDelay1_DSTATE -
                    QS_InnerRateLoop_U.phi_rad) * intrp1d_fu32fl_pw(bpIdx,
    rtb_Abs_i, QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_a);

  /* Lookup_n-D: '<S26>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Sum: '<S22>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
   *  Gain: '<S29>/derivative cutoff frequency 1'
   *  Inport: '<Root>/p_rps'
   *  Lookup_n-D: '<S26>/1-D Lookup Table2'
   *  Product: '<S26>/Product'
   *  Sum: '<S22>/Sum2'
   */
  rtb_Sum1_fe = (rtb_derivativecutofffrequency_0 - QS_InnerRateLoop_U.p_rps) *
    intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
                      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_fu) +
    (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_o2 + rtb_Product_ke);

  /* Lookup_n-D: '<S22>/1-D Lookup Table' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_uDLookupTable = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable_tableData_l);

  /* Lookup_n-D: '<S22>/1-D Lookup Table1' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_uDLookupTable1_p = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable1_tableData_n);

  /* DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_cv =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_bw;

  /* DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_d <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_j = 0.0F;
  }

  /* Lookup_n-D: '<S43>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Product: '<S43>/Product' incorporates:
   *  Inport: '<Root>/theta_rad'
   *  Lookup_n-D: '<S43>/1-D Lookup Table2'
   *  Sum: '<S24>/Sum'
   */
  rtb_Product_p = (QS_InnerRateLoop_Y.theta_cmd - QS_InnerRateLoop_U.theta_rad) *
    intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
                      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_ex);

  /* Lookup_n-D: '<S42>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Sum: '<S24>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
   *  Gain: '<S45>/derivative cutoff frequency 1'
   *  Inport: '<Root>/q_rps'
   *  Lookup_n-D: '<S42>/1-D Lookup Table2'
   *  Product: '<S42>/Product'
   *  Sum: '<S24>/Sum2'
   */
  rtb_uDLookupTable2_n = (rtb_derivativecutofffrequency_b -
    QS_InnerRateLoop_U.q_rps) * intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_c) +
    (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_j + rtb_Product_p);

  /* Lookup_n-D: '<S24>/1-D Lookup Table' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_Saturation_c = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable_tableData_m);

  /* Lookup_n-D: '<S24>/1-D Lookup Table1' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_uDLookupTable1_l = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable1_tableData_d);

  /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_nt =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_di;

  /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_j <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0F;
  }

  /* Lookup_n-D: '<S53>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/Constant'
   */
  if (rtb_Gain_on >= 100.0) {
    /* Sum: '<S25>/Sum1' incorporates:
     *  Inport: '<Root>/psi_rad'
     */
    rtb_Sum1_dm = QS_InnerRateLoop_Y.psi_cmd - QS_InnerRateLoop_U.psi_rad;

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S61>/Constant1'
     *  Constant: '<S61>/Constant2'
     *  Gain: '<S61>/Gain1'
     *  Switch: '<S61>/Switch1'
     */
    if (rtb_Sum1_dm >= 0.0F) {
      iU = 1;
    } else {
      rtb_Sum1_dm = -rtb_Sum1_dm;
      iU = -1;
    }

    /* End of Switch: '<S61>/Switch' */

    /* Product: '<S61>/Product' incorporates:
     *  Constant: '<S61>/Constant'
     *  Gain: '<S61>/Gain'
     *  Product: '<S61>/Divide'
     *  Rounding: '<S61>/Rounding Function'
     *  Sum: '<S61>/Subtract'
     */
    rtb_Product_h = (rtb_Sum1_dm - static_cast<real32_T>(floor(static_cast<
      real_T>(rtb_Sum1_dm * 0.159154937F))) * 6.28318548F) *
      static_cast<real32_T>(iU);

    /* Switch: '<S52>/Switch' incorporates:
     *  Abs: '<S52>/Abs'
     */
    if (static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Product_h))) >
        3.14159274F) {
      /* Switch: '<S52>/Switch1' incorporates:
       *  Constant: '<S52>/Constant1'
       *  Constant: '<S52>/Constant2'
       *  Sum: '<S52>/Add'
       *  Sum: '<S52>/Subtract'
       */
      if (rtb_Product_h >= 0.0F) {
        rtb_Product_h -= 6.28318548F;
      } else {
        rtb_Product_h += 6.28318548F;
      }

      /* End of Switch: '<S52>/Switch1' */
    }

    /* End of Switch: '<S52>/Switch' */
  } else {
    rtb_Product_h = 0.0F;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* Product: '<S53>/Product' incorporates:
   *  Lookup_n-D: '<S53>/1-D Lookup Table2'
   */
  rtb_Product_jw = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_au) * rtb_Product_h;

  /* Lookup_n-D: '<S55>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Sum: '<S25>/Sum5' incorporates:
   *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator'
   *  Inport: '<Root>/r_rps'
   *  Lookup_n-D: '<S55>/1-D Lookup Table2'
   *  Product: '<S55>/Product'
   *  Sum: '<S25>/Sum3'
   */
  rtb_Product_h = (rtb_Switch2_cz - QS_InnerRateLoop_U.r_rps) *
    intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
                      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_c0) +
    (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_l + rtb_Product_jw);

  /* Lookup_n-D: '<S25>/1-D Lookup Table' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_Sum1_bq = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable_tableData_h);

  /* Lookup_n-D: '<S25>/1-D Lookup Table1' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_Sum1_dm = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable1_tableData_f);

  /* DiscreteIntegrator: '<S60>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_ia =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_hv;

  /* Sum: '<S4>/Sum' */
  rtb_Product_j[0] = rtb_Switch_ep;

  /* Gain: '<S30>/derivative cutoff frequency 1' incorporates:
   *  DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
   *  Gain: '<S29>/derivative cutoff frequency 1'
   *  Gain: '<S30>/derivative cutoff frequency '
   *  Sum: '<S30>/Sum1'
   */
  rtb_Product_b_tmp = (rtb_derivativecutofffrequency_0 -
                       QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_hq) *
    100.0F;

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S30>/derivative cutoff frequency 1'
   */
  rtb_Product_j[1] = rtb_Product_b_tmp;

  /* Sum: '<S24>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
   *  Gain: '<S45>/derivative cutoff frequency 1'
   *  Gain: '<S46>/derivative cutoff frequency '
   *  Gain: '<S46>/derivative cutoff frequency 1'
   *  Sum: '<S46>/Sum1'
   */
  rtb_Product_b_tmp_0 = (rtb_derivativecutofffrequency_b -
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mk) * 100.0F;

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S46>/derivative cutoff frequency 1'
   *  Sum: '<S24>/Sum3'
   */
  rtb_Product_j[2] = rtb_Product_b_tmp_0;

  /* Gain: '<S56>/derivative cutoff frequency 1' incorporates:
   *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
   *  Gain: '<S56>/derivative cutoff frequency '
   *  Sum: '<S56>/Sum1'
   */
  rtb_Product_b_tmp_1 = (rtb_Switch2_cz -
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_d) * 100.0F;

  /* Sum: '<S4>/Sum' incorporates:
   *  DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S60>/Discrete-Time Integrator'
   *  Gain: '<S56>/derivative cutoff frequency 1'
   *  Product: '<S33>/Product1'
   *  Product: '<S40>/Product1'
   *  Product: '<S49>/Product1'
   *  Product: '<S60>/Product1'
   *  Sum: '<S33>/Sum1'
   *  Sum: '<S40>/Sum1'
   *  Sum: '<S49>/Sum1'
   *  Sum: '<S60>/Sum1'
   */
  rtb_Product_j[3] = rtb_Product_b_tmp_1;
  rtb_Sum1_f[0] = rtb_Sum1_c0 * rtb_uDLookupTable_cs / rtb_uDLookupTable1 +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_c4;
  rtb_Sum1_f[1] = rtb_Sum1_fe * rtb_uDLookupTable / rtb_uDLookupTable1_p +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_bw;
  rtb_Sum1_f[2] = rtb_uDLookupTable2_n * rtb_Saturation_c / rtb_uDLookupTable1_l
    + QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_di;
  rtb_Sum1_f[3] = rtb_Product_h * rtb_Sum1_bq / rtb_Sum1_dm +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_hv;

  /* SignalConversion generated from: '<S63>/Product' incorporates:
   *  Inport: '<Root>/p_rps'
   *  Inport: '<Root>/phi_rad'
   *  Inport: '<Root>/psi_rad'
   *  Inport: '<Root>/q_rps'
   *  Inport: '<Root>/r_rps'
   *  Inport: '<Root>/theta_rad'
   */
  rtb_Add5_3[3] = QS_InnerRateLoop_U.p_rps;
  rtb_Add5_3[4] = QS_InnerRateLoop_U.q_rps;
  rtb_Add5_3[5] = QS_InnerRateLoop_U.r_rps;
  rtb_Add5_3[6] = QS_InnerRateLoop_U.phi_rad;
  rtb_Add5_3[7] = QS_InnerRateLoop_U.theta_rad;
  rtb_Add5_3[8] = QS_InnerRateLoop_U.psi_rad;

  /* Sum: '<S4>/Sum' incorporates:
   *  Lookup_n-D: '<S63>/1-D Lookup Table2'
   *  Product: '<S63>/Product'
   */
  for (iU = 0; iU < 4; iU++) {
    rtb_Sum1_j_idx_1 = 0.0F;
    for (i = 0; i < 9; i++) {
      rtb_Sum1_j_idx_1 += rtb_uDLookupTable2[(i << 2) + iU] * rtb_Add5_3[i];
    }

    rtb_Product_b_0[iU] = (rtb_Product_j[iU] + rtb_Sum1_f[iU]) -
      rtb_Sum1_j_idx_1;
  }

  /* Product: '<S62>/Product' incorporates:
   *  Lookup_n-D: '<S62>/1-D Lookup Table2'
   */
  for (iU = 0; iU < 4; iU++) {
    rtb_Product_j[iU] = rtb_uDLookupTable2_k5[iU + 12] * rtb_Product_b_0[3] +
      (rtb_uDLookupTable2_k5[iU + 8] * rtb_Product_b_0[2] +
       (rtb_uDLookupTable2_k5[iU + 4] * rtb_Product_b_0[1] +
        rtb_uDLookupTable2_k5[iU] * rtb_Product_b_0[0]));
  }

  /* End of Product: '<S62>/Product' */

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem Grab and Freeze Value Upon Engagement' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (!QS_InnerRateLoop_U.engage) {
    /* Saturate: '<Root>/Saturation' incorporates:
     *  Inport: '<Root>/mixer_in_throttle'
     *  Inport: '<S5>/In1'
     */
    if (QS_InnerRateLoop_U.mixer_in_throttle > 2.0F) {
      QS_InnerRateLoop_B.In1[0] = 2.0F;
    } else if (QS_InnerRateLoop_U.mixer_in_throttle < -1.0F) {
      QS_InnerRateLoop_B.In1[0] = -1.0F;
    } else {
      QS_InnerRateLoop_B.In1[0] = QS_InnerRateLoop_U.mixer_in_throttle;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Saturate: '<Root>/Saturation1' incorporates:
     *  Inport: '<Root>/mixer_in_y'
     *  Inport: '<S5>/In1'
     */
    if (QS_InnerRateLoop_U.mixer_in_y > 2.0F) {
      QS_InnerRateLoop_B.In1[1] = 2.0F;
    } else if (QS_InnerRateLoop_U.mixer_in_y < -2.0F) {
      QS_InnerRateLoop_B.In1[1] = -2.0F;
    } else {
      QS_InnerRateLoop_B.In1[1] = QS_InnerRateLoop_U.mixer_in_y;
    }

    /* End of Saturate: '<Root>/Saturation1' */

    /* Saturate: '<Root>/Saturation2' incorporates:
     *  Inport: '<Root>/mixer_in_x'
     *  Inport: '<S5>/In1'
     */
    if (QS_InnerRateLoop_U.mixer_in_x > 2.0F) {
      QS_InnerRateLoop_B.In1[2] = 2.0F;
    } else if (QS_InnerRateLoop_U.mixer_in_x < -2.0F) {
      QS_InnerRateLoop_B.In1[2] = -2.0F;
    } else {
      QS_InnerRateLoop_B.In1[2] = QS_InnerRateLoop_U.mixer_in_x;
    }

    /* End of Saturate: '<Root>/Saturation2' */

    /* Saturate: '<Root>/Saturation3' incorporates:
     *  Inport: '<Root>/mixer_in_z'
     *  Inport: '<S5>/In1'
     */
    if (QS_InnerRateLoop_U.mixer_in_z > 2.0F) {
      QS_InnerRateLoop_B.In1[3] = 2.0F;
    } else if (QS_InnerRateLoop_U.mixer_in_z < -2.0F) {
      QS_InnerRateLoop_B.In1[3] = -2.0F;
    } else {
      QS_InnerRateLoop_B.In1[3] = QS_InnerRateLoop_U.mixer_in_z;
    }

    /* End of Saturate: '<Root>/Saturation3' */
  }

  /* End of Logic: '<Root>/Logical Operator' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem Grab and Freeze Value Upon Engagement' */

  /* DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
  rtb_Switch2_cz = QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_co;

  /* DeadZone: '<S16>/Dead Zone3' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   *  Gain: '<S64>/Gain'
   *  Sum: '<S64>/Sum1'
   */
  QS_InnerRateLoop_Y.CF_Vz = 6.66666651F * rtb_Product_j[0] +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_co;

  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_di =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_i;

  /* Sum: '<S65>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   *  Gain: '<S65>/Gain'
   */
  rtb_uDLookupTable_a = 6.66666651F * rtb_Product_j[1] +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_i;

  /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_bl =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_ch;

  /* Sum: '<S66>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator'
   *  Gain: '<S66>/Gain'
   */
  QS_InnerRateLoop_Y.pitch_sweep = 6.66666651F * rtb_Product_j[2] +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_ch;

  /* DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_k0 =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_a5;

  /* Sum: '<S67>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator'
   *  Gain: '<S67>/Gain'
   */
  QS_InnerRateLoop_Y.yaw_sweep = 0.364F * rtb_Product_j[3] +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_a5;

  /* Sum: '<Root>/Sum1' */
  rtb_Sum1_j_idx_0 = QS_InnerRateLoop_B.In1[0] + QS_InnerRateLoop_Y.CF_Vz;
  rtb_Sum1_j_idx_1 = QS_InnerRateLoop_B.In1[1] + rtb_uDLookupTable_a;
  rtb_Sum1_j_idx_2 = QS_InnerRateLoop_B.In1[2] + QS_InnerRateLoop_Y.pitch_sweep;
  rtb_Sum1_j_idx_3 = QS_InnerRateLoop_B.In1[3] + QS_InnerRateLoop_Y.yaw_sweep;

  /* Saturate: '<Root>/Saturation4' */
  if (rtb_Sum1_j_idx_0 > 0.9F) {
    rtb_Abs_i = 0.9F;
  } else if (rtb_Sum1_j_idx_0 < 0.05F) {
    rtb_Abs_i = 0.05F;
  } else {
    rtb_Abs_i = rtb_Sum1_j_idx_0;
  }

  /* End of Saturate: '<Root>/Saturation4' */

  /* Outport: '<Root>/mixer_throttle' */
  QS_InnerRateLoop_Y.mixer_throttle = rtb_Abs_i;

  /* Abs: '<S10>/Abs' incorporates:
   *  Sum: '<S10>/Sum3'
   */
  rtb_Abs_i = static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Sum1_j_idx_0 -
    rtb_Abs_i)));

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S94>/Constant'
   *  Lookup_n-D: '<S37>/1-D Lookup Table2'
   *  Product: '<S37>/Product'
   *  RelationalOperator: '<S94>/Compare'
   */
  if (rtb_Abs_i > 0.0F) {
    rtb_Product_o = 0.0F;
  } else {
    /* Lookup_n-D: '<S37>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
    rtb_Product_o *= intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData);
  }

  /* End of Switch: '<S39>/Switch' */

  /* Saturate: '<Root>/Saturation7' */
  if (rtb_Sum1_j_idx_1 > 1.0F) {
    rtb_Abs_i = 1.0F;
  } else if (rtb_Sum1_j_idx_1 < -1.0F) {
    rtb_Abs_i = -1.0F;
  } else {
    rtb_Abs_i = rtb_Sum1_j_idx_1;
  }

  /* End of Saturate: '<Root>/Saturation7' */

  /* Outport: '<Root>/mixer_x' */
  QS_InnerRateLoop_Y.mixer_x = rtb_Abs_i;

  /* Abs: '<S11>/Abs' incorporates:
   *  Sum: '<S11>/Sum3'
   */
  rtb_Abs_i = static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Sum1_j_idx_1 -
    rtb_Abs_i)));

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S95>/Constant'
   *  Lookup_n-D: '<S28>/1-D Lookup Table2'
   *  Product: '<S28>/Product'
   *  RelationalOperator: '<S95>/Compare'
   */
  if (rtb_Abs_i > 0.0F) {
    rtb_Product_ke = 0.0F;
  } else {
    /* Lookup_n-D: '<S28>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
    rtb_Product_ke *= intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
      QS_InnerRateLoop_ConstP.pooled6);
  }

  /* End of Switch: '<S32>/Switch' */

  /* Saturate: '<Root>/Saturation6' */
  if (rtb_Sum1_j_idx_2 > 1.0F) {
    rtb_Abs_i = 1.0F;
  } else if (rtb_Sum1_j_idx_2 < -1.0F) {
    rtb_Abs_i = -1.0F;
  } else {
    rtb_Abs_i = rtb_Sum1_j_idx_2;
  }

  /* End of Saturate: '<Root>/Saturation6' */

  /* Outport: '<Root>/mixer_y' */
  QS_InnerRateLoop_Y.mixer_y = rtb_Abs_i;

  /* Abs: '<S12>/Abs' incorporates:
   *  Sum: '<S12>/Sum3'
   */
  rtb_Abs_i = static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Sum1_j_idx_2 -
    rtb_Abs_i)));

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S48>/Constant'
   *  Constant: '<S96>/Constant'
   *  Lookup_n-D: '<S44>/1-D Lookup Table2'
   *  Product: '<S44>/Product'
   *  RelationalOperator: '<S96>/Compare'
   */
  if (rtb_Abs_i > 0.0F) {
    rtb_Product_p = 0.0F;
  } else {
    /* Lookup_n-D: '<S44>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
    rtb_Product_p *= intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_e);
  }

  /* End of Switch: '<S48>/Switch' */

  /* Saturate: '<Root>/Saturation5' */
  if (rtb_Sum1_j_idx_3 > 1.0F) {
    rtb_Abs_i = 1.0F;
  } else if (rtb_Sum1_j_idx_3 < -1.0F) {
    rtb_Abs_i = -1.0F;
  } else {
    rtb_Abs_i = rtb_Sum1_j_idx_3;
  }

  /* End of Saturate: '<Root>/Saturation5' */

  /* Outport: '<Root>/mixer_z' */
  QS_InnerRateLoop_Y.mixer_z = rtb_Abs_i;

  /* Abs: '<S13>/Abs' incorporates:
   *  Sum: '<S13>/Sum3'
   */
  rtb_Abs_i = static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Abs_i -
    rtb_Sum1_j_idx_3)));

  /* Switch: '<S59>/Switch' incorporates:
   *  Constant: '<S59>/Constant'
   *  Constant: '<S97>/Constant'
   *  Lookup_n-D: '<S54>/1-D Lookup Table2'
   *  Product: '<S54>/Product'
   *  RelationalOperator: '<S97>/Compare'
   */
  if (rtb_Abs_i > 0.0F) {
    rtb_Product_jw = 0.0F;
  } else {
    /* Lookup_n-D: '<S54>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
    rtb_Product_jw *= intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
      QS_InnerRateLoop_ConstP.pooled6);
  }

  /* End of Switch: '<S59>/Switch' */

  /* Outport: '<Root>/roll_sweep' */
  QS_InnerRateLoop_Y.roll_sweep = rtb_uDLookupTable_a;

  /* Outport: '<Root>/coll_sweep' */
  QS_InnerRateLoop_Y.coll_sweep = QS_InnerRateLoop_Y.CF_Vz;

  /* Product: '<S60>/Product' incorporates:
   *  Product: '<S60>/Product2'
   *  Sum: '<S60>/Sum'
   *  Sum: '<S60>/Sum2'
   *  UnitDelay: '<S60>/Unit Delay'
   */
  rtb_Sum1_j_idx_3 = ((rtb_Sum1_dm - rtb_Sum1_bq) * rtb_Product_h / rtb_Sum1_dm
                      - QS_InnerRateLoop_DW.UnitDelay_DSTATE_o) * rtb_Sum1_bq;

  /* Product: '<S49>/Product2' incorporates:
   *  Sum: '<S49>/Sum2'
   */
  rtb_Sum1_j_idx_2 = (rtb_uDLookupTable1_l - rtb_Saturation_c) *
    rtb_uDLookupTable2_n / rtb_uDLookupTable1_l;

  /* Outport: '<Root>/vz_cmd' incorporates:
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_Y.vz_cmd =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_fs;

  /* DeadZone: '<S16>/Dead Zone3' incorporates:
   *  Trigonometry: '<S70>/Trigonometric Function3'
   */
  QS_InnerRateLoop_Y.CF_Vz = static_cast<real32_T>(cos(static_cast<real_T>
    (rtb_uDLookupTable3)));

  /* Trigonometry: '<S70>/Trigonometric Function6' */
  rtb_Sum1_dm = static_cast<real32_T>(sin(static_cast<real_T>(rtb_uDLookupTable3)));

  /* Product: '<S70>/Divide4' incorporates:
   *  Product: '<S70>/Divide9'
   */
  rtb_Abs_i = QS_InnerRateLoop_ConstB.TrigonometricFunction1_m *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5_f;

  /* Product: '<S70>/Divide1' incorporates:
   *  Product: '<S70>/Divide7'
   */
  rtb_Sum1_bq = QS_InnerRateLoop_ConstB.TrigonometricFunction4_k *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5_f;

  /* Sum: '<S70>/Add5' incorporates:
   *  Product: '<S70>/Divide'
   *  Product: '<S70>/Divide1'
   *  Product: '<S70>/Divide13'
   *  Product: '<S70>/Divide14'
   *  Product: '<S70>/Divide3'
   *  Product: '<S70>/Divide4'
   *  Product: '<S70>/Divide5'
   *  Sum: '<S70>/Add1'
   *  Sum: '<S70>/Add2'
   */
  QS_InnerRateLoop_Y.Vnorth_cmd = ((rtb_Abs_i * QS_InnerRateLoop_Y.CF_Vz +
    QS_InnerRateLoop_ConstB.TrigonometricFunction4_k * rtb_Sum1_dm) * rtb_Add7_d
    + (rtb_Sum1_bq * QS_InnerRateLoop_Y.CF_Vz -
       QS_InnerRateLoop_ConstB.TrigonometricFunction1_m * rtb_Sum1_dm) *
    rtb_Add6_a) + QS_InnerRateLoop_ConstB.TrigonometricFunction2_a *
    QS_InnerRateLoop_Y.CF_Vz * rtb_Add5_ky;

  /* Sum: '<S70>/Add6' incorporates:
   *  Product: '<S70>/Divide10'
   *  Product: '<S70>/Divide15'
   *  Product: '<S70>/Divide16'
   *  Product: '<S70>/Divide6'
   *  Product: '<S70>/Divide7'
   *  Product: '<S70>/Divide8'
   *  Product: '<S70>/Divide9'
   *  Sum: '<S70>/Add3'
   *  Sum: '<S70>/Add4'
   */
  QS_InnerRateLoop_Y.Veast_cmd = ((rtb_Abs_i * rtb_Sum1_dm -
    QS_InnerRateLoop_ConstB.TrigonometricFunction4_k * QS_InnerRateLoop_Y.CF_Vz)
    * rtb_Add7_d + (rtb_Sum1_bq * rtb_Sum1_dm +
                    QS_InnerRateLoop_ConstB.TrigonometricFunction1_m *
                    QS_InnerRateLoop_Y.CF_Vz) * rtb_Add6_a) +
    QS_InnerRateLoop_ConstB.TrigonometricFunction2_a * rtb_Sum1_dm * rtb_Add5_ky;

  /* Sum: '<S70>/Add7' incorporates:
   *  Product: '<S70>/Divide11'
   *  Product: '<S70>/Divide12'
   *  Product: '<S70>/Divide2'
   */
  QS_InnerRateLoop_Y.Vdown_cmd =
    (QS_InnerRateLoop_ConstB.TrigonometricFunction1_m *
     QS_InnerRateLoop_ConstB.TrigonometricFunction2_a * rtb_Add7_d +
     QS_InnerRateLoop_ConstB.TrigonometricFunction4_k *
     QS_InnerRateLoop_ConstB.TrigonometricFunction2_a * rtb_Add6_a) +
    -QS_InnerRateLoop_ConstB.TrigonometricFunction5_f * rtb_Add5_ky;

  /* DiscreteIntegrator: '<S83>/Discrete-Time Integrator' */
  if (QS_InnerRateLoop_Y.TrajectoryON &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_h <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0F;
  }

  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n >= 0.0174520072F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0174520072F;
  } else if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n <=
             -0.0174520072F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n = -0.0174520072F;
  }

  /* Lookup_n-D: '<S81>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Product: '<S81>/Product' incorporates:
   *  Lookup_n-D: '<S81>/1-D Lookup Table2'
   *  Product: '<S71>/Divide'
   *  Product: '<S71>/Divide2'
   *  Product: '<S71>/Divide6'
   *  Sum: '<S71>/Add5'
   *  Sum: '<S73>/Sum'
   *  Sum: '<S73>/Sum4'
   */
  rtb_uDLookupTable1_l = ((((QS_InnerRateLoop_ConstB.TrigonometricFunction2_ak *
    rtb_DiscreteTimeIntegrator_l * QS_InnerRateLoop_Y.Vnorth_corr +
    QS_InnerRateLoop_ConstB.TrigonometricFunction2_ak * rtb_Product_nk *
    QS_InnerRateLoop_Y.Veast_corr) +
    -QS_InnerRateLoop_ConstB.TrigonometricFunction5_j *
    QS_InnerRateLoop_Y.Vdown_corr) + rtb_Add5_ky) - rtb_Add5_e) *
    intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
                      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_kg);

  /* DeadZone: '<S16>/Dead Zone3' incorporates:
   *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
   *  Sum: '<S73>/Sum1'
   */
  QS_InnerRateLoop_Y.CF_Vz = QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n
    + rtb_uDLookupTable1_l;

  /* Lookup_n-D: '<S73>/1-D Lookup Table' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_Sum1_dm = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable_tableData_d);

  /* Lookup_n-D: '<S73>/1-D Lookup Table1' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_Product_h = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable1_tableData_m);

  /* DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */
  rtb_Add5_e = QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_g;

  /* Gain: '<S73>/Gain5' incorporates:
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   *  Product: '<S84>/Product1'
   *  Sum: '<S84>/Sum1'
   */
  rtb_Abs_i = -(QS_InnerRateLoop_Y.CF_Vz * rtb_Sum1_dm / rtb_Product_h +
                QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_g);

  /* Sum: '<S16>/Sum' */
  rtb_Sum1_bq = rtb_Abs_i + rtb_Gain_ed;

  /* Saturate: '<S16>/Saturation4' */
  if (rtb_Sum1_bq > 0.610820234F) {
    rtb_Add7_d = 0.610820234F;
  } else if (rtb_Sum1_bq < -0.610820234F) {
    rtb_Add7_d = -0.610820234F;
  } else {
    rtb_Add7_d = rtb_Sum1_bq;
  }

  /* End of Saturate: '<S16>/Saturation4' */

  /* Switch: '<S112>/Switch' incorporates:
   *  DeadZone: '<S16>/Dead Zone2'
   *  Gain: '<S16>/thetacmd'
   *  Inport: '<Root>/input_lon'
   */
  if (QS_InnerRateLoop_Y.TrajectoryON) {
    /* Switch: '<S16>/Switch2' incorporates:
     *  Sum: '<S16>/Sum1'
     */
    if (rtb_LogicalOperator2_e) {
      /* Saturate: '<S16>/Saturation5' */
      if (rtb_Abs_i > 0.261780113F) {
        rtb_Abs_i = 0.261780113F;
      } else if (rtb_Abs_i < -0.261780113F) {
        rtb_Abs_i = -0.261780113F;
      }

      /* End of Saturate: '<S16>/Saturation5' */
    } else {
      rtb_Abs_i = rtb_Add7_d - rtb_Gain_ed;
    }

    /* End of Switch: '<S16>/Switch2' */
  } else {
    if (QS_InnerRateLoop_U.input_lon > 0.05F) {
      /* DeadZone: '<S16>/Dead Zone2' incorporates:
       *  Inport: '<Root>/input_lon'
       */
      rtb_Sum1_j_idx_1 = QS_InnerRateLoop_U.input_lon - 0.05F;
    } else if (QS_InnerRateLoop_U.input_lon >= -0.05F) {
      /* DeadZone: '<S16>/Dead Zone2' */
      rtb_Sum1_j_idx_1 = 0.0F;
    } else {
      /* DeadZone: '<S16>/Dead Zone2' incorporates:
       *  Inport: '<Root>/input_lon'
       */
      rtb_Sum1_j_idx_1 = QS_InnerRateLoop_U.input_lon - -0.05F;
    }

    rtb_Abs_i = 0.785340309F * rtb_Sum1_j_idx_1;
  }

  /* End of Switch: '<S112>/Switch' */

  /* Switch: '<S112>/Switch1' incorporates:
   *  RelationalOperator: '<S112>/Relational Operator'
   *  Sum: '<S112>/Sum1'
   *  UnitDelay: '<S112>/Unit Delay'
   *  UnitDelay: '<S112>/Unit Delay1'
   *  UnitDelay: '<S112>/Unit Delay2'
   */
  if (QS_InnerRateLoop_DW.UnitDelay_DSTATE_e2 == QS_InnerRateLoop_Y.TrajectoryON)
  {
    rtb_uDLookupTable_a = QS_InnerRateLoop_DW.UnitDelay1_DSTATE_f;
  } else {
    rtb_uDLookupTable_a = QS_InnerRateLoop_DW.UnitDelay2_DSTATE_k - rtb_Abs_i;
  }

  /* End of Switch: '<S112>/Switch1' */

  /* Saturate: '<S112>/Saturation' */
  if (rtb_uDLookupTable_a > 0.0025F) {
    rtb_Add5_ky = 0.0025F;
  } else if (rtb_uDLookupTable_a < -0.0025F) {
    rtb_Add5_ky = -0.0025F;
  } else {
    rtb_Add5_ky = rtb_uDLookupTable_a;
  }

  /* End of Saturate: '<S112>/Saturation' */

  /* Sum: '<S112>/Sum' */
  QS_InnerRateLoop_DW.UnitDelay1_DSTATE_f = rtb_uDLookupTable_a - rtb_Add5_ky;

  /* Sum: '<S112>/Sum2' */
  QS_InnerRateLoop_DW.UnitDelay2_DSTATE_k = rtb_Abs_i +
    QS_InnerRateLoop_DW.UnitDelay1_DSTATE_f;

  /* Lookup_n-D: '<S50>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Lookup_n-D: '<S51>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx_0 = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U,
    &rtb_uDLookupTable2_n);

  /* Product: '<S51>/Product' incorporates:
   *  Lookup_n-D: '<S50>/1-D Lookup Table2'
   *  Lookup_n-D: '<S51>/1-D Lookup Table2'
   *  Product: '<S50>/Product'
   *  Sum: '<S47>/Sum'
   *  Sum: '<S47>/Sum1'
   *  UnitDelay: '<S47>/Unit Delay'
   *  UnitDelay: '<S47>/Unit Delay1'
   */
  rtb_Add5_ky = ((QS_InnerRateLoop_DW.UnitDelay2_DSTATE_k -
                  QS_InnerRateLoop_DW.UnitDelay1_DSTATE_c) * intrp1d_fu32fl_pw
                 (bpIdx, rtb_Abs_i,
                  QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_or) -
                 QS_InnerRateLoop_DW.UnitDelay_DSTATE_j) * intrp1d_fu32fl_pw
    (bpIdx_0, rtb_uDLookupTable2_n,
     QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_gp);

  /* RelationalOperator: '<S115>/Compare' incorporates:
   *  Abs: '<S109>/Abs'
   *  Constant: '<S115>/Constant'
   *  Sum: '<S109>/Sum3'
   */
  rtb_Compare_m = (static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Add7_d -
    rtb_Sum1_bq))) > 0.0F);

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/Constant'
   *  Lookup_n-D: '<S82>/1-D Lookup Table2'
   *  Product: '<S82>/Product'
   */
  if (rtb_Compare_m) {
    rtb_Add7_d = 0.0F;
  } else {
    /* Lookup_n-D: '<S82>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx = plook_u32ff_evenxg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
    rtb_Add7_d = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_f) * rtb_uDLookupTable1_l;
  }

  /* End of Switch: '<S83>/Switch' */

  /* DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
  if (QS_InnerRateLoop_Y.TrajectoryON &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_dc <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf = 0.0F;
  }

  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf >= 0.0174520072F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf = 0.0174520072F;
  } else if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf <=
             -0.0174520072F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf = -0.0174520072F;
  }

  /* Lookup_n-D: '<S77>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Product: '<S71>/Divide1' incorporates:
   *  Product: '<S71>/Divide7'
   */
  rtb_Sum1_bq = QS_InnerRateLoop_ConstB.TrigonometricFunction4_km *
    QS_InnerRateLoop_ConstB.TrigonometricFunction5_j;

  /* Product: '<S77>/Product' incorporates:
   *  Lookup_n-D: '<S77>/1-D Lookup Table2'
   *  Product: '<S71>/Divide1'
   *  Product: '<S71>/Divide11'
   *  Product: '<S71>/Divide13'
   *  Product: '<S71>/Divide15'
   *  Product: '<S71>/Divide3'
   *  Product: '<S71>/Divide7'
   *  Product: '<S71>/Divide8'
   *  Sum: '<S71>/Add1'
   *  Sum: '<S71>/Add3'
   *  Sum: '<S71>/Add6'
   *  Sum: '<S72>/Sum'
   *  Sum: '<S72>/Sum4'
   */
  rtb_Product_nk = (((((rtb_Sum1_bq * rtb_DiscreteTimeIntegrator_l -
                        QS_InnerRateLoop_ConstB.TrigonometricFunction1_g *
                        rtb_Product_nk) * QS_InnerRateLoop_Y.Vnorth_corr +
                       (rtb_Sum1_bq * rtb_Product_nk +
                        QS_InnerRateLoop_ConstB.TrigonometricFunction1_g *
                        rtb_DiscreteTimeIntegrator_l) *
                       QS_InnerRateLoop_Y.Veast_corr) +
                      QS_InnerRateLoop_ConstB.TrigonometricFunction4_km *
                      QS_InnerRateLoop_ConstB.TrigonometricFunction2_ak *
                      QS_InnerRateLoop_Y.Vdown_corr) + rtb_Add6_a) - rtb_Add6_i)
    * intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
                        QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_n);

  /* Sum: '<S72>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S79>/Discrete-Time Integrator'
   */
  rtb_Sum1_bq = QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf +
    rtb_Product_nk;

  /* Lookup_n-D: '<S72>/1-D Lookup Table' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_uDLookupTable_a = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable_tableData_hs);

  /* Lookup_n-D: '<S72>/1-D Lookup Table1' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
  rtb_uDLookupTable1_l = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
    QS_InnerRateLoop_ConstP.uDLookupTable1_tableData_p);

  /* DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cc;

  /* Sum: '<S80>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
   *  Product: '<S80>/Product1'
   */
  rtb_Add6_a = rtb_Sum1_bq * rtb_uDLookupTable_a / rtb_uDLookupTable1_l +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cc;

  /* Sum: '<S16>/Sum3' */
  rtb_uDLookupTable2_n = rtb_Add6_a + rtb_Gain1;

  /* Saturate: '<S16>/Saturation1' */
  if (rtb_uDLookupTable2_n > 0.610820234F) {
    rtb_Sum1_j_idx_1 = 0.610820234F;
  } else if (rtb_uDLookupTable2_n < -0.610820234F) {
    rtb_Sum1_j_idx_1 = -0.610820234F;
  } else {
    rtb_Sum1_j_idx_1 = rtb_uDLookupTable2_n;
  }

  /* End of Saturate: '<S16>/Saturation1' */

  /* RelationalOperator: '<S116>/Compare' incorporates:
   *  Abs: '<S110>/Abs'
   *  Constant: '<S116>/Constant'
   *  Sum: '<S110>/Sum3'
   */
  rtb_RelationalOperator_b1 = (static_cast<real32_T>(fabs(static_cast<real_T>
    (rtb_Sum1_j_idx_1 - rtb_uDLookupTable2_n))) > 0.0F);

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S90>/Constant'
   *  Logic: '<S75>/Logical Operator'
   *  Lookup_n-D: '<S89>/1-D Lookup Table2'
   *  Product: '<S89>/Product'
   */
  if (rtb_Compare_m || rtb_RelationalOperator_b1) {
    rtb_Add6_i = 0.0F;
  } else {
    /* Lookup_n-D: '<S89>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
    rtb_Add6_i = intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
      QS_InnerRateLoop_ConstP.pooled12) * rtb_Product_ng;
  }

  /* End of Switch: '<S90>/Switch' */

  /* Switch: '<S79>/Switch' incorporates:
   *  Constant: '<S79>/Constant'
   *  Lookup_n-D: '<S78>/1-D Lookup Table2'
   *  Product: '<S78>/Product'
   */
  if (rtb_RelationalOperator_b1) {
    rtb_Product_nk = 0.0F;
  } else {
    /* Lookup_n-D: '<S78>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
    rtb_Product_nk *= intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_o);
  }

  /* End of Switch: '<S79>/Switch' */

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S93>/Constant'
   *  Logic: '<S76>/Logical Operator'
   *  Lookup_n-D: '<S92>/1-D Lookup Table2'
   *  Product: '<S92>/Product'
   */
  if (rtb_Compare_m || rtb_RelationalOperator_b1) {
    rtb_Product = 0.0F;
  } else {
    /* Lookup_n-D: '<S92>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);
    rtb_Product *= intrp1d_fu32fl_pw(bpIdx, rtb_Abs_i,
      QS_InnerRateLoop_ConstP.pooled12);
  }

  /* End of Switch: '<S93>/Switch' */

  /* Switch: '<S113>/Switch' incorporates:
   *  DeadZone: '<S16>/Dead Zone1'
   *  Gain: '<S16>/phicmd'
   *  Inport: '<Root>/input_lat'
   */
  if (QS_InnerRateLoop_Y.TrajectoryON) {
    /* Switch: '<S16>/Switch1' incorporates:
     *  Sum: '<S16>/Sum4'
     */
    if (rtb_LogicalOperator2_e) {
      /* Saturate: '<S16>/Saturation3' */
      if (rtb_Add6_a > 0.174520075F) {
        rtb_Add6_a = 0.174520075F;
      } else if (rtb_Add6_a < -0.174520075F) {
        rtb_Add6_a = -0.174520075F;
      }

      /* End of Saturate: '<S16>/Saturation3' */
    } else {
      rtb_Add6_a = rtb_Sum1_j_idx_1 - rtb_Gain1;
    }

    /* End of Switch: '<S16>/Switch1' */
  } else {
    if (QS_InnerRateLoop_U.input_lat > 0.05F) {
      /* DeadZone: '<S16>/Dead Zone1' incorporates:
       *  Inport: '<Root>/input_lat'
       */
      rtb_Sum1_j_idx_1 = QS_InnerRateLoop_U.input_lat - 0.05F;
    } else if (QS_InnerRateLoop_U.input_lat >= -0.05F) {
      /* DeadZone: '<S16>/Dead Zone1' */
      rtb_Sum1_j_idx_1 = 0.0F;
    } else {
      /* DeadZone: '<S16>/Dead Zone1' incorporates:
       *  Inport: '<Root>/input_lat'
       */
      rtb_Sum1_j_idx_1 = QS_InnerRateLoop_U.input_lat - -0.05F;
    }

    rtb_Add6_a = 0.785340309F * rtb_Sum1_j_idx_1;
  }

  /* End of Switch: '<S113>/Switch' */

  /* Switch: '<S113>/Switch1' incorporates:
   *  RelationalOperator: '<S113>/Relational Operator'
   *  Sum: '<S113>/Sum1'
   *  UnitDelay: '<S113>/Unit Delay'
   *  UnitDelay: '<S113>/Unit Delay1'
   *  UnitDelay: '<S113>/Unit Delay2'
   */
  if (QS_InnerRateLoop_DW.UnitDelay_DSTATE_j1 == QS_InnerRateLoop_Y.TrajectoryON)
  {
    rtb_uDLookupTable2_n = QS_InnerRateLoop_DW.UnitDelay1_DSTATE_fj;
  } else {
    rtb_uDLookupTable2_n = QS_InnerRateLoop_DW.UnitDelay2_DSTATE_a - rtb_Add6_a;
  }

  /* End of Switch: '<S113>/Switch1' */

  /* Saturate: '<S113>/Saturation' */
  if (rtb_uDLookupTable2_n > 0.0025F) {
    rtb_Product_ng = 0.0025F;
  } else if (rtb_uDLookupTable2_n < -0.0025F) {
    rtb_Product_ng = -0.0025F;
  } else {
    rtb_Product_ng = rtb_uDLookupTable2_n;
  }

  /* End of Saturate: '<S113>/Saturation' */

  /* Sum: '<S113>/Sum' */
  QS_InnerRateLoop_DW.UnitDelay1_DSTATE_fj = rtb_uDLookupTable2_n -
    rtb_Product_ng;

  /* Sum: '<S113>/Sum2' */
  QS_InnerRateLoop_DW.UnitDelay2_DSTATE_a = rtb_Add6_a +
    QS_InnerRateLoop_DW.UnitDelay1_DSTATE_fj;

  /* Lookup_n-D: '<S34>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evenxg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Sum: '<S31>/Sum' incorporates:
   *  Lookup_n-D: '<S34>/1-D Lookup Table2'
   *  Product: '<S34>/Product'
   *  Sum: '<S31>/Sum1'
   *  UnitDelay: '<S31>/Unit Delay'
   *  UnitDelay: '<S31>/Unit Delay1'
   */
  rtb_Product_ng = (QS_InnerRateLoop_DW.UnitDelay2_DSTATE_a -
                    QS_InnerRateLoop_DW.UnitDelay1_DSTATE_a) * intrp1d_fu32fl_pw
    (bpIdx, rtb_Abs_i, QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_ob) -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_g;

  /* Lookup_n-D: '<S35>/1-D Lookup Table2' incorporates:
   *  Saturate: '<Root>/Saturation8'
   */
  bpIdx = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U, &rtb_Abs_i);

  /* Sum: '<S84>/Sum' incorporates:
   *  Product: '<S84>/Product2'
   *  Sum: '<S84>/Sum2'
   *  UnitDelay: '<S84>/Unit Delay'
   */
  rtb_Gain1 = (rtb_Product_h - rtb_Sum1_dm) * QS_InnerRateLoop_Y.CF_Vz /
    rtb_Product_h - QS_InnerRateLoop_DW.UnitDelay_DSTATE_oc;

  /* Outport: '<Root>/phi_cmd' */
  QS_InnerRateLoop_Y.phi_cmd = QS_InnerRateLoop_DW.UnitDelay1_DSTATE;

  /* Abs: '<S111>/Abs' incorporates:
   *  Sum: '<S111>/Sum3'
   */
  rtb_Abs = static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Abs - rtb_Sum2_pj)));

  /* Switch: '<S87>/Switch' incorporates:
   *  Constant: '<S117>/Constant'
   *  Constant: '<S87>/Constant'
   *  Lookup_n-D: '<S85>/1-D Lookup Table2'
   *  Product: '<S85>/Product'
   *  RelationalOperator: '<S117>/Compare'
   */
  if (rtb_Abs > 0.0F) {
    rtb_Sum2_pj = 0.0F;
  } else {
    /* Lookup_n-D: '<S85>/1-D Lookup Table2' incorporates:
     *  Saturate: '<Root>/Saturation8'
     */
    bpIdx_0 = plook_u32ff_evencg(rtb_Saturation8, 0.0F, 1.75F, 4U,
      &rtb_uDLookupTable2_n);
    rtb_Sum2_pj = intrp1d_fu32fl_pw(bpIdx_0, rtb_uDLookupTable2_n,
      QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_ej) * rtb_Product_ee;
  }

  /* End of Switch: '<S87>/Switch' */

  /* RelationalOperator: '<S15>/Relational Operator' incorporates:
   *  Constant: '<S15>/Constant3'
   */
  rtb_RelationalOperator_b1 = (rtb_Gain2 >= 18.0F);

  /* Outport: '<Root>/ScoreDisplay' incorporates:
   *  Logic: '<S15>/Logical Operator1'
   *  RelationalOperator: '<S15>/Relational Operator2'
   */
  QS_InnerRateLoop_Y.ScoreDisplay = (rtb_RelationalOperator_b1 && (rtb_Gain2 <=
    QS_InnerRateLoop_ConstB.Sum2));

  /* Outport: '<Root>/ScoreOn' incorporates:
   *  Logic: '<S15>/Logical Operator'
   *  RelationalOperator: '<S15>/Relational Operator1'
   */
  QS_InnerRateLoop_Y.ScoreOn = (rtb_RelationalOperator_b1 && (rtb_Gain2 <=
    QS_InnerRateLoop_ConstB.Sum1));

  /* Sum: '<S18>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/Ax_mpss'
   *  Inport: '<Root>/Ay_mpss'
   *  Inport: '<Root>/Az_mpss'
   *  Inport: '<Root>/theta_rad'
   *  Product: '<S6>/Divide11'
   *  Product: '<S6>/Divide12'
   *  Product: '<S6>/Divide2'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S6>/Add7'
   *  Trigonometry: '<S6>/Trigonometric Function5'
   *  UnitDelay: '<S18>/Unit Delay'
   */
  rtb_Sum = (((rtb_DiscreteTimeIntegrator_jh * QS_InnerRateLoop_U.Az_mpss +
               rtb_Sum_of * QS_InnerRateLoop_U.Ay_mpss) + -static_cast<real32_T>
              (sin(static_cast<real_T>(QS_InnerRateLoop_U.theta_rad))) *
              QS_InnerRateLoop_U.Ax_mpss) + 9.81) -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_j2;

  /* Sum: '<S19>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Baro_Alt_m'
   *  UnitDelay: '<S19>/Unit Delay'
   */
  rtb_Saturation8 = -QS_InnerRateLoop_U.Baro_Alt_m -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_da;

  /* Sum: '<S20>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Baro_Alt_m'
   *  UnitDelay: '<S20>/Unit Delay'
   */
  rtb_Sum_of = -QS_InnerRateLoop_U.Baro_Alt_m -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_ag;

  /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Baro_Alt_m'
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_j != 0) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_e =
      -QS_InnerRateLoop_U.Baro_Alt_m;
  }

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_l <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_e =
      -QS_InnerRateLoop_U.Baro_Alt_m;
  }

  /* DiscreteIntegrator: '<S21>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_em <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cg = 0.0F;
  }

  rtb_DiscreteTimeIntegrator_jh =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cg;

  /* Outport: '<Root>/CF_Alt' incorporates:
   *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   *  Sum: '<S1>/Sum1'
   */
  QS_InnerRateLoop_Y.CF_Alt =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_e +
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cg;

  /* DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Baro_Alt_m'
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_m != 0) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_o3 =
      -QS_InnerRateLoop_U.Baro_Alt_m;
  }

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_hn <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_o3 =
      -QS_InnerRateLoop_U.Baro_Alt_m;
  }

  /* Sum: '<S19>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/Baro_Alt_m'
   */
  rtb_Product_ee = -QS_InnerRateLoop_U.Baro_Alt_m -
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_o3;

  /* Sum: '<S17>/Sum3' incorporates:
   *  Gain: '<S17>/Gain1'
   *  Sum: '<S17>/Sum5'
   *  UnitDelay: '<S17>/Unit Delay'
   *  UnitDelay: '<S17>/Unit Delay1'
   */
  rtb_Gain2 = (rtb_Product_ee - QS_InnerRateLoop_DW.UnitDelay1_DSTATE_a1) *
    1.41442716F - QS_InnerRateLoop_DW.UnitDelay_DSTATE_ak;

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_IC_LO_e != 0) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_g = rtb_Product_ee;
  }

  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_Prev_gs <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_g = rtb_Product_ee;
  }

  /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_pr <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_nv = 0.0F;
  }

  /* DeadZone: '<S16>/Dead Zone3' incorporates:
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  Sum: '<S1>/Sum'
   */
  QS_InnerRateLoop_Y.CF_Vz = QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_g
    + QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_nv;

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_lm <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_gh = 0.0F;
  }

  /* DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_f <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_dn = 0.0F;
  }

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if (QS_InnerRateLoop_U.engage &&
      (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_f0 <= 0)) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_nq = 0.0F;
  }

  /* DeadZone: '<S16>/Dead Zone3' incorporates:
   *  Inport: '<Root>/input_ped'
   */
  if (QS_InnerRateLoop_U.input_ped > 0.05F) {
    rtb_Sum1_j_idx_1 = QS_InnerRateLoop_U.input_ped - 0.05F;
  } else if (QS_InnerRateLoop_U.input_ped >= -0.05F) {
    rtb_Sum1_j_idx_1 = 0.0F;
  } else {
    rtb_Sum1_j_idx_1 = QS_InnerRateLoop_U.input_ped - -0.05F;
  }

  /* End of DeadZone: '<S16>/Dead Zone3' */

  /* Sum: '<S108>/Sum' incorporates:
   *  Gain: '<S16>/rcmd'
   *  UnitDelay: '<S108>/Unit Delay'
   */
  rtb_Product_ee = 3.14136124F * rtb_Sum1_j_idx_1 -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_k;

  /* DiscreteIntegrator: '<S108>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  if ((QS_InnerRateLoop_U.engage &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_bv <= 0)) ||
      ((!QS_InnerRateLoop_U.engage) &&
       (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_bv == 1))) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_gy = 0.0F;
  }

  /* Update for Delay: '<S99>/Delay1' incorporates:
   *  Inport: '<Root>/CH8_flag'
   */
  QS_InnerRateLoop_DW.Delay1_DSTATE = QS_InnerRateLoop_U.CH8_flag;

  /* Switch: '<S99>/Switch' */
  if (!rtb_LogicalOperator2_g) {
    /* Update for Sum: '<S99>/Sum2' incorporates:
     *  Constant: '<S99>/Constant1'
     *  Delay: '<S99>/Delay2'
     */
    QS_InnerRateLoop_DW.Delay2_DSTATE = 0.0F;
  }

  /* End of Switch: '<S99>/Switch' */

  /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_a += 0.0025F * rtb_Product;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_m += 0.0025F *
    QS_InnerRateLoop_Y.Vnorth_cmd;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_a = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* Update for DiscreteIntegrator: '<S90>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_h += 0.0025F * rtb_Add6_i;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_o = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator1' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTATE += 0.0025F *
    QS_InnerRateLoop_Y.Veast_cmd;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevRes = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_c += 0.0025F * rtb_Sum2_pj;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_b = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator2' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_IC_LOAD = 0U;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_DSTATE += 0.0025F *
    QS_InnerRateLoop_Y.Vdown_cmd;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_PrevRes = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* Update for Sum: '<S22>/Sum3' incorporates:
   *  UnitDelay: '<S114>/Unit Delay1'
   */
  QS_InnerRateLoop_DW.UnitDelay1_DSTATE = rtb_TrigonometricFunction3;

  /* Update for UnitDelay: '<S114>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_ax = QS_InnerRateLoop_Y.TrajectoryON;

  /* Update for UnitDelay: '<S38>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_a =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_fs;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_hq += rtb_Product_b_tmp *
    0.0025F;

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_b +=
    rtb_derivativecutofffrequency_0 * 0.0025F;

  /* Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_o += 0.0025F *
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_dn;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevR_g = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mk += rtb_Product_b_tmp_0 *
    0.0025F;

  /* Update for DiscreteIntegrator: '<S45>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_o +=
    rtb_derivativecutofffrequency_b * 0.0025F;

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_m += 0.0025F *
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_nq;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevR_j = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_d += rtb_Product_b_tmp_1 *
    0.0025F;

  /* Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S57>/derivative cutoff frequency '
   *  Sum: '<S57>/Sum'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mr +=
    (QS_InnerRateLoop_Y.psi_cmd -
     QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mr) * 100.0F * 0.0025F;

  /* Update for Delay: '<S16>/Delay' */
  QS_InnerRateLoop_DW.icLoad = false;

  /* Update for Switch: '<S16>/Switch3' incorporates:
   *  Delay: '<S16>/Delay'
   */
  QS_InnerRateLoop_DW.Delay_DSTATE = rtb_uDLookupTable3;

  /* Update for Delay: '<S16>/Delay1' */
  QS_InnerRateLoop_DW.Delay1_DSTATE_j[0] = QS_InnerRateLoop_DW.Delay1_DSTATE_j[1];
  QS_InnerRateLoop_DW.Delay1_DSTATE_j[1] = QS_InnerRateLoop_Y.TrajectoryON;

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_b = 0U;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_mz += 0.0025F *
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_gy;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_p = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S58>/Constant'
   *  Constant: '<S58>/Constant1'
   *  Inport: '<Root>/engage'
   *  RelationalOperator: '<S58>/Relational Operator'
   */
  if (rtb_Gain_on >= 100.0) {
    iU = 0;
  } else {
    iU = QS_InnerRateLoop_U.engage;
  }

  /* End of Switch: '<S58>/Switch' */

  /* Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE += 0.0025 * static_cast<
    real_T>(iU);
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_bp = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f += 0.0025F * rtb_Product_o;
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f >= 0.1F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f = 0.1F;
  } else if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f <= -0.1F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_f = -0.1F;
  }

  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_m = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* End of Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_fs += 0.0025F * rtb_Switch_ep;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_n = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   *  Product: '<S40>/Product'
   *  Product: '<S40>/Product2'
   *  Sum: '<S40>/Sum'
   *  Sum: '<S40>/Sum2'
   *  UnitDelay: '<S40>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_c4 += ((rtb_uDLookupTable1 -
    rtb_uDLookupTable_cs) * rtb_Sum1_c0 / rtb_uDLookupTable1 -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_h) * rtb_uDLookupTable_cs * 0.0025F;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_by = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_o2 += 0.0025F *
    rtb_Product_ke;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_e = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' incorporates:
   *  Product: '<S33>/Product'
   *  Product: '<S33>/Product2'
   *  Sum: '<S33>/Sum'
   *  Sum: '<S33>/Sum2'
   *  UnitDelay: '<S33>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_bw += ((rtb_uDLookupTable1_p
    - rtb_uDLookupTable) * rtb_Sum1_fe / rtb_uDLookupTable1_p -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_b) * rtb_uDLookupTable * 0.0025F;

  /* Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_j += 0.0025F * rtb_Product_p;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_d = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
   *  Product: '<S49>/Product'
   *  Sum: '<S49>/Sum'
   *  UnitDelay: '<S49>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_di += (rtb_Sum1_j_idx_2 -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_eo) * rtb_Saturation_c * 0.0025F;

  /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_l += 0.0025F *
    rtb_Product_jw;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_j = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_hv += 0.0025F *
    rtb_Sum1_j_idx_3;

  /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S64>/Gain1'
   *  Gain: '<S64>/Gain2'
   *  Sum: '<S64>/Sum'
   *  UnitDelay: '<S64>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_co += (-5.66666651F *
    rtb_Product_j[0] - QS_InnerRateLoop_DW.UnitDelay_DSTATE_f) * 100.0F *
    0.0025F;

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S65>/Gain1'
   *  Gain: '<S65>/Gain2'
   *  Sum: '<S65>/Sum'
   *  UnitDelay: '<S65>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_i += (-5.66666651F *
    rtb_Product_j[1] - QS_InnerRateLoop_DW.UnitDelay_DSTATE_av) * 100.0F *
    0.0025F;

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S66>/Gain1'
   *  Gain: '<S66>/Gain2'
   *  Sum: '<S66>/Sum'
   *  UnitDelay: '<S66>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_ch += (-5.66666651F *
    rtb_Product_j[2] - QS_InnerRateLoop_DW.UnitDelay_DSTATE_d) * 100.0F *
    0.0025F;

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S67>/Gain1'
   *  Gain: '<S67>/Gain2'
   *  Sum: '<S67>/Sum'
   *  UnitDelay: '<S67>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_a5 += (0.636F *
    rtb_Product_j[3] - QS_InnerRateLoop_DW.UnitDelay_DSTATE_e) * 5.46F * 0.0025F;

  /* Update for UnitDelay: '<S64>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_f = rtb_Switch2_cz;

  /* Update for UnitDelay: '<S65>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_av = rtb_DiscreteTimeIntegrator_di;

  /* Update for UnitDelay: '<S66>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_d = rtb_DiscreteTimeIntegrator_bl;

  /* Update for UnitDelay: '<S67>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_e = rtb_DiscreteTimeIntegrator_k0;

  /* Update for UnitDelay: '<S60>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_o = rtb_DiscreteTimeIntegrator_ia;

  /* Update for UnitDelay: '<S49>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_eo = rtb_DiscreteTimeIntegrator_nt;

  /* Update for UnitDelay: '<S33>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_b = rtb_DiscreteTimeIntegrator_cv;

  /* Update for UnitDelay: '<S40>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_h = rtb_DiscreteTimeIntegrator_hs;

  /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n += 0.0025F * rtb_Add7_d;
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n >= 0.0174520072F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0174520072F;
  } else if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n <=
             -0.0174520072F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_n = -0.0174520072F;
  }

  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_h = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* End of Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator' incorporates:
   *  Product: '<S84>/Product'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_g += rtb_Sum1_dm * rtb_Gain1
    * 0.0025F;

  /* Update for UnitDelay: '<S112>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_e2 = QS_InnerRateLoop_Y.TrajectoryON;

  /* Update for UnitDelay: '<S47>/Unit Delay1' */
  QS_InnerRateLoop_DW.UnitDelay1_DSTATE_c = rtb_Sum3_f;

  /* Update for UnitDelay: '<S47>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_j =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_nq;

  /* Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf += 0.0025F *
    rtb_Product_nk;
  if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf >= 0.0174520072F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf = 0.0174520072F;
  } else if (QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf <=
             -0.0174520072F) {
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cf = -0.0174520072F;
  }

  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_dc = static_cast<int8_T>
    (QS_InnerRateLoop_Y.TrajectoryON);

  /* End of Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' incorporates:
   *  Product: '<S80>/Product'
   *  Product: '<S80>/Product2'
   *  Sum: '<S80>/Sum'
   *  Sum: '<S80>/Sum2'
   *  UnitDelay: '<S80>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cc += ((rtb_uDLookupTable1_l
    - rtb_uDLookupTable_a) * rtb_Sum1_bq / rtb_uDLookupTable1_l -
    QS_InnerRateLoop_DW.UnitDelay_DSTATE_gi) * rtb_uDLookupTable_a * 0.0025F;

  /* Update for UnitDelay: '<S113>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_j1 = QS_InnerRateLoop_Y.TrajectoryON;

  /* Update for UnitDelay: '<S31>/Unit Delay1' */
  QS_InnerRateLoop_DW.UnitDelay1_DSTATE_a = rtb_DiscreteTimeIntegrator1;

  /* Update for UnitDelay: '<S31>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_g =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_dn;

  /* Update for UnitDelay: '<S80>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_gi = rtb_DiscreteTimeIntegrator_l;

  /* Update for UnitDelay: '<S84>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_oc = rtb_Add5_e;

  /* Update for UnitDelay: '<S18>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_j2 =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_nv;

  /* Update for UnitDelay: '<S19>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_da =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_o3;

  /* Update for UnitDelay: '<S20>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_ag =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_e;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S20>/Gain'
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_j = 0U;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTATE_e += 0.5F * rtb_Sum_of *
    0.0025F;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_l = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S21>/Gain'
   *  Inport: '<Root>/engage'
   *  Sum: '<S21>/Sum'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_cg +=
    (QS_InnerRateLoop_Y.CF_Vz - QS_InnerRateLoop_DW.UnitDelay_DSTATE_o1) * 0.5F *
    0.0025F;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_em = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S19>/Gain'
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_m = 0U;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_o3 += 0.5F * rtb_Saturation8 *
    0.0025F;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_hn = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for UnitDelay: '<S17>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
   */
  QS_InnerRateLoop_DW.UnitDelay1_DSTATE_a1 =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_g;

  /* Update for UnitDelay: '<S17>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_ak =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_gh;

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_IC_LO_e = 0U;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_DSTAT_g += 0.0025F *
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_gh;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_Prev_gs = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S18>/Gain'
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_nv += static_cast<real32_T>
    (0.5 * rtb_Sum * 0.0025);
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_pr = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_o1 = rtb_DiscreteTimeIntegrator_jh;

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S17>/Gain'
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_gh += 2.828F * rtb_Gain2 *
    0.0025F;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_lm = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   *  Lookup_n-D: '<S35>/1-D Lookup Table2'
   *  Product: '<S35>/Product'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_dn += intrp1d_fu32fl_pw(bpIdx,
    rtb_Abs_i, QS_InnerRateLoop_ConstP.uDLookupTable2_tableData_l) *
    rtb_Product_ng * 0.0025F;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_f = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_nq += 0.0025F * rtb_Add5_ky;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_f0 = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);

  /* Update for UnitDelay: '<S108>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator'
   */
  QS_InnerRateLoop_DW.UnitDelay_DSTATE_k =
    QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_gy;

  /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S108>/Gain'
   *  Inport: '<Root>/engage'
   */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_DSTAT_gy += 10.0F * rtb_Product_ee *
    0.0025F;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_bv = static_cast<int8_T>
    (QS_InnerRateLoop_U.engage);
}

/* Model initialize function */
void QS_InnerRateLoopModelClass::initialize()
{
  /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_a = 2;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S90>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_o = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator1' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevRes = 2;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_b = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator2' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_PrevRes = 2;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator2_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator1' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevR_g = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator1' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_PrevR_j = 2;

  /* InitializeConditions for Delay: '<S16>/Delay' */
  QS_InnerRateLoop_DW.icLoad = true;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_p = 2;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_bp = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_m = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_n = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_by = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_d = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_j = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_h = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_dc = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_l = 2;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_em = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_hn = 2;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_IC_LOA_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_Prev_gs = 2;
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator1_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_pr = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_lm = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevRe_f = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_f0 = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
  QS_InnerRateLoop_DW.DiscreteTimeIntegrator_PrevR_bv = 2;
}

/* Model terminate function */
void QS_InnerRateLoopModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
QS_InnerRateLoopModelClass::QS_InnerRateLoopModelClass() :
  QS_InnerRateLoop_B(),
  QS_InnerRateLoop_DW(),
  QS_InnerRateLoop_U(),
  QS_InnerRateLoop_Y(),
  QS_InnerRateLoop_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
QS_InnerRateLoopModelClass::~QS_InnerRateLoopModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_QS_InnerRateLoop_T * QS_InnerRateLoopModelClass::getRTM()
{
  return (&QS_InnerRateLoop_M);
}
