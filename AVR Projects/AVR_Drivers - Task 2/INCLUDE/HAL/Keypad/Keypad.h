/*
 * Keypad.h
 *
 *  Created on: Sep 10, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_H_
#include "../../../SERVICES/std_types.h"
typedef struct{
	u8 DataPortId;
}Keypad_tstrucCfg;
///////////////////////////////////////////

///////////////////////////////////////////
#define Keypad_NotPressed 0xff
#define Keypad_Pressed 0
///////////////////////////////////////////
/*********************Keypad_vidInit********************/
/* USE : Initialize the KeyPad according to user cfg   */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Keypad_vidInit(Keypad_tstrucCfg*Add_strucKeypad);

/***************Keypad_u8GetPressedKey*******************/
/* USE : To get the pressed button in Keypad            */
/* PARAMETERS: The struct carries cfg                   */
/* RETURN: The Character or integer representing the    */
/* Pressed key                                          */
/********************************************************/
u8 Keypad_u8GetPressedKey(Keypad_tstrucCfg*Add_strucKeypad);


#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_H_ */
