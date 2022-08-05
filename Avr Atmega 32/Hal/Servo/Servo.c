/*
 * Servo.c
 *
 * Created: 7/5/2022 3:33:47 PM
 *  Author: Mohamed Safwat
 */ 
/************************_INCLUDES_******************/
#include "Servo.h"
/************************_FUNCTION_DEFINATION_******************/

void H_Servo_Init(void)
{
	M_Timer1_Pwm1Init();
	M_Timer1_Pwm1SetFrequancy(50);
}
void H_Servo_Start(void)
{
M_Timer1_Pwm1Start();
	
}
void H_Servo_Stop(void)
{
	M_Timer1_Pwm1Stop();
	
}
void H_Servo_SetAngle(u8 local_u8_Angel)
{
	 f32 Local_f32_DutyCycle=0;
	 Local_f32_DutyCycle=0.0277*local_u8_Angel+5.000;
	 M_Timer1_Pwm1SetDutyCycle(Local_f32_DutyCycle);
}