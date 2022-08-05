/*
 * Ssd.c
 *
 * Created: 6/5/2022 11:49:18 PM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "Ssd.h"

/*****************************************_MACROS_***********************************************/

/*****************************************_PROTOTYPES_*******************************************/
static void H_SSD_DigitDisplay(u8,u8);

void H_Ssd_Init(void)
{
	M_Dio_PinMode(Ssd_A_Pin,OUTPUT);
	M_Dio_PinMode(Ssd_B_Pin,OUTPUT);
	M_Dio_PinMode(Ssd_C_Pin,OUTPUT);
	M_Dio_PinMode(Ssd_D_Pin,OUTPUT);
	
	M_Dio_PinMode(Ssd_EN2_Pin,OUTPUT);
	M_Dio_PinMode(Ssd_EN1_Pin,OUTPUT);
}
void H_Ssd_Write(u8 local_u8_Number)
{
	u8 Local_u8_Counter=0;
	u8 local_u8_Unit=local_u8_Number %10;
	u8 local_u8_Tens=local_u8_Number /10;
	for (Local_u8_Counter=0;Local_u8_Counter<50;Local_u8_Counter++)
	{
		H_SSD_DigitDisplay(local_u8_Unit,Ssd_Right);
		H_SSD_DigitDisplay(local_u8_Tens,Ssd_Left);
		
	}
 	
}
	
 static void H_SSD_DigitDisplay(u8 Local_u8_Number,u8 Local_u8_Ss)
 {
	 switch(Local_u8_Ss)
	 {
         case Ssd_Right:
		 	M_Dio_PinWrite(Ssd_EN1_Pin,LOW);
		 	M_Dio_PinWrite(Ssd_EN2_Pin,HIGH);
		 break;
		 case Ssd_Left:
		      M_Dio_PinWrite(Ssd_EN1_Pin,HIGH);
		      M_Dio_PinWrite(Ssd_EN2_Pin,LOW);
		 break;
		 default:                  break;
	 }
	 switch(Local_u8_Number)
	 {
		 case 0:
		 M_Dio_PinWrite(Ssd_A_Pin,LOW);
		 M_Dio_PinWrite(Ssd_B_Pin,LOW);
		 M_Dio_PinWrite(Ssd_C_Pin,LOW);
		 M_Dio_PinWrite(Ssd_D_Pin,LOW);
		 break;
		 case 1:
		 M_Dio_PinWrite(Ssd_A_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_B_Pin,LOW);
		 M_Dio_PinWrite(Ssd_C_Pin,LOW);
		 M_Dio_PinWrite(Ssd_D_Pin,LOW);
		 break;
		 case 2:
		 M_Dio_PinWrite(Ssd_A_Pin,LOW);
		 M_Dio_PinWrite(Ssd_B_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_C_Pin,LOW);
		 M_Dio_PinWrite(Ssd_D_Pin,LOW);
		 break;
		 case 3:
		 M_Dio_PinWrite(Ssd_A_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_B_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_C_Pin,LOW);
		 M_Dio_PinWrite(Ssd_D_Pin,LOW);
		 break;
		 case 4:
		 M_Dio_PinWrite(Ssd_A_Pin,LOW);
		 M_Dio_PinWrite(Ssd_B_Pin,LOW);
		 M_Dio_PinWrite(Ssd_C_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_D_Pin,LOW);
		 break;
		 case 5:
		 M_Dio_PinWrite(Ssd_A_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_B_Pin,LOW);
		 M_Dio_PinWrite(Ssd_C_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_D_Pin,LOW);
		 break;
		 case 6:
		 M_Dio_PinWrite(Ssd_A_Pin,LOW);
		 M_Dio_PinWrite(Ssd_B_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_C_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_D_Pin,LOW);
		 break;
		 case 7:
		 M_Dio_PinWrite(Ssd_A_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_B_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_C_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_D_Pin,LOW);
		 break;
		 case 8:
		 M_Dio_PinWrite(Ssd_A_Pin,LOW);
		 M_Dio_PinWrite(Ssd_B_Pin,LOW);
		 M_Dio_PinWrite(Ssd_C_Pin,LOW);
		 M_Dio_PinWrite(Ssd_D_Pin,HIGH);
		 break;
		 case 9:
		 M_Dio_PinWrite(Ssd_A_Pin,HIGH);
		 M_Dio_PinWrite(Ssd_B_Pin,LOW);
		 M_Dio_PinWrite(Ssd_C_Pin,LOW);
		 M_Dio_PinWrite(Ssd_D_Pin,HIGH);
		 break;
		 default:                break;
	 }
	 _delay_ms(5);
	 
 }
 void H_Ssd_CounterUp(u8 Local_u8_Target)
 {
	 u8 Local_u8_Number =0;
	 for(Local_u8_Number=0;Local_u8_Number<=Local_u8_Target;Local_u8_Number++)
	 {
		 H_Ssd_Write(Local_u8_Number);
	 }
 }

 void H_Ssd_CounterDown(u8 Local_u8_Target)
 {
	 u8 Local_u8_Number =0;
	 for(Local_u8_Target;Local_u8_Target>Local_u8_Number;Local_u8_Target--)
	 {
		 H_Ssd_Write(Local_u8_Target);
	 }
	 
 }

/*****************************************_SELECT_DELAT_TIME_************************************/

/*****************************************_SELECT_LED_PIN_***************************************/
