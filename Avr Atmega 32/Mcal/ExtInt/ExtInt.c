/*
 * ExtInt.c
 *
 * Created: 6/7/2022 1:26:05 PM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "ExtInt.h"
void (* CallBack)(void);
/*****************************************_MACROS_*********************************************/

/*****************************************_PROTOTYPES_*********************************************/
void M_ExtInt_Int0Init(void)

{
	#if Sense_Control == Rising_Edge 
	SetBit(MCUCR,0);
	SetBit(MCUCR,1);
	#elif Sense_Control == Low_Level
	ClrBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#elif Sense_Control == Logical_Change
	SetBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#elif Sense_Control == Falling_Edge
	ClrBit(MCUCR,0);
	SetBit(MCUCR,1);
	#endif
	SetBit(GICR,6); //To Enable local Interrupt
	SetBit(SREG,7); //To Enable Global Interrupt
	
}
void M_Ext_SetCallBack(void (*Ptr)(void) )
{
  CallBack=Ptr	; 
}
ISR(INT0_vect)
{
	CallBack();
}