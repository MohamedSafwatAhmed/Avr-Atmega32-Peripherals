/*
 * DcMotor.h
 *
 * Created: 6/23/2022 1:30:11 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_
/**************************_INCLUDES_****************/
#include "DcMotorCfg.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "Dio.h"
#include "Timer0.h"
/**************************_MACROS_****************/
#define CLK    1
#define ACLK   2
/**************************_PROTOTYPES_****************/
void H_DcMotor_Init(void);
void H_DcMotor_SetDirection(u8);
void H_DcMotor_SetSpeed(u8);
void H_DcMotor_Start(void);
void H_DcMotor_Stop(void);





#endif /* DCMOTOR_H_ */