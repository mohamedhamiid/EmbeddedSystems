/*
 * Lcd.h
 *
 *  Created on: Sep 9, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_HAL_LCD_LCD_H_
#define INCLUDE_HAL_LCD_LCD_H_
#include "../../../SERVICES/std_types.h"
typedef struct {
	u8 DataPortId;
	u8 CtrlPortId;
	u8 RS_Pin;
	u8 RW_Pin;
	u8 EN_Pin;
}Lcd_tstrucCfg;
/////////////////////////////////////
//RS
#define LCD_SEND_COMMAND 0
#define LCD_SEND_DATA 1
//RW
#define LCD_WRITE_DATA 0
#define LCD_READ_DATA 1
//EN
#define LCD_ENABLE 1
#define LCD_DISABLE 0
////////////////////////////////////
#define LCD_LINE1_COMMAND 128
#define LCD_LINE2_COMMAND 128+0x40
////////////////////////////////////
#define LCD_LINE1 0
#define LCD_LINE2 1
////////////////////////////////////


/********************Lcd_vidEnablePulse*****************/
/* USE : Send Pulse to LCD to enable it                */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_vidEnablePulse(Lcd_tstrucCfg*Add_structLcd);


/********************Lcd_vidSendCommand*****************/
/* USE : Send Command to LCD Processor                 */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Command represented in Binary     */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_vidSendCommand(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_CommandVal);

/********************Lcd_vidSendData********************/
/* USE : Send Data to LCD                              */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Data Value                        */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_vidSendData(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_DataVal);

/************************Lcd_vidInit********************/
/* USE : Initialize the LCD according to user cfg      */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_vidInit(Lcd_tstrucCfg*Add_structLcd);

/***********************Lcd_CLR*************************/
/* USE : Clear The LCD if the user needs               */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_CLR(Lcd_tstrucCfg*Add_strucLcd);


/********************Lcd_WriteLetter********************/
/* USE : Write Single Letter on LCD                    */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Data to write                     */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_WriteLetter(Lcd_tstrucCfg*Add_strucLcd,u8*Add_u8LcdLetter);


/********************Lcd_WriteString********************/
/* USE : Write String on LCD                           */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Pointer points to the address of  */
/*             element of string                       */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_WriteString(Lcd_tstrucCfg*Add_strucLcd,u8*Add_u8LcdString);


/********************Lcd_WriteNumber********************/
/* USE : Write Numbers on LCD                          */
/* PARAMETERS: - The struct carries cfg                */
/*             - The number to be displayed            */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_WriteNumber(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_u8LcdNumber);


/*******************Lcd_GotoPosition********************/
/* USE : Select Position to write on LCD               */
/* PARAMETERS: - The struct carries cfg                */
/*             - The Line 1 or 2                       */
/*             - The position in the line 0-15         */
/* RETURN: No Return                                   */
/*******************************************************/
void Lcd_GotoPosition(Lcd_tstrucCfg*Add_strucLcd,u8 Copy_u8Line,u8 Copy_u8Digit);




#endif /* INCLUDE_HAL_LCD_LCD_H_ */
