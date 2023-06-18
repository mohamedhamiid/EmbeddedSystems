/*
 * STEPPER.h
 *
 *  Created on: Sep 21, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_HAL_STEPPER_STEPPER_H_
#define INCLUDE_HAL_STEPPER_STEPPER_H_
#include "../../../SERVICES/std_types.h"
/////////////////////////////////////////////
typedef struct{
	u8 Port:2;
}Stepper_tstructCfg;
////////////////////////////////////////////
#define Stepper_COUNTER_CLOCKWISE 0
#define Stepper_CLOCKWISE 1

#define Stepper_HALF_STEP 0
#define Stepper_FULL_STEP 1

#define Stepper_FULL_STEP_90DEG  1
#define Stepper_FULL_STEP_180DEG 2
#define Stepper_FULL_STEP_270DEG 3
#define Stepper_FULL_STEP_360DEG 4

#define Stepper_HALF_STEP_45DEG  1
#define Stepper_HALF_STEP_90DEG  2
#define Stepper_HALF_STEP_135DEG 3
#define Stepper_HALF_STEP_180DEG 4
#define Stepper_HALF_STEP_225DEG 5
#define Stepper_HALF_STEP_270DEG 6
#define Stepper_HALF_STEP_315DEG 7
#define Stepper_HALF_STEP_360DEG 8


/*******************Stepper_voidInit********************/
/* USE : Initialize the Stepper according to user cfg  */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Stepper_voidInit(Stepper_tstructCfg*Add_structStepper);

/*********************Stepper_voidOn********************/
/* USE : Turn on stepper and control it                */
/* PARAMETERS: - The struct carries cfg                */
/*             - Stepper Direction                     */
/*             - Stepper Rotation Degree               */
/*             - Stepper mode                          */
/* RETURN: No Return                                   */
/*******************************************************/
void Stepper_voidOn(Stepper_tstructCfg*Add_structStepper,u8 Copy_u8StepperDirection,u8 Copy_u8StepperStepMode,u8 Copy_u8StepperDegree);



#endif /* INCLUDE_HAL_STEPPER_STEPPER_H_ */
