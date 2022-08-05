/*
 * Timer1.c
 *
 * Created: 7/4/2022 3:01:45 PM
 *  Author: Mohamed Safwat
 */ 
/******************************_INCLUDES_*******************************/
#include "Timer1.h"
/*******************************_MACROS_*******************************/

/***************************_FUNCTION_DEFINITIONS_**********************/

void M_Timer1_Pwm1Init(void)
{
	
 //To Make PD5_Pin as output
 SetBit(DDRD,5);    
 //to Select mode 14 
 ClrBit(TCCR1A,0);
 SetBit(TCCR1A,1);	
 SetBit(TCCR1B,3);
 SetBit(TCCR1B,4);
 // TO Choose Non Inverted Mode And generate PWM at OC1A Pin
 ClrBit(TCCR1A,6);
 SetBit(TCCR1A,7);
 
}
void M_Timer1_Pwm1SetFrequancy(u8 local_u8_Frequency)
{
	ICR1=((F_OSc*1000000/Timer1_Prescaler)/local_u8_Frequency);
}
void M_Timer1_Pwm1SetDutyCycle(u8 local_u8_DutyCycle)
{
	//fast Pwm Non_Inverted 
OCR1A=(((local_u8_DutyCycle * ICR1) / 100) -1);
}
void M_Timer1_Pwm1Start(void)
{	
 #if Timer1_Prescaler == 256			
  ClrBit(TCCR1B,0);
  ClrBit(TCCR1B,1);
  SetBit(TCCR1B,2);
  
  #endif
  
}				 
void M_Timer1_Pwm1Stop(void)
{
	ClrBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	ClrBit(TCCR1B,2);
}
