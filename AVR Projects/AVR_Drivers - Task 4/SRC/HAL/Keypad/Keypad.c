#include "../../../INCLUDE/HAL/Keypad/Keypad.h"
#include "../../../INCLUDE/MCAL/DIO/DIO.h"
#include"../../../SERVICES/std_types.h"
#include "util/delay.h"
#include "../../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../../SERVICES/bit_utilies.h"

/*********************Keypad_arrCfg*********************/
/* USE : Cfg Keypad Characters                         */
/*******************************************************/
u8 Keypad_arrCfg [4][4]={
		{7,8,9,'/'}	,
		{4,5,6,'x'}	,
		{1,2,3,'-'}	,
		{'c',0,'=','+'}
};
// R1 --> pin0
// C1 --> pin4


/*********************Keypad_vidInit********************/
/* USE : Initialize the KeyPad according to user cfg   */
/* PARAMETERS: The struct carries cfg                  */
/* RETURN: No Return                                   */
/*******************************************************/
void Keypad_vidInit(Keypad_tstrucCfg*Add_strucKeypad){
	DIO_enuSetPortDirection(Add_strucKeypad->DataPortId,0x0f); // 4 Input 4 OutPut
	DIO_enuSetPortValue(Add_strucKeypad->DataPortId,DIO_u8_PORT_OUTPUT);
}

/***************Keypad_u8GetPressedKey*******************/
/* USE : To get the pressed button in Keypad            */
/* PARAMETERS: The struct carries cfg                   */
/* RETURN: The Character or integer representing the    */
/* Pressed key                                          */
/********************************************************/
u8 Keypad_u8GetPressedKey(Keypad_tstrucCfg*Add_strucKeypad){
	u8 Keypad_RowResult=1;
	u8 Keypad_Result=Keypad_NotPressed;
	for(u8 Keypad_u8Col=0;Keypad_u8Col<4;Keypad_u8Col++){
		//Activate each col (=0)
		DIO_enuSetPinValue(Add_strucKeypad->DataPortId,Keypad_u8Col,DIO_u8_LOW);

		for(u8 Keypad_u8Row=0;Keypad_u8Row<4;Keypad_u8Row++){

			DIO_u8GetPinValue(Add_strucKeypad->DataPortId,Keypad_u8Row+4,&Keypad_RowResult);

			if(Keypad_RowResult==Keypad_Pressed){
				while(Keypad_RowResult==Keypad_Pressed){
					DIO_u8GetPinValue(Add_strucKeypad->DataPortId,Keypad_u8Row+4,&Keypad_RowResult);
				}
				DIO_enuSetPinValue(Add_strucKeypad->DataPortId,Keypad_u8Col,DIO_u8_HIGH);
				return Keypad_arrCfg [Keypad_u8Col][Keypad_u8Row];
				_delay_ms(10);
			}

		}

		DIO_enuSetPinValue(Add_strucKeypad->DataPortId,Keypad_u8Col,DIO_u8_HIGH);
	}

	return Keypad_Result;
}
