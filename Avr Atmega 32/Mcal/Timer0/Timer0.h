 /*
 * Timer0.h
 *
 * Created: 6/10/2022 2:44:48 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
/*****************************************_INCLUDES_*********************************************/
#include "Timer0Cfg.h"
#include "StdTypes.h"
#include "Reg.h"
#include "Dio.h"
#include <avr/interrupt.h>
/*****************************************_MACROS_*********************************************/

#define Normal_Mode			 1
#define Ctc_Mode			 2
#define      Inverted		 1
#define  Non_Inverted		 2
#define Fast_Pwm0            1
#define Phase_Correct_Pwm0   2


/*****************************************_PROTOTYPES_*********************************************/
void M_Timer0_Init(void);
void M_Timer0_SetTime(u32);
void M_Timer0_Start(void);
void M_Timer0_Stop(void);
void M_Timer0_SetCallBack(void (*)(void));

void M_Timer0_Pwm0Init(void);
void M_Timer0_Pwm0SetDutyCycle(u8);
void M_Timer0_Pwm0Start(void);
void M_Timer0_Pwm0Stop(void);

#endif /* TIMER0_H_ */