/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 30 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "HSTP_config.h"
#include "HSTP_interface.h"
#include "HSTP_priv.h"


void HSTP_voidSendSynchronous(u8* Add_u8DataArr){

	MDIO_voidSetPinValue(HSTP_DATA_PIN , MDIO_PIN_LOW);
	for(s8 Loc_u8BlockNo = HSTP_NO_OF_BLOCKS-1 ; Loc_u8BlockNo >= 0 ; Loc_u8BlockNo--){
	     for(s8 Loc_s8Counter = 7 ; Loc_s8Counter>=0 ;Loc_s8Counter--){

	     	/* Sending Bit by Bit starting from b7 */
	     	u8 Loc_u8Bit = GET_BIT(Add_u8DataArr[Loc_u8BlockNo],Loc_s8Counter) ;
	     	MDIO_voidSetPinValue(HSTP_DATA_PIN, Loc_u8Bit);

	     	/* Send Pulse to Shift Clock */
	     	MDIO_voidSetPinValue(HSTP_SHIFT_CLOCK_PIN , MDIO_PIN_HIGH);
	     	MSTK_voidSetBusyWait(1 , us) ;
	     	MDIO_voidSetPinValue(HSTP_SHIFT_CLOCK_PIN , MDIO_PIN_LOW);
	     	MSTK_voidSetBusyWait(1 , us) ;
	     }
	}

    /* Send Pulse to Storage Clock */
    MDIO_voidSetPinValue(HSTP_STORAGE_CLOCK_PIN , MDIO_PIN_HIGH);
    MSTK_voidSetBusyWait(1 , us) ;
    MDIO_voidSetPinValue(HSTP_STORAGE_CLOCK_PIN , MDIO_PIN_LOW);
    MSTK_voidSetBusyWait(1 , us) ;
}
