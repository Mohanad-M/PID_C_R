/*
 * File: PID_C_R_Simulink_1_0_CLC.c
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

/* Block signals (default storage) */
B_PID_C_R_Simulink_1_0_CLC_T PID_C_R_Simulink_1_0_CLC_B;

/* Block states (default storage) */
DW_PID_C_R_Simulink_1_0_CLC_T PID_C_R_Simulink_1_0_CLC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_PID_C_R_Simulink_1_0__T PID_C_R_Simulink_1_0_CL_PrevZCX;

/* Real-time model */
RT_MODEL_PID_C_R_Simulink_1_0_T PID_C_R_Simulink_1_0_CLC_M_;
RT_MODEL_PID_C_R_Simulink_1_0_T *const PID_C_R_Simulink_1_0_CLC_M =
  &PID_C_R_Simulink_1_0_CLC_M_;

/* Forward declaration for local functions */
static real_T PID__rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
static void matlabCodegenHandle_matl_g5f5mf(codertarget_arduinobase_blo_g_T *obj);
static void PID_C_R_Simu_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void PID_C_R_Simul_SystemCore_delete(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCo_g5(codertarget_arduinobase_block_T *obj);
static void arduino_PWMOutput_set_pinNumb_g(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T y;
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (table[iLeft + 1UL] - table[iLeft]) * frac + table[iLeft];
  }

  return y;
}

/*
 * System initialize for trigger system:
 *    '<S6>/Triggered Subsystem'
 *    '<S7>/Triggered Subsystem'
 */
void PID_C_R_TriggeredSubsystem_Init(int32_T *rty_Out1,
  DW_TriggeredSubsystem_PID_C_R_T *localDW, P_TriggeredSubsystem_PID_C_R__T
  *localP)
{
  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* SystemInitialize for Outport: '<S10>/Out1' */
  *rty_Out1 = localP->Out1_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S6>/Triggered Subsystem'
 *    '<S7>/Triggered Subsystem'
 */
void PID_C_R_Simu_TriggeredSubsystem(RT_MODEL_PID_C_R_Simulink_1_0_T * const
  PID_C_R_Simulink_1_0_CLC_M, boolean_T rtu_Trigger, int32_T *rty_Out1,
  DW_TriggeredSubsystem_PID_C_R_T *localDW, P_TriggeredSubsystem_PID_C_R__T
  *localP, ZCE_TriggeredSubsystem_PID_C__T *localZCE)
{
  real_T rtb_DigitalClock;
  real_T tmp;

  /* Outputs for Triggered SubSystem: '<S6>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S10>/Trigger'
   */
  if (rtu_Trigger && (localZCE->TriggeredSubsystem_Trig_ZCE_g != POS_ZCSIG)) {
    /* DigitalClock: '<S10>/Digital Clock' */
    rtb_DigitalClock = ((PID_C_R_Simulink_1_0_CLC_M->Timing.clockTick0) * 0.001);

    /* Product: '<S10>/Divide' incorporates:
     *  Constant: '<S10>/Constant'
     *  Sum: '<S10>/Add'
     *  UnitDelay: '<S10>/Unit Delay'
     */
    tmp = floor(localP->Constant_Value / (rtb_DigitalClock -
      localDW->UnitDelay_DSTATE));
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    *rty_Out1 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp;

    /* End of Product: '<S10>/Divide' */

    /* Update for UnitDelay: '<S10>/Unit Delay' */
    localDW->UnitDelay_DSTATE = rtb_DigitalClock;
  }

  localZCE->TriggeredSubsystem_Trig_ZCE_g = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S6>/Triggered Subsystem' */
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773UL * 16807UL;
  hi = *u / 127773UL * 2836UL;
  if ((int32_T)lo < (int32_T)hi) {
    *u = 2147483647UL - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

static real_T PID__rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    PID_C_R_Simulink_1_0_CLC_B.sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = PID_C_R_Simulink_1_0_CLC_B.sr * PID_C_R_Simulink_1_0_CLC_B.sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * PID_C_R_Simulink_1_0_CLC_B.sr;
  return y;
}

static void matlabCodegenHandle_matl_g5f5mf(codertarget_arduinobase_blo_g_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void PID_C_R_Simu_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(obj->PinPWM);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void PID_C_R_Simul_SystemCore_delete(codertarget_arduinobase_inter_T *obj)
{
  PID_C_R_Simu_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    PID_C_R_Simul_SystemCore_delete(obj);
  }
}

static void matlabCodegenHandle_matlabCo_g5(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void arduino_PWMOutput_set_pinNumb_g(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
  obj->PinPWM = 11UL;
}

static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
  obj->PinPWM = 10UL;
}

/* Model step function */
void PID_C_R_Simulink_1_0_CLC_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real32_T rtb_Memory;
  real32_T rtb_WeightedSampleTime;
  real32_T rtb_Gain;
  boolean_T rtb_Compare;
  int32_T tmp;

  /* MATLABSystem: '<S7>/Digital Input' */
  if (PID_C_R_Simulink_1_0_CLC_DW.obj_l.SampleTime !=
      PID_C_R_Simulink_1_0_CLC_P.DigitalInput_SampleTime_d) {
    PID_C_R_Simulink_1_0_CLC_DW.obj_l.SampleTime =
      PID_C_R_Simulink_1_0_CLC_P.DigitalInput_SampleTime_d;
  }

  rtb_Compare = readDigitalPin(8);

  /* Outputs for Triggered SubSystem: '<S7>/Triggered Subsystem' */
  PID_C_R_Simu_TriggeredSubsystem(PID_C_R_Simulink_1_0_CLC_M, rtb_Compare,
    &PID_C_R_Simulink_1_0_CLC_B.Divide,
    &PID_C_R_Simulink_1_0_CLC_DW.TriggeredSubsystem_o,
    &PID_C_R_Simulink_1_0_CLC_P.TriggeredSubsystem_o,
    &PID_C_R_Simulink_1_0_CL_PrevZCX.TriggeredSubsystem_o);

  /* End of MATLABSystem: '<S7>/Digital Input' */
  /* End of Outputs for SubSystem: '<S7>/Triggered Subsystem' */

  /* MATLABSystem: '<S6>/Digital Input' */
  if (PID_C_R_Simulink_1_0_CLC_DW.obj_e.SampleTime !=
      PID_C_R_Simulink_1_0_CLC_P.DigitalInput_SampleTime) {
    PID_C_R_Simulink_1_0_CLC_DW.obj_e.SampleTime =
      PID_C_R_Simulink_1_0_CLC_P.DigitalInput_SampleTime;
  }

  rtb_Compare = readDigitalPin(9);

  /* Outputs for Triggered SubSystem: '<S6>/Triggered Subsystem' */
  PID_C_R_Simu_TriggeredSubsystem(PID_C_R_Simulink_1_0_CLC_M, rtb_Compare,
    &PID_C_R_Simulink_1_0_CLC_B.Divide_a,
    &PID_C_R_Simulink_1_0_CLC_DW.TriggeredSubsystem,
    &PID_C_R_Simulink_1_0_CLC_P.TriggeredSubsystem,
    &PID_C_R_Simulink_1_0_CL_PrevZCX.TriggeredSubsystem);

  /* End of MATLABSystem: '<S6>/Digital Input' */
  /* End of Outputs for SubSystem: '<S6>/Triggered Subsystem' */

  /* Switch: '<S1>/Environment Switch' incorporates:
   *  Constant: '<S1>/Switch Control'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S3>/Sum1'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (PID_C_R_Simulink_1_0_CLC_P.SwitchControl_Value) {
    tmp = PID_C_R_Simulink_1_0_CLC_DW.UnitDelay_DSTATE -
      PID_C_R_Simulink_1_0_CLC_DW.UnitDelay1_DSTATE;
  } else {
    tmp = PID_C_R_Simulink_1_0_CLC_B.Divide -
      PID_C_R_Simulink_1_0_CLC_B.Divide_a;
  }

  /* End of Switch: '<S1>/Environment Switch' */

  /* Gain: '<S12>/Gain' */
  rtb_Gain = PID_C_R_Simulink_1_0_CLC_P.Gain_Gain_e * (real32_T)tmp;

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<Root>/Turn Angle'
   *  Constant: '<S15>/Constant'
   */
  rtb_Compare = (PID_C_R_Simulink_1_0_CLC_P.TurnAngle_Value !=
                 PID_C_R_Simulink_1_0_CLC_P.Constant_Value);

  /* Outputs for Triggered SubSystem: '<S12>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  if ((!rtb_Compare) &&
      (PID_C_R_Simulink_1_0_CL_PrevZCX.TriggeredSubsystem_Trig_ZCE != 0)) {
    /* Inport: '<S14>/theta_diff' incorporates:
     *  Memory generated from: '<S12>/Triggered Subsystem'
     */
    PID_C_R_Simulink_1_0_CLC_B.theta_diff =
      PID_C_R_Simulink_1_0_CLC_DW.TmpLatchAtTriggeredSubsystemInp;
  }

  PID_C_R_Simulink_1_0_CL_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Compare;

  /* End of Outputs for SubSystem: '<S12>/Triggered Subsystem' */

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<Root>/Turn Angle'
   *  Constant: '<S4>/Constant2'
   *  Gain: '<S4>/Gain'
   *  Sum: '<S12>/Sum3'
   */
  if (PID_C_R_Simulink_1_0_CLC_P.TurnAngle_Value != 0.0F) {
    rtb_Memory = PID_C_R_Simulink_1_0_CLC_P.Constant2_Value;
  } else {
    rtb_Memory = (rtb_Gain - PID_C_R_Simulink_1_0_CLC_B.theta_diff) *
      PID_C_R_Simulink_1_0_CLC_P.Gain_Gain;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<Root>/Speed'
   *  Constant: '<Root>/Turn Angle'
   */
  rtb_WeightedSampleTime = (PID_C_R_Simulink_1_0_CLC_P.Speed_Value -
    PID_C_R_Simulink_1_0_CLC_P.TurnAngle_Value) + rtb_Memory;

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_WeightedSampleTime > PID_C_R_Simulink_1_0_CLC_P.Saturation1_UpperSat)
  {
    rtb_WeightedSampleTime = PID_C_R_Simulink_1_0_CLC_P.Saturation1_UpperSat;
  } else {
    if (rtb_WeightedSampleTime < PID_C_R_Simulink_1_0_CLC_P.Saturation1_LowerSat)
    {
      rtb_WeightedSampleTime = PID_C_R_Simulink_1_0_CLC_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<S4>/Saturation1' */

  /* MATLABSystem: '<S3>/PWM1' incorporates:
   *  Gain: '<S3>/Scale1'
   */
  obj = &PID_C_R_Simulink_1_0_CLC_DW.obj;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(PID_C_R_Simulink_1_0_CLC_DW.obj.PinPWM);
  PID_C_R_Simulink_1_0_CLC_B.u0 = PID_C_R_Simulink_1_0_CLC_P.Scale1_Gain *
    rtb_WeightedSampleTime;
  if (!(PID_C_R_Simulink_1_0_CLC_B.u0 < 255.0)) {
    PID_C_R_Simulink_1_0_CLC_B.u0 = 255.0;
  }

  if (!(PID_C_R_Simulink_1_0_CLC_B.u0 > 0.0)) {
    PID_C_R_Simulink_1_0_CLC_B.u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(PID_C_R_Simulink_1_0_CLC_DW.obj.MW_PWM_HANDLE,
                      PID_C_R_Simulink_1_0_CLC_B.u0);

  /* End of MATLABSystem: '<S3>/PWM1' */

  /* Sum: '<S8>/Add' incorporates:
   *  Constant: '<S3>/Constant1'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Lookup_n-D: '<S8>/1-D Lookup Table'
   *  Memory: '<S8>/Memory'
   *  RandomNumber: '<S8>/Random Number1'
   *  SampleTimeMath: '<S8>/Weighted Sample Time'
   *  Sum: '<S8>/Add1'
   *
   * About '<S8>/Weighted Sample Time':
   *  y = u * K where K = ( w * Ts )
   */
  rtb_WeightedSampleTime = (real32_T)((look1_binlcapw(rtb_WeightedSampleTime,
    PID_C_R_Simulink_1_0_CLC_P.uDLookupTable_bp01Data,
    PID_C_R_Simulink_1_0_CLC_P.uDLookupTable_tableData, 2UL) +
    PID_C_R_Simulink_1_0_CLC_DW.NextOutput) +
    PID_C_R_Simulink_1_0_CLC_P.Constant1_Value) *
    PID_C_R_Simulink_1_0_CLC_P.WeightedSampleTime_WtEt +
    PID_C_R_Simulink_1_0_CLC_DW.Memory_PreviousInput;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  rtb_Memory = (real32_T)floor(rtb_WeightedSampleTime);
  if (rtIsNaNF(rtb_Memory) || rtIsInfF(rtb_Memory)) {
    rtb_Memory = 0.0F;
  } else {
    rtb_Memory = (real32_T)fmod(rtb_Memory, 4.294967296E+9);
  }

  PID_C_R_Simulink_1_0_CLC_DW.UnitDelay1_DSTATE = rtb_Memory < 0.0F ? -(int32_T)
    (uint32_T)-rtb_Memory : (int32_T)(uint32_T)rtb_Memory;

  /* End of DataTypeConversion: '<S8>/Data Type Conversion1' */

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<Root>/Speed'
   *  Constant: '<Root>/Turn Angle'
   */
  rtb_Memory = PID_C_R_Simulink_1_0_CLC_P.Speed_Value +
    PID_C_R_Simulink_1_0_CLC_P.TurnAngle_Value;

  /* Saturate: '<S4>/Saturation' */
  if (rtb_Memory > PID_C_R_Simulink_1_0_CLC_P.Saturation_UpperSat) {
    rtb_Memory = PID_C_R_Simulink_1_0_CLC_P.Saturation_UpperSat;
  } else {
    if (rtb_Memory < PID_C_R_Simulink_1_0_CLC_P.Saturation_LowerSat) {
      rtb_Memory = PID_C_R_Simulink_1_0_CLC_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* MATLABSystem: '<S3>/PWM' incorporates:
   *  Gain: '<S3>/Scale'
   */
  obj = &PID_C_R_Simulink_1_0_CLC_DW.obj_d;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(PID_C_R_Simulink_1_0_CLC_DW.obj_d.PinPWM);
  PID_C_R_Simulink_1_0_CLC_B.u0 = PID_C_R_Simulink_1_0_CLC_P.Scale_Gain *
    rtb_Memory;
  if (!(PID_C_R_Simulink_1_0_CLC_B.u0 < 255.0)) {
    PID_C_R_Simulink_1_0_CLC_B.u0 = 255.0;
  }

  if (!(PID_C_R_Simulink_1_0_CLC_B.u0 > 0.0)) {
    PID_C_R_Simulink_1_0_CLC_B.u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(PID_C_R_Simulink_1_0_CLC_DW.obj_d.MW_PWM_HANDLE,
                      PID_C_R_Simulink_1_0_CLC_B.u0);

  /* End of MATLABSystem: '<S3>/PWM' */

  /* Sum: '<S9>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Lookup_n-D: '<S9>/1-D Lookup Table'
   *  Memory: '<S9>/Memory'
   *  RandomNumber: '<S9>/Random Number1'
   *  SampleTimeMath: '<S9>/Weighted Sample Time'
   *  Sum: '<S9>/Add1'
   *
   * About '<S9>/Weighted Sample Time':
   *  y = u * K where K = ( w * Ts )
   */
  PID_C_R_Simulink_1_0_CLC_DW.Memory_PreviousInput_l += (real32_T)
    ((look1_binlcapw(rtb_Memory,
                     PID_C_R_Simulink_1_0_CLC_P.uDLookupTable_bp01Data_f,
                     PID_C_R_Simulink_1_0_CLC_P.uDLookupTable_tableData_b, 2UL)
      + PID_C_R_Simulink_1_0_CLC_DW.NextOutput_j) +
     PID_C_R_Simulink_1_0_CLC_P.Constant_Value_i) *
    PID_C_R_Simulink_1_0_CLC_P.WeightedSampleTime_WtEt_p;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Memory = (real32_T)floor
    (PID_C_R_Simulink_1_0_CLC_DW.Memory_PreviousInput_l);
  if (rtIsNaNF(rtb_Memory) || rtIsInfF(rtb_Memory)) {
    rtb_Memory = 0.0F;
  } else {
    rtb_Memory = (real32_T)fmod(rtb_Memory, 4.294967296E+9);
  }

  PID_C_R_Simulink_1_0_CLC_DW.UnitDelay_DSTATE = rtb_Memory < 0.0F ? -(int32_T)
    (uint32_T)-rtb_Memory : (int32_T)(uint32_T)rtb_Memory;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion1' */

  /* MATLABSystem: '<S5>/Digital Output2' incorporates:
   *  Constant: '<S5>/Constant'
   */
  writeDigitalPin(4, (uint8_T)PID_C_R_Simulink_1_0_CLC_P.Constant_Value_f);

  /* MATLABSystem: '<S5>/Digital Output3' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  writeDigitalPin(5, (uint8_T)PID_C_R_Simulink_1_0_CLC_P.Constant1_Value_f);

  /* MATLABSystem: '<S5>/Digital Output' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  writeDigitalPin(2, (uint8_T)PID_C_R_Simulink_1_0_CLC_P.Constant2_Value_d);

  /* MATLABSystem: '<S5>/Digital Output1' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  writeDigitalPin(3, (uint8_T)PID_C_R_Simulink_1_0_CLC_P.Constant3_Value);

  /* Update for Memory generated from: '<S12>/Triggered Subsystem' */
  PID_C_R_Simulink_1_0_CLC_DW.TmpLatchAtTriggeredSubsystemInp = rtb_Gain;

  /* Update for RandomNumber: '<S8>/Random Number1' */
  PID_C_R_Simulink_1_0_CLC_DW.NextOutput = PID__rt_nrand_Upu32_Yd_f_pw_snf
    (&PID_C_R_Simulink_1_0_CLC_DW.RandSeed) *
    PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_StdDev +
    PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_Mean;

  /* Update for Memory: '<S8>/Memory' */
  PID_C_R_Simulink_1_0_CLC_DW.Memory_PreviousInput = rtb_WeightedSampleTime;

  /* Update for RandomNumber: '<S9>/Random Number1' */
  PID_C_R_Simulink_1_0_CLC_DW.NextOutput_j = PID__rt_nrand_Upu32_Yd_f_pw_snf
    (&PID_C_R_Simulink_1_0_CLC_DW.RandSeed_e) *
    PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_StdDev_h +
    PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_Mean_m;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  PID_C_R_Simulink_1_0_CLC_M->Timing.clockTick0++;
}

/* Model initialize function */
void PID_C_R_Simulink_1_0_CLC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_inter_T *obj;
    uint32_T tseed;
    uint16_T r;
    uint16_T t;
    real_T tmp;
    PID_C_R_Simulink_1_0_CL_PrevZCX.TriggeredSubsystem_Trig_ZCE = ZERO_ZCSIG;
    PID_C_R_Simulink_1_0_CL_PrevZCX.TriggeredSubsystem_o.TriggeredSubsystem_Trig_ZCE_g
      = POS_ZCSIG;
    PID_C_R_Simulink_1_0_CL_PrevZCX.TriggeredSubsystem.TriggeredSubsystem_Trig_ZCE_g
      = POS_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    PID_C_R_Simulink_1_0_CLC_DW.UnitDelay_DSTATE =
      PID_C_R_Simulink_1_0_CLC_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
    PID_C_R_Simulink_1_0_CLC_DW.UnitDelay1_DSTATE =
      PID_C_R_Simulink_1_0_CLC_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for Memory generated from: '<S12>/Triggered Subsystem' */
    PID_C_R_Simulink_1_0_CLC_DW.TmpLatchAtTriggeredSubsystemInp =
      PID_C_R_Simulink_1_0_CLC_P.TmpLatchAtTriggeredSubsystemInp;

    /* InitializeConditions for RandomNumber: '<S8>/Random Number1' */
    tmp = floor(PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (uint16_T)(tseed >> 16);
    t = (uint16_T)tseed & 32768U;
    PID_C_R_Simulink_1_0_CLC_DW.RandSeed = ((((tseed - ((uint32_T)r << 16)) + t)
      << 16UL) + t) + r;
    if (PID_C_R_Simulink_1_0_CLC_DW.RandSeed < 1UL) {
      PID_C_R_Simulink_1_0_CLC_DW.RandSeed = 1144108930UL;
    } else {
      if (PID_C_R_Simulink_1_0_CLC_DW.RandSeed > 2147483646UL) {
        PID_C_R_Simulink_1_0_CLC_DW.RandSeed = 2147483646UL;
      }
    }

    PID_C_R_Simulink_1_0_CLC_DW.NextOutput = PID__rt_nrand_Upu32_Yd_f_pw_snf
      (&PID_C_R_Simulink_1_0_CLC_DW.RandSeed) *
      PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_StdDev +
      PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_Mean;

    /* End of InitializeConditions for RandomNumber: '<S8>/Random Number1' */

    /* InitializeConditions for Memory: '<S8>/Memory' */
    PID_C_R_Simulink_1_0_CLC_DW.Memory_PreviousInput =
      PID_C_R_Simulink_1_0_CLC_P.Memory_InitialCondition;

    /* InitializeConditions for RandomNumber: '<S9>/Random Number1' */
    tmp = floor(PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_Seed_l);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (uint16_T)(tseed >> 16);
    t = (uint16_T)tseed & 32768U;
    PID_C_R_Simulink_1_0_CLC_DW.RandSeed_e = ((((tseed - ((uint32_T)r << 16)) +
      t) << 16UL) + t) + r;
    if (PID_C_R_Simulink_1_0_CLC_DW.RandSeed_e < 1UL) {
      PID_C_R_Simulink_1_0_CLC_DW.RandSeed_e = 1144108930UL;
    } else {
      if (PID_C_R_Simulink_1_0_CLC_DW.RandSeed_e > 2147483646UL) {
        PID_C_R_Simulink_1_0_CLC_DW.RandSeed_e = 2147483646UL;
      }
    }

    PID_C_R_Simulink_1_0_CLC_DW.NextOutput_j = PID__rt_nrand_Upu32_Yd_f_pw_snf
      (&PID_C_R_Simulink_1_0_CLC_DW.RandSeed_e) *
      PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_StdDev_h +
      PID_C_R_Simulink_1_0_CLC_P.RandomNumber1_Mean_m;

    /* End of InitializeConditions for RandomNumber: '<S9>/Random Number1' */

    /* InitializeConditions for Memory: '<S9>/Memory' */
    PID_C_R_Simulink_1_0_CLC_DW.Memory_PreviousInput_l =
      PID_C_R_Simulink_1_0_CLC_P.Memory_InitialCondition_e;

    /* SystemInitialize for Triggered SubSystem: '<S7>/Triggered Subsystem' */
    PID_C_R_TriggeredSubsystem_Init(&PID_C_R_Simulink_1_0_CLC_B.Divide,
      &PID_C_R_Simulink_1_0_CLC_DW.TriggeredSubsystem_o,
      &PID_C_R_Simulink_1_0_CLC_P.TriggeredSubsystem_o);

    /* End of SystemInitialize for SubSystem: '<S7>/Triggered Subsystem' */

    /* SystemInitialize for Triggered SubSystem: '<S6>/Triggered Subsystem' */
    PID_C_R_TriggeredSubsystem_Init(&PID_C_R_Simulink_1_0_CLC_B.Divide_a,
      &PID_C_R_Simulink_1_0_CLC_DW.TriggeredSubsystem,
      &PID_C_R_Simulink_1_0_CLC_P.TriggeredSubsystem);

    /* End of SystemInitialize for SubSystem: '<S6>/Triggered Subsystem' */

    /* SystemInitialize for Triggered SubSystem: '<S12>/Triggered Subsystem' */
    /* SystemInitialize for Outport: '<S14>/theta_offset' */
    PID_C_R_Simulink_1_0_CLC_B.theta_diff =
      PID_C_R_Simulink_1_0_CLC_P.theta_offset_Y0;

    /* End of SystemInitialize for SubSystem: '<S12>/Triggered Subsystem' */

    /* Start for MATLABSystem: '<S7>/Digital Input' */
    PID_C_R_Simulink_1_0_CLC_DW.obj_l.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_CLC_DW.obj_l.SampleTime =
      PID_C_R_Simulink_1_0_CLC_P.DigitalInput_SampleTime_d;
    PID_C_R_Simulink_1_0_CLC_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(8, 0);
    PID_C_R_Simulink_1_0_CLC_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Input' */
    PID_C_R_Simulink_1_0_CLC_DW.obj_e.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_CLC_DW.obj_e.SampleTime =
      PID_C_R_Simulink_1_0_CLC_P.DigitalInput_SampleTime;
    PID_C_R_Simulink_1_0_CLC_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(9, 0);
    PID_C_R_Simulink_1_0_CLC_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM1' */
    PID_C_R_Simulink_1_0_CLC_DW.obj.matlabCodegenIsDeleted = true;
    PID_C_R_Simulink_1_0_CLC_DW.obj.isInitialized = 0L;
    PID_C_R_Simulink_1_0_CLC_DW.obj.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumb_g(&PID_C_R_Simulink_1_0_CLC_DW.obj,
      &PID_C_R_Simulink_1_0_CLC_DW.gobj_2);
    obj = &PID_C_R_Simulink_1_0_CLC_DW.obj;
    PID_C_R_Simulink_1_0_CLC_DW.obj.isSetupComplete = false;
    PID_C_R_Simulink_1_0_CLC_DW.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(PID_C_R_Simulink_1_0_CLC_DW.obj.PinPWM, 0.0,
      0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(PID_C_R_Simulink_1_0_CLC_DW.obj.PinPWM);
    MW_PWM_Start(PID_C_R_Simulink_1_0_CLC_DW.obj.MW_PWM_HANDLE);
    PID_C_R_Simulink_1_0_CLC_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM' */
    PID_C_R_Simulink_1_0_CLC_DW.obj_d.matlabCodegenIsDeleted = true;
    PID_C_R_Simulink_1_0_CLC_DW.obj_d.isInitialized = 0L;
    PID_C_R_Simulink_1_0_CLC_DW.obj_d.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumber(&PID_C_R_Simulink_1_0_CLC_DW.obj_d,
      &PID_C_R_Simulink_1_0_CLC_DW.gobj_2_f);
    obj = &PID_C_R_Simulink_1_0_CLC_DW.obj_d;
    PID_C_R_Simulink_1_0_CLC_DW.obj_d.isSetupComplete = false;
    PID_C_R_Simulink_1_0_CLC_DW.obj_d.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(PID_C_R_Simulink_1_0_CLC_DW.obj_d.PinPWM,
      0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (PID_C_R_Simulink_1_0_CLC_DW.obj_d.PinPWM);
    MW_PWM_Start(PID_C_R_Simulink_1_0_CLC_DW.obj_d.MW_PWM_HANDLE);
    PID_C_R_Simulink_1_0_CLC_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output2' */
    PID_C_R_Simulink_1_0_CLC_DW.obj_a.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_CLC_DW.obj_a.isInitialized = 1L;
    digitalIOSetup(4, 1);
    PID_C_R_Simulink_1_0_CLC_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output3' */
    PID_C_R_Simulink_1_0_CLC_DW.obj_j.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_CLC_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(5, 1);
    PID_C_R_Simulink_1_0_CLC_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    PID_C_R_Simulink_1_0_CLC_DW.obj_et.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_CLC_DW.obj_et.isInitialized = 1L;
    digitalIOSetup(2, 1);
    PID_C_R_Simulink_1_0_CLC_DW.obj_et.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output1' */
    PID_C_R_Simulink_1_0_CLC_DW.obj_p.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_CLC_DW.obj_p.isInitialized = 1L;
    digitalIOSetup(3, 1);
    PID_C_R_Simulink_1_0_CLC_DW.obj_p.isSetupComplete = true;
  }
}

/* Model terminate function */
void PID_C_R_Simulink_1_0_CLC_terminate(void)
{
  /* Terminate for MATLABSystem: '<S7>/Digital Input' */
  matlabCodegenHandle_matl_g5f5mf(&PID_C_R_Simulink_1_0_CLC_DW.obj_l);

  /* Terminate for MATLABSystem: '<S6>/Digital Input' */
  matlabCodegenHandle_matl_g5f5mf(&PID_C_R_Simulink_1_0_CLC_DW.obj_e);

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  matlabCodegenHandle_matlabCodeg(&PID_C_R_Simulink_1_0_CLC_DW.obj);

  /* Terminate for MATLABSystem: '<S3>/PWM' */
  matlabCodegenHandle_matlabCodeg(&PID_C_R_Simulink_1_0_CLC_DW.obj_d);

  /* Terminate for MATLABSystem: '<S5>/Digital Output2' */
  matlabCodegenHandle_matlabCo_g5(&PID_C_R_Simulink_1_0_CLC_DW.obj_a);

  /* Terminate for MATLABSystem: '<S5>/Digital Output3' */
  matlabCodegenHandle_matlabCo_g5(&PID_C_R_Simulink_1_0_CLC_DW.obj_j);

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  matlabCodegenHandle_matlabCo_g5(&PID_C_R_Simulink_1_0_CLC_DW.obj_et);

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  matlabCodegenHandle_matlabCo_g5(&PID_C_R_Simulink_1_0_CLC_DW.obj_p);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
