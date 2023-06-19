#include "util/delay.h"
#include "../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../INCLUDE/MCAL/TIMER/TIMER.h"
#include "../../INCLUDE/MCAL/UART/UART_priv.h"
#include "../../INCLUDE/MCAL/TIMER/TIMER_priv.h"
#include "../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../SERVICES/bit_utilies.h"
#include "../../INCLUDE/HAL/Led/Led.h"
#include "../../INCLUDE/HAL/Button/Button.h"

/************************************Task 10*********************************/
/* - Declaring 2 switches: one for increase and the other to decrease       */
/* - On pressing the increase switch, the leds turns on one by one          */
/* - When the 8 leds are turned on and pressing the increasing switch again */
/* the interrupt happens and all leds are turned on and off continuously    */
/* also the buzzer turns on , until I press the decrease switch             */
/* - The same interrupt happened when pressing the decrease switch and all  */
/* leds are off                                                             */
/****************************************************************************/
int main(){
	DIO_enuSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_OUTPUT);
Button_tstrucCfg buttons[2]={
		{.Pin=DIO_u8_PIN0, .Button_NestStruct.Port=DIO_u8_PORTA},
		{.Pin=DIO_u8_PIN3, .Button_NestStruct.Port=DIO_u8_PORTD},
};

s8 Ledcounter=0;
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
//////////////////////////////////////////////////////////////////
Ledcounter=0;
u8 ErrorFlag=0;
while(1){
	//increase button
	u8 forloopcounter=0;
	do{
		if(Button_u8ButtonRead(&buttons[0])==Button_Pressed){

			if(Ledcounter<8 && Ledcounter>=0)
				Led_vidOn(&Led_sys[Ledcounter]);
			else
				ErrorFlag=1;
			_delay_ms(300);
			Ledcounter++;
		}

		else if(Button_u8ButtonRead(&buttons[1])==Button_Pressed){

			if(Ledcounter<8 && Ledcounter>=0)
				Led_vidOff(&Led_sys[Ledcounter]);
			else
				ErrorFlag=1;
			_delay_ms(300);
			Ledcounter--;
		}
	}while(ErrorFlag==0);
	//Error
	do{
//		if(Ledcounter<8 && Ledcounter>=0){
//					for(forloopcounter=0;forloopcounter<=Ledcounter;forloopcounter++)
//					Led_vidOn(&Led_sys[forloopcounter]);
//					ErrorFlag=0;
//					break;
//				}
		for(forloopcounter=0;forloopcounter<8;forloopcounter++)
			Led_vidOn(&Led_sys[forloopcounter]);
		DIO_enuSetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH); //buzz

		_delay_ms(300);

		for(forloopcounter=0;forloopcounter<8;forloopcounter++)
			Led_vidOff(&Led_sys[forloopcounter]);
		DIO_enuSetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);

		_delay_ms(300);

		if(Button_u8ButtonRead(&buttons[0])==Button_Pressed && Ledcounter<0){
			Ledcounter++;
			if(Ledcounter<8 && Ledcounter>=0){
								for(forloopcounter=0;forloopcounter<=Ledcounter;forloopcounter++)
								Led_vidOn(&Led_sys[forloopcounter]);
								ErrorFlag=0;
								break;
							}
		}
		else if((Button_u8ButtonRead(&buttons[1])==Button_Pressed) && Ledcounter>7){
			Ledcounter--;
			if(Ledcounter<8 && Ledcounter>=0){
								for(forloopcounter=0;forloopcounter<=Ledcounter;forloopcounter++)
								Led_vidOn(&Led_sys[forloopcounter]);
								ErrorFlag=0;
								break;
							}
		}


	}while(ErrorFlag==1);
}
return 0;
}


