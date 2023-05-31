/*
 * ADC.h
 *
 *  Created on: Sep 24, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_MCAL_ADC_ADC_H_
#define INCLUDE_MCAL_ADC_ADC_H_
#include "../../../SERVICES/std_types.h"
// PROPERTIES
#define ADC_VREF_AREF             0
#define ADC_VREF_RESERVED         1
#define ADC_VREF_AVCC_2V          2
#define ADC_VREF_AVCC_5V          3
/////////////////////////////////////
#define ADC_ADJUSTMENT_RIGHT      0
#define ADC_ADJUSTMENT_LEFT       1
/////////////////////////////////////
#define ADC_PRESCALER_2           0
#define ADC_PRESCALER_4           1
#define ADC_PRESCALER_8           2
#define ADC_PRESCALER_16          3
#define ADC_PRESCALER_32          4
#define ADC_PRESCALER_64          5
#define ADC_PRESCALER_128         6
/////////////////////////////////////
#define ADC_ANALOG_CHANNEL_PIN0   0
#define ADC_ANALOG_CHANNEL_PIN1   1
#define ADC_ANALOG_CHANNEL_PIN2   2
#define ADC_ANALOG_CHANNEL_PIN3   3
#define ADC_ANALOG_CHANNEL_PIN4   4
#define ADC_ANALOG_CHANNEL_PIN5   5
#define ADC_ANALOG_CHANNEL_PIN6   6
#define ADC_ANALOG_CHANNEL_PIN7   7
/////////////////////////////////////
#define ADC_ENABLE_ADCSRA_ADEN    7
/////////////////////////////////////


//REGISTERS SLOTS
//////////////////////


// VREF PINS SETUP
#define ADC_VREF_ADMUX_REFS0 6
#define ADC_VREF_ADMUX_REFS1 7
// 00 --> AREF
// 01 --> 5V INTERNAL
// 10 --> RESERVED
// 11 --> 2.56V

///////////////////////

// ADC ADJUSTMENT
#define ADC_ADJUSTMENT_ADMUX_ADLAR 5
// 0  --> RIGHT
// 1  --> LEFT

///////////////////////

//ADC PRESCALER
#define ADC_PRESCALER_ADCSRA_ADPS0 0
#define ADC_PRESCALER_ADCSRA_ADPS1 1
#define ADC_PRESCALER_ADCSRA_ADPS2 2
// 000 --> 2
// 001 --> 2
// 010 --> 4
// 011 --> 8
// 100 --> 16
// 101 --> 32
// 110 --> 64
// 111 --> 128

/////////////////////////

// ADC ANALOG CHANNEL
#define ADC_ANALOG_CHANNEL_ADMUX0  0
#define ADC_ANALOG_CHANNEL_ADMUX1  1
#define ADC_ANALOG_CHANNEL_ADMUX2  2
#define ADC_ANALOG_CHANNEL_ADMUX3  3
#define ADC_ANALOG_CHANNEL_ADMUX4  4

//////////////////////////
	// CONVERSION
#define ADC_START_CONVERSION       6
#define ADC_CONVERSION_IN_PROGRESS 1
/////////////////////////
#define ADC_TimeOut 0

void ADC_voidInit();
/********************ADC_voidInit*************************/
/* USE : Configure ADC according to cfg file             */
/* PARAMETERS: No Parameters                             */
/* RETURN: No Return Types                               */
/*********************************************************/
void ADC_voidGetRead(u16*Add_u16AdcRead);
/*******************ADC_voidGetRead***********************/
/* USE : Get Value read from ADC pin                     */
/* PARAMETERS: Address of variable to put value in it    */
/* RETURN: No Return Types                               */
/*********************************************************/
void ADC_voidDisable();
/*****************ADC_voidDisable*************************/
/* USE : Disable ADC                                     */
/* PARAMETERS: No Parameters                             */
/* RETURN: No Return                                     */
/*********************************************************/

#endif /* INCLUDE_MCAL_ADC_ADC_H_ */
