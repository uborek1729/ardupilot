//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: QS_InnerRateLoop_data.cpp
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
#include "QS_InnerRateLoop.h"
#include "QS_InnerRateLoop_private.h"

// Invariant block signals (default storage)
const ConstBlockIO_QS_InnerRateLoop_T QS_InnerRateLoop_ConstB = {
  1.0F
  ,                                    // '<S6>/Trigonometric Function2'
  0.0F
  ,                                    // '<S6>/Trigonometric Function5'
  0.0F
  ,                                    // '<S6>/Trigonometric Function4'
  1.0F
  ,                                    // '<S6>/Trigonometric Function1'
  1.0F
  ,                                    // '<S5>/Trigonometric Function3'
  0.0F
  ,                                    // '<S5>/Trigonometric Function6'
  1.0F
  ,                                    // '<S60>/Trigonometric Function1'
  0.0F
  ,                                    // '<S60>/Trigonometric Function5'
  0.0F
  ,                                    // '<S60>/Trigonometric Function4'
  1.0F
  ,                                    // '<S60>/Trigonometric Function2'
  1.0F
  ,                                    // '<S86>/Trigonometric Function1'
  0.0F
  ,                                    // '<S86>/Trigonometric Function5'
  0.0F
  ,                                    // '<S86>/Trigonometric Function4'
  1.0F
  ,                                    // '<S86>/Trigonometric Function2'
  0.0F
  ,                                    // '<S59>/Trigonometric Function4'
  0.0F
  ,                                    // '<S59>/Trigonometric Function5'
  1.0F
  ,                                    // '<S59>/Trigonometric Function1'
  1.0F
  ,                                    // '<S59>/Trigonometric Function2'
  71.304F
  ,                                    // '<S9>/Sum2'
  51.304F
  // '<S9>/Sum1'
};

// Constant parameters (default storage)
const ConstParam_QS_InnerRateLoop_T QS_InnerRateLoop_ConstP = {
  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S17>/1-D Lookup Table2'
  //    '<S43>/1-D Lookup Table2'

  { 1.395F, 1.395F, 1.395F, 1.395F, 1.395F },

  // Pooled Parameter (Expression: bpV)
  //  Referenced by:
  //    '<S11>/1-D Lookup Table'
  //    '<S11>/1-D Lookup Table1'
  //    '<S12>/1-D Lookup Table'
  //    '<S12>/1-D Lookup Table1'
  //    '<S13>/1-D Lookup Table'
  //    '<S13>/1-D Lookup Table1'
  //    '<S14>/1-D Lookup Table'
  //    '<S14>/1-D Lookup Table1'
  //    '<S51>/1-D Lookup Table2'
  //    '<S52>/1-D Lookup Table2'
  //    '<S15>/1-D Lookup Table2'
  //    '<S16>/1-D Lookup Table2'
  //    '<S17>/1-D Lookup Table2'
  //    '<S25>/1-D Lookup Table2'
  //    '<S26>/1-D Lookup Table2'
  //    '<S31>/1-D Lookup Table2'
  //    '<S32>/1-D Lookup Table2'
  //    '<S33>/1-D Lookup Table2'
  //    '<S42>/1-D Lookup Table2'
  //    '<S43>/1-D Lookup Table2'
  //    '<S44>/1-D Lookup Table2'
  //    '<S61>/1-D Lookup Table'
  //    '<S61>/1-D Lookup Table1'
  //    '<S62>/1-D Lookup Table'
  //    '<S62>/1-D Lookup Table1'
  //    '<S23>/1-D Lookup Table2'
  //    '<S24>/1-D Lookup Table2'
  //    '<S30>/1-D Lookup Table2'
  //    '<S39>/1-D Lookup Table2'
  //    '<S40>/1-D Lookup Table2'
  //    '<S66>/1-D Lookup Table2'
  //    '<S67>/1-D Lookup Table2'
  //    '<S70>/1-D Lookup Table2'
  //    '<S71>/1-D Lookup Table2'
  //    '<S74>/1-D Lookup Table2'
  //    '<S75>/1-D Lookup Table2'
  //    '<S77>/1-D Lookup Table2'
  //    '<S78>/1-D Lookup Table2'
  //    '<S80>/1-D Lookup Table2'
  //    '<S81>/1-D Lookup Table2'

  { 0.0F, 1.75F, 3.5F, 5.25F, 7.0F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S26>/1-D Lookup Table2'
  //    '<S67>/1-D Lookup Table2'

  { 0.93F, 0.93F, 0.93F, 0.93F, 0.93F },

  // Computed Parameter: uDLookupTable2_tableData
  //  Referenced by: '<S33>/1-D Lookup Table2'

  { 1.3671F, 1.3671F, 1.395F, 1.395F, 1.395F },

  // Computed Parameter: uDLookupTable2_tableData_f
  //  Referenced by: '<S71>/1-D Lookup Table2'

  { 0.9114F, 0.9114F, 0.93F, 0.93F, 0.93F },

  // Computed Parameter: uDLookupTable2_tableData_e
  //  Referenced by: '<S74>/1-D Lookup Table2'

  { 0.372F, 0.372F, 0.372F, 0.372F, 0.372F },

  // Pooled Parameter (Expression: KlatlonI)
  //  Referenced by:
  //    '<S78>/1-D Lookup Table2'
  //    '<S81>/1-D Lookup Table2'

  { 0.186F, 0.186F, 0.186F, 0.186F, 0.186F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S52>/Constant'
  //    '<S52>/1-D Lookup Table2'

  { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F,
    13.0F, 14.0F, 15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 20.0F, 21.0F, 22.0F, 23.0F,
    24.0F, 25.0F, 26.0F, 27.0F, 28.0F, 29.0F, 30.0F, 31.0F, 32.0F, 33.0F, 34.0F,
    35.0F, 36.0F },

  // Computed Parameter: uDLookupTable2_tableData_g
  //  Referenced by: '<S52>/1-D Lookup Table2'

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
  //    '<S51>/Constant'
  //    '<S51>/1-D Lookup Table2'

  { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F,
    13.0F, 14.0F, 15.0F, 16.0F },

  // Computed Parameter: uDLookupTable2_tableData_b
  //  Referenced by: '<S51>/1-D Lookup Table2'

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
  //    '<S77>/1-D Lookup Table2'
  //    '<S80>/1-D Lookup Table2'

  { 1.06200528F, 1.06200528F, 1.60746443F, 1.60746443F, 1.60746443F },

  // Computed Parameter: uDLookupTable2_tableData_k
  //  Referenced by: '<S75>/1-D Lookup Table2'

  { 1.31274533F, 1.31274533F, 1.41110694F, 1.41110694F, 1.41110694F },

  // Expression: PSIdata'
  //  Referenced by: '<S9>/1-D Lookup Table3'

  { 0.0F, -0.480011F, -1.92001343F, -4.32998657F, -7.70001221F, -12.0299988F,
    -17.3200073F, -23.5799866F, -30.6799927F, -37.8999939F, -45.1099854F,
    -52.3299866F, -59.5499878F, -66.769989F, -73.9899902F, -81.2099915F,
    -88.4200134F, -95.6400146F, -102.859985F, -110.08F, -117.3F, -124.520004F,
    -131.74F, -138.95F, -146.17F, -153.39F, -160.61F, -167.83F, -175.05F,
    -182.26F, -189.48F, -196.7F, -203.92F, -211.14F, -218.36F, -225.57F,
    -232.790009F, -240.01001F, -247.230011F, -254.45F, -261.666016F, -268.884F,
    -276.103F, -283.320984F, -290.539F, -297.758F, -304.976F, -312.194F,
    -319.413F, -326.511F, -332.767F, -338.06F, -342.391F, -345.76F, -348.166016F,
    -349.61F, -350.09079F, -350.09079F, -350.09079F, -350.09079F, -350.09079F,
    -350.09079F, -350.09079F, -350.09079F, -350.09079F, -350.09079F, -350.09079F,
    -350.09079F, -350.09079F, -350.09079F, -349.61F, -348.166016F, -345.76F,
    -342.391F, -338.06F, -332.767F, -326.511F, -319.413F, -312.194F, -304.976F,
    -297.758F, -290.539F, -283.320984F, -276.103F, -268.884F, -261.666016F,
    -254.45F, -247.230011F, -240.01001F, -232.790009F, -225.57F, -218.36F,
    -211.14F, -203.92F, -196.7F, -189.48F, -182.26F, -175.05F, -167.83F,
    -160.61F, -153.39F, -146.17F, -138.95F, -131.74F, -124.520004F, -117.3F,
    -110.08F, -102.859985F, -95.6400146F, -88.4200134F, -81.2099915F,
    -73.9899902F, -66.769989F, -59.5499878F, -52.3299866F, -45.1099854F,
    -37.8999939F, -30.6799927F, -23.5799866F, -17.3200073F, -12.0299988F,
    -7.70001221F, -4.32998657F, -1.92001343F, -0.480011F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Expression: VYdata'
  //  Referenced by: '<S9>/1-D Lookup Table1'

  { 0.0F, 0.0011518F, 0.0092131F, 0.031071F, 0.073497F, 0.14293F, 0.24503F,
    0.38403F, 0.52479F, 0.63179F, 0.72877F, 0.81419F, 0.88672F, 0.94518F,
    0.98867F, 1.0165F, 1.0282F, 1.0236F, 1.0028F, 0.96605F, 0.91402F, 0.8475F,
    0.76755F, 0.67543F, 0.57261F, 0.46071F, 0.34151F, 0.21689F, 0.088834F,
    -0.040628F, -0.16945F, -0.29558F, -0.41703F, -0.53186F, -0.63827F, -0.73456F,
    -0.8192F, -0.89086F, -0.9484F, -0.99091F, -1.0177F, -1.0284F, -1.0227F,
    -1.0009F, -0.96319F, -0.91021F, -0.8428F, -0.76204F, -0.66919F, -0.52971F,
    -0.37655F, -0.25621F, -0.16595F, -0.10121F, -0.05625F, -0.024734F,
    2.4298E-15F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.024734F, 0.05625F, 0.10121F, 0.16595F, 0.25621F,
    0.37655F, 0.52971F, 0.66919F, 0.76204F, 0.8428F, 0.91021F, 0.96319F, 1.0009F,
    1.0227F, 1.0284F, 1.0177F, 0.99091F, 0.9484F, 0.89086F, 0.8192F, 0.73456F,
    0.63827F, 0.53186F, 0.41703F, 0.29558F, 0.16945F, 0.040628F, -0.088834F,
    -0.21689F, -0.34151F, -0.46071F, -0.57261F, -0.67543F, -0.76755F, -0.8475F,
    -0.91402F, -0.96605F, -1.0028F, -1.0236F, -1.0282F, -1.0165F, -0.98867F,
    -0.94518F, -0.88672F, -0.81419F, -0.72877F, -0.63179F, -0.52479F, -0.38403F,
    -0.24503F, -0.14293F, -0.073497F, -0.031071F, -0.0092131F, -0.0011518F,
    -9.9264E-28F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F },

  // Expression: VXdata'
  //  Referenced by: '<S9>/1-D Lookup Table'

  { 0.0F, 0.13714F, 0.27413F, 0.41025F, 0.54363F, 0.67065F, 0.78553F, 0.87984F,
    0.88462F, 0.81167F, 0.72585F, 0.62853F, 0.52124F, 0.40569F, 0.28372F,
    0.15724F, 0.028271F, -0.10115F, -0.22896F, -0.35314F, -0.47173F, -0.58284F,
    -0.68471F, -0.77573F, -0.85445F, -0.91962F, -0.97022F, -1.0054F, -1.0247F,
    -1.0278F, -1.0145F, -0.98519F, -0.94024F, -0.88039F, -0.80658F, -0.71999F,
    -0.62198F, -0.51412F, -0.39811F, -0.27578F, -0.14909F, -0.020031F, 0.10934F,
    0.23699F, 0.36087F, 0.47904F, 0.58961F, 0.69084F, 0.78111F, 0.80063F,
    0.73164F, 0.63605F, 0.52287F, 0.39879F, 0.26846F, 0.13489F, -1.3909E-14F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.13489F, -0.26846F, -0.39879F, -0.52287F, -0.63605F, -0.73164F, -0.80063F,
    -0.78111F, -0.69084F, -0.58961F, -0.47904F, -0.36087F, -0.23699F, -0.10934F,
    0.020031F, 0.14909F, 0.27578F, 0.39811F, 0.51412F, 0.62198F, 0.71999F,
    0.80658F, 0.88039F, 0.94024F, 0.98519F, 1.0145F, 1.0278F, 1.0247F, 1.0054F,
    0.97022F, 0.91962F, 0.85445F, 0.77573F, 0.68471F, 0.58284F, 0.47173F,
    0.35314F, 0.22896F, 0.10115F, -0.028271F, -0.15724F, -0.28372F, -0.40569F,
    -0.52124F, -0.62853F, -0.72585F, -0.81167F, -0.88462F, -0.87984F, -0.78553F,
    -0.67065F, -0.54363F, -0.41025F, -0.27413F, -0.13714F, 1.412E-14F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Expression: VZdata'
  //  Referenced by: '<S9>/1-D Lookup Table2'

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  // Computed Parameter: uDLookupTable2_tableData_j
  //  Referenced by: '<S30>/1-D Lookup Table2'

  { 0.05F, 0.05F, 0.390530795F, 0.390530795F, 0.390530795F },

  // Computed Parameter: uDLookupTable2_tableData_o
  //  Referenced by: '<S25>/1-D Lookup Table2'

  { 13.8842F, 13.8842F, 13.1121073F, 13.1121073F, 13.1121073F },

  // Computed Parameter: uDLookupTable_tableData_k
  //  Referenced by: '<S12>/1-D Lookup Table'

  { 6.46751261F, 6.46751261F, 6.56189537F, 6.56189537F, 6.56189537F },

  // Computed Parameter: uDLookupTable1_tableData_g
  //  Referenced by: '<S12>/1-D Lookup Table1'

  { 13.3729925F, 13.3729925F, 13.1806431F, 13.1806431F, 13.1806431F },

  // Computed Parameter: uDLookupTable2_tableData_a
  //  Referenced by: '<S16>/1-D Lookup Table2'

  { 74.3660049F, 74.3660049F, 79.0965118F, 79.0965118F, 79.0965118F },

  // Computed Parameter: uDLookupTable2_tableData_fu
  //  Referenced by: '<S15>/1-D Lookup Table2'

  { 9.68285179F, 9.68285179F, 10.4349728F, 10.4349728F, 10.4349728F },

  // Computed Parameter: uDLookupTable_tableData_l
  //  Referenced by: '<S11>/1-D Lookup Table'

  { 18.469429F, 18.469429F, 18.2494831F, 18.2494831F, 18.2494831F },

  // Computed Parameter: uDLookupTable1_tableData_n
  //  Referenced by: '<S11>/1-D Lookup Table1'

  { 10.5364656F, 10.5364656F, 10.6634521F, 10.6634521F, 10.6634521F },

  // Computed Parameter: uDLookupTable2_tableData_ex
  //  Referenced by: '<S32>/1-D Lookup Table2'

  { 72.7000046F, 72.7000046F, 80.6645279F, 80.6645279F, 80.6645279F },

  // Computed Parameter: uDLookupTable2_tableData_c
  //  Referenced by: '<S31>/1-D Lookup Table2'

  { 9.37461853F, 9.37461853F, 10.8184862F, 10.8184862F, 10.8184862F },

  // Computed Parameter: uDLookupTable_tableData_m
  //  Referenced by: '<S13>/1-D Lookup Table'

  { 18.1789932F, 18.1789932F, 17.7086353F, 17.7086353F, 17.7086353F },

  // Computed Parameter: uDLookupTable1_tableData_d
  //  Referenced by: '<S13>/1-D Lookup Table1'

  { 10.2808905F, 10.2808905F, 10.989131F, 10.989131F, 10.989131F },

  // Computed Parameter: uDLookupTable2_tableData_au
  //  Referenced by: '<S42>/1-D Lookup Table2'

  { 61.9079514F, 61.9079514F, 44.0603371F, 44.0603371F, 44.0603371F },

  // Computed Parameter: uDLookupTable2_tableData_c0
  //  Referenced by: '<S44>/1-D Lookup Table2'

  { 11.19275F, 11.19275F, 6.49346828F, 6.49346828F, 6.49346828F },

  // Computed Parameter: uDLookupTable_tableData_h
  //  Referenced by: '<S14>/1-D Lookup Table'

  { 16.530386F, 16.530386F, 29.8244877F, 29.8244877F, 29.8244877F },

  // Computed Parameter: uDLookupTable1_tableData_f
  //  Referenced by: '<S14>/1-D Lookup Table1'

  { 11.7724104F, 11.7724104F, 6.52492332F, 6.52492332F, 6.52492332F },

  // Computed Parameter: uDLookupTable2_tableData_kg
  //  Referenced by: '<S70>/1-D Lookup Table2'

  { 0.250343561F, 0.250343561F, 0.0984954387F, 0.0984954387F, 0.0984954387F },

  // Computed Parameter: uDLookupTable_tableData_d
  //  Referenced by: '<S62>/1-D Lookup Table'

  { 15.3020601F, 15.3020601F, 35.7363586F, 35.7363586F, 35.7363586F },

  // Computed Parameter: uDLookupTable1_tableData_m
  //  Referenced by: '<S62>/1-D Lookup Table1'

  { 1.35708845F, 1.35708845F, 0.605056047F, 0.605056047F, 0.605056047F },

  // Computed Parameter: uDLookupTable2_tableData_or
  //  Referenced by: '<S39>/1-D Lookup Table2'

  { 2.27227163F, 2.27227163F, 2.19286227F, 2.19286227F, 2.19286227F },

  // Computed Parameter: uDLookupTable2_tableData_gp
  //  Referenced by: '<S40>/1-D Lookup Table2'

  { 9.08908653F, 9.08908653F, 8.77144909F, 8.77144909F, 8.77144909F },

  // Computed Parameter: uDLookupTable2_tableData_n
  //  Referenced by: '<S66>/1-D Lookup Table2'

  { 0.280079037F, 0.280079037F, 0.065381512F, 0.065381512F, 0.065381512F },

  // Computed Parameter: uDLookupTable_tableData_hs
  //  Referenced by: '<S61>/1-D Lookup Table'

  { 12.8306608F, 12.8306608F, 46.7874565F, 46.7874565F, 46.7874565F },

  // Computed Parameter: uDLookupTable1_tableData_p
  //  Referenced by: '<S61>/1-D Lookup Table1'

  { 1.68522108F, 1.68522108F, 0.462143093F, 0.462143093F, 0.462143093F },

  // Computed Parameter: uDLookupTable2_tableData_ob
  //  Referenced by: '<S23>/1-D Lookup Table2'

  { 2.59953475F, 2.59953475F, 2.32651448F, 2.32651448F, 2.32651448F },

  // Computed Parameter: uDLookupTable2_tableData_l
  //  Referenced by: '<S24>/1-D Lookup Table2'

  { 10.398139F, 10.398139F, 9.30605793F, 9.30605793F, 9.30605793F }
};

//
// File trailer for generated code.
//
// [EOF]
//
