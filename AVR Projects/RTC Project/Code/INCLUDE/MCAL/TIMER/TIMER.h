/*
 * TIMER.h
 *
 *  Created on: Oct 1, 2022
 *      Author: mh_sm
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_H_
#define INCLUDE_MCAL_TIMER_TIMER_H_
#include "../../../SERVICES/std_types.h"
extern volatile u8 Loc_u8BigDelayValueCounterMaxValue;
/////////////////////////////////////////////////////
#define TIMER_NO_TIMER0                    0
#define TIMER_NO_TIMER1                    1
#define TIMER_NO_TIMER2                    2

#define TIMER1_CHANNEL_A                   0
#define TIMER1_CHANNEL_B                   1
////////////////////// TIMER 1 \\\\\\\\\\\\\\\\\\\\\\
/////////////////////////////////////////////////////
// FORCE OUTPUT COMPARE ( INSTANT COMPARE )
#define TIMER1_FOC_ON                      1
#define TIMER1_FOC_OFF                     0
#define TIMER1_FOC_CHANNEL_A_ON                       0b0000010000000000
#define TIMER1_FOC_CHANNEL_A_OFF 		              0b0000000000000000
#define TIMER1_FOC_CHANNEL_B_ON                       0b0000100000000000
#define TIMER1_FOC_CHANNEL_B_OFF 		              0b0000000000000000
/////////////////////////////////////////////////////
// WAVE FORM GENERATION MODE
#define TIMER1_MODE_NORMAL                              0b0000000000000000
#define TIMER1_MODE_PWM_PHASE_CORRECT_8_BIT             0b0000000100000000
#define TIMER1_MODE_PWM_PHASE_CORRECT_9_BIT             0b0000001000000000
#define TIMER1_MODE_PWM_PHASE_CORRECT_10_BIT            0b0000001100000000
#define TIMER1_MODE_CTC                                 0b0000000000001000
#define TIMER1_MODE_PWM_FAST_8_BIT                      0b0000000100001000
#define TIMER1_MODE_PWM_FAST_9_BIT                      0b0000001000001000
#define TIMER1_MODE_PWM_FAST_10_BIT                     0b0000001100001000
#define TIMER1_MODE_PWM_PHASE_CORRECT_SET_TOP_VALUE     0b0000001000010000 //ICR1-->WRITE TOP VALUE ON IT
#define TIMER1_MODE_PWM_PHASE_CORRECT_COMPARE_CHANNEL_A 0b0000001100010000 //OCR1A
#define TIMER1_MODE_PWM_CTC_SET_TOP_VALUE               0b0000000000011000 //ICR1
#define TIMER1_MODE_PWM_FAST_SET_TOP_VALUE              0b0000000100011000 //ICR1-->WRITE TOP VALUE ON IT
#define TIMER1_MODE_PWM_FAST_COMPARE_CHANNEL_A          0b0000001100011000 //OCR1A
/////////////////////////////////////////////////////
#define TIMER1_MODE_NORMAL_OPERATION 						0
#define TIMER1_MODE_TOGGLE_OPERATION                        1
#define TIMER1_MODE_CLEAR_OPERATION                         2
#define TIMER1_MODE_SET_OPERATION                           3
/////////////////////////////////////////////////////
// COMPARE MATCH OUTPUT MODE (NO PWM) CHANNEL B
// control the Output Compare  pin (OC1B)behavior
#define TIMER1_CHANNEL_B_OC1_NO_PWM_NORMAL_OPERATION  0b0000000000000000 // OC1B DISCONNECTED (ISR REQUIRED)
#define TIMER1_CHANNEL_B_OC1_NO_PWM_TOGGLE_OPERATION  0b0001000000000000 // OC1B TOGGLE
#define TIMER1_CHANNEL_B_OC1_NO_PWM_CLEAR_OPERATION   0b0010000000000000 // OC1B CLEAR
#define TIMER1_CHANNEL_B_OC1_NO_PWM_SET_OPERATION     0b0011000000000000 // OC1B SET
/////////////////////////////////////////////////////
// COMPARE MATCH OUTPUT MODE (NO PWM) CHANNEL A
// control the Output Compare  pin (OC1A)behavior
#define TIMER1_CHANNEL_A_OC1_NO_PWM_NORMAL_OPERATION  0b0000000000000000 // OC1A DISCONNECTED (ISR REQUIRED)
#define TIMER1_CHANNEL_A_OC1_NO_PWM_TOGGLE_OPERATION  0b0100000000000000 // OC1A TOGGLE
#define TIMER1_CHANNEL_A_OC1_NO_PWM_CLEAR_OPERATION   0b1000000000000000 // OC1A CLEAR
#define TIMER1_CHANNEL_A_OC1_NO_PWM_SET_OPERATION     0b1100000000000000 // OC1A SET
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
// COMPARE MATCH OUTPUT MODE (PWM) CHANNEL B
// control the Output Compare  pin (OC1)behavior
#define TIMER1_CHANNEL_B_OC1_PWM_NORMAL_OPERATION     0b0000000000000000 // OC1 DISCONNECTED (ISR REQUIRED)
#define TIMER1_CHANNEL_B_OC1_PWM_RESERVED             0b0001000000000000 // OC1 RESERVED (DON'T USE)
#define TIMER1_CHANNEL_B_OC1_PWM_CLEAR_OPERATION      0b0010000000000000 // OC1 CLEAR ON COMPARE + SET AT TOP   (INVERTING)
#define TIMER1_CHANNEL_B_OC1_PWM_SET_OPERATION        0b0011000000000000 // OC1 SET ON COMPARE   + CLEAR AT TOP (NON INVETING)
/////////////////////////////////////////////////////
// COMPARE MATCH OUTPUT MODE (PWM) CHANNEL A
// control the Output Compare  pin (OC1)behavior
#define TIMER1_CHANNEL_A_OC1_PWM_NORMAL_OPERATION    0b0000000000000000 // OC1 DISCONNECTED (ISR REQUIRED)
#define TIMER1_CHANNEL_A_OC1_PWM_RESERVED            0b0100000000000000 // OC1 RESERVED (DON'T USE)
#define TIMER1_CHANNEL_A_OC1_PWM_CLEAR_OPERATION     0b1000000000000000 // OC1 CLEAR ON COMPARE + SET AT TOP   (INVERTING)
#define TIMER1_CHANNEL_A_OC1_PWM_SET_OPERATION       0b1100000000000000 // OC1 SET ON COMPARE   + CLEAR AT TOP (NON INVETING)
/////////////////////////////////////////////////////
// CLOCK SELECT
// prescaler
#define TIMER1_CLOCK_NO_CLOCK_SOURCE       0b0000000000000000 // TIMER STOPPED
#define TIMER1_CLOCK_NO_PRESCALLING        0b0000000000000001 // NO PRESCALLING
#define TIMER1_CLOCK_PRESCALLING_8         0b0000000000000010 // PRESCALLING 8
#define TIMER1_CLOCK_PRESCALLING_64        0b0000000000000011 // PRESCALLING 64
#define TIMER1_CLOCK_PRESCALLING_256       0b0000000000000100 // PRESCALLING 256
#define TIMER1_CLOCK_PRESCALLING_1024      0b0000000000000101 // PRESCALLING 1024
/////////////////////////////////////////////////////
// TIMER COUNTER REGISTER
// RESPONSIBLE OF COUNT
// CAN WRITE PRELOAD VALUE ON IT
#define TIMER1_PRELOAD_NO_VALUE            0
#define TIMER1_PRELOAD_VALUE               1
/////////////////////////////////////////////////////
// OUTPUT COMPARE REGISTER
// WRITE VALUE ON IT TO DO RISE FLAG WHEN TIMER REACH
#define TIMER1_COMPARE_NO_VALUE			   0
/////////////////////////////////////////////////////
// TIMER INTERRUPT MASK
#define TIMER1_COMAPARE_MATCH_CHANNEL_A_PIE_INTERRUPT_ON 0b00010000
#define TIMER1_INPUT_CAPTURE_PIE_INTERRUPT_ON            0b00100000
#define TIMER1_COMAPARE_MATCH_CHANNEL_B_PIE_INTERRUPT_ON 0b00001000
#define TIMER1_OVER_FLOW_PIE_INTERRUPT_ON                0b00000100
////////////////////////////////////////////////////
#define TIMER1_INTERRUPT_ON                    1
#define TIMER1_INTERRUPT_OFF                   0
////////////////////////////////////////////////////
#define TIMER1_CLOCK_PRESCALLING_8_RESULT      8
#define TIMER1_CLOCK_PRESCALLING_64_RESULT 	   64
#define TIMER1_CLOCK_PRESCALLING_256_RESULT    256
#define TIMER1_CLOCK_PRESCALLING_1024_RESULT   1024
////////////////////////////////////////////////////
////////////////////// TIMER 0\\\\\\\\\\\\\\\\\\\\\\
/////////////////////////////////////////////////////
// FORCE OUTPUT COMPARE ( INSTANT COMPARE )
#define TIMER0_FOC_ON                      0b10000000
#define TIMER0_FOC_OFF 				       0b00000000
/////////////////////////////////////////////////////
// WAVE FORM GENERATION MODE
#define TIMER0_MODE_NORMAL                 0b00000000
#define TIMER0_MODE_PWM_PHASE_CORRECT      0b00001000
#define TIMER0_MODE_CTC                    0b01000000
#define TIMER0_MODE_PWM_FAST               0b01001000
/////////////////////////////////////////////////////
// COMPARE MATCH OUTPUT MODE (NO PWM)
// control the Output Compare  pin (OC0)behavior
// PORTB PIN3
#define TIMER0_OC0_NO_PWM_NORMAL_OPERATION 0b00000000 // OC0 DISCONNECTED (ISR REQUIRED)
#define TIMER0_OC0_NO_PWM_TOGGLE_OPERATION 0b00010000 // OC0 TOGGLE
#define TIMER0_OC0_NO_PWM_CLEAR_OPERATION  0b00100000 // OC0 CLEAR
#define TIMER0_OC0_NO_PWM_SET_OPERATION    0b00110000 // OC0 SET
/////////////////////////////////////////////////////
// COMPARE MATCH OUTPUT MODE (PWM)
// control the Output Compare  pin (OC0)behavior
// PORTB PIN3
#define TIMER0_OC0_PWM_NORMAL_OPERATION    0b00000000 // OC0 DISCONNECTED (ISR REQUIRED)
#define TIMER0_OC0_PWM_RESERVED_OPERATION  0b00010000 // OC0 RESERVED (DON'T USE)
#define TIMER0_OC0_PWM_CLEAR_OPERATION     0b00100000 // OC0 CLEAR ON COMPARE + SET AT TOP   (INVERTING)
#define TIMER0_OC0_PWM_SET_OPERATION       0b00110000 // OC0 SET ON COMPARE   + CLEAR AT TOP (NON INVETING)
/////////////////////////////////////////////////////
// CLOCK SELECT
// prescaler
#define TIMER0_CLOCK_NO_CLOCK_SOURCE       0b00000000 // TIMER STOPPED
#define TIMER0_CLOCK_NO_PRESCALLING        0b00000001 // NO PRESCALLING
#define TIMER0_CLOCK_PRESCALLING_8         0b00000010 // PRESCALLING 8
#define TIMER0_CLOCK_PRESCALLING_64        0b00000011 // PRESCALLING 64
#define TIMER0_CLOCK_PRESCALLING_256       0b00000100 // PRESCALLING 256
#define TIMER0_CLOCK_PRESCALLING_1024      0b00000101 // PRESCALLING 1024
/////////////////////////////////////////////////////
// TIMER COUNTER REGISTER
// RESPONSIBLE OF COUNT
// CAN WRITE PRELOAD VALUE ON IT
#define TIMER0_PRELOAD_NO_VALUE            0
#define TIMER0_PRELOAD_VALUE               1
/////////////////////////////////////////////////////
// OUTPUT COMPARE REGISTER
// WRITE VALUE ON IT TO DO RISE FLAG WHEN TIMER REACH
#define TIMER0_COMPARE_NO_VALUE			   0
/////////////////////////////////////////////////////
// TIMER INTERRUPT MASK
#define TIMER0_COMAPARE_MATCH_PIE_INTERRUPT_ON 0b00000010
#define TIMER0_OVER_FLOW_PIE_INTERRUPT_ON      0b00000001
////////////////////////////////////////////////////
#define TIMER_INTERRUPT_ON                    1
#define TIMER_INTERRUPT_OFF                   0
////////////////////////////////////////////////////
#define TIMER0_CLOCK_PRESCALLING_8_RESULT      8
#define TIMER0_CLOCK_PRESCALLING_64_RESULT 	   64
#define TIMER0_CLOCK_PRESCALLING_256_RESULT    256
#define TIMER0_CLOCK_PRESCALLING_1024_RESULT   1024
////////////////////////////////////////////////////
////////////////////// TIMER 2\\\\\\\\\\\\\\\\\\\\\\
/////////////////////////////////////////////////////
// FORCE OUTPUT COMPARE ( INSTANT COMPARE )
#define TIMER2_FOC_ON                      0b10000000
#define TIMER2_FOC_OFF 				       0b00000000
/////////////////////////////////////////////////////
// WAVE FORM GENERATION MODE
#define TIMER2_MODE_NORMAL                 0b00000000
#define TIMER2_MODE_PWM_PHASE_CORRECT      0b00001000
#define TIMER2_MODE_CTC                    0b01000000
#define TIMER2_MODE_PWM_FAST               0b01001000
/////////////////////////////////////////////////////
// COMPARE MATCH OUTPUT MODE (NO PWM)
// control the Output Compare pin (OC2) behavior
// PORTB PIN3
#define TIMER2_OC2_NO_PWM_NORMAL_OPERATION 0b00000000 // OC0 DISCONNECTED (ISR REQUIRED)
#define TIMER2_OC2_NO_PWM_TOGGLE_OPERATION 0b00010000 // OC0 TOGGLE
#define TIMER2_OC2_NO_PWM_CLEAR_OPERATION  0b00100000 // OC0 CLEAR
#define TIMER2_OC2_NO_PWM_SET_OPERATION    0b00110000 // OC0 SET
/////////////////////////////////////////////////////
// COMPARE MATCH OUTPUT MODE (PWM)
// control the Output Compare pin (OC2) behavior
// PORTB PIN3
#define TIMER2_OC2_PWM_NORMAL_OPERATION    0b00000000 // OC0 DISCONNECTED (ISR REQUIRED)
#define TIMER2_OC2_PWM_RESERVED_OPERATION  0b00010000 // OC0 RESERVED (DON'T USE)
#define TIMER2_OC2_PWM_CLEAR_OPERATION     0b00100000 // OC0 CLEAR ON COMPARE + SET AT TOP   (INVERTING)
#define TIMER2_OC2_PWM_SET_OPERATION       0b00110000 // OC0 SET ON COMPARE   + CLEAR AT TOP (NON INVETING)
/////////////////////////////////////////////////////
// CLOCK SELECT
#define TIMER2_CLOCK_EXTERNAL              0b00001000
// prescaler
#define TIMER2_CLOCK_NO_CLOCK_SOURCE       0b00000000 // TIMER STOPPED
#define TIMER2_CLOCK_NO_PRESCALLING        0b00000001 // NO PRESCALLING
#define TIMER2_CLOCK_PRESCALLING_8         0b00000010 // PRESCALLING 8
#define TIMER2_CLOCK_PRESCALLING_64        0b00000011 // PRESCALLING 64
#define TIMER2_CLOCK_PRESCALLING_128       0b00000101 // PRESCALLING 64
#define TIMER2_CLOCK_PRESCALLING_256       0b00000100 // PRESCALLING 256
#define TIMER2_CLOCK_PRESCALLING_1024      0b00000101 // PRESCALLING 1024
/////////////////////////////////////////////////////
// TIMER COUNTER REGISTER
// RESPONSIBLE OF COUNT
// CAN WRITE PRELOAD VALUE ON IT
#define TIMER2_PRELOAD_NO_VALUE            0
#define TIMER2_PRELOAD_VALUE               1
/////////////////////////////////////////////////////
// OUTPUT COMPARE REGISTER
// WRITE VALUE ON IT TO DO RISE FLAG WHEN TIMER REACH
#define TIMER2_COMPARE_NO_VALUE			   0
/////////////////////////////////////////////////////
// TIMER INTERRUPT MASK
#define TIMER2_COMAPARE_MATCH_PIE_INTERRUPT_ON 0b00000010
#define TIMER2_OVER_FLOW_PIE_INTERRUPT_ON      0b00000001
////////////////////////////////////////////////////
#define TIMER2_INTERRUPT_ON                    1
#define TIMER2_INTERRUPT_OFF                   0
////////////////////////////////////////////////////
#define TIMER2_CLOCK_PRESCALLING_8_RESULT      8
#define TIMER2_CLOCK_PRESCALLING_64_RESULT 	   64
#define TIMER2_CLOCK_PRESCALLING_256_RESULT    256
#define TIMER2_CLOCK_PRESCALLING_1024_RESULT   1024
////////////////////////////////////////////////////
#define FREQUENCY_CPU                          8

typedef struct{
	u16 Timer_u8TimerNo:2;
	u16 Timer_u8TimerForceOutputCompare;
	u16 Timer_u8WaveFormGenerationMode;
	u16 Timer_u8ClockSelect;
	u16 Timer_u8OcBehaviour;
	u16 Timer1_u8Channel;
	u16 Timer_Interrupt;
	u16  Timer2_ExtClock;

}Timer_structTimerCfg;
////////////////////////////////////////
// DELAY FUNC CFG
#define TIMER_DELAY_UNIT_us 0
#define TIMER_DELAY_UNIT_ms 1
#define TIMER_DELAY_UNIT_s  2

#define TIMER0_TOP_VALUE    256
#define TIMER1_TOP_VALUE    65536
#define TIMER2_TOP_VALUE    256

typedef struct{
	u8 Timer_u8TimerNo:2;
	u8 Timer_u8OcBehaviour;
	u8 Timer_u8Interrupt;
}Timer_structDelayFunc;
///////////////////////////////////////////
#define TIMER_PWM_NON_INVERTING 0
#define TIMER_PWM_INVERTING     1
#define TIMER_PWM_ISR           2
//typedef struct{
//	u8 Timer_u8TimerNo:2;
//	u8 Timer_u8OcBehaviour:2;
//	u8 Timer1_u8Channel:2;
//}Timer_structPwmFunc;
//////////////////////////////////////////
void TIMER_voidTimerInit(Timer_structTimerCfg*Add_structTimerCfg);
/****************TIMER_voidTimerInit**********************/
/* USE : Initialize Timer with Configurations in the     */
/* struct also determine which timer to use              */
/* PARAMETERS:                                           */
/* 1- Struct carries configurations                      */
/* RETURN: No Return                                     */
/*********************************************************/
//void TIMER_voidDelay(Timer_structDelayFunc*Add_structDelayFunc,f32 Copy_u16DelayValue);

void TIMER_voidTimer1SetTopValue(Timer_structTimerCfg*Add_structTimerCfg,u16 Copy_u8Timer1TopValue);
/**************TIMER_voidTimer1SetTopValue****************/
/* USE : Set [timer 1] top Value                         */
/* PARAMETERS:                                           */
/* 1- Copy of Top Value                                  */
/* RETURN: No Return                                     */
/*********************************************************/
void TIMER_voidPwmOn(Timer_structTimerCfg*Add_structTimerCfg,u16 Copy_u8DuttyValue);
/******************TIMER_voidPwmOn************************/
/* USE : Turn on Pulse Width Modulation                  */
/* PARAMETERS:                                           */
/* 1- Struct carries configurations                      */
/* 2- Dutty Value                                        */
/* RETURN: No Return                                     */
/*********************************************************/
void TIMER_voidCTCcfg (Timer_structTimerCfg*Add_structTimerCfg,u16 Copy_u16OcrVal);
void TIMER_voidTimerOn(Timer_structTimerCfg*Add_structTimerCfg);
void TIMER_voidTimerOff(Timer_structTimerCfg*Add_structTimerCfg);
#endif /* INCLUDE_MCAL_TIMER_TIMER_H_ */
