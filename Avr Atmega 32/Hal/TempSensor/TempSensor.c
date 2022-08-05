/*
 * TempSensor.c
 *
 * Created: 6/9/2022 10:06:41 PM
 *  Author: Mohamed Safwat
 */ 
/*****************************************_INCLUDES_*********************************************/
#include "TempSensor.h"
/*****************************************_PROTOTYPES_*********************************************/

void H_TempSensor_Init(void)
{
M_Adc_Init();	
}
 u16 H_TempSensor_Read(void)
 {
	 u16 Local_u16_AdcValue = M_Adc_Read();
	 u16 Local_u8_Temp = ((u32)Local_u16_AdcValue *500)/1023;
	 return Local_u8_Temp;
 }
