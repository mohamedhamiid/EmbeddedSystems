/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 15 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_priv.h"
#include "AFIO_config.h"

void AFIO_voidSetEXTIPin(u8 Copy_u8Line , u8 Copy_u8Port){

	if(Copy_u8Line<=19){

		u8 Loc_u8RegNo = Copy_u8Line / 4 ;
		u8 Loc_u8SegmentNo = Copy_u8Line % 4 ;

		AFIO->AFIO_EXTICR[Loc_u8RegNo] &= ~(0b1111<<Loc_u8SegmentNo); /* reset the desired 4 bits */
		AFIO->AFIO_EXTICR[Loc_u8RegNo] |=  (Copy_u8Port<<Loc_u8SegmentNo);

	}
	else{
		/* Error : Invalid Line Or Pin */
	}

}



