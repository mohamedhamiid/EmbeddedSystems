#include "util/delay.h"
#include "../../INCLUDE/MCAL/DIO/DIO.h"
#include "../../INCLUDE/MCAL/DIO/DIO_priv.h"
#include "../../SERVICES/bit_utilies.h"
#include "../../INCLUDE/HAL/seg_7/seg_7.h"

/********************************Task 5*******************************/
/* - Counter With two 7 segment 0-->99                               */
/*********************************************************************/
// Task 5
int main(){
	u8 segment_7[10]={63,6,91,79,102,109,125,7,127,111};
	Seg_tCfg Seg1 = { // Left
			.Port = DIO_u8_PORTA ,
			.Common_Type = Seg_CommCathode ,
		};
	Seg_tCfg Seg2 = { //Right
				.Port = DIO_u8_PORTC ,
				.Common_Type = Seg_CommCathode ,
			};
while(1){
	for(int Seg2_Counter=1;Seg2_Counter<10;Seg2_Counter++){
		for(u8 Seg1_Counter=0;Seg1_Counter<10;Seg1_Counter++){
			Seg_vidOn(&Seg1,segment_7[Seg1_Counter]);
			_delay_ms(1000);
		}
	Seg_vidOn(&Seg2,segment_7[Seg2_Counter]);
	}
}
	return 0;
}

