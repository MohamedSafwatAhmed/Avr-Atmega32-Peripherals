/*
 * Spi.c
 *
 * Created: 6/22/2022 9:52:36 AM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "Spi.h"
/*****************************************_FUNCTION_DEFINITION_*********************************************/
void M_Spi_Init(void)
{ 
	//To choose mode
  #if Mode ==Master
   SetBit(SPCR,MSTR); //Select Master 
   SetBit(DDRB,5);    //To set MOSI Pin as output 
   SetBit(DDRB,4);    //To set SS Pin as output
   SetBit(DDRB,7);    // To set Sck Pin as output 
   ClrBit(DDRB,6);    //To set MISo pin as input 
  #elif Mode == Slave 
    ClrBit(SPCR,MSTR); //Select Slave
    ClrBit(DDRB,5);    //To set MOSI Pin as output
    ClrBit(DDRB,4);    //To set SS Pin as input
    ClrBit(DDRB,7);    // To set Sck Pin as input
    SetBit(DDRB,6);    //To set MISO pin as input
	#endif
	SetBit(SPCR,SPR0);  //To Choose Division factor as fosc/128
	SetBit(SPCR,SPR1);
	
	SetBit(SPCR,DORD);   // TO set Data order to LSB
	SetBit(SPCR,SPE);   //To enable SPI Protocol
     
}

u8  M_Spi_Transive(u8 local_u8_Send)
{
	SPDR=local_u8_Send;
	while(GetBit(SPSR,SPIF)==0);
	return SPDR;
}