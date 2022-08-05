/*
 * Timer1.h
 *
 * Created: 7/4/2022 3:02:14 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
/*****************************************_INCLUDES_*********************************************/
#include "Timer1Cfg.h"
#include "StdTypes.h"
#include "Reg.h"
#include "Dio.h"
/*******************************************_MACROS_*********************************************/

/*****************************************_PROTOTYPES_*********************************************/

void M_Timer1_Pwm1Init(void);
void M_Timer1_Pwm1SetFrequancy(u8);
void M_Timer1_Pwm1SetDutyCycle(u8);
void M_Timer1_Pwm1Start(void);
void M_Timer1_Pwm1Stop(void);
#endif /* TIMER1_H_ */