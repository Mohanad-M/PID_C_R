/*
 * File: PID_C_R_Simulink_1_0_CLC.h
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

#ifndef RTW_HEADER_PID_C_R_Simulink_1_0_CLC_h_
#define RTW_HEADER_PID_C_R_Simulink_1_0_CLC_h_
#include <math.h>
#include <stddef.h>
#ifndef PID_C_R_Simulink_1_0_CLC_COMMON_INCLUDES_
# define PID_C_R_Simulink_1_0_CLC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                           /* PID_C_R_Simulink_1_0_CLC_COMMON_INCLUDES_ */

#include "PID_C_R_Simulink_1_0_CLC_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S6>/Triggered Subsystem' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S10>/Unit Delay' */
} DW_TriggeredSubsystem_PID_C_R_T;

/* Zero-crossing (trigger) state for system '<S6>/Triggered Subsystem' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE_g;/* '<S6>/Triggered Subsystem' */
} ZCE_TriggeredSubsystem_PID_C__T;

/* Block signals (default storage) */
typedef struct {
  real_T u0;
  real_T sr;
  real32_T theta_diff;                 /* '<S14>/theta_diff' */
  int32_T Divide;                      /* '<S11>/Divide' */
  int32_T Divide_a;                    /* '<S10>/Divide' */
} B_PID_C_R_Simulink_1_0_CLC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/PWM1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S3>/PWM' */
  codertarget_arduinobase_blo_g_T obj_l;/* '<S7>/Digital Input' */
  codertarget_arduinobase_blo_g_T obj_e;/* '<S6>/Digital Input' */
  j_codertarget_arduinobase_int_T gobj_1;/* '<S3>/PWM1' */
  j_codertarget_arduinobase_int_T gobj_2;/* '<S3>/PWM1' */
  j_codertarget_arduinobase_int_T gobj_3;/* '<S3>/PWM1' */
  j_codertarget_arduinobase_int_T gobj_4;/* '<S3>/PWM1' */
  j_codertarget_arduinobase_int_T gobj_1_g;/* '<S3>/PWM' */
  j_codertarget_arduinobase_int_T gobj_2_f;/* '<S3>/PWM' */
  j_codertarget_arduinobase_int_T gobj_3_l;/* '<S3>/PWM' */
  j_codertarget_arduinobase_int_T gobj_4_p;/* '<S3>/PWM' */
  codertarget_arduinobase_block_T obj_a;/* '<S5>/Digital Output2' */
  codertarget_arduinobase_block_T obj_j;/* '<S5>/Digital Output3' */
  codertarget_arduinobase_block_T obj_et;/* '<S5>/Digital Output' */
  codertarget_arduinobase_block_T obj_p;/* '<S5>/Digital Output1' */
  real_T NextOutput;                   /* '<S8>/Random Number1' */
  real_T NextOutput_j;                 /* '<S9>/Random Number1' */
  int32_T UnitDelay_DSTATE;            /* '<S3>/Unit Delay' */
  int32_T UnitDelay1_DSTATE;           /* '<S3>/Unit Delay1' */
  real32_T TmpLatchAtTriggeredSubsystemInp;/* synthesized block */
  real32_T Memory_PreviousInput;       /* '<S8>/Memory' */
  real32_T Memory_PreviousInput_l;     /* '<S9>/Memory' */
  uint32_T RandSeed;                   /* '<S8>/Random Number1' */
  uint32_T RandSeed_e;                 /* '<S9>/Random Number1' */
  DW_TriggeredSubsystem_PID_C_R_T TriggeredSubsystem_o;/* '<S7>/Triggered Subsystem' */
  DW_TriggeredSubsystem_PID_C_R_T TriggeredSubsystem;/* '<S6>/Triggered Subsystem' */
} DW_PID_C_R_Simulink_1_0_CLC_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S12>/Triggered Subsystem' */
  ZCE_TriggeredSubsystem_PID_C__T TriggeredSubsystem_o;/* '<S7>/Triggered Subsystem' */
  ZCE_TriggeredSubsystem_PID_C__T TriggeredSubsystem;/* '<S6>/Triggered Subsystem' */
} PrevZCX_PID_C_R_Simulink_1_0__T;

/* Parameters for system: '<S6>/Triggered Subsystem' */
struct P_TriggeredSubsystem_PID_C_R__T_ {
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S10>/Unit Delay'
                                        */
  real_T Constant_Value;               /* Expression: 6
                                        * Referenced by: '<S10>/Constant'
                                        */
  int32_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S10>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_PID_C_R_Simulink_1_0_CLC_T_ {
  real_T DigitalInput_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<S6>/Digital Input'
                                        */
  real_T DigitalInput_SampleTime_d;    /* Expression: 0.001
                                        * Referenced by: '<S7>/Digital Input'
                                        */
  real_T uDLookupTable_tableData[3];   /* Expression: [-360 0 360]
                                        * Referenced by: '<S8>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[3];    /* Expression: [-100 0 100]
                                        * Referenced by: '<S8>/1-D Lookup Table'
                                        */
  real_T RandomNumber1_Mean;           /* Expression: 0
                                        * Referenced by: '<S8>/Random Number1'
                                        */
  real_T RandomNumber1_StdDev;       /* Computed Parameter: RandomNumber1_StdDev
                                      * Referenced by: '<S8>/Random Number1'
                                      */
  real_T RandomNumber1_Seed;           /* Expression: randi(1000)
                                        * Referenced by: '<S8>/Random Number1'
                                        */
  real_T uDLookupTable_tableData_b[3]; /* Expression: [-360 0 360]
                                        * Referenced by: '<S9>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data_f[3];  /* Expression: [-100 0 100]
                                        * Referenced by: '<S9>/1-D Lookup Table'
                                        */
  real_T RandomNumber1_Mean_m;         /* Expression: 0
                                        * Referenced by: '<S9>/Random Number1'
                                        */
  real_T RandomNumber1_StdDev_h;   /* Computed Parameter: RandomNumber1_StdDev_h
                                    * Referenced by: '<S9>/Random Number1'
                                    */
  real_T RandomNumber1_Seed_l;         /* Expression: randi(1000)
                                        * Referenced by: '<S9>/Random Number1'
                                        */
  int32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  int32_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S3>/Unit Delay1'
                               */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real32_T theta_offset_Y0;            /* Computed Parameter: theta_offset_Y0
                                        * Referenced by: '<S14>/theta_offset'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S15>/Constant'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S12>/Gain'
                                        */
  real32_T TmpLatchAtTriggeredSubsystemInp;
                          /* Computed Parameter: TmpLatchAtTriggeredSubsystemInp
                           * Referenced by: synthesized block
                           */
  real32_T TurnAngle_Value;            /* Computed Parameter: TurnAngle_Value
                                        * Referenced by: '<Root>/Turn Angle'
                                        */
  real32_T Speed_Value;                /* Computed Parameter: Speed_Value
                                        * Referenced by: '<Root>/Speed'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S4>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S4>/Saturation1'
                                      */
  real32_T Scale1_Gain;                /* Computed Parameter: Scale1_Gain
                                        * Referenced by: '<S3>/Scale1'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real32_T WeightedSampleTime_WtEt;
                                  /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S8>/Weighted Sample Time'
                                   */
  real32_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S8>/Memory'
                                   */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S4>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S4>/Saturation'
                                       */
  real32_T Scale_Gain;                 /* Computed Parameter: Scale_Gain
                                        * Referenced by: '<S3>/Scale'
                                        */
  real32_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T WeightedSampleTime_WtEt_p;
                                /* Computed Parameter: WeightedSampleTime_WtEt_p
                                 * Referenced by: '<S9>/Weighted Sample Time'
                                 */
  real32_T Memory_InitialCondition_e;
                                /* Computed Parameter: Memory_InitialCondition_e
                                 * Referenced by: '<S9>/Memory'
                                 */
  boolean_T SwitchControl_Value;       /* Expression: switch_mode
                                        * Referenced by: '<S1>/Switch Control'
                                        */
  boolean_T Constant_Value_f;          /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S5>/Constant'
                                        */
  boolean_T Constant1_Value_f;         /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S5>/Constant1'
                                        */
  boolean_T Constant2_Value_d;         /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S5>/Constant2'
                                        */
  boolean_T Constant3_Value;           /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S5>/Constant3'
                                        */
  P_TriggeredSubsystem_PID_C_R__T TriggeredSubsystem_o;/* '<S7>/Triggered Subsystem' */
  P_TriggeredSubsystem_PID_C_R__T TriggeredSubsystem;/* '<S6>/Triggered Subsystem' */
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
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (default storage) */
extern P_PID_C_R_Simulink_1_0_CLC_T PID_C_R_Simulink_1_0_CLC_P;

/* Block signals (default storage) */
extern B_PID_C_R_Simulink_1_0_CLC_T PID_C_R_Simulink_1_0_CLC_B;

/* Block states (default storage) */
extern DW_PID_C_R_Simulink_1_0_CLC_T PID_C_R_Simulink_1_0_CLC_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_PID_C_R_Simulink_1_0__T PID_C_R_Simulink_1_0_CL_PrevZCX;

/* Model entry point functions */
extern void PID_C_R_Simulink_1_0_CLC_initialize(void);
extern void PID_C_R_Simulink_1_0_CLC_step(void);
extern void PID_C_R_Simulink_1_0_CLC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_C_R_Simulink_1_0_T *const PID_C_R_Simulink_1_0_CLC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S1>/Numerical Unity' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'PID_C_R_Simulink_1_0_CLC'
 * '<S1>'   : 'PID_C_R_Simulink_1_0_CLC/Environment Controller'
 * '<S2>'   : 'PID_C_R_Simulink_1_0_CLC/Model Info'
 * '<S3>'   : 'PID_C_R_Simulink_1_0_CLC/Motors'
 * '<S4>'   : 'PID_C_R_Simulink_1_0_CLC/PID Controller'
 * '<S5>'   : 'PID_C_R_Simulink_1_0_CLC/Motors/Enable Motors'
 * '<S6>'   : 'PID_C_R_Simulink_1_0_CLC/Motors/Left Wheels Encoder'
 * '<S7>'   : 'PID_C_R_Simulink_1_0_CLC/Motors/Right Wheels Encoder'
 * '<S8>'   : 'PID_C_R_Simulink_1_0_CLC/Motors/Simulated Left Wheel Motor'
 * '<S9>'   : 'PID_C_R_Simulink_1_0_CLC/Motors/Simulated Right Wheel Motor'
 * '<S10>'  : 'PID_C_R_Simulink_1_0_CLC/Motors/Left Wheels Encoder/Triggered Subsystem'
 * '<S11>'  : 'PID_C_R_Simulink_1_0_CLC/Motors/Right Wheels Encoder/Triggered Subsystem'
 * '<S12>'  : 'PID_C_R_Simulink_1_0_CLC/PID Controller/Calculate theta_diff'
 * '<S13>'  : 'PID_C_R_Simulink_1_0_CLC/PID Controller/Calculate theta_diff/Detect Flag'
 * '<S14>'  : 'PID_C_R_Simulink_1_0_CLC/PID Controller/Calculate theta_diff/Triggered Subsystem'
 * '<S15>'  : 'PID_C_R_Simulink_1_0_CLC/PID Controller/Calculate theta_diff/Detect Flag/Compare To Zero'
 */
#endif                              /* RTW_HEADER_PID_C_R_Simulink_1_0_CLC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
