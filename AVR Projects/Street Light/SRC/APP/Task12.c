#include "util/delay.h"
#include "../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../INCLUDE/MCAL/ADC/ADC.h"
#include "../../INCLUDE/MCAL/ADC/ADC_priv.h"
#include "../../INCLUDE/MCAL/ADC/ADC_cfg.h"
#include "../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../SERVICES/bit_utilies.h"
#include "../../INCLUDE/HAL/Led/Led.h"
#include "../../INCLUDE/HAL/Lcd/Lcd.h"

/************************************Task 12*********************************/
/* - ADC                                                                    */
/* - LDR + LCD                                                              */
/* - Take The LDR read and display it on LCD , if it's dark turn on light   */
/****************************************************************************/

int main(){
	ADC_voidInit();
	u16 Loc_u16AdcRead=0;
	Lcd_tstrucCfg lcd1={
			.CtrlPortId=DIO_u8_PORTB,
			.DataPortId=DIO_u8_PORTD,
			.EN_Pin=2,
			.RW_Pin=1,
			.RS_Pin=0
	};
	Lcd_vidInit(&lcd1);
	u8 Lcd_string[]="Voltage = ";
	u8 Lcd_string2[]="V";
	Lcd_WriteString(&lcd1,Lcd_string);
	Lcd_GotoPosition(&lcd1,LCD_LINE2,14);
	Lcd_WriteString(&lcd1,Lcd_string2);

	while(1){
	ADC_voidGetRead(&Loc_u16AdcRead);
	Loc_u16AdcRead*=((5.0-(5.0/1023.0))/1023.0);
	Lcd_GotoPosition(&lcd1,LCD_LINE2,12);
	Lcd_WriteNumber(&lcd1,Loc_u16AdcRead);
	if(Loc_u16AdcRead>2){
		for(Ledcounter=0;Ledcounter<8;Ledcounter++)
			Led_vidOn(&Led_sys[Ledcounter]);
	}
	else{
		for(Ledcounter=0;Ledcounter<8;Ledcounter++)
			Led_vidOff(&Led_sys[Ledcounter]);
	}

	_delay_ms(1000);
	}

return 0;
}


