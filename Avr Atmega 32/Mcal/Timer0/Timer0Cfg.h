/*
 * Timer0Cfg.h
 *
 * Created: 6/10/2022 2:45:06 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef TIMER0CFG_H_
#define TIMER0CFG_H_
/*********************_SELECT_TIMER0_MODE********************/
//Option 1-> [Normal_Mode]
//Option 2-> [Ctc_Mode]
#define  Timer0_Mode         Normal_Mode

/*********************_SELECT_FAST_PWM0_MODE********************/
//Option 1-> [Inverted]
//Option 2-> [Non_Inverted]
#define  Fast_Pwm0_Mode         Non_Inverted

/*********************_SELECT_FAST_PWM0_MODE********************/
//Option 1-> [Inverted]
//Option 2-> [Non_Inverted]
#define  Phase_Correct_Pwm0_Mode        Non_Inverted

/*********************_SELECT_PWM0_MODE********************/
//Option 1-> [Fast_Pwm0]
//Option 2-> [Phase_Correct_Pwm0]
#define Pwm0_Mode   Phase_Correct_Pwm0_Mode

/*********************_SELECT_FREQUANCY_********************/
#define  F_OSc                  16 

/*********************_SELECT_TIMER0_PRESCALER********************/
//Option 1-> [1024]
//Option 2-> [256]
#define  Timer0_Prescaler       1024

#endif /* TIMER0CFG_H_ */