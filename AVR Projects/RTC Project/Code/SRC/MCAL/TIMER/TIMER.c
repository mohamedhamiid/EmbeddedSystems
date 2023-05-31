/*
 * TIMER.c
 *
 *  Created on: Oct 1, 2022
 *      Author: mh_sm
 */
#include "../../../INCLUDE/MCAL/TIMER/TIMER.h"
#include "../../../INCLUDE/MCAL/TIMER/TIMER_priv.h"
#include "../../../SERVICES/bit_utilies.h"
#include "../../../SERVICES/std_types.h"
#include "../../../INCLUDE/MCAL/GIE/GIE.h"
volatile u16 Global_u16TimerClockPrescalerValue=0;
volatile f32 Global_u8TickTimeValue=0;
volatile f32 Global_u16PeriodicTimeValue=0;
volatile u16 Global_u8WaveFormGenerationMode;
volatile u8 Loc_u8BigDelayValueCounterMaxValue;

void TIMER_voidTimerInit(Timer_structTimerCfg*Add_structTimerCfg){
	switch(Add_structTimerCfg->Timer_u8TimerNo){
	case TIMER_NO_TIMER0:

		switch(Add_structTimerCfg->Timer_u8TimerForceOutputCompare){
		case TIMER0_FOC_ON:TCCR0|=TIMER0_FOC_ON;break;
		case TIMER0_FOC_OFF:TCCR0|=TIMER0_FOC_OFF;break;
		}

		switch(Add_structTimerCfg->Timer_u8WaveFormGenerationMode){
		case TIMER0_MODE_NORMAL:			TCCR0|=TIMER0_MODE_NORMAL;Global_u8WaveFormGenerationMode=TIMER0_MODE_NORMAL;break;
		case TIMER0_MODE_CTC:				TCCR0|=TIMER0_MODE_CTC;Global_u8WaveFormGenerationMode=TIMER0_MODE_CTC;break;
		case TIMER0_MODE_PWM_FAST:			TCCR0|=TIMER0_MODE_PWM_FAST;Global_u8WaveFormGenerationMode=TIMER0_MODE_PWM_FAST;break;
		case TIMER0_MODE_PWM_PHASE_CORRECT: TCCR0|=TIMER0_MODE_PWM_PHASE_CORRECT;Global_u8WaveFormGenerationMode=TIMER0_MODE_PWM_PHASE_CORRECT;break;
		}

		switch(Add_structTimerCfg->Timer_u8OcBehaviour){
		case TIMER0_OC0_NO_PWM_NORMAL_OPERATION:TCCR0|=TIMER0_OC0_NO_PWM_NORMAL_OPERATION;break;
		case TIMER0_OC0_NO_PWM_TOGGLE_OPERATION:TCCR0|=TIMER0_OC0_NO_PWM_TOGGLE_OPERATION;break;
		case TIMER0_OC0_NO_PWM_CLEAR_OPERATION: TCCR0|=TIMER0_OC0_NO_PWM_CLEAR_OPERATION;break;
		case TIMER0_OC0_NO_PWM_SET_OPERATION:   TCCR0|=TIMER0_OC0_NO_PWM_SET_OPERATION;break;
		}


		switch(Add_structTimerCfg->Timer_u8ClockSelect){
		case TIMER0_CLOCK_NO_CLOCK_SOURCE : TCCR0|=TIMER0_CLOCK_NO_CLOCK_SOURCE ; break;
		case TIMER0_CLOCK_NO_PRESCALLING  : TCCR0|=TIMER0_CLOCK_NO_PRESCALLING  ; break;
		case TIMER0_CLOCK_PRESCALLING_8   : TCCR0|=TIMER0_CLOCK_PRESCALLING_8;Global_u16TimerClockPrescalerValue=8; break;
		case TIMER0_CLOCK_PRESCALLING_64  : TCCR0|=TIMER0_CLOCK_PRESCALLING_64;Global_u16TimerClockPrescalerValue=64; break;
		case TIMER0_CLOCK_PRESCALLING_256 : TCCR0|=TIMER0_CLOCK_PRESCALLING_256;Global_u16TimerClockPrescalerValue=128;break;
		case TIMER0_CLOCK_PRESCALLING_1024: TCCR0|=TIMER0_CLOCK_PRESCALLING_1024;Global_u16TimerClockPrescalerValue=1024;break;
		}
	break;
	case TIMER_NO_TIMER1:

		switch(Add_structTimerCfg->Timer_u8TimerForceOutputCompare){
		case TIMER1_FOC_ON:
			switch(Add_structTimerCfg->Timer1_u8Channel){
				case TIMER1_CHANNEL_A: TCCR1|=TIMER1_FOC_CHANNEL_A_ON;break;
				case TIMER1_CHANNEL_B: TCCR1|=TIMER1_FOC_CHANNEL_B_ON;break;
			}
		break;
		case TIMER1_FOC_OFF:
			switch(Add_structTimerCfg->Timer1_u8Channel){
				case TIMER1_CHANNEL_A: TCCR1|=TIMER1_FOC_CHANNEL_A_OFF;break;
				case TIMER1_CHANNEL_B: TCCR1|=TIMER1_FOC_CHANNEL_B_OFF;break;
			}
		break;
		}

		switch(Add_structTimerCfg->Timer_u8WaveFormGenerationMode){
		case TIMER1_MODE_NORMAL                              :TCCR1|=TIMER1_MODE_NORMAL                              ;Global_u8WaveFormGenerationMode=TIMER1_MODE_NORMAL                             ;break;
		case TIMER1_MODE_PWM_PHASE_CORRECT_8_BIT             :TCCR1|=TIMER1_MODE_PWM_PHASE_CORRECT_8_BIT             ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_PHASE_CORRECT_8_BIT            ;break;
		case TIMER1_MODE_PWM_PHASE_CORRECT_9_BIT             :TCCR1|=TIMER1_MODE_PWM_PHASE_CORRECT_9_BIT             ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_PHASE_CORRECT_9_BIT            ;break;
		case TIMER1_MODE_PWM_PHASE_CORRECT_10_BIT            :TCCR1|=TIMER1_MODE_PWM_PHASE_CORRECT_10_BIT           ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_PHASE_CORRECT_10_BIT           ;break;
		case TIMER1_MODE_CTC                                 :TCCR1|=TIMER1_MODE_CTC                                ;Global_u8WaveFormGenerationMode=TIMER1_MODE_CTC                                ;break;
		case TIMER1_MODE_PWM_FAST_8_BIT                      :TCCR1|=TIMER1_MODE_PWM_FAST_8_BIT                     ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_FAST_8_BIT                     ;break;
		case TIMER1_MODE_PWM_FAST_9_BIT                      :TCCR1|=TIMER1_MODE_PWM_FAST_9_BIT                     ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_FAST_9_BIT                     ;break;
		case TIMER1_MODE_PWM_FAST_10_BIT                     :TCCR1|=TIMER1_MODE_PWM_FAST_10_BIT                    ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_FAST_10_BIT                    ;break;
		case TIMER1_MODE_PWM_PHASE_CORRECT_SET_TOP_VALUE     :TCCR1|=TIMER1_MODE_PWM_PHASE_CORRECT_SET_TOP_VALUE    ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_PHASE_CORRECT_SET_TOP_VALUE    ;break;
		case TIMER1_MODE_PWM_PHASE_CORRECT_COMPARE_CHANNEL_A :TCCR1|=TIMER1_MODE_PWM_PHASE_CORRECT_COMPARE_CHANNEL_A;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_PHASE_CORRECT_COMPARE_CHANNEL_A;break;
		case TIMER1_MODE_PWM_CTC_SET_TOP_VALUE               :TCCR1|=TIMER1_MODE_PWM_CTC_SET_TOP_VALUE              ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_CTC_SET_TOP_VALUE              ;break;
		case TIMER1_MODE_PWM_FAST_SET_TOP_VALUE              :TCCR1|=TIMER1_MODE_PWM_FAST_SET_TOP_VALUE             ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_FAST_SET_TOP_VALUE             ;break;
		case TIMER1_MODE_PWM_FAST_COMPARE_CHANNEL_A          :TCCR1|=TIMER1_MODE_PWM_FAST_COMPARE_CHANNEL_A         ;Global_u8WaveFormGenerationMode=TIMER1_MODE_PWM_FAST_COMPARE_CHANNEL_A         ;break;

		}

		switch(Add_structTimerCfg->Timer_u8OcBehaviour){
		case TIMER1_CHANNEL_B_OC1_NO_PWM_NORMAL_OPERATION: TCCR1|=TIMER1_CHANNEL_B_OC1_NO_PWM_NORMAL_OPERATION;break;
		case TIMER1_CHANNEL_B_OC1_NO_PWM_TOGGLE_OPERATION: TCCR1|=TIMER1_CHANNEL_B_OC1_NO_PWM_TOGGLE_OPERATION;break;
		case TIMER1_CHANNEL_B_OC1_NO_PWM_CLEAR_OPERATION : TCCR1|=TIMER1_CHANNEL_B_OC1_NO_PWM_CLEAR_OPERATION ;break;
		case TIMER1_CHANNEL_B_OC1_NO_PWM_SET_OPERATION   : TCCR1|=TIMER1_CHANNEL_B_OC1_NO_PWM_SET_OPERATION   ;break;

//		case TIMER1_CHANNEL_A_OC1_NO_PWM_NORMAL_OPERATION: TCCR0|=TIMER1_CHANNEL_A_OC1_NO_PWM_NORMAL_OPERATION;break;
		case TIMER1_CHANNEL_A_OC1_NO_PWM_TOGGLE_OPERATION: TCCR1|=TIMER1_CHANNEL_A_OC1_NO_PWM_TOGGLE_OPERATION;break;
		case TIMER1_CHANNEL_A_OC1_NO_PWM_CLEAR_OPERATION : TCCR1|=TIMER1_CHANNEL_A_OC1_NO_PWM_CLEAR_OPERATION ;break;
		case TIMER1_CHANNEL_A_OC1_NO_PWM_SET_OPERATION   : TCCR1|=TIMER1_CHANNEL_A_OC1_NO_PWM_SET_OPERATION   ;break;
		}


		switch(Add_structTimerCfg->Timer_u8ClockSelect){
		case TIMER1_CLOCK_NO_CLOCK_SOURCE : TCCR1|=TIMER1_CLOCK_NO_CLOCK_SOURCE ;break;
		case TIMER1_CLOCK_NO_PRESCALLING  : TCCR1|=TIMER1_CLOCK_NO_PRESCALLING  ;break;
		case TIMER1_CLOCK_PRESCALLING_8   : TCCR1|=TIMER1_CLOCK_PRESCALLING_8   ;break;
		case TIMER1_CLOCK_PRESCALLING_64  : TCCR1|=TIMER1_CLOCK_PRESCALLING_64  ;break;
		case TIMER1_CLOCK_PRESCALLING_256 : TCCR1|=TIMER1_CLOCK_PRESCALLING_256 ;break;
		case TIMER1_CLOCK_PRESCALLING_1024: TCCR1|=TIMER1_CLOCK_PRESCALLING_1024;break;
		}
	break;
	case TIMER_NO_TIMER2:

		switch(Add_structTimerCfg->Timer_u8TimerForceOutputCompare){
		case TIMER2_FOC_ON:TCCR2|=TIMER2_FOC_ON;break;
		case TIMER2_FOC_OFF:TCCR2|=TIMER2_FOC_OFF;break;
		}

		switch(Add_structTimerCfg->Timer_u8WaveFormGenerationMode){
		case TIMER2_MODE_NORMAL:			TCCR2|=TIMER2_MODE_NORMAL;Global_u8WaveFormGenerationMode=TIMER2_MODE_NORMAL;break;
		case TIMER2_MODE_CTC:				TCCR2|=TIMER2_MODE_CTC;Global_u8WaveFormGenerationMode=TIMER2_MODE_CTC;break;
		case TIMER2_MODE_PWM_FAST:			TCCR2|=TIMER2_MODE_PWM_FAST;Global_u8WaveFormGenerationMode=TIMER2_MODE_PWM_FAST;break;
		case TIMER2_MODE_PWM_PHASE_CORRECT: TCCR2|=TIMER2_MODE_PWM_PHASE_CORRECT;Global_u8WaveFormGenerationMode=TIMER2_MODE_PWM_PHASE_CORRECT;break;
		}

		switch(Add_structTimerCfg->Timer_u8OcBehaviour){
		case TIMER2_OC2_NO_PWM_NORMAL_OPERATION:TCCR2|=TIMER2_OC2_NO_PWM_NORMAL_OPERATION;break;
		case TIMER2_OC2_NO_PWM_TOGGLE_OPERATION:TCCR2|=TIMER2_OC2_NO_PWM_TOGGLE_OPERATION;break;
		case TIMER2_OC2_NO_PWM_CLEAR_OPERATION: TCCR2|=TIMER2_OC2_NO_PWM_CLEAR_OPERATION;break;
		case TIMER2_OC2_NO_PWM_SET_OPERATION:   TCCR2|=TIMER2_OC2_NO_PWM_SET_OPERATION;break;
		}

		switch(Add_structTimerCfg->Timer2_ExtClock){
		case TIMER2_CLOCK_EXTERNAL : ASSR |= TIMER2_CLOCK_EXTERNAL ; break;
		}
		switch(Add_structTimerCfg->Timer_u8ClockSelect){
		// External ClocK

		// Internal Clock
		case TIMER2_CLOCK_NO_CLOCK_SOURCE : TCCR2|=TIMER2_CLOCK_NO_CLOCK_SOURCE ; break;
		case TIMER2_CLOCK_NO_PRESCALLING  : TCCR2|=TIMER2_CLOCK_NO_PRESCALLING  ; break;
		case TIMER2_CLOCK_PRESCALLING_8   : TCCR2|=TIMER2_CLOCK_PRESCALLING_8;Global_u16TimerClockPrescalerValue=8; break;
		case TIMER2_CLOCK_PRESCALLING_64  : TCCR2|=TIMER2_CLOCK_PRESCALLING_64;Global_u16TimerClockPrescalerValue=64; break;
		case TIMER2_CLOCK_PRESCALLING_256 : TCCR2|=TIMER2_CLOCK_PRESCALLING_256;Global_u16TimerClockPrescalerValue=128;break;
		case TIMER2_CLOCK_PRESCALLING_1024: TCCR2|=TIMER2_CLOCK_PRESCALLING_1024;Global_u16TimerClockPrescalerValue=1024;break;
		}
	}
		switch(Add_structTimerCfg->Timer_Interrupt){

		case TIMER_INTERRUPT_ON:
		switch(Add_structTimerCfg->Timer_u8TimerNo){
		case TIMER_NO_TIMER0:
		switch(Add_structTimerCfg->Timer_u8WaveFormGenerationMode){
			case TIMER0_MODE_NORMAL : TIMSK|=TIMER0_OVER_FLOW_PIE_INTERRUPT_ON; break;
			case TIMER0_MODE_CTC    : TIMSK|=TIMER0_COMAPARE_MATCH_PIE_INTERRUPT_ON; break;
		}
		break;
		case TIMER_NO_TIMER1:
		switch(Add_structTimerCfg->Timer_u8WaveFormGenerationMode){
			case TIMER1_MODE_NORMAL : TIMSK|=TIMER1_OVER_FLOW_PIE_INTERRUPT_ON; break;
			case TIMER1_MODE_CTC    :
				switch(Add_structTimerCfg->Timer1_u8Channel){
				case TIMER1_CHANNEL_A: TIMSK|=TIMER1_COMAPARE_MATCH_CHANNEL_A_PIE_INTERRUPT_ON; break;
				}break;
		}
		break;
		case TIMER_NO_TIMER2:
		switch(Add_structTimerCfg->Timer_u8WaveFormGenerationMode){
			case TIMER2_MODE_NORMAL : TIMSK|=TIMER2_OVER_FLOW_PIE_INTERRUPT_ON; break;
			case TIMER2_MODE_CTC    : TIMSK|=TIMER2_COMAPARE_MATCH_PIE_INTERRUPT_ON; break;
		}
		break;

		}
		break;
}
}
//void TIMER_voidDelay(Timer_structDelayFunc*Add_structDelayFunc,f32 Copy_f32DelayValue){
//	//Copy_u16DelayValue*=1000000;
//	Global_u8TickTimeValue=Global_u16TimerClockPrescalerValue/FREQUENCY_CPU;
//	Global_u16PeriodicTimeValue=Global_u8TickTimeValue*TIMER0_TOP_VALUE;
//
//	switch(Add_structDelayFunc->Timer_u8Interrupt){
//	case TIMER0_INTERRUPT_ON:
//		GIE_voidGlobalInterruptEnable();
//		TIMSK|=TIMER0_COMAPARE_MATCH_PIE_INTERRUPT_ON;
//		TIMSK|=TIMER0_OVER_FLOW_PIE_INTERRUPT_ON;
//		break;
//	case TIMER0_INTERRUPT_OFF:
//		GIE_voidGlobalInterruptDisable();
//		break;
//	}
//
//
//
//	switch(Add_structDelayFunc->Timer_u8TimerNo){
//
//	case TIMER_NO_TIMER0:
//
//		switch(Global_u8WaveFormGenerationMode){
//
//		case TIMER0_MODE_NORMAL:
//
//			TCNT0=0;
//			if(Copy_f32DelayValue>=Global_u8TickTimeValue && Copy_f32DelayValue<=Global_u16PeriodicTimeValue){
//				Loc_u8BigDelayValueCounterMaxValue=1;
//				TCNT0=TIMER0_TOP_VALUE-(Copy_f32DelayValue/Global_u16PeriodicTimeValue*TIMER0_TOP_VALUE);
//
//			}
//
//			else if(Copy_f32DelayValue>Global_u16PeriodicTimeValue){
//				if((u16)Copy_f32DelayValue%TIMER0_TOP_VALUE==0){
//						Loc_u8BigDelayValueCounterMaxValue=Copy_f32DelayValue/TIMER0_TOP_VALUE;
//						TCNT0=0;
//				}
//				else{
//						Loc_u8BigDelayValueCounterMaxValue=(Copy_f32DelayValue/TIMER0_TOP_VALUE)+1;
//						TCNT0=(Copy_f32DelayValue/TIMER0_TOP_VALUE)-((Copy_f32DelayValue/TIMER0_TOP_VALUE)*(float)TIMER0_TOP_VALUE)+0.5;
//				}
////				TCCR0|=Add_structDelayFunc->Timer_u8OcBehaviour;
//			}
//		}
//		 break;
//	}
//}
void TIMER_voidPwmOn(Timer_structTimerCfg*Add_structTimerCfg,u16 Copy_u8DuttyValue){
switch(Add_structTimerCfg->Timer_u8TimerNo){
case TIMER_NO_TIMER0: OCR0 = Copy_u8DuttyValue;break;
//	switch(Add_structTimerCfg->Timer_u8OcBehaviour){
//	case TIMER0_OC0_PWM_SET_OPERATION:OCR0 = (TIMER0_TOP_VALUE-Copy_u8DuttyValue)*TIMER0_TOP_VALUE/100.0;break;
//	case TIMER0_OC0_PWM_CLEAR_OPERATION:OCR0 = Copy_u8DuttyValue*TIMER0_TOP_VALUE/100.0;break;
//break;
case TIMER_NO_TIMER1:
	switch(Add_structTimerCfg->Timer_u8OcBehaviour){
	case TIMER1_CHANNEL_B_OC1_PWM_SET_OPERATION:OCR1B=Copy_u8DuttyValue;break;
	case TIMER1_CHANNEL_B_OC1_PWM_CLEAR_OPERATION:OCR1B=Copy_u8DuttyValue;break;
	case TIMER1_CHANNEL_A_OC1_PWM_SET_OPERATION:OCR1A=Copy_u8DuttyValue;break;
	case TIMER1_CHANNEL_A_OC1_PWM_CLEAR_OPERATION:OCR1A=Copy_u8DuttyValue;break;
//	case TIMER1_CHANNEL_B_OC1_PWM_SET_OPERATION:OCR1B=(TIMER1_TOP_VALUE-Copy_u8DuttyValue)*TIMER1_TOP_VALUE/100.0;break;
//	case TIMER1_CHANNEL_B_OC1_PWM_CLEAR_OPERATION:OCR1B=Copy_u8DuttyValue*TIMER1_TOP_VALUE/100.0;break;
//	case TIMER1_CHANNEL_A_OC1_PWM_SET_OPERATION:OCR1A=(TIMER1_TOP_VALUE-Copy_u8DuttyValue)*TIMER1_TOP_VALUE/100.0;break;
//	case TIMER1_CHANNEL_A_OC1_PWM_CLEAR_OPERATION:OCR1A=Copy_u8DuttyValue*TIMER1_TOP_VALUE/100.0;break;
	}
break;
}
}
void TIMER_voidTimer1SetTopValue(Timer_structTimerCfg*Add_structTimerCfg,u16 Copy_u8Timer1TopValue){
	if (Add_structTimerCfg->Timer_u8TimerNo == TIMER_NO_TIMER1)
		ICR1=Copy_u8Timer1TopValue;
}

void TIMER_voidCTCcfg (Timer_structTimerCfg*Add_structTimerCfg,u16 Copy_u16OcrVal){
	switch(Add_structTimerCfg->Timer_u8TimerNo){
	case TIMER_NO_TIMER0 : OCR0 = Copy_u16OcrVal;break;
	case TIMER_NO_TIMER1 : switch (Add_structTimerCfg->Timer1_u8Channel){
							case TIMER1_CHANNEL_A:
							OCR1A = Copy_u16OcrVal;break;
							case TIMER1_CHANNEL_B:
							OCR1B = Copy_u16OcrVal;break;
							}break;
	case TIMER_NO_TIMER2 : OCR2 = Copy_u16OcrVal;break;
	}
}

void TIMER_voidTimerOff(Timer_structTimerCfg*Add_structTimerCfg){
	switch(Add_structTimerCfg->Timer_u8TimerNo){
	case TIMER_NO_TIMER0 : TCCR0&=0b11111000;break;
	case TIMER_NO_TIMER1 : TCCR1&=0b1111111111111000;break;
	case TIMER_NO_TIMER2 : TCCR2&=0b11111000;break;
	}
}

void TIMER_voidTimerOn(Timer_structTimerCfg*Add_structTimerCfg){
	switch(Add_structTimerCfg->Timer_u8TimerNo){

	case TIMER_NO_TIMER0 :
	switch(Add_structTimerCfg->Timer_u8ClockSelect){
	case TIMER0_CLOCK_NO_CLOCK_SOURCE : TCCR0|=TIMER0_CLOCK_NO_CLOCK_SOURCE ; break;
	case TIMER0_CLOCK_NO_PRESCALLING  : TCCR0|=TIMER0_CLOCK_NO_PRESCALLING  ; break;
	case TIMER0_CLOCK_PRESCALLING_8   : TCCR0|=TIMER0_CLOCK_PRESCALLING_8;Global_u16TimerClockPrescalerValue=8; break;
	case TIMER0_CLOCK_PRESCALLING_64  : TCCR0|=TIMER0_CLOCK_PRESCALLING_64;Global_u16TimerClockPrescalerValue=64; break;
	case TIMER0_CLOCK_PRESCALLING_256 : TCCR0|=TIMER0_CLOCK_PRESCALLING_256;Global_u16TimerClockPrescalerValue=128;break;
	case TIMER0_CLOCK_PRESCALLING_1024: TCCR0|=TIMER0_CLOCK_PRESCALLING_1024;Global_u16TimerClockPrescalerValue=1024;break;
	};break;

	case TIMER_NO_TIMER1 :
	switch(Add_structTimerCfg->Timer_u8ClockSelect){
	case TIMER1_CLOCK_NO_CLOCK_SOURCE : TCCR1|=TIMER1_CLOCK_NO_CLOCK_SOURCE ;break;
	case TIMER1_CLOCK_NO_PRESCALLING  : TCCR1|=TIMER1_CLOCK_NO_PRESCALLING  ;break;
	case TIMER1_CLOCK_PRESCALLING_8   : TCCR1|=TIMER1_CLOCK_PRESCALLING_8   ;break;
	case TIMER1_CLOCK_PRESCALLING_64  : TCCR1|=TIMER1_CLOCK_PRESCALLING_64  ;break;
	case TIMER1_CLOCK_PRESCALLING_256 : TCCR1|=TIMER1_CLOCK_PRESCALLING_256 ;break;
	case TIMER1_CLOCK_PRESCALLING_1024: TCCR1|=TIMER1_CLOCK_PRESCALLING_1024;break;
	};break;

	case TIMER_NO_TIMER2 :
	switch(Add_structTimerCfg->Timer_u8ClockSelect){
	case TIMER2_CLOCK_NO_CLOCK_SOURCE : TCCR2|=TIMER2_CLOCK_NO_CLOCK_SOURCE ; break;
	case TIMER2_CLOCK_NO_PRESCALLING  : TCCR2|=TIMER2_CLOCK_NO_PRESCALLING  ; break;
	case TIMER2_CLOCK_PRESCALLING_8   : TCCR2|=TIMER2_CLOCK_PRESCALLING_8;Global_u16TimerClockPrescalerValue=8; break;
	case TIMER2_CLOCK_PRESCALLING_64  : TCCR2|=TIMER2_CLOCK_PRESCALLING_64;Global_u16TimerClockPrescalerValue=64; break;
	case TIMER2_CLOCK_PRESCALLING_256 : TCCR2|=TIMER2_CLOCK_PRESCALLING_256;Global_u16TimerClockPrescalerValue=128;break;
	case TIMER2_CLOCK_PRESCALLING_1024: TCCR2|=TIMER2_CLOCK_PRESCALLING_1024;Global_u16TimerClockPrescalerValue=1024;break;
	};break;

	}
}






