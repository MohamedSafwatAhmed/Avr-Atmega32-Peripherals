/*
 * Uart.c
 *
 * Created: 6/20/2022 9:27:23 AM
 *  Author: Mohamed Safwat
 */ 
/********************************_INCLUDES_************************/

#include "Uart.h"

void M_Uart_Init(void)
{
	ClrBit(DDRD,0);   //To enable circuit for Rx
	SetBit(DDRD,1);   //To enable circuit for Tx0
 u8 local_u8_UCSRC =0b10000000;
//to Select Character size =8 bits
 SetBit(local_u8_UCSRC,1);
 SetBit(local_u8_UCSRC,2);
 ClrBit(UCSRB,2);
 //to Select Asynchronous mode
 ClrBit(local_u8_UCSRC,6);
 #if Parity_Mode == Parity_Disable
 ClrBit(local_u8_UCSRC,4);
 ClrBit(local_u8_UCSRC,5);
 #elif Parity_Mode == Parity_Odd
  SetBit(local_u8_UCSRC,4);
  SetBit(local_u8_UCSRC,5);
 #elif Parity_Mode == Parity_Even
  ClrBit(local_u8_UCSRC,4);
  SetBit(local_u8_UCSRC,5);
 #endif
 ClrBit(local_u8_UCSRC,3);          //to Select one stop bit
 UBRRL = ((u32)F_Osc*1000000 / ((u32)16 * Baud_Rate))-1;
 UCSRC =local_u8_UCSRC;             // Tick Here :-)
 SetBit(UCSRB,4);                   //to enable rx.ciruit
 SetBit(UCSRB,3);                   // to enable tx.circuit
 
 	
}
void M_Uart_Transmit(u8 Local_u8_Data)
{
	UDR =Local_u8_Data;
	while(GetBit(UCSRA,6)==0);
}
u8  M_Uart_Rec(void)
{
	while(GetBit(UCSRA,7)==0);
	return UDR;
}

