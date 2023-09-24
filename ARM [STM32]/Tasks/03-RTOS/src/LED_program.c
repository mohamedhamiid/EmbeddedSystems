/*
 * Led.c
 *
 *  Created on: Sep 4, 2022
 *      Author: mh_sm
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LED_interface.h"


/****************** LED_voidInitLed  *******************/
/* USE : Initialize the Led according to user cfg      */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void HLED_voidInitLed(HLED_structCfg * Add_structLedCfg){

	DIO_voidSetPinDirection(Add_structLedCfg->LED_2bitsPort    ,
							Add_structLedCfg->LED_u8Pin        ,
							Add_structLedCfg->LED_2bitsOutFreq ,
							DIO_OUTPUT_PUSH_PULL);
}

/***********************Led_vidOn***********************/
/* USE : Turn on Led                                   */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void HLED_voidTurnOn(HLED_structCfg*Add_structLedCfg){
	if((Add_structLedCfg->LED_1bitConnectionType) == LED_ACTIVE_HIGH){

		Add_structLedCfg->LED_1bitCurrentState = LED_ACTIVE_HIGH_ON;

		DIO_voidSetPinValue(Add_structLedCfg->LED_2bitsPort ,
							Add_structLedCfg->LED_u8Pin     ,
							LED_ACTIVE_HIGH_ON);
	}
	else if(Add_structLedCfg->LED_1bitConnectionType == LED_ACTIVE_LOW){

		Add_structLedCfg->LED_1bitCurrentState = LED_ACTIVE_LOW_ON;

		DIO_voidSetPinValue(Add_structLedCfg->LED_2bitsPort ,
							Add_structLedCfg->LED_u8Pin     ,
							LED_ACTIVE_LOW_ON);
	}
}


/***********************Led_vidOff**********************/
/* USE : Turn off Led                                  */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void HLED_voidTurnOff(HLED_structCfg*Add_structLedCfg){
	if(Add_structLedCfg->LED_1bitConnectionType == LED_ACTIVE_HIGH){
		Add_structLedCfg->LED_1bitCurrentState = LED_ACTIVE_HIGH_OFF;
		DIO_voidSetPinValue(Add_structLedCfg->LED_2bitsPort ,
							Add_structLedCfg->LED_u8Pin     ,
							LED_ACTIVE_HIGH_OFF);
	}
	else if(Add_structLedCfg->LED_1bitConnectionType == LED_ACTIVE_LOW){
		Add_structLedCfg->LED_1bitCurrentState = LED_ACTIVE_LOW_OFF;
		DIO_voidSetPinValue(Add_structLedCfg->LED_2bitsPort ,
							Add_structLedCfg->LED_u8Pin     ,
							LED_ACTIVE_LOW_OFF);
	}
}


/***********************Led_vidToggle*******************/
/* USE : Toggle Led                                    */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void HLED_voidToggle(HLED_structCfg*Add_structLedCfg){

	if(Add_structLedCfg->LED_1bitConnectionType == LED_ACTIVE_HIGH){
			if(Add_structLedCfg->LED_1bitCurrentState == LED_ACTIVE_HIGH_OFF){ //OFF-->ON

				DIO_voidSetPinValue(Add_structLedCfg->LED_2bitsPort ,
									Add_structLedCfg->LED_u8Pin,
									LED_ACTIVE_HIGH_ON);

				Add_structLedCfg->LED_1bitCurrentState = LED_ACTIVE_HIGH_ON;
			}


			else if(Add_structLedCfg->LED_1bitCurrentState == LED_ACTIVE_HIGH_ON){ //ON-->OFF
				DIO_voidSetPinValue(Add_structLedCfg->LED_2bitsPort ,
									Add_structLedCfg->LED_u8Pin     ,
									LED_ACTIVE_HIGH_OFF);
				Add_structLedCfg->LED_1bitCurrentState = LED_ACTIVE_HIGH_OFF;
			}
		}


	else if(Add_structLedCfg->LED_1bitConnectionType == LED_ACTIVE_LOW){

			if(Add_structLedCfg->LED_1bitCurrentState == LED_ACTIVE_LOW_OFF){

				DIO_voidSetPinValue(Add_structLedCfg->LED_2bitsPort ,
									Add_structLedCfg->LED_u8Pin,
									LED_ACTIVE_LOW_ON);

				Add_structLedCfg->LED_1bitCurrentState = LED_ACTIVE_LOW_ON;
			}


			else if(Add_structLedCfg->LED_1bitCurrentState == LED_ACTIVE_LOW_ON){
				DIO_voidSetPinValue(Add_structLedCfg->LED_2bitsPort ,
									Add_structLedCfg->LED_u8Pin     ,
								 	LED_ACTIVE_LOW_OFF);
				Add_structLedCfg->LED_1bitCurrentState = LED_ACTIVE_LOW_OFF;
			}

		}

}



