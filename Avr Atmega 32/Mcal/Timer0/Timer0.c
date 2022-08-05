/*
 * Timer0.c
 *
 * Created: 6/10/2022 2:44:33 PM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "Timer0.h"
u32 Timer0_u32_NumOfOverFlow=0;
u8 Timer0_u8_RemTicks=       0;
u32 Timer0_u32_NumOfCompareMatch=0;
void (*CallBack)(void); //pointer to function
/*****************************************_PROTOTYPES_*********************************************/
void M_Timer0_Init(void)
{
	#if Timer0_Mode ==Normal_Mode
 //To Select Normal Mode
  ClrBit(TCCR0,3);
  ClrBit(TCCR0,6);
  SetBit(TIMSK,0);  //To Enable timer0 overflow int 
  #elif Timer0_Mode ==Ctc_Mode
  //To Select CTC Mode
  SetBit(TCCR0,3);
  ClrBit(TCCR0,6);
  SetBit(TIMSK,1);  //To Enable timer0 Compare match interrupt
  #endif
  
  SetBit(SREG,7);   //To Enable Global register for interrupts
  
}
void M_Timer0_SetTime(u32 Local_u8_DesiredTime)
{
	#if Timer0_Mode ==Normal_Mode
	u32 Local_32_TickTime=Timer0_Prescaler/F_OSc;   //result in microsecond
	u32 Local_u32_Total_Tickes =(Local_u8_DesiredTime*1000)/Local_32_TickTime;
	Timer0_u32_NumOfOverFlow=Local_u32_Total_Tickes/256;
	u8 Timer0_u8_RemTicks    =Local_u32_Total_Tickes%256;
	if(Timer0_u8_RemTicks !=0)
	{
		TCNT0         =256-Timer0_u8_RemTicks;
		Timer0_u32_NumOfOverFlow ++;
	}
	#elif Timer0_Mode ==Ctc_Mode
    u32 Local_32_TickTime=Timer0_Prescaler/F_OSc;
	u32 Local_u32_Total_Tickes =(Local_u8_DesiredTime*1000)/Local_32_TickTime;
	u8 Local_u8_DevisionFactor =255;
	while(Local_u32_Total_Tickes % Local_u8_DevisionFactor) //to choose int value
	{
		Local_u8_DevisionFactor --;
	}
	    Timer0_u32_NumOfCompareMatch =Local_u32_Total_Tickes/Local_u8_DevisionFactor;
	    OCR0                        =Local_u8_DevisionFactor-1;     
	#endif
}

void M_Timer0_Start(void)
{
	//TO select Prescaler -> 1024
	#if Timer0_Prescaler ==1024
	SetBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#elif Timer0_Prescaler ==256
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#endif
}
void M_Timer0_Stop(void)
{
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	ClrBit(TCCR0,2);
}

void M_Timer0_Pwm0Init(void)
{
	SetBit(DDRB,3) ;  //To make PB3 -> Output  
	#if Pwm0_Mode == Fast_Pwm0
	SetBit(TCCR0,3); // To enable Fast PWM
	SetBit(TCCR0,6);
	////
		#if Fast_Pwm0_Mode == Inverted
		SetBit(TCCR0,4);
		SetBit(TCCR0,5);
		#elif Fast_Pwm0_Mode == Non_Inverted
		ClrBit(TCCR0,4);
		SetBit(TCCR0,5);
		#endif
	#elif Pwm0_Mode ==Phase_Correct_Pwm0
	ClrBit(TCCR0,3); // To enable Phase correct PWM
	SetBit(TCCR0,6);
		#if Phase_Correct_Pwm0_Mode == Inverted
		SetBit(TCCR0,4);
		SetBit(TCCR0,5);
		#elif Phase_Correct_Pwm0_Mode == Non_Inverted
		ClrBit(TCCR0,4);
		SetBit(TCCR0,5);
		#endif
	#endif
	
}
void M_Timer0_Pwm0SetDutyCycle(u8 Local_u8_DutyCycle)
{
	#if Pwm0_Mode == Fast_Pwm0
		#if Fast_Pwm0_Mode ==Inverted
		OCR0=255-((256/100)*Local_u8_DutyCycle);  
		#elif Fast_Pwm0_Mode ==Non_Inverted
		OCR0=(((Local_u8_DutyCycle*256)/100)-1);
		#endif
	#elif Pwm0_Mode ==Phase_Correct_Pwm0
		#if Phase_Correct_Pwm0_Mode ==Inverted
	    OCR0=255-((255/100)*Local_u8_DutyCycle);   
		#elif Phase_Correct_Pwm0_Mode ==Non_Inverted
		OCR0=((Local_u8_DutyCycle*255)/100);
		#endif
	#endif
}
void M_Timer0_Pwm0Start(void)
{
    M_Timer0_Start();	
}
void M_Timer0_Pwm0Stop(void)
{
	M_Timer0_Stop();
}

void M_Timer0_SetCallBack(void (*ptr)(void))
{
	CallBack=ptr;
}
 #if Timer0_Mode == Normal_Mode
ISR(TIMER0_OVF_vect)
{
	static u32 Local_u32_Counter=0;
	Local_u32_Counter++;
	if(Local_u32_Counter==Timer0_u32_NumOfOverFlow)
	{
		CallBack();
		Local_u32_Counter=0;
		TCNT0 =256-Timer0_u8_RemTicks;
	}
}

#elif Timer0_Mode == Ctc_Mode
ISR(TIMER0_COMP_vect)
{
	static u32 Local_u32_Counter=0;
	Local_u32_Counter++;
	if(Local_u32_Counter==Timer0_u32_NumOfCompareMatch)
	{
		CallBack();
		Local_u32_Counter=0;
		
	}
	
}
#endif
