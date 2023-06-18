/*
 * Button.c
 *
 *  Created on: Sep 6, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/HAL/Button/Button.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../../INCLUDE/MCAL/EXTINT/EXTINT.h"
#include "util/delay.h"
#include "../../../SERVICES/bit_utilies.h"


/*****************Button_vidButtonInit******************/
/* USE : Initialize the Button according to user cfg   */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/* PULL UP mode                                        */
/*******************************************************/
void Button_vidButtonInit(Button_tstrucCfg*Add_structButton){
	DIO_enuSetPinDirection(Add_structButton->Button_NestStruct.Port,Add_structButton->Pin,DIO_u8_INPUT);
	DIO_enuSetPinValue(Add_structButton->Button_NestStruct.Port,Add_structButton->Pin,DIO_u8_HIGH);
}


/*****************Button_u8ButtonRead********************/
/* USE : Determine whether the Button is Pressed or not */
/* PARAMETERS: The struct carries cfg                   */
/* RETURN: The Button Read                              */
/* The FOR loop solve debouncing problem                */
/********************************************************/
u8 Button_u8ButtonRead(Button_tstrucCfg*Add_structButton){
	u8 ButtonRead;
	for(u8 Button_u8ButtonDebouncing=0;Button_u8ButtonDebouncing<=150;Button_u8ButtonDebouncing++){
	DIO_u8GetPinValue(Add_structButton->Button_NestStruct.Port,Add_structButton->Pin,&ButtonRead);
	if(ButtonRead==Button_NotPressed)
		Button_u8ButtonDebouncing=0;
	}
	return ButtonRead;
}
