/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 01 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/

#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "STD_TYPES.h"

/* Options
 	 	  SWITCH_u8Pin			     :	DIO_PINn (n:0-15)


          SWITCH_2bitsPort           :  DIO_PORTA
							     		DIO_PORTB
							     	 	DIO_PORTC

		  SWITCH_1bitConnectionType  :  SWITCH_PULL_UP       NOTE: Connect the switch
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	   to GND
                                     	SWITCH_PULL_DOWN	 NOTE: Connect the switch
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	   to VCC
										SWITCH_PULL_FLOATING
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  */

typedef struct{
	u8 SWITCH_u8Pin   										   ;
	u8 SWITCH_2bitsPort       		 : 2                       ;
	u8 SWITCH_2bitsMode 	  		 : 2                       ;
}SWITCH_structCfg;

/* Modes */
#define SWITCH_PULL_FLOATING    	   1
#define SWITCH_PULL_UP 			       2
#define SWITCH_PULL_DOWN               3

/* Readings */
#define SWITCH_PULL_UP_PRESSED         0
#define SWITCH_PULL_UP_NOT_PRESSED     1

#define SWITCH_PULL_DOWN_PRESSED       1
#define SWITCH_PULL_DOWN_NOT_PRESSED   0



void SWITCH_voidInitSwitch(SWITCH_structCfg * Add_structButton);
u8 SWITCH_u8ButtonRead(SWITCH_structCfg * Add_structButton);

#endif /* INCLUDE_HAL_BUTTON_BUTTON_H_ */
