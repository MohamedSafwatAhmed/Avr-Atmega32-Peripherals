/*
 * Wdt.c
 *
 * Created: 7/5/2022 12:58:48 PM
 *  Author: Mohamed Safwat
 */ 
/******************************_INCLUDES_*******************************/
#include "Wdt.h"
/*******************************_MACROS_*******************************/

/***************************_FUNCTION_DEFINITIONS_**********************/
void M_Wdt_Init(void)
{
	SetBit(WDTCR,3);  // To enable Circuit of watch Dog Timer 
	//to select Window time= 2.1 Second 
	SetBit(WDTCR,0);
	SetBit(WDTCR,1);
	SetBit(WDTCR,2);
}
void M_Wdt_Refresh(void)
{
	asm("WDR");
}