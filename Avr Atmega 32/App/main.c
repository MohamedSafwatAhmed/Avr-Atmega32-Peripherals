/*****************************************_INCLUDES_*********************************************/
#include "Dio.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "Reg.h"
#include "PushButton.h"
#include "Buzzer.h"
#include "Led.h"
#include "Lcd.h"
#include "KeyPad.h"
#include "Ssd.h"
#include "Adc.h"
#include "TempSensor.h"
#include "Timer0.h"
#include "Uart.h"
#include "Spi.h"
#include "DcMotor.h"
#include "Timer1.h"
#include "Wdt.h"
#include "Servo.h"
#include "Twi.h"
#include "Eeprom.h"
#include "ExtInt.h"    
/*****************************************_MACROS_***********************************************/
#define F_CPU 16000000UL
#include <util/delay.h>
/****************************************_FUNCTIONS_********************************************/
void A_ExtInt0_Excuation(void);
void A_Timer0_Excution(void);
/***********************************************************************************************/
int main(void)
{
	
	M_Timer0_Init();
	M_Timer0_SetTime(1000);
	M_Timer0_Start();
	while(1)
	 {	
		 M_Timer0_SetCallBack(A_Timer0_Excution);
		 ClrBit(PORTC,7);
	 }
 }	

void A_ExtInt0_Excution(void)
{
	
}
void A_Timer0_Excution(void)
{
  SetBit(DDRC,7);
 SetBit(PORTC,7);	
}