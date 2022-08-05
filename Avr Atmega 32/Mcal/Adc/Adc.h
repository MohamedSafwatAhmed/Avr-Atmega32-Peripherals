 /*
 * Adc.h
 *
 * Created: 6/3/2022 9:11:52 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef ADC_H_
#define ADC_H_
/*****************************************_INCLUDES_*********************************************/
#include "AdcCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
/*****************************************_MACROS_*********************************************/
#define  ADC_INT      1
#define  ADC_POL      2

#define  AVCC         1
#define AREF_PIN      2
#define _2v56         3
/*****************************************_PROTOTYPES_*********************************************/
void M_Adc_Init(void);
u16  M_Adc_Read(void);

#endif /* ADC_H_ */