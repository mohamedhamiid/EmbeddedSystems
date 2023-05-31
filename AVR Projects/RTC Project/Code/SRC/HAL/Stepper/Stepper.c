/*
 * Stepper.c
 *
 *  Created on: Sep 21, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/HAL/Stepper/Stepper.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"
#include "util/delay.h"

/*******************Stepper_voidInit********************/
/* USE : Initialize the Stepper according to user cfg  */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Stepper_voidInit(Stepper_tstructCfg*Add_structStepper){
	DIO_enuSetPortDirection(Add_structStepper->Port,0b00001111);
	DIO_enuSetPortValue(Add_structStepper->Port,0);
}

/*********************Stepper_voidOn********************/
/* USE : Turn on stepper and control it                */
/* PARAMETERS: - The struct carries cfg                */
/*             - Stepper Direction                     */
/*             - Stepper Rotation Degree               */
/*             - Stepper mode                          */
/* RETURN: No Return                                   */
/*******************************************************/
void Stepper_voidOn(Stepper_tstructCfg*Add_structStepper,u8 Copy_u8StepperDirection,u8 Copy_u8StepperStepMode,u8 Copy_u8StepperDegree){
	u8 StepperCounter=0;


	switch(Copy_u8StepperStepMode){


	case Stepper_FULL_STEP:
		for(StepperCounter=0;StepperCounter<Copy_u8StepperDegree;StepperCounter++){
			switch(Copy_u8StepperDirection){
				case Stepper_CLOCKWISE:DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000001);break;
				case Stepper_COUNTER_CLOCKWISE:DIO_enuSetPortValue(DIO_u8_PORTA ,0b00001000);break;
			}
			_delay_ms(5);
			DIO_enuSetPortValue(Add_structStepper->Port,0);
		}
	break;


	case Stepper_HALF_STEP:
		for(StepperCounter=0;StepperCounter<Copy_u8StepperDegree;StepperCounter++){
			switch(Copy_u8StepperDirection){
				case Stepper_CLOCKWISE:DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000011);break;
				case Stepper_COUNTER_CLOCKWISE:DIO_enuSetPortValue(DIO_u8_PORTA ,0b00001100);break;
			}
			_delay_ms(5);
			DIO_enuSetPortValue(Add_structStepper->Port,0);
		}
	break;
	}
}

