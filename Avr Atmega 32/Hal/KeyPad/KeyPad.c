/*
 * KeyPad.c
 *
 * Created: 5/27/2022 7:46:20 PM
 *  Author: Mohamed Safwat
 */ 
#include "KeyPad.h"	
void H_KeyPad_Init(void)
{
	M_Dio_PinMode(KeyPad_R0_Pin,OUTPUT);
	M_Dio_PinMode(KeyPad_R1_Pin,OUTPUT);
	M_Dio_PinMode(KeyPad_R2_Pin,OUTPUT);
	M_Dio_PinMode(KeyPad_R3_Pin,OUTPUT);
	
	M_Dio_PinMode(KeyPad_C0_Pin,INPUT);
	M_Dio_PinMode(KeyPad_C1_Pin,INPUT);
	M_Dio_PinMode(KeyPad_C2_Pin,INPUT);
	M_Dio_PinMode(KeyPad_C3_Pin,INPUT);
								
	M_Dio_PinWrite(KeyPad_R0_Pin,HIGH);
	M_Dio_PinWrite(KeyPad_R1_Pin,HIGH);
	M_Dio_PinWrite(KeyPad_R2_Pin,HIGH);
	M_Dio_PinWrite(KeyPad_R3_Pin,HIGH);
	
	M_Dio_PullUPRes(KeyPad_C0_Pin,ENABLE);
	M_Dio_PullUPRes(KeyPad_C1_Pin,ENABLE);
	M_Dio_PullUPRes(KeyPad_C2_Pin,ENABLE);
	M_Dio_PullUPRes(KeyPad_C3_Pin,ENABLE);
}
u8 H_KeyPad_Read(void)
{ 
	u8 Local_u8_Reading=Keypad_RELEASED;
	u8 local_u8_Col=0;
	u8 local_u8_Row=0;
	u8 Local_u8_Value=0;	
	#if Keypad_Mode == Type_1
	u8 Local_u8_Arr[4][4]={{'1','2','3','A'},
		                   {'4','5','6','B'},
						   {'7','8','9','C'},
						   {'*','0','#','D'}};
    #elif Keypad_Mode ==Type_2	    
	u8 Local_u8_Arr[4][4]={{'7','8','9','/'},
	                       {'4','5','6','*'},
	                       {'1','2','3','-'},
	                       {'C','0','=','+'}};
    #endif
	
    for(local_u8_Row=KeyPad_R0_Pin;local_u8_Row<=KeyPad_R3_Pin;local_u8_Row ++)
	{
			M_Dio_PinWrite(local_u8_Row,LOW);
			for(local_u8_Col=KeyPad_C0_Pin;local_u8_Col<=KeyPad_C3_Pin;local_u8_Col++)
			{
				Local_u8_Reading=M_Dio_PinRead(local_u8_Col);
				if(Local_u8_Reading==KeyPad_PRESSED)
				{
					_delay_ms(KeyPad_Debouncing_Time);
					if(M_Dio_PinRead(local_u8_Col)==KeyPad_PRESSED)
					{
						while(M_Dio_PinRead(local_u8_Col)==KeyPad_PRESSED)
						Local_u8_Value =Local_u8_Arr[local_u8_Row-KeyPad_R0_Pin][local_u8_Col-KeyPad_C0_Pin];
					}
					
					
				} 
				M_Dio_PinWrite(local_u8_Row,HIGH); 
			}

	}
	return Local_u8_Value;
}
