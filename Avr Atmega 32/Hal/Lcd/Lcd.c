/*
 * Lcd.c
 *
 * Created: 5/24/2022 10:36:08 PM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "Lcd.h"
/*****************************************_MACROS_***********************************************/

/*****************************************_PROTOTYPES_*******************************************/

void H_Lcd_Init(void)
{
	#if    Lcd_Mode    ==    _8_Bit_Mode
	M_Dio_PinMode(Lcd_data0_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data1_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data2_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data3_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data4_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data5_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data6_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data7_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_Rs_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_En_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_Rw_Pin,OUTPUT);
	M_Dio_PinWrite(Lcd_Rw_Pin,LOW);
	_delay_ms(1000);
	H_Lcd_WriteCommand(Lcd_8_Bit_Mode);
	H_Lcd_WriteCommand(Lcd_Display_On_Cursor_off);
	H_Lcd_WriteCommand(Lcd_Clear);
	H_Lcd_WriteCommand(Lcd_Return_Home);
	
	#elif Lcd_Mode    ==    _4_Bit_Mode
	M_Dio_PinMode(Lcd_data4_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data5_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data6_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_data7_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_Rs_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_En_Pin,OUTPUT);
	M_Dio_PinMode(Lcd_Rw_Pin,OUTPUT);
	M_Dio_PinWrite(Lcd_Rw_Pin,LOW);
	_delay_ms(1000);
	H_Lcd_WriteCommand(Lcd_4_Bit_Mode_1);
	H_Lcd_WriteCommand(Lcd_4_Bit_Mode_2);
	H_Lcd_WriteCommand(Lcd_4_Bit_Mode_3);
	H_Lcd_WriteCommand(Lcd_Display_On_Cursor_off);
	H_Lcd_WriteCommand(Lcd_Clear);
	H_Lcd_WriteCommand(Lcd_Return_Home);
	#endif
}

void H_Lcd_WriteCharacter(u8 Local_u8_Character)
{
	#if Lcd_Mode == _8_Bit_Mode
	M_Dio_PinWrite(Lcd_Rs_Pin,HIGH);
	Lcd_Data_Port=Local_u8_Character;
	M_Dio_PinWrite(Lcd_En_Pin,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(Lcd_En_Pin,LOW);
	_delay_ms(5);
	
	#elif Lcd_Mode  ==  _4_Bit_Mode
	M_Dio_PinWrite(Lcd_Rs_Pin,HIGH);
	Lcd_Data_Port=(Local_u8_Character & 0xF0) | (Lcd_Data_Port & 0x0F);
	M_Dio_PinWrite(Lcd_En_Pin,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(Lcd_En_Pin,LOW);
	_delay_ms(1);
	M_Dio_PinWrite(Lcd_Rs_Pin,HIGH);
	Lcd_Data_Port=(Local_u8_Character <<4) | (Lcd_Data_Port & 0x0F);
	M_Dio_PinWrite(Lcd_En_Pin,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(Lcd_En_Pin,LOW);
	_delay_ms(5);
	
	#endif
}
void H_Lcd_WriteCommand(u8 Local_u8_Command)
{
	#if Lcd_Mode    ==    _8_Bit_Mode
	M_Dio_PinWrite(Lcd_Rs_Pin,LOW);
	Lcd_Data_Port = Local_u8_Command;
	M_Dio_PinWrite(Lcd_En_Pin,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(Lcd_En_Pin,LOW);
	_delay_ms(5);
	
	#elif Lcd_Mode   ==   _4_Bit_Mode
	M_Dio_PinWrite(Lcd_Rs_Pin,LOW);
	Lcd_Data_Port =(Local_u8_Command & 0xF0) | (Lcd_Data_Port &0x0F);
	M_Dio_PinWrite(Lcd_En_Pin,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(Lcd_En_Pin,LOW);
	_delay_ms(1);
	Lcd_Data_Port = (Local_u8_Command << 4) | (Lcd_Data_Port & 0x0F);
	M_Dio_PinWrite(Lcd_En_Pin,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(Lcd_En_Pin,LOW);
	_delay_ms(5);
	#endif
}
void H_Lcd_WriteString(u8* Local_u8_Ptr)
{   
	u8 Local_u8_Counter=0;
	while(Local_u8_Ptr[Local_u8_Counter] !=Null_)
	{
		H_Lcd_WriteCharacter(Local_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter ++;
	}
}
void H_Lcd_WriteNumber(s32 Local_s32_Number)
{
	u8 Local_u8_Arr [10] = {0};
	s8 Local_s8_Counter  = 0;
	u8 Local_u8_Digit    = 0;
	if(Local_s32_Number == 0)
	{
		H_Lcd_WriteCharacter('0');
	}
	else
	{
		if(Local_s32_Number < 0)
		{
			H_Lcd_WriteCharacter('-');
			Local_s32_Number = Local_s32_Number * -1;
		}
		while(Local_s32_Number != 0)
		{
			Local_u8_Digit = Local_s32_Number % 10;
			Local_u8_Arr[Local_s8_Counter] = Local_u8_Digit;
			Local_s8_Counter++;
			Local_s32_Number = Local_s32_Number / 10;
		}
		Local_s8_Counter--;
		while(Local_s8_Counter >= 0)
		{
			H_Lcd_WriteCharacter(Local_u8_Arr[Local_s8_Counter] + 48);
			Local_s8_Counter--;
		}
	}
}
void H_Lcd_Clr(void)
{
	H_Lcd_WriteCommand(Lcd_Clear);
}

void H_Lcd_GoTO(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 local_u_Arr[2] ={0x80,0xC0};
	H_Lcd_WriteCommand(local_u_Arr[Local_u8_Row]+Local_u8_Col);
}

void H_Lcd_ShiftRight(void)
{
 H_Lcd_WriteCommand(Lcd_Shift_Right);
}
void H_Lcd_ShiftLeft(void)
{
  H_Lcd_WriteCommand(Lcd_Shift_Left);
	
}