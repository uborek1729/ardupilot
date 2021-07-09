/*
 * QS_InnerRateLoop_data.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "QS_InnerRateLoop".
 *
 * Model version              : 1.539
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C++ source code generated on : Thu Jul  8 22:32:02 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "QS_InnerRateLoop.h"
#include "QS_InnerRateLoop_private.h"

/* Invariant block signals (default storage) */
const ConstB_QS_InnerRateLoop_T QS_InnerRateLoop_ConstB = {
  1.0F
  ,                                    /* '<S9>/Trigonometric Function2' */
  0.0F
  ,                                    /* '<S9>/Trigonometric Function5' */
  0.0F
  ,                                    /* '<S9>/Trigonometric Function4' */
  1.0F
  ,                                    /* '<S9>/Trigonometric Function1' */
  1.0F
  ,                                    /* '<S8>/Trigonometric Function3' */
  0.0F
  ,                                    /* '<S8>/Trigonometric Function6' */
  1.0F
  ,                                    /* '<S72>/Trigonometric Function1' */
  0.0F
  ,                                    /* '<S72>/Trigonometric Function5' */
  0.0F
  ,                                    /* '<S72>/Trigonometric Function4' */
  1.0F
  ,                                    /* '<S72>/Trigonometric Function2' */
  1.0F
  ,                                    /* '<S103>/Trigonometric Function1' */
  0.0F
  ,                                    /* '<S103>/Trigonometric Function5' */
  0.0F
  ,                                    /* '<S103>/Trigonometric Function4' */
  1.0F
  ,                                    /* '<S103>/Trigonometric Function2' */
  0.0F
  ,                                    /* '<S71>/Trigonometric Function4' */
  0.0F
  ,                                    /* '<S71>/Trigonometric Function5' */
  1.0F
  ,                                    /* '<S71>/Trigonometric Function1' */
  1.0F
  ,                                    /* '<S71>/Trigonometric Function2' */
  52.4F
  ,                                    /* '<S12>/Sum2' */
  32.4F
  /* '<S12>/Sum1' */
};

/* Constant parameters (default storage) */
const ConstP_QS_InnerRateLoop_T QS_InnerRateLoop_ConstP = {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S29>/1-D Lookup Table2'
   *   '<S55>/1-D Lookup Table2'
   */
  { 1.395F, 1.395F, 1.395F, 1.395F, 1.395F },

  /* Pooled Parameter (Expression: bpV)
   * Referenced by:
   *   '<S23>/1-D Lookup Table'
   *   '<S23>/1-D Lookup Table1'
   *   '<S24>/1-D Lookup Table'
   *   '<S24>/1-D Lookup Table1'
   *   '<S25>/1-D Lookup Table'
   *   '<S25>/1-D Lookup Table1'
   *   '<S26>/1-D Lookup Table'
   *   '<S26>/1-D Lookup Table1'
   *   '<S63>/1-D Lookup Table2'
   *   '<S64>/1-D Lookup Table2'
   *   '<S27>/1-D Lookup Table2'
   *   '<S28>/1-D Lookup Table2'
   *   '<S29>/1-D Lookup Table2'
   *   '<S37>/1-D Lookup Table2'
   *   '<S38>/1-D Lookup Table2'
   *   '<S43>/1-D Lookup Table2'
   *   '<S44>/1-D Lookup Table2'
   *   '<S45>/1-D Lookup Table2'
   *   '<S54>/1-D Lookup Table2'
   *   '<S55>/1-D Lookup Table2'
   *   '<S56>/1-D Lookup Table2'
   *   '<S73>/1-D Lookup Table'
   *   '<S73>/1-D Lookup Table1'
   *   '<S74>/1-D Lookup Table'
   *   '<S74>/1-D Lookup Table1'
   *   '<S35>/1-D Lookup Table2'
   *   '<S36>/1-D Lookup Table2'
   *   '<S42>/1-D Lookup Table2'
   *   '<S51>/1-D Lookup Table2'
   *   '<S52>/1-D Lookup Table2'
   *   '<S78>/1-D Lookup Table2'
   *   '<S79>/1-D Lookup Table2'
   *   '<S82>/1-D Lookup Table2'
   *   '<S83>/1-D Lookup Table2'
   *   '<S86>/1-D Lookup Table2'
   *   '<S87>/1-D Lookup Table2'
   *   '<S89>/1-D Lookup Table2'
   *   '<S90>/1-D Lookup Table2'
   *   '<S92>/1-D Lookup Table2'
   *   '<S93>/1-D Lookup Table2'
   */
  { 0.0F, 1.75F, 3.5F, 5.25F, 7.0F },

  /* Computed Parameter: uDLookupTable2_tableData
   * Referenced by: '<S38>/1-D Lookup Table2'
   */
  { 0.93F, 0.93F, 0.6975F, 0.6975F, 0.6975F },

  /* Computed Parameter: uDLookupTable2_tableData_e
   * Referenced by: '<S45>/1-D Lookup Table2'
   */
  { 1.3671F, 1.3671F, 1.395F, 1.395F, 1.395F },

  /* Computed Parameter: uDLookupTable2_tableData_o
   * Referenced by: '<S79>/1-D Lookup Table2'
   */
  { 0.93F, 0.93F, 0.93F, 0.93F, 0.93F },

  /* Computed Parameter: uDLookupTable2_tableData_f
   * Referenced by: '<S83>/1-D Lookup Table2'
   */
  { 0.9114F, 0.9114F, 0.93F, 0.93F, 0.93F },

  /* Computed Parameter: uDLookupTable2_tableData_ej
   * Referenced by: '<S86>/1-D Lookup Table2'
   */
  { 0.372F, 0.372F, 0.279F, 0.279F, 0.279F },

  /* Pooled Parameter (Expression: KlatlonI)
   * Referenced by:
   *   '<S90>/1-D Lookup Table2'
   *   '<S93>/1-D Lookup Table2'
   */
  { 0.186F, 0.186F, 0.186F, 0.186F, 0.186F },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S64>/Constant'
   *   '<S64>/1-D Lookup Table2'
   */
  { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F,
    13.0F, 14.0F, 15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 20.0F, 21.0F, 22.0F, 23.0F,
    24.0F, 25.0F, 26.0F, 27.0F, 28.0F, 29.0F, 30.0F, 31.0F, 32.0F, 33.0F, 34.0F,
    35.0F, 36.0F },

  /* Computed Parameter: uDLookupTable2_tableData_g
   * Referenced by: '<S64>/1-D Lookup Table2'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 4.1F, 4.1F,
    2.505F, 2.505F, 2.505F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, -4.1F, -4.1F, -3.18F, -3.18F, -3.18F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.33784F, -0.33784F, -0.53738F, -0.53738F,
    -0.53738F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.305F, -0.305F,
    -0.305F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, -0.895F, -0.895F, -0.895F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 5.0F, 5.0F, 5.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.357F, -0.357F, -0.357F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.5F, -0.5F, -0.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 1.03F, 1.03F, 1.03F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F },

  /* Pooled Parameter (Expression: [1:16])
   * Referenced by:
   *   '<S63>/Constant'
   *   '<S63>/1-D Lookup Table2'
   */
  { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F,
    13.0F, 14.0F, 15.0F, 16.0F },

  /* Computed Parameter: uDLookupTable2_tableData_b
   * Referenced by: '<S63>/1-D Lookup Table2'
   */
  { -0.025305314F, -0.025305314F, -0.0254905038F, -0.0254905038F, -0.0254905038F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.000900337647F, -0.000900337647F,
    -0.000900337647F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0068965517F, 0.0068965517F, 0.00709219836F, 0.00709219836F,
    0.00709219836F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0F, -0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00593134388F,
    0.00593134388F, 0.00641025649F, 0.00641025649F, 0.00641025649F, -0.0F, -0.0F,
    0.0F, 0.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F,
    -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, 0.0871084109F,
    0.0871084109F, 0.0887369215F, 0.0887369215F, 0.0887369215F },

  /* Pooled Parameter (Expression: Klatlon)
   * Referenced by:
   *   '<S89>/1-D Lookup Table2'
   *   '<S92>/1-D Lookup Table2'
   */
  { 1.10032868F, 1.10032868F, 1.53239489F, 1.53239489F, 1.53239489F },

  /* Computed Parameter: uDLookupTable2_tableData_k
   * Referenced by: '<S87>/1-D Lookup Table2'
   */
  { 1.27092195F, 1.27092195F, 1.56805921F, 1.56805921F, 1.56805921F },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S12>/1-D Lookup Table'
   *   '<S12>/1-D Lookup Table2'
   *   '<S12>/1-D Lookup Table3'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  /* Expression: VYdata'
   * Referenced by: '<S12>/1-D Lookup Table1'
   */
  { 0.0F, 0.27429F, 0.54857F, 0.82286F, 1.0971F, 1.3714F, 1.6457F, 1.92F,
    2.1943F, 2.4686F, 2.7429F, 3.0171F, 3.2914F, 3.5657F, 3.84F, 4.1143F,
    4.0457F, 3.7714F, 3.4971F, 3.2229F, 2.9486F, 2.6743F, 2.4F, 2.1257F, 1.8514F,
    1.5771F, 1.3029F, 1.0286F, 0.75429F, 0.48F, 0.20571F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F },

  /* Computed Parameter: uDLookupTable2_tableData_j
   * Referenced by: '<S42>/1-D Lookup Table2'
   */
  { 0.05F, 0.05F, 0.575429142F, 0.575429142F, 0.575429142F },

  /* Computed Parameter: uDLookupTable2_tableData_ok
   * Referenced by: '<S37>/1-D Lookup Table2'
   */
  { 13.8948441F, 13.8948441F, 12.1517277F, 12.1517277F, 12.1517277F },

  /* Computed Parameter: uDLookupTable_tableData
   * Referenced by: '<S24>/1-D Lookup Table'
   */
  { 6.4624095F, 6.4624095F, 4.22524357F, 4.22524357F, 4.22524357F },

  /* Computed Parameter: uDLookupTable1_tableData_g
   * Referenced by: '<S24>/1-D Lookup Table1'
   */
  { 13.3835526F, 13.3835526F, 11.5142775F, 11.5142775F, 11.5142775F },

  /* Computed Parameter: uDLookupTable2_tableData_a
   * Referenced by: '<S28>/1-D Lookup Table2'
   */
  { 74.3660049F, 74.3660049F, 79.0965118F, 79.0965118F, 79.0965118F },

  /* Computed Parameter: uDLookupTable2_tableData_fu
   * Referenced by: '<S27>/1-D Lookup Table2'
   */
  { 9.68285179F, 9.68285179F, 10.4349728F, 10.4349728F, 10.4349728F },

  /* Computed Parameter: uDLookupTable_tableData_l
   * Referenced by: '<S23>/1-D Lookup Table'
   */
  { 18.469429F, 18.469429F, 18.2494831F, 18.2494831F, 18.2494831F },

  /* Computed Parameter: uDLookupTable1_tableData_n
   * Referenced by: '<S23>/1-D Lookup Table1'
   */
  { 10.5364656F, 10.5364656F, 10.6634521F, 10.6634521F, 10.6634521F },

  /* Computed Parameter: uDLookupTable2_tableData_ex
   * Referenced by: '<S44>/1-D Lookup Table2'
   */
  { 72.7000046F, 72.7000046F, 80.6645279F, 80.6645279F, 80.6645279F },

  /* Computed Parameter: uDLookupTable2_tableData_c
   * Referenced by: '<S43>/1-D Lookup Table2'
   */
  { 9.37461853F, 9.37461853F, 10.8184862F, 10.8184862F, 10.8184862F },

  /* Computed Parameter: uDLookupTable_tableData_m
   * Referenced by: '<S25>/1-D Lookup Table'
   */
  { 18.1789932F, 18.1789932F, 17.7086353F, 17.7086353F, 17.7086353F },

  /* Computed Parameter: uDLookupTable1_tableData_d
   * Referenced by: '<S25>/1-D Lookup Table1'
   */
  { 10.2808905F, 10.2808905F, 10.989131F, 10.989131F, 10.989131F },

  /* Computed Parameter: uDLookupTable2_tableData_au
   * Referenced by: '<S54>/1-D Lookup Table2'
   */
  { 61.9079514F, 61.9079514F, 44.0603371F, 44.0603371F, 44.0603371F },

  /* Computed Parameter: uDLookupTable2_tableData_c0
   * Referenced by: '<S56>/1-D Lookup Table2'
   */
  { 11.19275F, 11.19275F, 6.49346828F, 6.49346828F, 6.49346828F },

  /* Computed Parameter: uDLookupTable_tableData_h
   * Referenced by: '<S26>/1-D Lookup Table'
   */
  { 16.530386F, 16.530386F, 29.8244877F, 29.8244877F, 29.8244877F },

  /* Computed Parameter: uDLookupTable1_tableData_f
   * Referenced by: '<S26>/1-D Lookup Table1'
   */
  { 11.7724104F, 11.7724104F, 6.52492332F, 6.52492332F, 6.52492332F },

  /* Computed Parameter: uDLookupTable2_tableData_kg
   * Referenced by: '<S82>/1-D Lookup Table2'
   */
  { 0.238385901F, 0.238385901F, 0.0548932962F, 0.0548932962F, 0.0548932962F },

  /* Computed Parameter: uDLookupTable_tableData_d
   * Referenced by: '<S74>/1-D Lookup Table'
   */
  { 16.5300274F, 16.5300274F, 77.0379944F, 77.0379944F, 77.0379944F },

  /* Computed Parameter: uDLookupTable1_tableData_m
   * Referenced by: '<S74>/1-D Lookup Table1'
   */
  { 1.25627434F, 1.25627434F, 0.280673206F, 0.280673206F, 0.280673206F },

  /* Computed Parameter: uDLookupTable2_tableData_or
   * Referenced by: '<S51>/1-D Lookup Table2'
   */
  { 2.19574881F, 2.19574881F, 1.93458939F, 1.93458939F, 1.93458939F },

  /* Computed Parameter: uDLookupTable2_tableData_gp
   * Referenced by: '<S52>/1-D Lookup Table2'
   */
  { 8.78299522F, 8.78299522F, 7.73835754F, 7.73835754F, 7.73835754F },

  /* Computed Parameter: uDLookupTable2_tableData_n
   * Referenced by: '<S78>/1-D Lookup Table2'
   */
  { 0.264179349F, 0.264179349F, 0.0672647133F, 0.0672647133F, 0.0672647133F },

  /* Computed Parameter: uDLookupTable_tableData_hs
   * Referenced by: '<S73>/1-D Lookup Table'
   */
  { 14.3028345F, 14.3028345F, 44.4350777F, 44.4350777F, 44.4350777F },

  /* Computed Parameter: uDLookupTable1_tableData_p
   * Referenced by: '<S73>/1-D Lookup Table1'
   */
  { 1.51176333F, 1.51176333F, 0.486608773F, 0.486608773F, 0.486608773F },

  /* Computed Parameter: uDLookupTable2_tableData_ob
   * Referenced by: '<S35>/1-D Lookup Table2'
   */
  { 2.44883442F, 2.44883442F, 2.37146235F, 2.37146235F, 2.37146235F },

  /* Computed Parameter: uDLookupTable2_tableData_l
   * Referenced by: '<S36>/1-D Lookup Table2'
   */
  { 9.79533768F, 9.79533768F, 9.48584938F, 9.48584938F, 9.48584938F }
};
