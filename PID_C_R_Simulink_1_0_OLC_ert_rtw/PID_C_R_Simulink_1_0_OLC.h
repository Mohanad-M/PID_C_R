/*
 * File: PID_C_R_Simulink_1_0_OLC.h
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

#ifndef RTW_HEADER_PID_C_R_Simulink_1_0_OLC_h_
#define RTW_HEADER_PID_C_R_Simulink_1_0_OLC_h_
#include <math.h>
#include <stddef.h>
#ifndef PID_C_R_Simulink_1_0_OLC_COMMON_INCLUDES_
# define PID_C_R_Simulink_1_0_OLC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                           /* PID_C_R_Simulink_1_0_OLC_COMMON_INCLUDES_ */

#include "PID_C_R_Simulink_1_0_OLC_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/PWM' */
  codertarget_arduinobase_inter_T obj_o;/* '<S3>/PWM1' */
  codertarget_arduinobase_block_T obj_l;/* '<S7>/Digital Input' */
  codertarget_arduinobase_block_T obj_f;/* '<S5>/Digital Input' */
  j_codertarget_arduinobase_int_T gobj_1;/* '<S3>/PWM' */
  j_codertarget_arduinobase_int_T gobj_2;/* '<S3>/PWM' */
  j_codertarget_arduinobase_int_T gobj_3;/* '<S3>/PWM' */
  j_codertarget_arduinobase_int_T gobj_4;/* '<S3>/PWM' */
  j_codertarget_arduinobase_int_T gobj_1_c;/* '<S3>/PWM1' */
  j_codertarget_arduinobase_int_T gobj_2_f;/* '<S3>/PWM1' */
  j_codertarget_arduinobase_int_T gobj_3_h;/* '<S3>/PWM1' */
  j_codertarget_arduinobase_int_T gobj_4_p;/* '<S3>/PWM1' */
  codertarget_arduinobase_blo_o_T obj_a;/* '<S6>/Digital Output' */
  codertarget_arduinobase_blo_o_T obj_lo;/* '<S6>/Digital Output1' */
  codertarget_arduinobase_blo_o_T obj_n;/* '<S6>/Digital Output2' */
  codertarget_arduinobase_blo_o_T obj_fk;/* '<S6>/Digital Output3' */
} DW_PID_C_R_Simulink_1_0_OLC_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S7>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_f;/* '<S5>/Triggered Subsystem' */
} PrevZCX_PID_C_R_Simulink_1_0__T;

/* Parameters (default storage) */
struct P_PID_C_R_Simulink_1_0_OLC_T_ {
  real_T DigitalInput_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<S5>/Digital Input'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S10>/Outport'
                                        */
  real_T DigitalInput_SampleTime_h;    /* Expression: 0.001
                                        * Referenced by: '<S7>/Digital Input'
                                        */
  real_T Outport_Y0_h;                 /* Computed Parameter: Outport_Y0_h
                                        * Referenced by: '<S11>/Outport'
                                        */
  real_T Constant_Value;               /* Expression: 75
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Scale_Gain;                   /* Expression: 2.55
                                        * Referenced by: '<S3>/Scale'
                                        */
  real_T Scale1_Gain;                  /* Expression: 2.55
                                        * Referenced by: '<S3>/Scale1'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PID_C_R_Simulink_1_0__T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_PID_C_R_Simulink_1_0_OLC_T PID_C_R_Simulink_1_0_OLC_P;

/* Block states (default storage) */
extern DW_PID_C_R_Simulink_1_0_OLC_T PID_C_R_Simulink_1_0_OLC_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_PID_C_R_Simulink_1_0__T PID_C_R_Simulink_1_0_OL_PrevZCX;

/* External function called from main */
extern void PID_C_R_Simulink_1_0_OLC_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void PID_C_R_Simulink_1_0_OLC_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void PID_C_R_Simulink_1_0_OLC_initialize(void);
extern void PID_C_R_Simulink_1_0_OLC_step0(void);
extern void PID_C_R_Simulink_1_0_OLC_step1(void);
extern void PID_C_R_Simulink_1_0_OLC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_C_R_Simulink_1_0_T *const PID_C_R_Simulink_1_0_OLC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Environment Switch' : Unused code path elimination
 * Block '<S1>/Numerical Unity' : Unused code path elimination
 * Block '<S1>/Switch Control' : Unused code path elimination
 * Block '<S3>/Add' : Unused code path elimination
 * Block '<S3>/Add1' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S10>/Add' : Unused code path elimination
 * Block '<S10>/Constant' : Unused code path elimination
 * Block '<S10>/Digital Clock' : Unused code path elimination
 * Block '<S10>/Divide' : Unused code path elimination
 * Block '<S10>/Unit Delay' : Unused code path elimination
 * Block '<S11>/Add' : Unused code path elimination
 * Block '<S11>/Constant' : Unused code path elimination
 * Block '<S11>/Digital Clock' : Unused code path elimination
 * Block '<S11>/Divide' : Unused code path elimination
 * Block '<S11>/Unit Delay' : Unused code path elimination
 * Block '<S8>/1-D Lookup Table' : Unused code path elimination
 * Block '<S8>/Add' : Unused code path elimination
 * Block '<S8>/Add1' : Unused code path elimination
 * Block '<S8>/Data Type Conversion' : Unused code path elimination
 * Block '<S8>/Memory' : Unused code path elimination
 * Block '<S8>/Random Number' : Unused code path elimination
 * Block '<S8>/Weighted Sample Time' : Unused code path elimination
 * Block '<S9>/1-D Lookup Table' : Unused code path elimination
 * Block '<S9>/Add' : Unused code path elimination
 * Block '<S9>/Add1' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Unused code path elimination
 * Block '<S9>/Memory' : Unused code path elimination
 * Block '<S9>/Random Number' : Unused code path elimination
 * Block '<S9>/Weighted Sample Time' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PID_C_R_Simulink_1_0_OLC'
 * '<S1>'   : 'PID_C_R_Simulink_1_0_OLC/Environment Controller1'
 * '<S2>'   : 'PID_C_R_Simulink_1_0_OLC/Model Info'
 * '<S3>'   : 'PID_C_R_Simulink_1_0_OLC/Motors'
 * '<S4>'   : 'PID_C_R_Simulink_1_0_OLC/Open loop controller'
 * '<S5>'   : 'PID_C_R_Simulink_1_0_OLC/Motors/Left Wheels encoder'
 * '<S6>'   : 'PID_C_R_Simulink_1_0_OLC/Motors/Motor Enable'
 * '<S7>'   : 'PID_C_R_Simulink_1_0_OLC/Motors/Right Wheels encoder'
 * '<S8>'   : 'PID_C_R_Simulink_1_0_OLC/Motors/Simulated Left wheel motor'
 * '<S9>'   : 'PID_C_R_Simulink_1_0_OLC/Motors/Simulated Right wheel motor'
 * '<S10>'  : 'PID_C_R_Simulink_1_0_OLC/Motors/Left Wheels encoder/Triggered Subsystem'
 * '<S11>'  : 'PID_C_R_Simulink_1_0_OLC/Motors/Right Wheels encoder/Triggered Subsystem'
 */
#endif                              /* RTW_HEADER_PID_C_R_Simulink_1_0_OLC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
