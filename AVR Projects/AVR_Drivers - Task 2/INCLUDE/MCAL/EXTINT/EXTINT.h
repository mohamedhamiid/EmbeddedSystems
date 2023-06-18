/*
 * EXTINT.h
 *
 *  Created on: Sep 20, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_MCAL_EXTINT_EXTINT_H_
#define INCLUDE_MCAL_EXTINT_EXTINT_H_
#include "../../../SERVICES/std_types.h"
typedef struct{
	u8 IntNo : 2;
	u8 IntMode : 2;
}EXTINT_structCfg;
///////////////////////
#define EXTINT_INT0 0
#define EXTINT_INT1 1
#define EXTINT_INT2 2
//////////////////////
#define EXTINT_RISING_EDGE 0
#define EXTINT_FALLING_EDGE 1
#define EXTINT_LOGICAL_CHANGE 2
#define EXTINT_LOW_LEVEL 3
//////////////////////

void EXTINT_voidEnable(EXTINT_structCfg*Add_ExtInt);
/**************EXTINT_voidEnable************************/
/* USE : Enable The External Interrupt and configure it*/
/* PARAMETERS:                                         */
/* 1- Object of struct which include configurations:   */
/*    1- External Interrupt Number: 0 1 2              */
/*    2- External Interrupt Mode:                      */
/*   	 determine when Interrupt happened depending   */
/*   	 on action on its pin                          */
/* RETURN: No Return                                   */
/*******************************************************/

void EXTINT_voidDisable();
/**************EXTINT_voidEnable************************/
/* USE : Disable The External Interrupt                */
/* PARAMETERS: No Parameters                           */
/* RETURN: No Return                                   */
/*******************************************************/


#endif /* INCLUDE_MCAL_EXTINT_EXTINT_H_ */
