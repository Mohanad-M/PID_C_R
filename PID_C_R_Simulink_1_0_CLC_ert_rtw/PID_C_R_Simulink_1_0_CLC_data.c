/*
 * File: PID_C_R_Simulink_1_0_CLC_data.c
 *
 * Code generated for Simulink model 'PID_C_R_Simulink_1_0_CLC'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat May  8 22:30:24 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_C_R_Simulink_1_0_CLC.h"
#include "PID_C_R_Simulink_1_0_CLC_private.h"

/* Block parameters (default storage) */
P_PID_C_R_Simulink_1_0_CLC_T PID_C_R_Simulink_1_0_CLC_P = {
  /* Expression: 0.001
   * Referenced by: '<S6>/Digital Input'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S7>/Digital Input'
   */
  0.001,

  /* Expression: [-360 0 360]
   * Referenced by: '<S8>/1-D Lookup Table'
   */
  { -360.0, 0.0, 360.0 },

  /* Expression: [-100 0 100]
   * Referenced by: '<S8>/1-D Lookup Table'
   */
  { -100.0, 0.0, 100.0 },

  /* Expression: 0
   * Referenced by: '<S8>/Random Number1'
   */
  0.0,

  /* Computed Parameter: RandomNumber1_StdDev
   * Referenced by: '<S8>/Random Number1'
   */
  2.23606797749979,

  /* Expression: randi(1000)
   * Referenced by: '<S8>/Random Number1'
   */
  187.0,

  /* Expression: [-360 0 360]
   * Referenced by: '<S9>/1-D Lookup Table'
   */
  { -360.0, 0.0, 360.0 },

  /* Expression: [-100 0 100]
   * Referenced by: '<S9>/1-D Lookup Table'
   */
  { -100.0, 0.0, 100.0 },

  /* Expression: 0
   * Referenced by: '<S9>/Random Number1'
   */
  0.0,

  /* Computed Parameter: RandomNumber1_StdDev_h
   * Referenced by: '<S9>/Random Number1'
   */
  2.23606797749979,

  /* Expression: randi(1000)
   * Referenced by: '<S9>/Random Number1'
   */
  490.0,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S3>/Unit Delay'
   */
  0,

  /* Computed Parameter: UnitDelay1_InitialCondition
   * Referenced by: '<S3>/Unit Delay1'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S4>/Gain'
   */
  0.5F,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S4>/Constant2'
   */
  0.0F,

  /* Computed Parameter: theta_offset_Y0
   * Referenced by: '<S14>/theta_offset'
   */
  0.0F,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S15>/Constant'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S12>/Gain'
   */
  0.9346F,

  /* Computed Parameter: TmpLatchAtTriggeredSubsystemInp
   * Referenced by: synthesized block
   */
  0.0F,

  /* Computed Parameter: TurnAngle_Value
   * Referenced by: '<Root>/Turn Angle'
   */
  0.0F,

  /* Computed Parameter: Speed_Value
   * Referenced by: '<Root>/Speed'
   */
  75.0F,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<S4>/Saturation1'
   */
  100.0F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S4>/Saturation1'
   */
  0.0F,

  /* Computed Parameter: Scale1_Gain
   * Referenced by: '<S3>/Scale1'
   */
  2.55F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S3>/Constant1'
   */
  2.0F,

  /* Computed Parameter: WeightedSampleTime_WtEt
   * Referenced by: '<S8>/Weighted Sample Time'
   */
  0.001F,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S8>/Memory'
   */
  0.0F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S4>/Saturation'
   */
  100.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S4>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Scale_Gain
   * Referenced by: '<S3>/Scale'
   */
  2.55F,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S3>/Constant'
   */
  0.0F,

  /* Computed Parameter: WeightedSampleTime_WtEt_p
   * Referenced by: '<S9>/Weighted Sample Time'
   */
  0.001F,

  /* Computed Parameter: Memory_InitialCondition_e
   * Referenced by: '<S9>/Memory'
   */
  0.0F,

  /* Expression: switch_mode
   * Referenced by: '<S1>/Switch Control'
   */
  0,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S5>/Constant'
   */
  0,

  /* Computed Parameter: Constant1_Value_f
   * Referenced by: '<S5>/Constant1'
   */
  1,

  /* Computed Parameter: Constant2_Value_d
   * Referenced by: '<S5>/Constant2'
   */
  0,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S5>/Constant3'
   */
  1,

  /* Start of '<S7>/Triggered Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S11>/Unit Delay'
     */
    0.0,

    /* Expression: 6
     * Referenced by: '<S11>/Constant'
     */
    6.0,

    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S11>/Out1'
     */
    0
  }
  ,

  /* End of '<S7>/Triggered Subsystem' */

  /* Start of '<S6>/Triggered Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S10>/Unit Delay'
     */
    0.0,

    /* Expression: 6
     * Referenced by: '<S10>/Constant'
     */
    6.0,

    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S10>/Out1'
     */
    0
  }
  /* End of '<S6>/Triggered Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
