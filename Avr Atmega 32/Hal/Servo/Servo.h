/*
 * Servo.h
 *
 * Created: 7/5/2022 3:33:11 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef SERVO_H_
#define SERVO_H_
/********************_INCLUDES_*********/
#include "ServoCfg.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "Timer1.h"
/********************_PROTOTYPES_*********/
void H_Servo_Init(void);
void H_Servo_Start(void);
void H_Servo_SetAngle(u8);

#endif /* SERVO_H_ */