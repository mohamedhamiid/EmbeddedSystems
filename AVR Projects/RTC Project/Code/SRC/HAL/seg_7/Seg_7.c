/*
 * Seg_7.c
 *
 *  Created on: Sep 4, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/HAL/seg_7/seg_7.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../../SERVICES/std_types.h"

u8 segment_7[10]={63,6,91,79,102,109,125,7,127,111};

/*********************Seg_vidSegInit*********************/
/* USE: Initialize the 7 segments according to user cfg */
/* PARAMETERS: The struct carries cfg                   */
/* RETURN: No Return                                    */
/********************************************************/
void Seg_vidInit(Seg_tCfg*Add_structSeg){
	DIO_enuSetPortDirection(Add_structSeg->Port,DIO_u8_PORT_OUTPUT);
}

/***********************Seg_vidOn************************/
/* USE: Write on 7 Segment                              */
/* PARAMETERS: - The struct carries cfg                 */
/*             - The number to be written               */
/* RETURN: No Return                                    */
/********************************************************/
void Seg_vidOn(Seg_tCfg*Add_structSeg,u8 Add_u8SegVal){
	if((Add_structSeg->Common_Type) == Seg_CommCathode){
		DIO_enuSetPortValue(Add_structSeg->Port,segment_7[Add_u8SegVal]);
	}
	else if((Add_structSeg->Common_Type) == Seg_CommAnode){
			DIO_enuSetPortValue(Add_structSeg->Port,~(segment_7[Add_u8SegVal]));
	}
}

