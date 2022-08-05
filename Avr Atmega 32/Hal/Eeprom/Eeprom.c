/*
 * Eeprom.c
 *
 * Created: 7/14/2022 12:20:37 AM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "Eeprom.h"
#include "Led.h"
#include "Twi.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*****************************************_FUNCTION_DEFINITION_*********************************************/
void H_Eeprom_Init(void)
{
	M_Twi_Init();
	_delay_ms(1000);

}

void H_Eeprom_Write(u8 Local_u8_Data,u8 Local_u8_Page_Address,u8 Local_u8_Byte_Address)
{
	M_Twi_StartCondition();
	M_Twi_SendSlaveAddressWrite(0x50 |Local_u8_Page_Address);  //Ticke Here
	M_Twi_SendByte(Local_u8_Byte_Address);
	M_Twi_SendByte(Local_u8_Data);
	M_Twi_StopCondition();
}
u8   H_Eeprom_Read(u8 Local_u8_Page_Address,u8 Local_u8_Byte_Address)
{
	u8 local_u8_Data=0;
	M_Twi_StartCondition();
	M_Twi_SendSlaveAddressWrite(0x50 |Local_u8_Page_Address);  //Ticke Here
	M_Twi_SendByte(Local_u8_Byte_Address);
	M_Twi_RepeatStart();
	M_Twi_SendSlaveAddressRead(0x50 |Local_u8_Page_Address);  //Ticke Here
	local_u8_Data=M_Twi_ReadByte();
	M_Twi_StopCondition();
	
	return local_u8_Data;
}	

