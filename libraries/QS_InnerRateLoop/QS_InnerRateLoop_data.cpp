/*
 * QS_InnerRateLoop_data.cpp
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

/* Invariant block signals (default storage) */
const ConstB_QS_InnerRateLoop_T QS_InnerRateLoop_ConstB = {
  1.0F
  ,                                    /* '<S7>/Trigonometric Function3' */
  0.0F
  ,                                    /* '<S7>/Trigonometric Function6' */
  1.0F
  ,                                    /* '<S8>/Trigonometric Function1' */
  1.0F
  ,                                    /* '<S8>/Trigonometric Function2' */
  0.0F
  ,                                    /* '<S8>/Trigonometric Function4' */
  0.0F
  ,                                    /* '<S8>/Trigonometric Function5' */
  1.0F
  ,                                    /* '<S70>/Trigonometric Function1' */
  1.0F
  ,                                    /* '<S70>/Trigonometric Function2' */
  0.0F
  ,                                    /* '<S70>/Trigonometric Function4' */
  0.0F
  ,                                    /* '<S70>/Trigonometric Function5' */
  1.0F
  ,                                    /* '<S71>/Trigonometric Function1' */
  1.0F
  ,                                    /* '<S71>/Trigonometric Function2' */
  0.0F
  ,                                    /* '<S71>/Trigonometric Function4' */
  0.0F
  ,                                    /* '<S71>/Trigonometric Function5' */
  1.0F
  ,                                    /* '<S106>/Trigonometric Function1' */
  1.0F
  ,                                    /* '<S106>/Trigonometric Function2' */
  0.0F
  ,                                    /* '<S106>/Trigonometric Function4' */
  0.0F
  ,                                    /* '<S106>/Trigonometric Function5' */
  37.8F
  ,                                    /* '<S15>/Sum1' */
  57.8F
  /* '<S15>/Sum2' */
};

/* Constant parameters (default storage) */
const ConstP_QS_InnerRateLoop_T QS_InnerRateLoop_ConstP = {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S28>/1-D Lookup Table2'
   *   '<S54>/1-D Lookup Table2'
   */
  { 1.32525F, 1.32525F, 1.32525F, 1.32525F, 1.32525F },

  /* Pooled Parameter (Expression: bpV)
   * Referenced by:
   *   '<S22>/1-D Lookup Table'
   *   '<S22>/1-D Lookup Table1'
   *   '<S23>/1-D Lookup Table'
   *   '<S23>/1-D Lookup Table1'
   *   '<S24>/1-D Lookup Table'
   *   '<S24>/1-D Lookup Table1'
   *   '<S25>/1-D Lookup Table'
   *   '<S25>/1-D Lookup Table1'
   *   '<S62>/1-D Lookup Table2'
   *   '<S63>/1-D Lookup Table2'
   *   '<S26>/1-D Lookup Table2'
   *   '<S27>/1-D Lookup Table2'
   *   '<S28>/1-D Lookup Table2'
   *   '<S36>/1-D Lookup Table2'
   *   '<S37>/1-D Lookup Table2'
   *   '<S42>/1-D Lookup Table2'
   *   '<S43>/1-D Lookup Table2'
   *   '<S44>/1-D Lookup Table2'
   *   '<S53>/1-D Lookup Table2'
   *   '<S54>/1-D Lookup Table2'
   *   '<S55>/1-D Lookup Table2'
   *   '<S72>/1-D Lookup Table'
   *   '<S72>/1-D Lookup Table1'
   *   '<S73>/1-D Lookup Table'
   *   '<S73>/1-D Lookup Table1'
   *   '<S34>/1-D Lookup Table2'
   *   '<S35>/1-D Lookup Table2'
   *   '<S41>/1-D Lookup Table2'
   *   '<S50>/1-D Lookup Table2'
   *   '<S51>/1-D Lookup Table2'
   *   '<S77>/1-D Lookup Table2'
   *   '<S78>/1-D Lookup Table2'
   *   '<S81>/1-D Lookup Table2'
   *   '<S82>/1-D Lookup Table2'
   *   '<S85>/1-D Lookup Table2'
   *   '<S86>/1-D Lookup Table2'
   *   '<S88>/1-D Lookup Table2'
   *   '<S89>/1-D Lookup Table2'
   *   '<S91>/1-D Lookup Table2'
   *   '<S92>/1-D Lookup Table2'
   */
  { 0.0F, 1.75F, 3.5F, 5.25F, 7.0F },

  /* Computed Parameter: uDLookupTable2_tableData
   * Referenced by: '<S37>/1-D Lookup Table2'
   */
  { 0.8835F, 0.8835F, 0.6975F, 0.6975F, 0.6975F },

  /* Computed Parameter: uDLookupTable2_tableData_e
   * Referenced by: '<S44>/1-D Lookup Table2'
   */
  { 1.29874504F, 1.29874504F, 1.32525F, 1.32525F, 1.32525F },

  /* Computed Parameter: uDLookupTable2_tableData_o
   * Referenced by: '<S78>/1-D Lookup Table2'
   */
  { 0.8835F, 0.8835F, 0.8835F, 0.8835F, 0.8835F },

  /* Computed Parameter: uDLookupTable2_tableData_f
   * Referenced by: '<S82>/1-D Lookup Table2'
   */
  { 0.86583F, 0.86583F, 0.8835F, 0.8835F, 0.8835F },

  /* Computed Parameter: uDLookupTable2_tableData_ej
   * Referenced by: '<S85>/1-D Lookup Table2'
   */
  { 0.3534F, 0.3534F, 0.279F, 0.279F, 0.279F },

  /* Pooled Parameter (Expression: KlatlonI)
   * Referenced by:
   *   '<S89>/1-D Lookup Table2'
   *   '<S92>/1-D Lookup Table2'
   */
  { 0.1767F, 0.1767F, 0.1767F, 0.1767F, 0.1767F },

  /* Computed Parameter: uDLookupTable2_tableData_g
   * Referenced by: '<S63>/1-D Lookup Table2'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 4.1F, 4.1F,
    5.01F, 5.01F, 5.01F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, -4.1F, -4.1F, -3.18F, -3.18F, -3.18F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.33784F, -0.33784F, -0.53738F, -0.53738F,
    -0.53738F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.61F, -0.61F, -0.61F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.895F, -0.895F, -0.895F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 2.5F, 2.5F, 2.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, -0.357F, -0.357F, -0.357F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.5F, -0.5F, -0.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.12875F, 0.12875F, 0.12875F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S63>/Constant'
   *   '<S63>/1-D Lookup Table2'
   */
  { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F,
    13.0F, 14.0F, 15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 20.0F, 21.0F, 22.0F, 23.0F,
    24.0F, 25.0F, 26.0F, 27.0F, 28.0F, 29.0F, 30.0F, 31.0F, 32.0F, 33.0F, 34.0F,
    35.0F, 36.0F },

  /* Computed Parameter: uDLookupTable2_tableData_b
   * Referenced by: '<S62>/1-D Lookup Table2'
   */
  { -0.809770048F, -0.809770048F, -0.81569612F, -0.81569612F, -0.81569612F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0288108047F, -0.0288108047F,
    -0.0288108047F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.220689654F, 0.220689654F, 0.226950347F, 0.226950347F, 0.226950347F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.189803F, 0.189803F, 0.102564104F,
    0.102564104F, 0.102564104F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F,
    -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F,
    -0.0F, -0.0F, 0.696867287F, 0.696867287F, 0.354947686F, 0.354947686F,
    0.354947686F },

  /* Pooled Parameter (Expression: [1:16])
   * Referenced by:
   *   '<S62>/Constant'
   *   '<S62>/1-D Lookup Table2'
   */
  { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F,
    13.0F, 14.0F, 15.0F, 16.0F },

  /* Pooled Parameter (Expression: Klatlon)
   * Referenced by:
   *   '<S88>/1-D Lookup Table2'
   *   '<S91>/1-D Lookup Table2'
   */
  { 1.19897115F, 1.19897115F, 1.5525893F, 1.5525893F, 1.5525893F },

  /* Computed Parameter: uDLookupTable2_tableData_k
   * Referenced by: '<S86>/1-D Lookup Table2'
   */
  { 1.1895175F, 1.1895175F, 1.56837738F, 1.56837738F, 1.56837738F },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S15>/1-D Lookup Table'
   *   '<S15>/1-D Lookup Table3'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },

  /* Expression: VYdata'
   * Referenced by: '<S15>/1-D Lookup Table1'
   */
  { 0.0F, 0.4F, 0.8F, 1.2F, 1.6F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
    2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
    2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
    2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F,
    2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 1.9048F, 1.5238F, 1.1429F, 0.7619F,
    0.38095F, 0.0F },

  /* Expression: VZdata'
   * Referenced by: '<S15>/1-D Lookup Table2'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.63636F, -1.2727F, -1.75F, -1.75F,
    -1.2727F, -0.63636F, 0.0F, 0.0F, 0.15909F, 0.79545F, 1.4318F, 1.75F, 1.75F,
    1.1136F, 0.47727F, 0.0F, 0.0F, 0.0F, 0.31818F, 0.95455F, 1.5909F, 1.75F,
    1.5909F, 0.95455F, 0.31818F, 0.0F, 0.0F, 0.0F, -0.47727F, -1.1136F, -1.75F,
    -1.75F, -1.4318F, -0.79545F, -0.15909F, 0.0F, 0.0F, 0.0F, -0.63636F,
    -1.2727F, -1.75F, -1.75F, -1.2727F, -0.63636F, 0.0F, 0.0F, 0.15909F,
    0.79545F, 1.4318F, 1.75F, 1.75F, 1.1136F, 0.47727F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F },

  /* Computed Parameter: uDLookupTable2_tableData_j
   * Referenced by: '<S41>/1-D Lookup Table2'
   */
  { 0.05F, 0.05F, 0.575573742F, 0.575573742F, 0.575573742F },

  /* Computed Parameter: uDLookupTable2_tableData_ok
   * Referenced by: '<S36>/1-D Lookup Table2'
   */
  { 13.4329748F, 13.4329748F, 12.5736647F, 12.5736647F, 12.5736647F },

  /* Computed Parameter: uDLookupTable_tableData
   * Referenced by: '<S23>/1-D Lookup Table'
   */
  { 6.03728247F, 6.03728247F, 4.23799562F, 4.23799562F, 4.23799562F },

  /* Computed Parameter: uDLookupTable1_tableData_g
   * Referenced by: '<S23>/1-D Lookup Table1'
   */
  { 12.9291983F, 12.9291983F, 11.4796314F, 11.4796314F, 11.4796314F },

  /* Computed Parameter: uDLookupTable2_tableData_a
   * Referenced by: '<S27>/1-D Lookup Table2'
   */
  { 68.4127502F, 68.4127502F, 73.2033463F, 73.2033463F, 73.2033463F },

  /* Computed Parameter: uDLookupTable2_tableData_fu
   * Referenced by: '<S26>/1-D Lookup Table2'
   */
  { 9.47525F, 9.47525F, 10.2935343F, 10.2935343F, 10.2935343F },

  /* Computed Parameter: uDLookupTable_tableData_l
   * Referenced by: '<S22>/1-D Lookup Table'
   */
  { 17.010458F, 17.010458F, 16.7483501F, 16.7483501F, 16.7483501F },

  /* Computed Parameter: uDLookupTable1_tableData_n
   * Referenced by: '<S22>/1-D Lookup Table1'
   */
  { 10.3247509F, 10.3247509F, 10.4863319F, 10.4863319F, 10.4863319F },

  /* Computed Parameter: uDLookupTable2_tableData_ex
   * Referenced by: '<S43>/1-D Lookup Table2'
   */
  { 66.8576584F, 66.8576584F, 74.7438354F, 74.7438354F, 74.7438354F },

  /* Computed Parameter: uDLookupTable2_tableData_c
   * Referenced by: '<S42>/1-D Lookup Table2'
   */
  { 9.17511F, 9.17511F, 10.6743212F, 10.6743212F, 10.6743212F },

  /* Computed Parameter: uDLookupTable_tableData_m
   * Referenced by: '<S24>/1-D Lookup Table'
   */
  { 16.7384167F, 16.7384167F, 16.2591705F, 16.2591705F, 16.2591705F },

  /* Computed Parameter: uDLookupTable1_tableData_d
   * Referenced by: '<S24>/1-D Lookup Table1'
   */
  { 10.0770493F, 10.0770493F, 10.8018274F, 10.8018274F, 10.8018274F },

  /* Computed Parameter: uDLookupTable2_tableData_au
   * Referenced by: '<S53>/1-D Lookup Table2'
   */
  { 61.6084328F, 61.6084328F, 43.5334473F, 43.5334473F, 43.5334473F },

  /* Computed Parameter: uDLookupTable2_tableData_c0
   * Referenced by: '<S55>/1-D Lookup Table2'
   */
  { 11.9398546F, 11.9398546F, 7.0610714F, 7.0610714F, 7.0610714F },

  /* Computed Parameter: uDLookupTable_tableData_h
   * Referenced by: '<S25>/1-D Lookup Table'
   */
  { 14.0121517F, 14.0121517F, 24.9801807F, 24.9801807F, 24.9801807F },

  /* Computed Parameter: uDLookupTable1_tableData_f
   * Referenced by: '<S25>/1-D Lookup Table1'
   */
  { 12.5340319F, 12.5340319F, 7.03072405F, 7.03072405F, 7.03072405F },

  /* Computed Parameter: uDLookupTable2_tableData_kg
   * Referenced by: '<S81>/1-D Lookup Table2'
   */
  { 0.152694166F, 0.152694166F, 0.0786659196F, 0.0786659196F, 0.0786659196F },

  /* Computed Parameter: uDLookupTable_tableData_d
   * Referenced by: '<S73>/1-D Lookup Table'
   */
  { 28.9773388F, 28.9773388F, 42.2626495F, 42.2626495F, 42.2626495F },

  /* Computed Parameter: uDLookupTable1_tableData_m
   * Referenced by: '<S73>/1-D Lookup Table1'
   */
  { 0.646765411F, 0.646765411F, 0.461738825F, 0.461738825F, 0.461738825F },

  /* Computed Parameter: uDLookupTable2_tableData_or
   * Referenced by: '<S50>/1-D Lookup Table2'
   */
  { 1.67466819F, 1.67466819F, 1.99520171F, 1.99520171F, 1.99520171F },

  /* Computed Parameter: uDLookupTable2_tableData_gp
   * Referenced by: '<S51>/1-D Lookup Table2'
   */
  { 6.69867277F, 6.69867277F, 7.98080683F, 7.98080683F, 7.98080683F },

  /* Computed Parameter: uDLookupTable2_tableData_n
   * Referenced by: '<S77>/1-D Lookup Table2'
   */
  { 0.187895119F, 0.187895119F, 0.0659289658F, 0.0659289658F, 0.0659289658F },

  /* Computed Parameter: uDLookupTable_tableData_hs
   * Referenced by: '<S72>/1-D Lookup Table'
   */
  { 22.0453568F, 22.0453568F, 44.7723618F, 44.7723618F, 44.7723618F },

  /* Computed Parameter: uDLookupTable1_tableData_p
   * Referenced by: '<S72>/1-D Lookup Table1'
   */
  { 0.885188937F, 0.885188937F, 0.435856074F, 0.435856074F, 0.435856074F },

  /* Computed Parameter: uDLookupTable2_tableData_ob
   * Referenced by: '<S34>/1-D Lookup Table2'
   */
  { 1.88871968F, 1.88871968F, 2.16057444F, 2.16057444F, 2.16057444F },

  /* Computed Parameter: uDLookupTable2_tableData_l
   * Referenced by: '<S35>/1-D Lookup Table2'
   */
  { 7.55487871F, 7.55487871F, 8.64229774F, 8.64229774F, 8.64229774F }
};
