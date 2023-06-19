/*
 * Button.h
 *
 *  Created on: Sep 6, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_HAL_BUTTON_BUTTON_H_
#define INCLUDE_HAL_BUTTON_BUTTON_H_

#include "../../../SERVICES/std_types.h"

typedef struct{
	u8 Pin;
	struct Button_tSecCfg{
		u8 Port : 2 ;
		u8 ButtonRead: 1;
	}Button_NestStruct;
}Button_tstrucCfg;
//////////////////////////////////////////
#define Button_Pressed 0
#define Button_NotPressed 1
//////////////////////////////////////////


/*****************Button_vidButtonInit******************/
/* USE : Initialize the Button according to user cfg   */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/* PULL UP mode                                        */
/*******************************************************/
void Button_vidButtonInit(Button_tstrucCfg*Add_structButton);



/*****************Button_u8ButtonRead********************/
/* USE : Determine whether the Button is Pressed or not */
/* PARAMETERS: The struct carries cfg                   */
/* RETURN: The Button Read                              */
/* The FOR loop solve debouncing problem                */
/********************************************************/
u8 Button_u8ButtonRead(Button_tstrucCfg*Add_structButton);

#endif /* INCLUDE_HAL_BUTTON_BUTTON_H_ */
