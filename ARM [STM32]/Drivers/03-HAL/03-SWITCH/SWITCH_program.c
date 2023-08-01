/*
 * Button.c
 *
 *  Created on: Sep 6, 2022
 *      Author: mh_sm
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "SWITCH_interface.h"


void SWITCH_voidInitSwitch(SWITCH_structCfg * Add_structButton){
	DIO_voidSetPinDirection(Add_structButton->SWITCH_2bitsPort,Add_structButton->SWITCH_u8Pin,DIO_INPUT,Add_structButton->SWITCH_2bitsMode);
}


u8 SWITCH_u8ButtonRead(SWITCH_structCfg * Add_structButton){
	u8 Loc_u8ButtonRead;
		for(u16 Loc_u16ButtonDebouncing=0;Loc_u16ButtonDebouncing<=20000;Loc_u16ButtonDebouncing++){

			Loc_u8ButtonRead = DIO_u8GetPinValue(Add_structButton->SWITCH_2bitsPort,Add_structButton->SWITCH_u8Pin);

			if(Add_structButton->SWITCH_2bitsMode == SWITCH_PULL_DOWN && Loc_u8ButtonRead==SWITCH_PULL_DOWN_NOT_PRESSED) /* Check Stability */
				Loc_u16ButtonDebouncing=0;
			else if(Add_structButton->SWITCH_2bitsMode == SWITCH_PULL_UP && Loc_u8ButtonRead==SWITCH_PULL_UP_NOT_PRESSED) /* Check Stability */
				Loc_u16ButtonDebouncing=0;
		}
	return Loc_u8ButtonRead;
}
