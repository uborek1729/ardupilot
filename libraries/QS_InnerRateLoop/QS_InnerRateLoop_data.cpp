//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: QS_InnerRateLoop_data.cpp
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
#include "QS_InnerRateLoop.h"
#include "QS_InnerRateLoop_private.h"

// Invariant block signals (default storage)
const ConstBlockIO_QS_InnerRateLoop_T QS_InnerRateLoop_ConstB = {
  1.0F
  ,                                    // '<S8>/Trigonometric Function2'
  0.0F
  ,                                    // '<S8>/Trigonometric Function5'
  0.0F
  ,                                    // '<S8>/Trigonometric Function4'
  1.0F
  ,                                    // '<S8>/Trigonometric Function1'
  1.0F
  ,                                    // '<S7>/Trigonometric Function3'
  0.0F
  ,                                    // '<S7>/Trigonometric Function6'
  1.0F
  ,                                    // '<S67>/Trigonometric Function1'
  0.0F
  ,                                    // '<S67>/Trigonometric Function5'
  0.0F
  ,                                    // '<S67>/Trigonometric Function4'
  1.0F
  ,                                    // '<S67>/Trigonometric Function2'
  1.0F
  ,                                    // '<S93>/Trigonometric Function1'
  0.0F
  ,                                    // '<S93>/Trigonometric Function5'
  0.0F
  ,                                    // '<S93>/Trigonometric Function4'
  1.0F
  ,                                    // '<S93>/Trigonometric Function2'
  0.0F
  ,                                    // '<S66>/Trigonometric Function4'
  0.0F
  ,                                    // '<S66>/Trigonometric Function5'
  1.0F
  ,                                    // '<S66>/Trigonometric Function1'
  1.0F
  ,                                    // '<S66>/Trigonometric Function2'
  52.104F
  ,                                    // '<S11>/Sum2'
  32.104F
  // '<S11>/Sum1'
};

// Constant parameters (default storage)
const ConstParam_QS_InnerRateLoop_T QS_InnerRateLoop_ConstP = {
  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S24>/1-D Lookup Table2'
  //    '<S50>/1-D Lookup Table2'

  { 1.56937504F, 1.56937504F, 1.56937504F, 1.56937504F, 1.56937504F },

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

  { 0.0F, 1.75F, 3.5F, 5.25F, 7.0F },

  // Computed Parameter: uDLookupTable2_tableData
  //  Referenced by: '<S33>/1-D Lookup Table2'

  { 1.04625F, 1.04625F, 0.6975F, 0.6975F, 0.6975F },

  // Computed Parameter: uDLookupTable2_tableData_e
  //  Referenced by: '<S40>/1-D Lookup Table2'

  { 1.53798699F, 1.53798699F, 1.56937504F, 1.56937504F, 1.56937504F },

  // Computed Parameter: uDLookupTable2_tableData_o
  //  Referenced by: '<S74>/1-D Lookup Table2'

  { 1.04625F, 1.04625F, 1.04625F, 1.04625F, 1.04625F },

  // Computed Parameter: uDLookupTable2_tableData_f
  //  Referenced by: '<S78>/1-D Lookup Table2'

  { 1.0253247F, 1.0253247F, 1.04625F, 1.04625F, 1.04625F },

  // Computed Parameter: uDLookupTable2_tableData_ej
  //  Referenced by: '<S81>/1-D Lookup Table2'

  { 0.4185F, 0.4185F, 0.279F, 0.279F, 0.279F },

  // Pooled Parameter (Expression: KlatlonI)
  //  Referenced by:
  //    '<S85>/1-D Lookup Table2'
  //    '<S88>/1-D Lookup Table2'

  { 0.20925F, 0.20925F, 0.20925F, 0.20925F, 0.20925F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S59>/Constant'
  //    '<S59>/1-D Lookup Table2'

  { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F,
    13.0F, 14.0F, 15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 20.0F, 21.0F, 22.0F, 23.0F,
    24.0F, 25.0F, 26.0F, 27.0F, 28.0F, 29.0F, 30.0F, 31.0F, 32.0F, 33.0F, 34.0F,
    35.0F, 36.0F },

  // Computed Parameter: uDLookupTable2_tableData_g
  //  Referenced by: '<S59>/1-D Lookup Table2'

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

  // Pooled Parameter (Expression: [1:16])
  //  Referenced by:
  //    '<S58>/Constant'
  //    '<S58>/1-D Lookup Table2'

  { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F,
    13.0F, 14.0F, 15.0F, 16.0F },

  // Computed Parameter: uDLookupTable2_tableData_b
  //  Referenced by: '<S58>/1-D Lookup Table2'

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

  // Pooled Parameter (Expression: Klatlon)
  //  Referenced by:
  //    '<S84>/1-D Lookup Table2'
  //    '<S87>/1-D Lookup Table2'

  { 1.08906353F, 1.08906353F, 1.83910441F, 1.83910441F, 1.83910441F },

  // Computed Parameter: uDLookupTable2_tableData_k
  //  Referenced by: '<S82>/1-D Lookup Table2'

  { 1.59535158F, 1.59535158F, 1.56877232F, 1.56877232F, 1.56877232F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S11>/1-D Lookup Table'
  //    '<S11>/1-D Lookup Table2'
  //    '<S11>/1-D Lookup Table3'

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Expression: VYdata'
  //  Referenced by: '<S11>/1-D Lookup Table1'

  { 0.0F, 0.27429F, 0.54857F, 0.82286F, 1.0971F, 1.3714F, 1.6457F, 1.92F,
    2.1943F, 2.4686F, 2.7429F, 3.0171F, 3.2914F, 3.5657F, 3.84F, 4.1143F,
    4.0457F, 3.7714F, 3.4971F, 3.2229F, 2.9486F, 2.6743F, 2.4F, 2.1257F, 1.8514F,
    1.5771F, 1.3029F, 1.0286F, 0.75429F, 0.48F, 0.20571F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F },

  // Computed Parameter: uDLookupTable2_tableData_j
  //  Referenced by: '<S37>/1-D Lookup Table2'

  { 0.05F, 0.05F, 0.575780869F, 0.575780869F, 0.575780869F },

  // Computed Parameter: uDLookupTable2_tableData_ok
  //  Referenced by: '<S32>/1-D Lookup Table2'

  { 15.0997801F, 15.0997801F, 13.4657078F, 13.4657078F, 13.4657078F },

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S19>/1-D Lookup Table'

  { 7.51929808F, 7.51929808F, 4.16576815F, 4.16576815F, 4.16576815F },

  // Computed Parameter: uDLookupTable1_tableData_g
  //  Referenced by: '<S19>/1-D Lookup Table1'

  { 14.5577288F, 14.5577288F, 11.678668F, 11.678668F, 11.678668F },

  // Computed Parameter: uDLookupTable2_tableData_a
  //  Referenced by: '<S23>/1-D Lookup Table2'

  { 90.2208557F, 90.2208557F, 94.6370926F, 94.6370926F, 94.6370926F },

  // Computed Parameter: uDLookupTable2_tableData_fu
  //  Referenced by: '<S22>/1-D Lookup Table2'

  { 9.94392776F, 9.94392776F, 10.5055914F, 10.5055914F, 10.5055914F },

  // Computed Parameter: uDLookupTable_tableData_l
  //  Referenced by: '<S18>/1-D Lookup Table'

  { 22.6993046F, 22.6993046F, 22.6513653F, 22.6513653F, 22.6513653F },

  // Computed Parameter: uDLookupTable1_tableData_n
  //  Referenced by: '<S18>/1-D Lookup Table1'

  { 10.8502789F, 10.8502789F, 10.8732424F, 10.8732424F, 10.8732424F },

  // Computed Parameter: uDLookupTable2_tableData_ex
  //  Referenced by: '<S39>/1-D Lookup Table2'

  { 88.2629166F, 88.2629166F, 94.9927597F, 94.9927597F, 94.9927597F },

  // Computed Parameter: uDLookupTable2_tableData_c
  //  Referenced by: '<S38>/1-D Lookup Table2'

  { 9.62364388F, 9.62364388F, 10.6281157F, 10.6281157F, 10.6281157F },

  // Computed Parameter: uDLookupTable_tableData_m
  //  Referenced by: '<S20>/1-D Lookup Table'

  { 22.3370609F, 22.3370609F, 22.462904F, 22.462904F, 22.462904F },

  // Computed Parameter: uDLookupTable1_tableData_d
  //  Referenced by: '<S20>/1-D Lookup Table1'

  { 10.5895939F, 10.5895939F, 10.964468F, 10.964468F, 10.964468F },

  // Computed Parameter: uDLookupTable2_tableData_au
  //  Referenced by: '<S49>/1-D Lookup Table2'

  { 63.2989F, 63.2989F, 52.0198517F, 52.0198517F, 52.0198517F },

  // Computed Parameter: uDLookupTable2_tableData_c0
  //  Referenced by: '<S51>/1-D Lookup Table2'

  { 9.08854294F, 9.08854294F, 6.2368412F, 6.2368412F, 6.2368412F },

  // Computed Parameter: uDLookupTable_tableData_h
  //  Referenced by: '<S21>/1-D Lookup Table'

  { 25.4207115F, 25.4207115F, 38.5452385F, 38.5452385F, 38.5452385F },

  // Computed Parameter: uDLookupTable1_tableData_f
  //  Referenced by: '<S21>/1-D Lookup Table1'

  { 9.68870544F, 9.68870544F, 6.38973284F, 6.38973284F, 6.38973284F },

  // Computed Parameter: uDLookupTable2_tableData_kg
  //  Referenced by: '<S77>/1-D Lookup Table2'

  { 0.246534154F, 0.246534154F, 0.0227353368F, 0.0227353368F, 0.0227353368F },

  // Computed Parameter: uDLookupTable_tableData_d
  //  Referenced by: '<S69>/1-D Lookup Table'

  { 22.6906071F, 22.6906071F, 182.874084F, 182.874084F, 182.874084F },

  // Computed Parameter: uDLookupTable1_tableData_m
  //  Referenced by: '<S69>/1-D Lookup Table1'

  { 1.15828836F, 1.15828836F, 0.149643824F, 0.149643824F, 0.149643824F },

  // Computed Parameter: uDLookupTable2_tableData_or
  //  Referenced by: '<S46>/1-D Lookup Table2'

  { 2.19307184F, 2.19307184F, 2.23700905F, 2.23700905F, 2.23700905F },

  // Computed Parameter: uDLookupTable2_tableData_gp
  //  Referenced by: '<S47>/1-D Lookup Table2'

  { 8.77228737F, 8.77228737F, 8.94803619F, 8.94803619F, 8.94803619F },

  // Computed Parameter: uDLookupTable2_tableData_n
  //  Referenced by: '<S73>/1-D Lookup Table2'

  { 0.272078723F, 0.272078723F, 0.0343090817F, 0.0343090817F, 0.0343090817F },

  // Computed Parameter: uDLookupTable_tableData_hs
  //  Referenced by: '<S68>/1-D Lookup Table'

  { 19.9759369F, 19.9759369F, 130.158905F, 130.158905F, 130.158905F },

  // Computed Parameter: uDLookupTable1_tableData_p
  //  Referenced by: '<S68>/1-D Lookup Table1'

  { 1.3699472F, 1.3699472F, 0.210250512F, 0.210250512F, 0.210250512F },

  // Computed Parameter: uDLookupTable2_tableData_ob
  //  Referenced by: '<S30>/1-D Lookup Table2'

  { 2.39204073F, 2.39204073F, 2.29604816F, 2.29604816F, 2.29604816F },

  // Computed Parameter: uDLookupTable2_tableData_l
  //  Referenced by: '<S31>/1-D Lookup Table2'

  { 9.56816292F, 9.56816292F, 9.18419266F, 9.18419266F, 9.18419266F }
};

//
// File trailer for generated code.
//
// [EOF]
//
