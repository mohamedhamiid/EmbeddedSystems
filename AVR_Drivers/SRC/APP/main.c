#include "util/delay.h"
#include "../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../INCLUDE/MCAL/ADC/ADC.h"
#include "../../INCLUDE/MCAL/TIMER/TIMER.h"
#include "../../INCLUDE/MCAL/UART/UART.h"
#include "../../INCLUDE/MCAL/ADC/ADC_priv.h"
#include "../../INCLUDE/MCAL/UART/UART_priv.h"
#include "../../INCLUDE/MCAL/TIMER/TIMER_priv.h"
#include "../../INCLUDE/MCAL/ADC/ADC_cfg.h"
#include "../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../SERVICES/bit_utilies.h"
#include "../../INCLUDE/HAL/Led/Led.h"
#include "../../INCLUDE/HAL/seg_7/seg_7.h"
#include "../../INCLUDE/HAL/Button/Button.h"
#include "../../INCLUDE/HAL/Lcd/Lcd.h"
#include "../../INCLUDE/HAL/Keypad/Keypad.h"
#include "../../INCLUDE/MCAL/EXTINT/EXTINT.h"
#include "../../INCLUDE/MCAL/GIE/GIE.h"
#include "../../INCLUDE/HAL/STEPPER/STEPPER.h"
// Light one led+Button
//int main(){
//	Led_tCfg Led1 = {
//		.Led_NestStruct.Port = DIO_u8_PORTA ,
//		.Pin  = DIO_u8_PIN0 ,
//		.Led_NestStruct.Active_Status = Led_Active_High ,
//		.Led_NestStruct.Current_Status= Led_Active_High_High
//	};
//	Led_vidLedInit(&Led1);
//	Button_tstrucCfg Button1 = {
//			.Button_NestStruct.Port = DIO_u8_PORTC ,
//			.Pin = DIO_u8_PIN0 ,
//	};
//	Button_vidButtonInit(&Button1); // Direction + Pull up
//	u8 Read=0;
//	u8 counter=1;
//while(1){
//	Button_vidButtonRead(&Button1,&Read);
//	if(Read == Button_Pressed)
//		counter++;
//	if(counter%2==0)
//		Led_vidOn(&Led1);
//	else
//		Led_vidOff(&Led1);
//}
//return 0;
//}

// Task 1
//int main(){
//Led_tCfg task1[8];
////Initialize all Leds
//for(u8 Led_InitCount=0;Led_InitCount<8;Led_InitCount++){
//		 task1[Led_InitCount].Led_NestStruct.Port = DIO_u8_PORTA ;
//		 task1[Led_InitCount].Pin  = Led_InitCount ;
//		 task1[Led_InitCount].Led_NestStruct.Active_Status = Led_Active_High ;
//		 task1[Led_InitCount].Led_NestStruct.Current_Status= Led_Active_High_Low;
//		 Led_vidLedInit(&task1[Led_InitCount]);
//}
//while(1){
//for(u8 Led_Count=0;Led_Count<8;Led_Count++){
//	Led_vidOn(&task1[Led_Count]);
//	_delay_ms(200);
//	Led_vidOff(&task1[Led_Count]);
//	_delay_ms(200);
//}
//
//}
//return 0;
//}

//Task 2
//int main(){
//Led_tCfg task2[8];
////Initialize all Leds
//for(u8 Led_InitCount=0;Led_InitCount<8;Led_InitCount++){
//		 task2[Led_InitCount].Led_NestStruct.Port = DIO_u8_PORTA ;
//		 task2[Led_InitCount].Pin  = Led_InitCount ;
//		 task2[Led_InitCount].Led_NestStruct.Active_Status = Led_Active_High ;
//		 task2[Led_InitCount].Led_NestStruct.Current_Status= Led_Active_High_Low;
//		 Led_vidLedInit(&task2[Led_InitCount]);
//}
//while(1){
//for(u8 Led_ForwardCount=0;Led_ForwardCount<8;Led_ForwardCount++){
//	Led_vidOn(&task2[Led_ForwardCount]);
//	_delay_ms(200);
//	Led_vidOff(&task2[Led_ForwardCount]);
//	_delay_ms(200);
//}
//for(u8 Led_BackwardCount=6;Led_BackwardCount>=1;Led_BackwardCount--){
//	Led_vidOn(&task1[Led_BackwardCount]);
//	_delay_ms(200);
//	Led_vidOff(&task1[Led_BackwardCount]);
//	_delay_ms(200);
//}
//
//}
//return 0;
//}
/////////////////////////////////////////////
// Task 3
//int main(){
//Led_tCfg task3[8];
////Initialize all Leds
//for(u8 Led_InitCount=0;Led_InitCount<8;Led_InitCount++){
//		 task3[Led_InitCount].Led_NestStruct.Port = DIO_u8_PORTA ;
//		 task3[Led_InitCount].Pin  = Led_InitCount ;
//		 task3[Led_InitCount].Led_NestStruct.Active_Status = Led_Active_High ;
//		 task3[Led_InitCount].Led_NestStruct.Current_Status= Led_Active_High_Low;
//		 Led_vidLedInit(&task3[Led_InitCount]);
//}
//while(1){
//for(u8 Led_OnCount=0;Led_OnCount<4;Led_OnCount++){
//	Led_vidOn(&task3[(4+Led_OnCount)]);
//	Led_vidOn(&task3[(3-Led_OnCount)]);
//	_delay_ms(1000);
//}
//for(u8 Led_OffCount=3;Led_OffCount>=0;Led_OffCount--){
//	Led_vidOff(&task3[3-Led_OffCount]);
//	Led_vidOff(&task3[4+Led_OffCount]);
//	_delay_ms(1000);
//	if(Led_OffCount==0) break; // To avoid infinity loop because Counter is unsigned it will be 255(>=0)
//}
//
//}
//return 0;
//}
//Task 4
//int main(){
//	u8 segment_7[10]={63,6,91,79,102,109,125,7,127,111};
//	Seg_tCfg Seg2 = {
//				.Port = DIO_u8_PORTA ,
//				.Common_Type = Seg_CommCathode
//			};
//	Seg_vidSegInit(&Seg2);
//while(1){
//
//	for(u8 Seg2_Counter=0;Seg2_Counter<10;Seg2_Counter++){
//		Seg_vidOn(&Seg2,segment_7[Seg2_Counter]);
//		_delay_ms(1000);
//		}
//}
//	return 0;
//}

// Task 5
//int main(){
//	u8 segment_7[10]={63,6,91,79,102,109,125,7,127,111};
//	Seg_tCfg Seg1 = { // Left
//			.Port = DIO_u8_PORTA ,
//			.Common_Type = Seg_CommCathode ,
//		};
//	Seg_tCfg Seg2 = { //Right
//				.Port = DIO_u8_PORTC ,
//				.Common_Type = Seg_CommCathode ,
//			};
//while(1){
//	for(int Seg2_Counter=1;Seg2_Counter<10;Seg2_Counter++){
//		for(u8 Seg1_Counter=0;Seg1_Counter<10;Seg1_Counter++){
//			Seg_vidOn(&Seg1,segment_7[Seg1_Counter]);
//			_delay_ms(1000);
//		}
//	Seg_vidOn(&Seg2,segment_7[Seg2_Counter]);
//	}
//}
//	return 0;
//}

// Direction Output ---> (Port,Pin,Output) Init
// SetPinVal ---> (Port,Pin,High/Low) LedOn LedOff
// 3 func
// Parameters --> Struct
////////////////////////////////////////////////////
// Lcd + Keypad
//int main(){
//	Lcd_tstrucCfg Lcd1={
//			.DataPortId=DIO_u8_PORTD,
//			.CtrlPortId=DIO_u8_PORTB,
//			.RS_Pin=0,
//			.RW_Pin=1,
//			.EN_Pin=2
//	};
//	Keypad_tstrucCfg Keypad1={
//			.DataPortId=DIO_u8_PORTC
//	};
//
//	Lcd_vidInit(&Lcd1);
//
//	u8 Keypad=0;
//	//u8 Res=0;
//	Keypad_vidInit(&Keypad1);
////	Lcd_GotoPosition(&Lcd1,LCD_LINE1,5);
//	//u8 Lcd_Number = 8;
//	//Lcd_WriteLetter(&Lcd1,&Keypad);
//
//	while(1){
////	u8 Lcd_String[]="Hamiid";
//	//Lcd_WriteString(&Lcd1,Lcd_String);
//	Keypad=0;
//	Keypad = Keypad_u8GetPressedKey(&Keypad1);
//	if(Keypad!=Keypad_NotPressed){
//		switch(Keypad){
//		case '+': Lcd_WriteLetter(&Lcd1,&Keypad);break;
//		case '-': Lcd_WriteLetter(&Lcd1,&Keypad);break;
//		case 'x': Lcd_WriteLetter(&Lcd1,&Keypad);break;
//		case '/': Lcd_WriteLetter(&Lcd1,&Keypad);break;
//		case 'c': Lcd_CLR(&Lcd1);break;
//		default : Lcd_WriteNumber(&Lcd1,Keypad) ;break;
//		}
////		Lcd_WriteLetter(&Lcd1,&Keypad);
////		_delay_ms(200);
//	}
//	}
//return 0;
//}
/////////////////////////////////////////////////////////////////
//////////////////////////KEYPAD CALCULATOR/////////////////////
//int main(){
//	Lcd_tstrucCfg Lcd1={
//			.DataPortId=DIO_u8_PORTA,
//			.CtrlPortId=DIO_u8_PORTC,
//			.RS_Pin=0,
//			.RW_Pin=1,
//			.EN_Pin=2
//	};
//	Keypad_tstrucCfg Keypad1={
//			.DataPortId=DIO_u8_PORTD
//	};
//
//	Lcd_vidInit(&Lcd1);
//
//	u8 Keypad=0;
//	u8 Calc[3];
//
//	Keypad_vidInit(&Keypad1);
////	Lcd_GotoPosition(&Lcd1,LCD_LINE1,5);
//	//u8 Lcd_Number = 8;
//	//Lcd_WriteLetter(&Lcd1,&Keypad);
//
//	while(1){
////	u8 Lcd_String[]="Hamiid";
//	//Lcd_WriteString(&Lcd1,Lcd_String);
//		u8 count=0;
//	while(1){
//	Keypad = Keypad_u8GetPressedKey(&Keypad1);
//	if(Keypad=='=')
//		break;
//	else if(Keypad!=Keypad_NotPressed && Keypad<=255 && Keypad>=0 ){
//		Calc[count++]=Keypad;
//		switch(Keypad){
//		case '+': Lcd_WriteLetter(&Lcd1,&Keypad);break;
//		case '-': Lcd_WriteLetter(&Lcd1,&Keypad);break;
//		case 'x': Lcd_WriteLetter(&Lcd1,&Keypad);break;
//		case '/': Lcd_WriteLetter(&Lcd1,&Keypad);break;
//		case 'c': Lcd_CLR(&Lcd1);break;
//		default:Lcd_WriteNumber(&Lcd1,&Keypad);break;
//	}
//	}
//		}
//	u8 res=0;
//	//CALCULATING
//	switch(Calc[1]){
//			case '+': res=Calc[0]+Calc[2] ;break;
//			case '-': res=Calc[0]-Calc[2];break;
//			case 'x': res=Calc[0]*Calc[2];break;
//			case '/': res=Calc[0]/Calc[2];break;
//	}
//	Lcd_GotoPosition(&Lcd1,LCD_LINE2,12);
//	Lcd_WriteNumber(&Lcd1,&res);
//return 0;
//}
//}
///////////////////////////////////////////////////////
/////////////////////LCD TASK (SIN NAME)/////////////////////////
//int main(){
//	Lcd_tstrucCfg Lcd1={
//		.DataPortId=DIO_u8_PORTD,
//		.CtrlPortId=DIO_u8_PORTC,
//		.RS_Pin=0,
//		.RW_Pin=1,
//		.EN_Pin=2
//		};
//	u8 Lcd_String[]="Hamiid";
//	u8 Lcd_StringSize=strlen(Lcd_String);
//	u8 Lcd_HalfStringSize;
//	if(Lcd_StringSize%2==0)
//		Lcd_HalfStringSize=Lcd_StringSize/2;
//	else
//		Lcd_HalfStringSize=(Lcd_StringSize/2)+1;
//	Lcd_vidInit(&Lcd1);
//	u8 counter;
//	Lcd_WriteString(&Lcd1,Lcd_String);
//	while(1){
//		Lcd_WriteString(&Lcd1,Lcd_String);
//		_delay_ms(250);
//		Lcd_CLR(&Lcd1);
//		for(counter=0;counter<=((16-Lcd_HalfStringSize)/2);counter++){
//			if(counter%2==0){
//				Lcd_GotoPosition(&Lcd1,LCD_LINE2,counter+(Lcd_HalfStringSize));
//				Lcd_WriteString(&Lcd1,Lcd_String);
//			}
//			else if(counter%2!=0){
//						Lcd_GotoPosition(&Lcd1,LCD_LINE1,counter+(Lcd_HalfStringSize));
//						Lcd_WriteString(&Lcd1,Lcd_String);
//					}
//			_delay_ms(250);
//			Lcd_CLR(&Lcd1);
//
//		}
//
//		Lcd_GotoPosition(&Lcd1,LCD_LINE1,16-Lcd_StringSize);
//		Lcd_WriteString(&Lcd1,Lcd_String);
//		_delay_ms(250);
//		Lcd_CLR(&Lcd1);
//
//		for(counter=0;counter<=((16-Lcd_HalfStringSize)/2);counter++){
//					if(counter%2==0){
//						Lcd_GotoPosition(&Lcd1,LCD_LINE2,15-Lcd_StringSize-counter-1);
//						Lcd_WriteString(&Lcd1,Lcd_String);
//					}
//					else if(counter%2!=0){
//								Lcd_GotoPosition(&Lcd1,LCD_LINE1,15-Lcd_StringSize-counter-1);
//								Lcd_WriteString(&Lcd1,Lcd_String);
//							}
//					_delay_ms(250);
//					Lcd_CLR(&Lcd1);
//
//				}
//	}
//
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////
//Transistor + Relay
//int main(){
////	Led_tCfg Led1={
////		.Led_NestStruct.Port = DIO_u8_PORTA ,
////		.Pin  = DIO_u8_PIN1 ,
////		.Led_NestStruct.Active_Status = Led_Active_High ,
////		.Led_NestStruct.Current_Status= Led_Active_High_High
////	};
//	DIO_enuSetPortDirection(DIO_u8_PORTA,3);
//	DIO_enuSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN1,DIO_u8_HIGH);
//	while(1){
//		DIO_enuSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN0,DIO_u8_HIGH);
//		_delay_ms(5000);
//		DIO_enuSetPinValue(DIO_u8_PORTA ,DIO_u8_PIN0,DIO_u8_LOW);
//				_delay_ms(5000);
//	}
//return 0;
//}
/////////////////////////////////////////////////////////////////////////
 //Stepper
//int main(){
//	Stepper_tstructCfg Step = {
//		.Port=DIO_u8_PORTC
//	};
//	Stepper_voidInit(&Step);
//	DIO_enuSetPortDirection(DIO_u8_PORTC,255);
//	DIO_enuSetPortValue(DIO_u8_PORTC,0b00000001);
//
//	while(1){
//	// Step , Direction , Half or Full Step , Degree
//	Stepper_voidOn(&Step,Stepper_CLOCKWISE,Stepper_HALF_STEP,Stepper_HALF_STEP_135DEG);
//	_delay_ms(300);
//	Stepper_voidOn(&Step,Stepper_COUNTER_CLOCKWISE,Stepper_HALF_STEP,Stepper_HALF_STEP_180DEG);
//	_delay_ms(300);
//	}
//return 0;
//}
///////////////////////////////////////////////////////////////////////
// Task 1 Half Motor (4 Transistors)
//int main(){
//	DIO_enuSetPortDirection(DIO_u8_PORTA,255);
//	while(1){
//		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000011);
//		_delay_ms(2000);
//		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000000);
//		_delay_ms(2000);
//		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00001100);
//		_delay_ms(2000);
//		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000000);
//		_delay_ms(2000);
//
//
//	}
//return 0;
//}
//////////////////////////////////////////////////////////////////////////
//int main(){
//	DIO_enuSetPortDirection(DIO_u8_PORTA,255);
//	while(1){
//		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000001);
//		_delay_ms(10000);
//		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000000);
//		_delay_ms(10000);
//		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000010);
//		_delay_ms(10000);
//		DIO_enuSetPortValue(DIO_u8_PORTA ,0b00000000);
//		_delay_ms(10000);
//
//
//
//	}
//return 0;
//}
///////////////////////////INTERRUPT////////////////////
//void __vector_1 (void) __attribute__((signal));
//void __vector_1 (void){
//	_delay_ms(200);
//	TGL_BIT(PORTD_Register,6);
//	_delay_ms(200);
//}
//int main(){
//EXTINT_structCfg INT0={
//		.IntMode=EXTINT_FALLING_EDGE,
//		.IntNo=EXTINT_INT0
//
//};
//
//Button_tstrucCfg button1={
//		.Pin=DIO_u8_PIN2,
//		.Button_NestStruct.Port=DIO_u8_PORTD,
//};
//Led_tCfg Led_sys={
//	.Pin = DIO_u8_PIN7,
//	.Led_NestStruct.Port=DIO_u8_PORTD,
//	.Led_NestStruct.Current_Status=Led_Active_High_Low,
//	.Led_NestStruct.Active_Status=Led_Active_High
//};
//Led_tCfg Led_INT={
//	.Pin = DIO_u8_PIN6,
//	.Led_NestStruct.Port=DIO_u8_PORTD,
//	.Led_NestStruct.Current_Status=Led_Active_High_Low,
//	.Led_NestStruct.Active_Status=Led_Active_High
//};
//Led_vidLedInit(&Led_sys);
//Led_vidLedInit(&Led_INT);
//Button_vidButtonInit(&button1);
//EXTINT_voidEnable(&INT0);
//while(1){
//	Led_vidToggle(&Led_sys);
//	_delay_ms(200);
//}
//	return 0;
//}
////////////////////// TASK INTERRUPT
//void __vector_1 (void) __attribute__((signal));
//void __vector_1 (void){
//	_delay_ms(500);
//	TGL_BIT(PORTA_Register,6);
//	_delay_ms(500);
//}
//void __vector_2 (void) __attribute__((signal));
//void __vector_2 (void){
//	_delay_ms(200);
//	TGL_BIT(PORTA_Register,7);
//	_delay_ms(200);
//}
//int main(){
//	DIO_enuSetPortDirection(DIO_u8_PORTA,0b11000000);
//
//EXTINT_structCfg INT[2]={
//		{.IntMode=EXTINT_LOGICAL_CHANGE, .IntNo=EXTINT_INT0},
//		{.IntMode=EXTINT_LOGICAL_CHANGE, .IntNo=EXTINT_INT1},
//
//};
//
//Button_tstrucCfg buttons[2]={
//		{.Pin=DIO_u8_PIN2, .Button_NestStruct.Port=DIO_u8_PORTD},
//		{.Pin=DIO_u8_PIN3, .Button_NestStruct.Port=DIO_u8_PORTD},
//};
//////////////////////////////////////////////////////////////////
//u8 Ledcounter=0;
//Led_tCfg Led_sys[8];
//for(Ledcounter=0;Ledcounter<8;Ledcounter++){
//	Led_sys[Ledcounter].Pin = Ledcounter;
//	Led_sys[Ledcounter].Led_NestStruct.Port=DIO_u8_PORTC;
//	Led_sys[Ledcounter].Led_NestStruct.Current_Status=Led_Active_High_Low;
//	Led_sys[Ledcounter].Led_NestStruct.Active_Status=Led_Active_High;
//	Led_vidLedInit(&Led_sys[Ledcounter]);
//}
//Button_vidButtonInit(&buttons[0]);
//Button_vidButtonInit(&buttons[1]);
//EXTINT_voidEnable(&INT[0]);
//EXTINT_voidEnable(&INT[1]);
//////////////////////////////////////////////////////////////////////
//while(1){
//	for(Ledcounter=0;Ledcounter<8;Ledcounter+=2){
//		Led_vidToggle(&Led_sys[Ledcounter]);
//		_delay_ms(500);
//	}
//	for(Ledcounter=0;Ledcounter<8;Ledcounter+=2){
//		Led_vidToggle(&Led_sys[Ledcounter]);
//	}
//	for(Ledcounter=1;Ledcounter<8;Ledcounter+=2){
//		Led_vidToggle(&Led_sys[Ledcounter]);
//		_delay_ms(500);
//	}
//	for(Ledcounter=1;Ledcounter<8;Ledcounter+=2){
//		Led_vidToggle(&Led_sys[Ledcounter]);
//	}
//}
//	return 0;
//}
////////////////////////////////////////////////////////////////////
 //Task 1 Led increase and decraese
//int main(){
//	DIO_enuSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_OUTPUT);
//Button_tstrucCfg buttons[2]={
//		{.Pin=DIO_u8_PIN0, .Button_NestStruct.Port=DIO_u8_PORTA},
//		{.Pin=DIO_u8_PIN3, .Button_NestStruct.Port=DIO_u8_PORTD},
//};

//s8 Ledcounter=0;
//Led_tCfg Led_sys[8];
//for(Ledcounter=0;Ledcounter<8;Ledcounter++){
//	Led_sys[Ledcounter].Pin = Ledcounter;
//	Led_sys[Ledcounter].Led_NestStruct.Port=DIO_u8_PORTC;
//	Led_sys[Ledcounter].Led_NestStruct.Current_Status=Led_Active_High_Low;
//	Led_sys[Ledcounter].Led_NestStruct.Active_Status=Led_Active_High;
//	Led_vidLedInit(&Led_sys[Ledcounter]);
//}
//Button_vidButtonInit(&buttons[0]);
//Button_vidButtonInit(&buttons[1]);
////////////////////////////////////////////////////////////////////
//Ledcounter=0;
//u8 ErrorFlag=0;
//while(1){
//	//increase button
//	u8 forloopcounter=0;
//	do{
//		if(Button_u8ButtonRead(&buttons[0])==Button_Pressed){
//
//			if(Ledcounter<8 && Ledcounter>=0)
//				Led_vidOn(&Led_sys[Ledcounter]);
//			else
//				ErrorFlag=1;
//			_delay_ms(300);
//			Ledcounter++;
//		}
//
//		else if(Button_u8ButtonRead(&buttons[1])==Button_Pressed){
//
//			if(Ledcounter<8 && Ledcounter>=0)
//				Led_vidOff(&Led_sys[Ledcounter]);
//			else
//				ErrorFlag=1;
//			_delay_ms(300);
//			Ledcounter--;
//		}
//	}while(ErrorFlag==0);
//	//Error
//	do{
////		if(Ledcounter<8 && Ledcounter>=0){
////					for(forloopcounter=0;forloopcounter<=Ledcounter;forloopcounter++)
////					Led_vidOn(&Led_sys[forloopcounter]);
////					ErrorFlag=0;
////					break;
////				}
//		for(forloopcounter=0;forloopcounter<8;forloopcounter++)
//			Led_vidOn(&Led_sys[forloopcounter]);
//		DIO_enuSetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH); //buzz
//
//		_delay_ms(300);
//
//		for(forloopcounter=0;forloopcounter<8;forloopcounter++)
//			Led_vidOff(&Led_sys[forloopcounter]);
//		DIO_enuSetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
//
//		_delay_ms(300);
//
//		if(Button_u8ButtonRead(&buttons[0])==Button_Pressed && Ledcounter<0){
//			Ledcounter++;
//			if(Ledcounter<8 && Ledcounter>=0){
//								for(forloopcounter=0;forloopcounter<=Ledcounter;forloopcounter++)
//								Led_vidOn(&Led_sys[forloopcounter]);
//								ErrorFlag=0;
//								break;
//							}
//		}
//		else if((Button_u8ButtonRead(&buttons[1])==Button_Pressed) && Ledcounter>7){
//			Ledcounter--;
//			if(Ledcounter<8 && Ledcounter>=0){
//								for(forloopcounter=0;forloopcounter<=Ledcounter;forloopcounter++)
//								Led_vidOn(&Led_sys[forloopcounter]);
//								ErrorFlag=0;
//								break;
//							}
//		}
//
//
//	}while(ErrorFlag==1);
//}
//return 0;
//}
///////////////////////////ADC TASK 1

//int main(){
//	ADC_voidInit();
//	u16 Loc_u16AdcRead=0;
//	s8 Ledcounter=0;
//	Lcd_tstrucCfg lcd1={
//			.CtrlPortId=DIO_u8_PORTB,
//			.DataPortId=DIO_u8_PORTD,
//			.EN_Pin=2,
//			.RW_Pin=1,
//			.RS_Pin=0
//	};
//	Lcd_vidInit(&lcd1);
//	DIO_enuSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN5,1);
//	DIO_enuSetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,1);
//
//	Led_tCfg Led_sys[8];
//	for(Ledcounter=0;Ledcounter<8;Ledcounter++){
//		Led_sys[Ledcounter].Pin = Ledcounter;
//		Led_sys[Ledcounter].Led_NestStruct.Port=DIO_u8_PORTC;
//		Led_sys[Ledcounter].Led_NestStruct.Current_Status=Led_Active_High_Low;
//		Led_sys[Ledcounter].Led_NestStruct.Active_Status=Led_Active_High;
//		Led_vidLedInit(&Led_sys[Ledcounter]);
//	}
//	Ledcounter=0;
//	u16 Loc_previousRead=0;
//	u16 Loc_u16AdcReadLcd=0;
//	while(1){
//	ADC_voidGetRead(&Loc_u16AdcRead);
//	Loc_u16AdcReadLcd=(Loc_u16AdcReadLcd*(5.0/1024.0));
//	Lcd_WriteNumber(&lcd1,&Loc_u16AdcReadLcd);
//	if(Loc_u16AdcRead%256==0 && Loc_u16AdcRead>Loc_previousRead && Ledcounter<=7 && Ledcounter>=0){
//		Led_vidOn(&Led_sys[Ledcounter]);
//		Ledcounter++;
//		Loc_previousRead=Loc_u16AdcRead;
//	}
//	else if(Loc_u16AdcRead%256==0 && Loc_u16AdcRead<Loc_previousRead && Ledcounter<=7 && Ledcounter>=0){
//
//		Led_vidOff(&Led_sys[Ledcounter]);
//		Ledcounter--;
//		Loc_previousRead=Loc_u16AdcRead;
//	}
//	else if(Ledcounter>7||Ledcounter<0){
//		if (Ledcounter>7)
//			Ledcounter=7;
//		else
//			Ledcounter=0;
//	}
//
//	}
//return 0;
//}
//////////////////////////////////////////////////////////////////
 //LDR TASK ADC
//int main(){
//	ADC_voidInit();
//	u16 Loc_u16AdcRead=0;
//	Lcd_tstrucCfg lcd1={
//			.CtrlPortId=DIO_u8_PORTB,
//			.DataPortId=DIO_u8_PORTD,
//			.EN_Pin=2,
//			.RW_Pin=1,
//			.RS_Pin=0
//	};
//	Lcd_vidInit(&lcd1);
//	u8 Lcd_string[]="Voltage = ";
//	u8 Lcd_string2[]="V";
//	Lcd_WriteString(&lcd1,Lcd_string);
//	Lcd_GotoPosition(&lcd1,LCD_LINE2,14);
//	Lcd_WriteString(&lcd1,Lcd_string2);
//	while(1){
//	ADC_voidGetRead(&Loc_u16AdcRead);
//	Loc_u16AdcRead*=((5.0-(5.0/1023.0))/1023.0);
//	Lcd_GotoPosition(&lcd1,LCD_LINE2,12);
//	Lcd_WriteNumber(&lcd1,Loc_u16AdcRead);
//	u8 Ledcounter=0;
//	Led_tCfg Led_sys[8];
//		for(Ledcounter=0;Ledcounter<8;Ledcounter++){
//			Led_sys[Ledcounter].Pin = Ledcounter;
//			Led_sys[Ledcounter].Led_NestStruct.Port=DIO_u8_PORTC;
//			Led_sys[Ledcounter].Led_NestStruct.Current_Status=Led_Active_High_Low;
//			Led_sys[Ledcounter].Led_NestStruct.Active_Status=Led_Active_High;
//			Led_vidLedInit(&Led_sys[Ledcounter]);
//		}
//	if(Loc_u16AdcRead>2){
//		for(Ledcounter=0;Ledcounter<8;Ledcounter++)
//			Led_vidOn(&Led_sys[Ledcounter]);
//	}
//	else{
//		for(Ledcounter=0;Ledcounter<8;Ledcounter++)
//			Led_vidOff(&Led_sys[Ledcounter]);
//	}
//
//	_delay_ms(1000);
//	}
//
//return 0;
//}
//////////////////////////////////////////////////////
//int main(){
//	ADC_voidInit();
//	u16 Loc_u16AdcRead=0;
//	Lcd_tstrucCfg lcd1={
//			.CtrlPortId=DIO_u8_PORTB,
//			.DataPortId=DIO_u8_PORTD,
//			.EN_Pin=2,
//			.RW_Pin=1,
//			.RS_Pin=0
//	};
//	Lcd_vidInit(&lcd1);
//	u8 Lcd_string[]="TEMP = ";
//	u8 Lcd_string2[]="C";
//	Lcd_WriteString(&lcd1,Lcd_string);
//	Lcd_GotoPosition(&lcd1,LCD_LINE2,14);
//	Lcd_WriteString(&lcd1,Lcd_string2);
//	while(1){
//	ADC_voidGetRead(&Loc_u16AdcRead);
////	Lcd_GotoPosition(&lcd1,LCD_LINE2,0);
////	Lcd_WriteNumber(&lcd1,Loc_u16AdcRead);
//	Loc_u16AdcRead*=(500.0/1024.0);
//	if(Loc_u16AdcRead>10&&Loc_u16AdcRead<=45){
//	Lcd_GotoPosition(&lcd1,LCD_LINE2,6);
//	Lcd_WriteNumber(&lcd1,Loc_u16AdcRead);
//	_delay_ms(2000);
//	}
//	}
//
//return 0;
//}
////////////////////////////////////////////////////
//int main(){
//	ADC_voidInit();
//	u16 Loc_u16AdcRead=0;
//	Lcd_tstrucCfg lcd1={
//			.CtrlPortId=DIO_u8_PORTC,
//			.DataPortId=DIO_u8_PORTD,
//			.EN_Pin=2,
//			.RW_Pin=1,
//			.RS_Pin=0
//	};
//	Lcd_vidInit(&lcd1);
//	u8 Lcd_string[]="VOLT = ";
//	u8 Lcd_string2[2];
////	u8 Lcd_string2[]="C";
//	Lcd_WriteString(&lcd1,Lcd_string);
////	Lcd_GotoPosition(&lcd1,LCD_LINE2,14);
////	Lcd_WriteString(&lcd1,Lcd_string2);
//	u8 Sensor_Counter=0;
//	Button_tstrucCfg button1={
//			.Pin=DIO_u8_PIN0,
//			.Button_NestStruct.Port=DIO_u8_PORTB
//	};
//	Button_vidButtonInit(&button1);
//	while(1){
//	ADC_voidGetRead(&Loc_u16AdcRead);
////	Lcd_GotoPosition(&lcd1,LCD_LINE2,0);
////	Lcd_WriteNumber(&lcd1,Loc_u16AdcRead);
////	Loc_u16AdcReadV*=(5.0/1024.0);
////	Loc_u16AdcReadMV*=(5000.0/1024.0);
//	if(Button_u8ButtonRead(&button1)==Button_Pressed){
//		Sensor_Counter++;
//		_delay_ms(200);
//	}
//	if(Sensor_Counter%2==0){
//		Lcd_string2[0]='V';
//		Loc_u16AdcRead*=(5.0/1024.0);
//	}
//	else if(Sensor_Counter%2==1){
//		Lcd_string2[0]='m';
//		Lcd_string2[1]='V';
//
//		Loc_u16AdcRead*=(5000.0/1024.0);
//	}
//	Lcd_GotoPosition(&lcd1,LCD_LINE2,6);
//	Lcd_WriteNumber(&lcd1,Loc_u16AdcRead);
//	Lcd_GotoPosition(&lcd1,LCD_LINE2,14);
//	Lcd_WriteString(&lcd1,Lcd_string2);
//	}
//
//return 0;
//}
/////////////////////////////////////////////////////
// TIMER FAST PWM
//int main(){
//DIO_enuSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5,1);
//
//Timer_structTimerCfg timer1={
//		.Timer_u8TimerNo =TIMER_NO_TIMER1,
//		.Timer_u8TimerForceOutputCompare=TIMER1_FOC_OFF,
//		.Timer_u8WaveFormGenerationMode=TIMER1_MODE_PWM_FAST_COMPARE_CHANNEL_A,
//		.Timer_u8ClockSelect=TIMER1_CLOCK_PRESCALLING_8,
//		.Timer_u8OcBehaviour=TIMER1_CHANNEL_A_OC1_PWM_CLEAR_OPERATION,
//		.Timer1_u8Channel=TIMER1_CHANNEL_A
//};
//TIMER_voidTimerInit(&timer1);
////TCCR1=0b1000001100011010;
//
//	while(1){
//		OCR1A=10000;
//		_delay_ms(1000);
//		OCR1A=30000;
//		_delay_ms(1000);
//		OCR1A=60000;
//		_delay_ms(1000);
//
//	}
//	return 0;
//}
//////////////////////////////////////////////
//volatile u8 Loc_u8BigDelayValueCounterMaxValue;
//void __vector_10 (void) __attribute__((signal));
//void __vector_10 (void){
//	static u8 counter=0;
//	counter++;
//	if(counter==Loc_u8BigDelayValueCounterMaxValue){
//		TGL_BIT(PORTA_Register,3);
//	}
//
//}
//int main(){
//DIO_enuSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN3,1);
//Timer_structTimerCfg timer0={
//		.Timer_u8TimerNo =TIMER_NO_TIMER0,
//		.Timer_u8TimerForceOutputCompare=TIMER0_FOC_OFF,
//		.Timer_u8WaveFormGenerationMode=TIMER0_MODE_NORMAL,
//		.Timer_u8ClockSelect=TIMER0_CLOCK_PRESCALLING_8,
//};
//TIMER_voidTimerInit(&timer0);
//Timer_structDelayFunc Delayus={
//	.Timer_u8TimerNo=TIMER_NO_TIMER0,
//	.Timer_u8OcBehaviour=TIMER0_OC0_NO_PWM_TOGGLE_OPERATION,
//	.Timer_u8Interrupt=TIMER0_INTERRUPT_ON
//};
//	while(1){
//		TIMER_voidDelay(&Delayus,1000000);
//	}
//	return 0;
//}
///////////////////////////////////////////////////////
/////////////////// TASK 1 ///////////////////////////
//int main(){
//DIO_enuSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5,1);
//
//Timer_structTimerCfg timer1={
//		.Timer_u8TimerNo =TIMER_NO_TIMER1,
//		.Timer_u8TimerForceOutputCompare=TIMER1_FOC_OFF,
//		.Timer_u8WaveFormGenerationMode=TIMER1_MODE_PWM_PHASE_CORRECT_SET_TOP_VALUE,
//		.Timer_u8ClockSelect=TIMER1_CLOCK_PRESCALLING_8,
//		.Timer_u8OcBehaviour=TIMER1_CHANNEL_A_OC1_PWM_CLEAR_OPERATION,
//		.Timer1_u8Channel=TIMER1_CHANNEL_A
//};
//TIMER_voidTimerInit(&timer1);
////TCCR1=0b1000001100011010;
//ADC_voidInit();
//u16 Loc_u16AdcRead=0;
//ICR1=20000;
//
//	while(1){
////				OCR1A=1024;
////				_delay_ms(1000);
////				OCR1A=500;
////				_delay_ms(1000);
////				OCR1A=200;
////				_delay_ms(1000);
//
//ADC_voidGetRead(&Loc_u16AdcRead);
//
//TIMER_voidPwmOn(&timer1,(Loc_u16AdcRead*2.346)+100);
//	}
//	return 0;
//}
//////////////////////////////////////////
//int main(){
//
//DIO_enuSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,1);
//
//DIO_enuSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN1,1);
//DIO_enuSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,0);
//
//UART_voidInit();
//u8 Loc_u8ReturnData;
//while(1){
//	Loc_u8ReturnData = UART_u8GetChar();
//	if(Loc_u8ReturnData=='1')
//		DIO_enuSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,1);
//	if(Loc_u8ReturnData=='2')
//		DIO_enuSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,0);
//}
//}

////////////////////////////////////////////////////////
// UART DRIVER APP
int main(){

	Led_tCfg Led1={
		.Pin=DIO_u8_PIN0,
		.Led_NestStruct.Port=DIO_u8_PORTA,
		.Led_NestStruct.Active_Status=Led_Active_High,
		.Led_NestStruct.Current_Status=Led_Active_High_Low,
	};
	UART_structCfg uart={
			.UART_u8BaudRate=UART_BAUD_RATE_9600,
			.UART_u8CharSize=UART_CHARACTER_SIZE_8_BIT,
			.UART_u8Parity=UART_PARITY_DISABLED,
			.UART_u8Mode=UART_MODE_ASYNCHRONOUS,
			.UART_u8StopBit=UART_STOP_BIT_SELECT_1_BIT,
			.UART_u8EnableTXorRX=UART_ENABLE_TX_RX,
	};
Led_vidLedInit(&Led1);
UART_voidInit(&uart);
u8 Loc_u8UARTReturnData;
while(1){
	Loc_u8UARTReturnData = UART_u8GetChar();
	if(Loc_u8UARTReturnData=='1')
		Led_vidToggle(&Led1);
	if(Loc_u8UARTReturnData=='2')
		Led_vidToggle(&Led1);
}
}

