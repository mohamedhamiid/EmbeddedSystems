/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 30 / 7 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/

#ifndef SEVEN_SEG_INTERFACE_H
#define SEVEN_SEG_INTERFACE_H

#include "STD_TYPES.h"


/* Options
 	 	  SEVENSEG_u8StartPin	 :	 DIO_PINn (n:0-15)

		  SEVENSEG_2bitsOutFreq  :	 SEVENSEG_OUTPUT_2MHZ
                                     SEVENSEG_OUTPUT_10MHZ
                                     SEVENSEG_OUTPUT_50MHZ

          SEVENSEG_2bitPort      :   DIO_PORTA
							     	 DIO_PORTB
							     	 DIO_PORTC

		  SEVENSEG_1bitCommonType:   SEVEN_SEG_COMMON_CATHODE
                                     SEVEN_SEG_COMMON_ANODE     */

typedef struct{
		u8 SEVENSEG_u8StartPin          ;
		u8 SEVENSEG_2bitsOutFreq    : 2 ;
		u8 SEVENSEG_2bitPort 		: 2 ;
		u8 SEVENSEG_1bitCommonType  : 1 ;
}SEVENSEG_structCfg;

/* Common Type */
#define SEVENSEG_COMMON_CATHODE   	  1
#define SEVENSEG_COMMON_ANODE         0

/* Out Frequency */
#define SEVENSEG_OUTPUT_2MHZ         1
#define SEVENSEG_OUTPUT_10MHZ        2
#define SEVENSEG_OUTPUT_50MHZ        3

/* ProtoTypes */

/*********************Seg_vidSegInit*********************/
/* USE: Initialize the 7 segments according to user cfg */
/* PARAMETERS: The struct carries cfg                   */
/* RETURN: No Return                                    */
/********************************************************/
void SEVENSEG_voidInitSevenSeg(SEVENSEG_structCfg *Add_structSeg);

/***********************Seg_vidOn************************/
/* USE: Write on 7 Segment                              */
/* PARAMETERS: - The struct carries cfg                 */
/*             - The number to be written               */
/* RETURN: No Return                                    */
/********************************************************/
void SEVENSEG_voidTurnOnSevenSeg(SEVENSEG_structCfg *Add_structSeg ,u8 Add_u8SegVal);

#endif /* INCLUDE_HAL_SEG_7_SEG_7_H_ */
