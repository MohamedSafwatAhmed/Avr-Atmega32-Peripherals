/*
 * Buzzer.c
 *
 * Created: 6/7/2022 10:01:21 PM
 *  Author: Mohamed Safwat
 */ 
#include "Buzzer.h"

void H_Buzzer_Init(void)
{
	M_Dio_PinMode(BUZZER_PIN,OUTPUT);
}
void H_Buzzer_On(void)
{
	M_Dio_PinWrite(BUZZER_PIN,HIGH);
}
void H_Buzzer_Off(void)
{
	M_Dio_PinWrite(BUZZER_PIN,LOW);
}
void H_Buzzer_Tog(void)
{
	H_Buzzer_On();
	_delay_ms(BUZZER_DELAY_TIME_ON);
	H_Buzzer_Off();
	_delay_ms(BUZZER_DELAY_TIME_ON);
}
void H_Buzzer_BeepShort(void)
{
	H_Buzzer_On();
	_delay_ms(BUZZER_DELAY_TIME_ON);
	H_Buzzer_Off();
}
void H_Buzzer_BeepLong(void)
{
	H_Buzzer_On();
	_delay_ms(BUZZER_DELAY_TIME_LONG);
	H_Buzzer_Off();
}
void H_Buzzer_BeepTwice(void)
{
	H_Buzzer_BeepShort();
	_delay_ms(BUZZER_DELAY_TIME_OFF);
	H_Buzzer_BeepShort();
}
void H_Buzzer_BeepTriple(void)
{
	H_Buzzer_BeepShort();
	_delay_ms(BUZZER_DELAY_TIME_OFF);
	H_Buzzer_BeepShort();
	_delay_ms(BUZZER_DELAY_TIME_OFF);
	H_Buzzer_BeepShort();
}