/*
 * Lcd.c

 *
 *  Created on: Sep 9, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/HAL/Lcd/Lcd.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"
#include"../../../SERVICES/std_types.h"
#include "util/delay.h"

/********************Lcd_vidEnablePulse*****************/
/* USE : Send Pulse to LCD to enable it                */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_vidEnablePulse(Lcd_tstrucCfg*Add_strucLcd){
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->EN_Pin,DIO_u8_HIGH);
	_delay_ms(2);
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->EN_Pin,DIO_u8_LOW);
}

/********************Lcd_vidSendCommand*****************/
/* USE : Send Command to LCD Processor                 */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Command represented in Binary     */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_vidSendCommand(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_CommandVal){
	//RS
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->RS_Pin,DIO_u8_LOW);
	// Send Command
	DIO_enuSetPortValue(Add_strucLcd->DataPortId,Copy_CommandVal);
	Lcd_vidEnablePulse(Add_strucLcd);
}

/********************Lcd_vidSendData********************/
/* USE : Send Data to LCD                              */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Data Value                        */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_vidSendData(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_DataVal){
	//RS
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->RS_Pin,DIO_u8_HIGH);
	// Send Command
	DIO_enuSetPortValue(Add_strucLcd->DataPortId,Copy_DataVal);
	Lcd_vidEnablePulse(Add_strucLcd);
}


/************************Lcd_vidInit********************/
/* USE : Initialize the LCD according to user cfg      */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_vidInit(Lcd_tstrucCfg*Add_strucLcd){

	DIO_enuSetPinDirection(Add_strucLcd->CtrlPortId,Add_strucLcd->EN_Pin,DIO_u8_OUTPUT);//EN
	DIO_enuSetPinDirection(Add_strucLcd->CtrlPortId,Add_strucLcd->RS_Pin,DIO_u8_OUTPUT);//RS
	DIO_enuSetPinDirection(Add_strucLcd->CtrlPortId,Add_strucLcd->RW_Pin,DIO_u8_OUTPUT);//RW
	DIO_enuSetPinValue(Add_strucLcd->CtrlPortId,Add_strucLcd->RW_Pin,DIO_u8_LOW); // always write
	DIO_enuSetPortDirection(Add_strucLcd->DataPortId,DIO_u8_PORT_OUTPUT);//DataPort Direction
	///////////////////////////////////////////////////////////////////////////////////////////
	_delay_ms(30);
	//set
	Lcd_vidSendCommand(Add_strucLcd,0b00111000);
	_delay_ms(1);
	// Display On / Off
	Lcd_vidSendCommand(Add_strucLcd,0b00001100);
	_delay_ms(1);

	Lcd_vidSendCommand(Add_strucLcd,0b00000001);

}


/***********************Lcd_CLR*************************/
/* USE : Clear The LCD if the user needs               */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_CLR(Lcd_tstrucCfg*Add_strucLcd){
	Lcd_vidSendCommand(Add_strucLcd,0b00000001);
}


/********************Lcd_WriteLetter********************/
/* USE : Write Single Letter on LCD                    */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Data to write                     */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_WriteLetter(Lcd_tstrucCfg*Add_strucLcd,u8*Add_u8LcdLetter){
	Lcd_vidSendData(Add_strucLcd,*Add_u8LcdLetter);
}


/********************Lcd_WriteString********************/
/* USE : Write String on LCD                           */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Pointer points to the address of  */
/*             element of string                       */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_WriteString(Lcd_tstrucCfg*Add_strucLcd,u8*Add_u8LcdString){
	for(u8 StringCounter=0;Add_u8LcdString[StringCounter]!='\0';StringCounter++){
		Lcd_vidSendData(Add_strucLcd,Add_u8LcdString[StringCounter]);
	}
}

/********************Lcd_WriteNumber********************/
/* USE : Write Numbers on LCD                          */
/* PARAMETERS: - The struct carries cfg                */
/*             - The number to be displayed            */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_WriteNumber(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_u8LcdNumber){
	if(Copy_u8LcdNumber<10)
		Lcd_vidSendData(Add_strucLcd,Copy_u8LcdNumber+48);
	else{
		u8 Lcd_LargeNumbers[10];
		u8 count=9;
		do{
			Lcd_LargeNumbers[count--]=Copy_u8LcdNumber%10;
			Copy_u8LcdNumber/=10;

		}while(Copy_u8LcdNumber>1);
		if(Lcd_LargeNumbers[count+1]==0)
			count++;
		for(++count;count<10;count++){
			Lcd_vidSendData(Add_strucLcd,Lcd_LargeNumbers[count]+48);
		}
	}
}

/*******************Lcd_GotoPosition********************/
/* USE : Select Position to write on LCD               */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Line 1 or 2                       */
/*             - The position in the line 0-15         */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_GotoPosition(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_u8Line,u8 Copy_u8Digit){
	switch(Copy_u8Line){
	case LCD_LINE1:Lcd_vidSendCommand(Add_strucLcd,LCD_LINE1_COMMAND+Copy_u8Digit);break;
	case LCD_LINE2:Lcd_vidSendCommand(Add_strucLcd,LCD_LINE2_COMMAND+Copy_u8Digit);break;
	}
}


