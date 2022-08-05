/*
 * DcMotor.c
 *
 * Created: 6/23/2022 1:30:41 PM
 *  Author: Mohamed Safwat
 */ 

/**************************_INCLUDES_****************/
#include "DcMotor.h"
/**************************_MACROS_****************/

/**************************_FUNCTION_DEFINITION_****************/
void H_DcMotor_Init(void)
{
	M_Dio_PinMode(DCMotor_Pin1,OUTPUT);
	M_Dio_PinMode(DCMotor_Pin2,OUTPUT);
	M_Timer0_Pwm0Init();
	
}
void H_DcMotor_SetDirection(u8 Local_u8_Direction)
{
	switch(Local_u8_Direction)
	{
		case CLK :
		M_Dio_PinWrite(DCMotor_Pin1,HIGH);
		M_Dio_PinWrite(DCMotor_Pin2,LOW);
		break;
		case ACLK :
		M_Dio_PinWrite(DCMotor_Pin1,LOW);
		M_Dio_PinWrite(DCMotor_Pin2,HIGH);
		break;
		default:                    break;
		
	}

	
}
void H_DcMotor_SetSpeed(u8 local_u8_Speed)
{ 
	M_Timer0_Pwm0SetDutyCycle(local_u8_Speed); //MAPING should be here but the DC motor have no DataSheet to deal with
}
void H_DcMotor_Start(void)
{
 M_Timer0_Pwm0Start();	
}
void H_DcMotor_Stop(void)
{
 M_Timer0_Pwm0Stop();
}
