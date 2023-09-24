/*
 * DAC_program.c
 *
 *  Created on: Aug 26, 2023
 *      Author: mh_sm
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_priv.h"

volatile u32 Global_u32ArrLastIndex    = 0;
HDAC_structCfg * Global_structUsedDAC;
DAC_tDataInfo Global_structConvertedData;

void HDAC_voidStart(HDAC_structCfg* Add_structCfg){

	Global_structUsedDAC = Add_structCfg ;

	for(u8 i=Global_structUsedDAC->startPin ; i < 8 ; i++)
		MDIO_voidSetPinDirection(Global_structUsedDAC->port , i , MDIO_DIRECTION_OUTPUT_2MHZ, MDIO_MODE_OUTPUT_PUSH_PULL);

	MSTK_voidInit();

	MSTK_voidSetIntervalPeriodic(Add_structCfg->samplingFreqInUs,us,HDAC_voidConvertData);
}

void HDAC_voidConvertData(){

	MDIO_voidSet8BitsValue(Global_structUsedDAC->port,Global_structUsedDAC->startPin,Global_structConvertedData.CurrentDataArr[Global_u32ArrLastIndex]);

	Global_u32ArrLastIndex++;

	if(Global_u32ArrLastIndex==(Global_structConvertedData.CurrentDataSize))
		Global_u32ArrLastIndex=0;
}

void HDAC_voidSetConvertedData(u8*Add_u8DataArr,u32 Copy_u32ArrSize){

	Global_structConvertedData.CurrentDataSize = Copy_u32ArrSize ;

	Global_structConvertedData.CurrentDataArr  = Add_u8DataArr   ;
}

