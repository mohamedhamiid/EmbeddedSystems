#include "util/delay.h"
#include "../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../SERVICES/bit_utilies.h"
#include "../../INCLUDE/HAL/Led/Led.h"
#include "../../INCLUDE/HAL/Button/Button.h"
#include "../../INCLUDE/MCAL/EXTINT/EXTINT.h"
#include "../../INCLUDE/MCAL/GIE/GIE.h"
/*************************************Task 9*******************************/
/* - Connect 2 ExtInt to 2 switches , Each switch Turn on (DC Motor,Buzz) */
/* - The interrupt happened during main program is executed               */
/* - The main program is to turn on even leds onebyone then turn them off */
/* and do the same thing to odd leds                                      */
/**************************************************************************/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	_delay_ms(500);
	TGL_BIT(PORTA_Register,6);
	_delay_ms(500);
}
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	_delay_ms(200);
	TGL_BIT(PORTA_Register,7);
	_delay_ms(200);
}
int main(){
	DIO_enuSetPortDirection(DIO_u8_PORTA,0b11000000);

EXTINT_structCfg INT[2]={
		{.IntMode=EXTINT_LOGICAL_CHANGE, .IntNo=EXTINT_INT0},
		{.IntMode=EXTINT_LOGICAL_CHANGE, .IntNo=EXTINT_INT1},

};

Button_tstrucCfg buttons[2]={
		{.Pin=DIO_u8_PIN2, .Button_NestStruct.Port=DIO_u8_PORTD},
		{.Pin=DIO_u8_PIN3, .Button_NestStruct.Port=DIO_u8_PORTD},
};
////////////////////////////////////////////////////////////////

u8 Ledcounter=0;
Led_tCfg Led_sys[8];
for(Ledcounter=0;Ledcounter<8;Ledcounter++){
	Led_sys[Ledcounter].Pin = Ledcounter;
	Led_sys[Ledcounter].Led_NestStruct.Port=DIO_u8_PORTC;
	Led_sys[Ledcounter].Led_NestStruct.Current_Status=Led_Active_High_Low;
	Led_sys[Ledcounter].Led_NestStruct.Active_Status=Led_Active_High;
	Led_vidLedInit(&Led_sys[Ledcounter]);
}
Button_vidButtonInit(&buttons[0]);
Button_vidButtonInit(&buttons[1]);
EXTINT_voidEnable(&INT[0]);
EXTINT_voidEnable(&INT[1]);
////////////////////////////////////////////////////////////////////
while(1){
	for(Ledcounter=0;Ledcounter<8;Ledcounter+=2){
		Led_vidToggle(&Led_sys[Ledcounter]);
		_delay_ms(500);
	}
	for(Ledcounter=0;Ledcounter<8;Ledcounter+=2){
		Led_vidToggle(&Led_sys[Ledcounter]);
	}
	for(Ledcounter=1;Ledcounter<8;Ledcounter+=2){
		Led_vidToggle(&Led_sys[Ledcounter]);
		_delay_ms(500);
	}
	for(Ledcounter=1;Ledcounter<8;Ledcounter+=2){
		Led_vidToggle(&Led_sys[Ledcounter]);
	}
}
	return 0;
}

