/*
 * Adc.c
 *
 * Created: 6/3/2022 9:13:05 PM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "Lcd.h"
#include "Adc.h"
#include <avr/interrupt.h>  
#include "Dio.h"
/*****************************************_MACROS_*********************************************/

/*****************************************_PROTOTYPES_*********************************************/
void M_Adc_Init(void)
{
	#if   VREF  ==  AVCC
	ClrBit(ADMUX,7);
	SetBit(ADMUX,6);
	#elif VREF == AREF_PIN
	ClrBit(ADMUX,6);
	ClrBit(ADMUX,7);
	#elif VREF ==_2v56
	SetBit(ADMUX,6);
	SetBit(ADMUX,7);
	#endif
	ClrBit(ADMUX,5);   // to select Right  Adjust
	//TO select the Gain pain of reading PA1 
	ClrBit(ADMUX,4);
	ClrBit(ADMUX,3);
	ClrBit(ADMUX,2);
	ClrBit(ADMUX,1);
	ClrBit(ADMUX,0);
	//To Select 128 As Devision factor->ADC Circuit to 125 K Hz-> 
	SetBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	SetBit(ADCSRA,5);   //To Enable auto Trigger mode
	#if ADC_OPERATION_MODE == ADC_INT
	SetBit(ADCSRA,3);        //To Enable Local interrupt
	SetBit(GICR,6);           //To Enable Global interrupt
    #elif ADC_OPERATION_MODE ==ADC_POL
	SetBit(ADCSRA,7);            //To Enable ADC Circuit  
	#endif
	
}
#if ADC_OPERATION_MODE == ADC_POL
u16  M_Adc_Read(void)
{
	//u16  Not u8 As it return 1023 as max value//
	SetBit(ADCSRA,6);   //To start Conversion 
	while((GetBit(ADCSRA,4))==0); //To Stuck in exit after flag convert to one 
	return ADC_Value;
	// ADCL+(GetBit(ADCH,0) *256) + (GetBit(ADCH,1) *512) ; //To Read The Ten Bits of ADC
}

#elif ADC_OPERATION_MODE == ADC_INT
ISR(ADC_vect)
{
	H_Lcd_WriteNumber(ADC_Value);
}
#endif