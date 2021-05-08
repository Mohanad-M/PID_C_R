/*
 * File: PID_C_R_Simulink_1_0_CLC_private.h
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

#ifndef RTW_HEADER_PID_C_R_Simulink_1_0_CLC_private_h_
#define RTW_HEADER_PID_C_R_Simulink_1_0_CLC_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "PID_C_R_Simulink_1_0_CLC.h"

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void PID_C_R_TriggeredSubsystem_Init(int32_T *rty_Out1,
  DW_TriggeredSubsystem_PID_C_R_T *localDW, P_TriggeredSubsystem_PID_C_R__T
  *localP);
extern void PID_C_R_Simu_TriggeredSubsystem(RT_MODEL_PID_C_R_Simulink_1_0_T *
  const PID_C_R_Simulink_1_0_CLC_M, boolean_T rtu_Trigger, int32_T *rty_Out1,
  DW_TriggeredSubsystem_PID_C_R_T *localDW, P_TriggeredSubsystem_PID_C_R__T
  *localP, ZCE_TriggeredSubsystem_PID_C__T *localZCE);

#endif                      /* RTW_HEADER_PID_C_R_Simulink_1_0_CLC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
