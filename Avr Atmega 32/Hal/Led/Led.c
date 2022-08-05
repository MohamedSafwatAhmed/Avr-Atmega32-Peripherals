/*
 * Led.c
 *
 * Created: 5/24/2022 3:59:27 PM
 *  Author: Mohamed Safwat
 */ 


#include "Led.h"
#define F_CPU 16000000UL
#include <util/delay.h>
void H_led_Init(u8 Local_u8_LedPin)
{
	M_Dio_PinMode(Local_u8_LedPin,OUTPUT);
}
void H_led_On(u8 Local_u8_LedPin)
{
	M_Dio_PinWrite(Local_u8_LedPin,HIGH);
}
void H_led_Off(u8 Local_u8_LedPin)
{
	M_Dio_PinWrite(Local_u8_LedPin,LOW);
	
}

void H_led_Togg(u8 Local_u8_LedPin)
{
	M_Dio_PinWrite(Local_u8_LedPin,HIGH);
	_delay_ms(2000);
	M_Dio_PinWrite(Local_u8_LedPin,LOW);
	_delay_ms(2000);
}