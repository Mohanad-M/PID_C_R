/*
 * File: PID_C_R_Simulink_1_0_OLC.c
 *
 * Code generated for Simulink model 'PID_C_R_Simulink_1_0_OLC'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat May  8 21:23:49 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_C_R_Simulink_1_0_OLC.h"
#include "PID_C_R_Simulink_1_0_OLC_private.h"

/* Block states (default storage) */
DW_PID_C_R_Simulink_1_0_OLC_T PID_C_R_Simulink_1_0_OLC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_PID_C_R_Simulink_1_0__T PID_C_R_Simulink_1_0_OL_PrevZCX;

/* Real-time model */
RT_MODEL_PID_C_R_Simulink_1_0_T PID_C_R_Simulink_1_0_OLC_M_;
RT_MODEL_PID_C_R_Simulink_1_0_T *const PID_C_R_Simulink_1_0_OLC_M =
  &PID_C_R_Simulink_1_0_OLC_M_;

/* Forward declaration for local functions */
static void PID_C_R_Simu_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void PID_C_R_Simul_SystemCore_delete(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_inter_T *obj);
static void matlabCodegenHandle_matlabCo_oe(codertarget_arduinobase_block_T *obj);
static void matlabCodegenHandle_matlabC_oen(codertarget_arduinobase_blo_o_T *obj);
static void arduino_PWMOutput_set_pinNumb_o(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void arduino_PWMOutput_set_pinNumber(codertarget_arduinobase_inter_T *obj,
  j_codertarget_arduinobase_int_T *iobj_0);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void PID_C_R_Simulink_1_0_OLC_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(PID_C_R_Simulink_1_0_OLC_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PID_C_R_Simulink_1_0_OLC_M->Timing.TaskCounters.TID[1])++;
  if ((PID_C_R_Simulink_1_0_OLC_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    PID_C_R_Simulink_1_0_OLC_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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

static void matlabCodegenHandle_matlabCo_oe(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabC_oen(codertarget_arduinobase_blo_o_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void arduino_PWMOutput_set_pinNumb_o(codertarget_arduinobase_inter_T *obj,
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
  obj->PinPWM = 11UL;
}

/* Model step function for TID0 */
void PID_C_R_Simulink_1_0_OLC_step0(void) /* Sample time: [0.001s, 0.0s] */
{
  codertarget_arduinobase_inter_T *obj;
  real_T u0;
  uint8_T tmp;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S3>/PWM' */
  obj = &PID_C_R_Simulink_1_0_OLC_DW.obj;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(PID_C_R_Simulink_1_0_OLC_DW.obj.PinPWM);

  /* Gain: '<S3>/Scale' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Sum: '<S4>/Sum'
   */
  u0 = (PID_C_R_Simulink_1_0_OLC_P.Constant_Value +
        PID_C_R_Simulink_1_0_OLC_P.Constant1_Value) *
    PID_C_R_Simulink_1_0_OLC_P.Scale_Gain;

  /* MATLABSystem: '<S3>/PWM' */
  if (!(u0 < 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 > 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(PID_C_R_Simulink_1_0_OLC_DW.obj.MW_PWM_HANDLE, u0);

  /* MATLABSystem: '<S3>/PWM1' */
  obj = &PID_C_R_Simulink_1_0_OLC_DW.obj_o;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(PID_C_R_Simulink_1_0_OLC_DW.obj_o.PinPWM);

  /* Gain: '<S3>/Scale1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Sum: '<S4>/Sum1'
   */
  u0 = (PID_C_R_Simulink_1_0_OLC_P.Constant_Value -
        PID_C_R_Simulink_1_0_OLC_P.Constant1_Value) *
    PID_C_R_Simulink_1_0_OLC_P.Scale1_Gain;

  /* MATLABSystem: '<S3>/PWM1' */
  if (!(u0 < 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 > 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(PID_C_R_Simulink_1_0_OLC_DW.obj_o.MW_PWM_HANDLE, u0);

  /* MATLABSystem: '<S5>/Digital Input' */
  if (PID_C_R_Simulink_1_0_OLC_DW.obj_f.SampleTime !=
      PID_C_R_Simulink_1_0_OLC_P.DigitalInput_SampleTime) {
    PID_C_R_Simulink_1_0_OLC_DW.obj_f.SampleTime =
      PID_C_R_Simulink_1_0_OLC_P.DigitalInput_SampleTime;
  }

  readDigitalPin(9);

  /* End of MATLABSystem: '<S5>/Digital Input' */

  /* MATLABSystem: '<S7>/Digital Input' */
  if (PID_C_R_Simulink_1_0_OLC_DW.obj_l.SampleTime !=
      PID_C_R_Simulink_1_0_OLC_P.DigitalInput_SampleTime_h) {
    PID_C_R_Simulink_1_0_OLC_DW.obj_l.SampleTime =
      PID_C_R_Simulink_1_0_OLC_P.DigitalInput_SampleTime_h;
  }

  readDigitalPin(8);

  /* End of MATLABSystem: '<S7>/Digital Input' */

  /* MATLABSystem: '<S6>/Digital Output' incorporates:
   *  Constant: '<S6>/Constant'
   */
  u0 = rt_roundd_snf(PID_C_R_Simulink_1_0_OLC_P.Constant_Value_f);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp);

  /* End of MATLABSystem: '<S6>/Digital Output' */

  /* MATLABSystem: '<S6>/Digital Output1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  u0 = rt_roundd_snf(PID_C_R_Simulink_1_0_OLC_P.Constant1_Value_n);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(5, tmp);

  /* End of MATLABSystem: '<S6>/Digital Output1' */

  /* MATLABSystem: '<S6>/Digital Output2' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  u0 = rt_roundd_snf(PID_C_R_Simulink_1_0_OLC_P.Constant2_Value);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp);

  /* End of MATLABSystem: '<S6>/Digital Output2' */

  /* MATLABSystem: '<S6>/Digital Output3' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  u0 = rt_roundd_snf(PID_C_R_Simulink_1_0_OLC_P.Constant3_Value);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(3, tmp);

  /* End of MATLABSystem: '<S6>/Digital Output3' */
}

/* Model step function for TID1 */
void PID_C_R_Simulink_1_0_OLC_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void PID_C_R_Simulink_1_0_OLC_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    PID_C_R_Simulink_1_0_OL_PrevZCX.TriggeredSubsystem_Trig_ZCE_f = POS_ZCSIG;
    PID_C_R_Simulink_1_0_OL_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

    /* Start for MATLABSystem: '<S3>/PWM' */
    PID_C_R_Simulink_1_0_OLC_DW.obj.matlabCodegenIsDeleted = true;
    PID_C_R_Simulink_1_0_OLC_DW.obj.isInitialized = 0L;
    PID_C_R_Simulink_1_0_OLC_DW.obj.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumb_o(&PID_C_R_Simulink_1_0_OLC_DW.obj,
      &PID_C_R_Simulink_1_0_OLC_DW.gobj_2);
    obj = &PID_C_R_Simulink_1_0_OLC_DW.obj;
    PID_C_R_Simulink_1_0_OLC_DW.obj.isSetupComplete = false;
    PID_C_R_Simulink_1_0_OLC_DW.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(PID_C_R_Simulink_1_0_OLC_DW.obj.PinPWM, 0.0,
      0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(PID_C_R_Simulink_1_0_OLC_DW.obj.PinPWM);
    MW_PWM_Start(PID_C_R_Simulink_1_0_OLC_DW.obj.MW_PWM_HANDLE);
    PID_C_R_Simulink_1_0_OLC_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM1' */
    PID_C_R_Simulink_1_0_OLC_DW.obj_o.matlabCodegenIsDeleted = true;
    PID_C_R_Simulink_1_0_OLC_DW.obj_o.isInitialized = 0L;
    PID_C_R_Simulink_1_0_OLC_DW.obj_o.matlabCodegenIsDeleted = false;
    arduino_PWMOutput_set_pinNumber(&PID_C_R_Simulink_1_0_OLC_DW.obj_o,
      &PID_C_R_Simulink_1_0_OLC_DW.gobj_2_f);
    obj = &PID_C_R_Simulink_1_0_OLC_DW.obj_o;
    PID_C_R_Simulink_1_0_OLC_DW.obj_o.isSetupComplete = false;
    PID_C_R_Simulink_1_0_OLC_DW.obj_o.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(PID_C_R_Simulink_1_0_OLC_DW.obj_o.PinPWM,
      0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (PID_C_R_Simulink_1_0_OLC_DW.obj_o.PinPWM);
    MW_PWM_Start(PID_C_R_Simulink_1_0_OLC_DW.obj_o.MW_PWM_HANDLE);
    PID_C_R_Simulink_1_0_OLC_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Input' */
    PID_C_R_Simulink_1_0_OLC_DW.obj_f.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_OLC_DW.obj_f.SampleTime =
      PID_C_R_Simulink_1_0_OLC_P.DigitalInput_SampleTime;
    PID_C_R_Simulink_1_0_OLC_DW.obj_f.isInitialized = 1L;
    digitalIOSetup(9, 0);
    PID_C_R_Simulink_1_0_OLC_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Input' */
    PID_C_R_Simulink_1_0_OLC_DW.obj_l.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_OLC_DW.obj_l.SampleTime =
      PID_C_R_Simulink_1_0_OLC_P.DigitalInput_SampleTime_h;
    PID_C_R_Simulink_1_0_OLC_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(8, 0);
    PID_C_R_Simulink_1_0_OLC_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Output' */
    PID_C_R_Simulink_1_0_OLC_DW.obj_a.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_OLC_DW.obj_a.isInitialized = 1L;
    digitalIOSetup(4, 1);
    PID_C_R_Simulink_1_0_OLC_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Output1' */
    PID_C_R_Simulink_1_0_OLC_DW.obj_lo.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_OLC_DW.obj_lo.isInitialized = 1L;
    digitalIOSetup(5, 1);
    PID_C_R_Simulink_1_0_OLC_DW.obj_lo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Output2' */
    PID_C_R_Simulink_1_0_OLC_DW.obj_n.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_OLC_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(2, 1);
    PID_C_R_Simulink_1_0_OLC_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Output3' */
    PID_C_R_Simulink_1_0_OLC_DW.obj_fk.matlabCodegenIsDeleted = false;
    PID_C_R_Simulink_1_0_OLC_DW.obj_fk.isInitialized = 1L;
    digitalIOSetup(3, 1);
    PID_C_R_Simulink_1_0_OLC_DW.obj_fk.isSetupComplete = true;
  }
}

/* Model terminate function */
void PID_C_R_Simulink_1_0_OLC_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/PWM' */
  matlabCodegenHandle_matlabCodeg(&PID_C_R_Simulink_1_0_OLC_DW.obj);

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  matlabCodegenHandle_matlabCodeg(&PID_C_R_Simulink_1_0_OLC_DW.obj_o);

  /* Terminate for MATLABSystem: '<S5>/Digital Input' */
  matlabCodegenHandle_matlabCo_oe(&PID_C_R_Simulink_1_0_OLC_DW.obj_f);

  /* Terminate for MATLABSystem: '<S7>/Digital Input' */
  matlabCodegenHandle_matlabCo_oe(&PID_C_R_Simulink_1_0_OLC_DW.obj_l);

  /* Terminate for MATLABSystem: '<S6>/Digital Output' */
  matlabCodegenHandle_matlabC_oen(&PID_C_R_Simulink_1_0_OLC_DW.obj_a);

  /* Terminate for MATLABSystem: '<S6>/Digital Output1' */
  matlabCodegenHandle_matlabC_oen(&PID_C_R_Simulink_1_0_OLC_DW.obj_lo);

  /* Terminate for MATLABSystem: '<S6>/Digital Output2' */
  matlabCodegenHandle_matlabC_oen(&PID_C_R_Simulink_1_0_OLC_DW.obj_n);

  /* Terminate for MATLABSystem: '<S6>/Digital Output3' */
  matlabCodegenHandle_matlabC_oen(&PID_C_R_Simulink_1_0_OLC_DW.obj_fk);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
