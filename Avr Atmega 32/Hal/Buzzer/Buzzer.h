/*
 * Buzzer.h
 *
 * Created: 6/7/2022 10:01:40 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

/*************************************************_INCLUDES_********************************************/
#include "BuzzerCfg.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/**************************************************_MACROS_*********************************************/

/************************************************_PROTOTYPES_********************************************/
void H_Buzzer_Init(void);
void H_Buzzer_On(void);
void H_Buzzer_Off(void);
void H_Buzzer_Tog(void);
void H_Buzzer_BeepShort(void);
void H_Buzzer_BeepLong(void);
void H_Buzzer_BeepTwice(void);
void H_Buzzer_BeepTriple(void);





#endif /* BUZZER_H_ */