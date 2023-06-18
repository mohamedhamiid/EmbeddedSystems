/*
 * seg_7.h
 *
 *  Created on: Sep 4, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_HAL_SEG_7_SEG_7_H_
#define INCLUDE_HAL_SEG_7_SEG_7_H_

#include "../../../SERVICES/std_types.h"

typedef struct{
		u8 Port : 2 ;
		u8 Common_Type : 1 ;
}Seg_tCfg;
///////////////////////////////////////////
#define Seg_CommCathode 1
#define Seg_CommAnode 0
//////////////////////////////////////////

/*********************Seg_vidSegInit*********************/
/* USE: Initialize the 7 segments according to user cfg */
/* PARAMETERS: The struct carries cfg                   */
/* RETURN: No Return                                    */
/********************************************************/
void Seg_vidInit(Seg_tCfg*Add_structSeg);

/***********************Seg_vidOn************************/
/* USE: Write on 7 Segment                              */
/* PARAMETERS: - The struct carries cfg                 */
/*             - The number to be written               */
/* RETURN: No Return                                    */
/********************************************************/
void Seg_vidOn(Seg_tCfg*Add_structSeg,u8 Add_u8SegVal);

#endif /* INCLUDE_HAL_SEG_7_SEG_7_H_ */
