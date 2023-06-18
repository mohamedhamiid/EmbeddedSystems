/*
 * Led.h
 *
 *  Created on: Sep 4, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_HAL_LED_LED_H_
#define INCLUDE_HAL_LED_LED_H_

#include "../../../SERVICES/std_types.h"

typedef struct {
	u8 Pin;
	struct Led_tSecCfg{
		u8 Port : 2 ;
		u8 Active_Status : 1 ;
		u8 Current_Status : 1 ;
	}Led_NestStruct;
}Led_tCfg;
///////////////////////////////////////////////////////////////////
#define Led_Active_High 1
#define Led_Active_Low 0

#define Led_Active_High_High 1
#define Led_Active_High_Low 0


#define Led_Active_Low_High 0
#define Led_Active_Low_Low 1
/////////////////////////////////////////////////////////


/*********************Led_vidLedInit********************/
/* USE : Initialize the Led according to user cfg      */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Led_vidLedInit(Led_tCfg*Add_structLed);

/***********************Led_vidOn***********************/
/* USE : Turn on Led                                   */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Led_vidOn(Led_tCfg*Add_structLed);

/***********************Led_vidOff**********************/
/* USE : Turn off Led                                  */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Led_vidOff(Led_tCfg*Add_structLed);

/*******************Led_vidToggle***********************/
/* USE : Toggle Led                                    */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Led_vidToggle(Led_tCfg*Add_structLed);


/////////////////////////////////////////////////////////

#endif /* INCLUDE_HAL_LED_LED_H_ */
