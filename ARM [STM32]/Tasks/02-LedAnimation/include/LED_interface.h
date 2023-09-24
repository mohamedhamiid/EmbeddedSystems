/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 30 / 7 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


/* Options
 	 	 LED_u8Pin			     :	 DIO_PINn (n:0-15)

		 LED_2bitsOutFreq	     :	 LED_OUTPUT_2MHZ
                                     LED_OUTPUT_10MHZ
                                     LED_OUTPUT_50MHZ

          LED_2bitsPort          :   DIO_PORTA
							     	 DIO_PORTB
							     	 DIO_PORTC

		  LED_1bitConnectionType :   LED_ACTIVE_HIGH
                                     LED_ACTIVE_LOW

		  LED_1bitCurrentState   :   LED_ACTIVE_HIGH_ON
                                     LED_ACTIVE_HIGH_OFF

                                     LED_ACTIVE_LOW_ON
                                     LED_ACTIVE_LOW_OFF			*/

typedef struct {
	u8 LED_u8Pin;
	u8 LED_2bitsOutFreq       : 2 ;
	u8 LED_2bitsPort          : 2 ;
	u8 LED_1bitConnectionType : 1 ;
	u8 LED_1bitCurrentState   : 1 ;
}HLED_structCfg;


/* Connection Types */

#define LED_ACTIVE_HIGH         1
#define LED_ACTIVE_LOW          0

/* Active High Voltages  */

#define LED_ACTIVE_HIGH_ON      1
#define LED_ACTIVE_HIGH_OFF     0

/* Active Low Voltages  */

#define LED_ACTIVE_LOW_ON       0
#define LED_ACTIVE_LOW_OFF      1

/* Out Frequency */
#define LED_OUTPUT_2MHZ     	0b10
#define LED_OUTPUT_10MHZ    	0b01
#define LED_OUTPUT_50MHZ    	0b11

/* Prototypes */

void HLED_voidInitLed(HLED_structCfg * Add_structLedCfg);
void HLED_voidTurnOn (HLED_structCfg * Add_structLedCfg);
void HLED_voidTurnOff(HLED_structCfg * Add_structLedCfg);
void HLED_voidToggle (HLED_structCfg * Add_structLedCfg);


#endif /* INCLUDE_HAL_LED_LED_H_ */
