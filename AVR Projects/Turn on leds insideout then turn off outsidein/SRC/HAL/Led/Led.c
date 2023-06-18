/*
 * Led.c
 *
 *  Created on: Sep 4, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/HAL/Led/Led.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"

/*********************Led_vidLedInit********************/
/* USE : Initialize the Led according to user cfg      */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Led_vidLedInit(Led_tCfg*Add_structLed){
	DIO_enuSetPinDirection(Add_structLed->Led_NestStruct.Port,Add_structLed->Pin,DIO_u8_OUTPUT);
}

/***********************Led_vidOn***********************/
/* USE : Turn on Led                                   */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Led_vidOn(Led_tCfg*Add_structLed){
	if((Add_structLed->Led_NestStruct.Active_Status) == Led_Active_High){
		Add_structLed->Led_NestStruct.Current_Status = Led_Active_High_High;
		DIO_enuSetPinValue(Add_structLed->Led_NestStruct.Port,Add_structLed->Pin,Led_Active_High_High);
	}
	else if(Add_structLed->Led_NestStruct.Active_Status == Led_Active_Low){
		Add_structLed->Led_NestStruct.Current_Status = Led_Active_Low_High;
		DIO_enuSetPinValue(Add_structLed->Led_NestStruct.Port,Add_structLed->Pin,Led_Active_Low_High);
	}
}


/***********************Led_vidOff**********************/
/* USE : Turn off Led                                  */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Led_vidOff(Led_tCfg*Add_structLed){
	if(Add_structLed->Led_NestStruct.Active_Status == Led_Active_High){
		Add_structLed->Led_NestStruct.Current_Status = Led_Active_High_Low;
		DIO_enuSetPinValue(Add_structLed->Led_NestStruct.Port ,Add_structLed->Pin,Led_Active_High_Low);
	}
	else if(Add_structLed->Led_NestStruct.Active_Status == Led_Active_Low){
		Add_structLed->Led_NestStruct.Current_Status = Led_Active_Low_Low;
		DIO_enuSetPinValue(Add_structLed->Led_NestStruct.Port ,Add_structLed->Pin,Led_Active_Low_Low);
	}
}


/***********************Led_vidToggle*******************/
/* USE : Toggle Led                                    */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Led_vidToggle(Led_tCfg*Add_structLed){

	if(Add_structLed->Led_NestStruct.Active_Status == Led_Active_High){
			if(Add_structLed->Led_NestStruct.Current_Status == Led_Active_High_Low){ //OFF-->ON
				DIO_enuSetPinValue(Add_structLed->Led_NestStruct.Port ,Add_structLed->Pin,Led_Active_High_High);
				Add_structLed->Led_NestStruct.Current_Status = Led_Active_High_High;
			}


			else if(Add_structLed->Led_NestStruct.Current_Status == Led_Active_High_High){ //ON-->OFF
				DIO_enuSetPinValue(Add_structLed->Led_NestStruct.Port ,Add_structLed->Pin,Led_Active_High_Low);
				Add_structLed->Led_NestStruct.Current_Status = Led_Active_High_Low;
			}
		}


	else if(Add_structLed->Led_NestStruct.Active_Status == Led_Active_Low){
			if(Add_structLed->Led_NestStruct.Current_Status == Led_Active_Low_Low){
				DIO_enuSetPinValue(Add_structLed->Led_NestStruct.Port ,Add_structLed->Pin,Led_Active_Low_High);
				Add_structLed->Led_NestStruct.Current_Status = Led_Active_Low_High;
			}


			else if(Add_structLed->Led_NestStruct.Current_Status == Led_Active_Low_High){
				DIO_enuSetPinValue(Add_structLed->Led_NestStruct.Port ,Add_structLed->Pin,Led_Active_Low_Low);
				Add_structLed->Led_NestStruct.Current_Status = Led_Active_Low_Low;
			}
		}

}



