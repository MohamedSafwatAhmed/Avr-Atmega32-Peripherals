  /*
 * KeyPad.h
 *
 * Created: 5/27/2022 7:46:01 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
/*****************************************_INCLUDES_*********************************************/
#include "KeyPadCfg1.h"
#include "StdTypes.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*****************************************_MACROS_***********************************************/
#define KeyPad_PRESSED 0
#define Keypad_RELEASED 1
#define Type_1 1
#define Type_2 2
/*****************************************_PROTOTYPES_*******************************************/

/*****************************************_SELECT_DELAT_TIME_************************************/

/*****************************************_SELECT_LED_PIN_***************************************/
void H_KeyPad_Init(void);
u8 H_KeyPad_Read(void);
 



#endif /* KEYPAD_H_ */