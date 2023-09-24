/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 23 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef OS_PRIV_H
#define OS_PRIV_H


typedef struct{

	void (*func)(void);
	u16  periodicity;

}SOS_Task;

static SOS_Task SOS_Tasks[SOS_NO_OF_TASKS];

volatile u16 Global_u16TickCounts=0;

static void SOS_voidScheduler(){
	for(u8 Loc_u8Counter = 0 ; Loc_u8Counter < SOS_NO_OF_TASKS ; Loc_u8Counter++){
		if((Global_u16TickCounts % SOS_Tasks[Loc_u8Counter].periodicity)==0)
			SOS_Tasks[Loc_u8Counter].func();
	}
	Global_u16TickCounts++;
}
#endif
