/*
 * TempSensor.h
 *
 * Created: 6/9/2022 10:07:06 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_
/*****************************************_INCLUDES_*********************************************/
#include "TempSensorCfg.h"
#include "Adc.h"
#include "StdTypes.h"
/*****************************************_Prototypes_*********************************************/
void H_TempSensor_Init(void);
u16 H_TempSensor_Read(void);
 



#endif /* TEMPSENSOR_H_ */