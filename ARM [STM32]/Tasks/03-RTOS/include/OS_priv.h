/*************************************************************/
/* Author  : Mohamed Abdel Hamid                             */
/* Date    : 23 / 8 / 2023                                   */
/* Version : V01                                             */
/*************************************************************/
#ifndef OS_PRIV_H
#define OS_PRIV_H

#define NULL (void * )0

typedef struct{

	void (*func)(void);
	u32  periodicity  ;
	u32  firstDelay   ;
	u8   state        ;

}SOS_Task;

typedef enum{
	STATE_DORMANT   ,
	STATE_READY     ,
	STATE_RUNNING   ,
	STATE_WAITING   ,
	STATE_SUSPENDED ,
}SOS_enumState;

static SOS_Task SOS_Tasks[SOS_NO_OF_TASKS]={NULL};

static void SOS_voidScheduler(){
	for(u8 Loc_u8Counter = 0 ; Loc_u8Counter < SOS_NO_OF_TASKS ; Loc_u8Counter++){
		if((SOS_Tasks[Loc_u8Counter].func != NULL) && (SOS_Tasks[Loc_u8Counter].state == STATE_READY)){
			if(SOS_Tasks[Loc_u8Counter].firstDelay == 0){
				SOS_Tasks[Loc_u8Counter].firstDelay = SOS_Tasks[Loc_u8Counter].periodicity-1;
				SOS_Tasks[Loc_u8Counter].func();
			}
			else{
				SOS_Tasks[Loc_u8Counter].firstDelay--;
			}
		}
		else{
			/* ERROR */
		}

	}
}


#endif
