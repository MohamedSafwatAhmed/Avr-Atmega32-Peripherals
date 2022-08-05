/*
 * Ssd.h
 *
 * Created: 6/5/2022 11:48:02 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef SSD_H_
#define SSD_H_
/*****************************************_INCLUDES_*********************************************/
#include "SsdCfg.h"
#include "StdTypes.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*****************************************_MACROS_***********************************************/
#define  Ssd_Right 1
#define  Ssd_Left   2

/*****************************************_PROTOTYPES_*******************************************/
void H_Ssd_Init(void);
void H_Ssd_Write(u8);
 void H_Ssd_CounterUp(u8);
 void H_Ssd_CounterDown(u8);
/*****************************************_SELECT_DELAT_TIME_************************************/

/*****************************************_SELECT_LED_PIN_***************************************/


#endif /* SSD_H_ */