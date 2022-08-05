/*
 * Twi.c
 *
 * Created: 6/24/2022 10:04:57 PM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "Twi.h"
/*****************************************_FUNCTION_DEFINITION_*********************************************/
 
 void M_Twi_Init(void)
{
	#if TWI_MODE  == TWI_MASTER
	TWBR=12;  //to choose Fscl =400 KHZ
	#elif TWI_MODE  == TWI_SLAVE
	TWAR==0b00000010;    //To select the slave add =1 and disable general call      
	#endif
	SetBit(TWCR,2);  //to enable TWI circuit
}
void M_Twi_StartCondition(void)
{
	SetBit(TWCR,5);   //To enable circuit of start condition and check if bus is free
	SetBit(TWCR,7); 
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != START_ACK);  //To check If the Start condition transmit And With 0xF8 to write the MSB  
	
}
void M_Twi_SendSlaveAddressWrite(u8 local_u8_Address)
{
	TWDR =(local_u8_Address <<1);  // To send address in 7 bit MSB and send Write oprand in MSB 
	SetBit(TWCR,7);                //To clear the flag bit
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_WR_ACK);
}
void M_Twi_SendSlaveAddressRead(u8 local_u8_Address)
{
	TWDR =(local_u8_Address << 1) | 1;//shifting address and send one in LSB :_)
	SetBit(TWCR,7); 
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_RD_ACK);
}
void M_Twi_SendByte(u8 Local_u8_Data)
{
	TWDR=Local_u8_Data;
	ClrBit(TWCR,5);
	SetBit(TWCR,7); 
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != WR_BYTE_ACK);
}
u8 M_Twi_ReadByte(void)
{
	ClrBit(TWCR,5);//Problem in order here :-) 
	ClrBit(TWCR,4);//Problem in order here :-) 
	SetBit(TWCR,6);//Problem in order here :-) 
	SetBit(TWCR,7);   //from Datas heeet page 188
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != RD_BYTE_WITH_ACK);  //
	return TWDR;
}
void M_Twi_RepeatStart(void)
{
	SetBit(TWCR,5);
	SetBit(TWCR,7); 
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != REP_START_ACK);
}
void M_Twi_StopCondition(void)
{
	SetBit(TWCR,4);
	SetBit(TWCR,7); //to set flag bit with 1
	//while(GetBit(TWCR,7) == 0);
}
void M_Twi_Ack(void)
{
	SetBit(TWCR,6); //Ack bit
	SetBit(TWCR,7);
	while(GetBit(TWCR,7) == 0);
}
