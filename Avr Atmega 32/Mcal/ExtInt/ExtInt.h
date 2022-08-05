/*
 * ExtInt.h
 *
 * Created: 6/7/2022 1:26:26 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_
/*****************************************_INCLUDES_*********************************************/
#include "ExtIntCfg.h"
#include "BitMath.h"
#include "Reg.h"
#include "Dio.h"
#include <avr/interrupt.h>  
/*****************************************_MACROS_*********************************************/

#define   Rising_Edge         1
#define   Low_Level           2
#define   Logical_Change      3
#define   Falling_Edge        4
/*****************************************_PROTOTYPES_*********************************************/
void M_ExtInt_Int0Init(void);
void M_Ext_SetCallBack(void (*)(void));


#endif /* EXTINT_H_ */