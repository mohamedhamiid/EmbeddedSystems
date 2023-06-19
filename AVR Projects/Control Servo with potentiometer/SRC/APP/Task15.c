#include "util/delay.h"
#include "../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../INCLUDE/MCAL/ADC/ADC.h"
#include "../../INCLUDE/MCAL/TIMER/TIMER.h"
#include "../../INCLUDE/MCAL/ADC/ADC_priv.h"
#include "../../INCLUDE/MCAL/TIMER/TIMER_priv.h"
#include "../../INCLUDE/MCAL/ADC/ADC_cfg.h"
#include "../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../SERVICES/bit_utilies.h"

/*******************************************Task 15****************************************/
/* - Timer                                                                                */
/* - PWM + POT + Servo                                                                    */
/* - Control the Servo motor with POT. When rotating the POT , the servo rotates the same */
/******************************************************************************************/

int main(){
DIO_enuSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_OUTPUT);

Timer_structTimerCfg timer1={
		.Timer_u8TimerNo =TIMER_NO_TIMER1,
		.Timer_u8TimerForceOutputCompare=TIMER1_FOC_OFF,
		.Timer_u8WaveFormGenerationMode=TIMER1_MODE_PWM_PHASE_CORRECT_SET_TOP_VALUE,
		.Timer_u8ClockSelect=TIMER1_CLOCK_PRESCALLING_8,
		.Timer_u8OcBehaviour=TIMER1_CHANNEL_A_OC1_PWM_CLEAR_OPERATION,
		.Timer1_u8Channel=TIMER1_CHANNEL_A
};
TIMER_voidTimerInit(&timer1);
ADC_voidInit();
u16 Loc_u16AdcRead=0;
TIMER_voidTimer1SetTopValue(&timer1,20000); // The Reciprocal of 20000 us is 50 --> The freq. req. to servo
	while(1){
ADC_voidGetRead(&Loc_u16AdcRead);
TIMER_voidPwmOn(&timer1,(Loc_u16AdcRead*2.346)+100);
	}
	return 0;
}


