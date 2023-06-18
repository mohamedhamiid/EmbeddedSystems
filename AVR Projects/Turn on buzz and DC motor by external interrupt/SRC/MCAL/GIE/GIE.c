/*
 * GIE.c
 *
 *  Created on: Sep 20, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/MCAL/GIE/GIE_priv.h"
#include "../../../INCLUDE/MCAL/GIE/GIE.h"
#include"../../../SERVICES/bit_utilies.h"
#include"../../../SERVICES/std_types.h"
void GIE_voidGlobalInterruptEnable(){
	SET_BIT(SREG,7);
}
void GIE_voidGlobalInterruptDisable(){
	CLR_BIT(SREG,7);
}



