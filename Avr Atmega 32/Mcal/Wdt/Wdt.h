/*
 * Wdt.h
 *
 * Created: 7/5/2022 12:57:53 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef WDT_H_
#define WDT_H_

/******************************_INCLUDES_*******************************/
#include "WdtCfg1.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
/*******************************_MACROS_*******************************/

/***************************_FUNCTION_PROTOTYPES_**********************/
void M_Wdt_Init(void);
void M_Wdt_Refresh(void);



#endif /* WDT_H_ */