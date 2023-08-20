/*
 * Seg_7.c
 *
 *  Created on: Sep 4, 2022
 *      Author: mh_sm
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEVENSEG_interface.h"

u8 SEVENSEG_u8Digits[10]={63,6,91,79,102,109,125,7,127,111};

/*********************Seg_vidSegInit*********************/
/* USE: Initialize the 7 segments according to user cfg */
/* PARAMETERS: The struct carries cfg                   */
/* RETURN: No Return                                    */
/********************************************************/
void SEVENSEG_voidInitSevenSeg(SEVENSEG_structCfg *Add_structSeg){
	for(u8 i = Add_structSeg->SEVENSEG_u8StartPin ; i < Add_structSeg->SEVENSEG_u8StartPin+8 ; i++)
	DIO_voidSetPinDirection(Add_structSeg->SEVENSEG_2bitPort,i,Add_structSeg->SEVENSEG_2bitsOutFreq,DIO_OUTPUT_PUSH_PULL);
}

/***********************Seg_vidOn************************/
/* USE: Write on 7 Segment                              */
/* PARAMETERS: - The struct carries cfg                 */
/*             - The number to be written               */
/* RETURN: No Return                                    */
/********************************************************/
void SEVENSEG_voidTurnOnSevenSeg(SEVENSEG_structCfg *Add_structSeg ,u8 Copy_u8SegVal){
	if(Copy_u8SegVal<=9 && Copy_u8SegVal >= 0){
		if((Add_structSeg->SEVENSEG_1bitCommonType) == SEVENSEG_COMMON_CATHODE){
			DIO_voidSet8BitsValue(Add_structSeg->SEVENSEG_2bitPort,Add_structSeg->SEVENSEG_u8StartPin,SEVENSEG_u8Digits[Copy_u8SegVal]);
		}
		else if((Add_structSeg->SEVENSEG_1bitCommonType) == SEVENSEG_COMMON_ANODE){
			DIO_voidSet8BitsValue(Add_structSeg->SEVENSEG_2bitPort,Add_structSeg->SEVENSEG_u8StartPin,~SEVENSEG_u8Digits[Copy_u8SegVal]);
		}
	}
	else{/* Invalid 7 seg value */}
}

