/*
 * Dio.h
 *
 * Created: 5/23/2022 5:25:15 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef DIO_H_
#define DIO_H_
/*********************************************_INCLUDES_*****************************************************************/
#include "DioCfg.h"
#include "BitMath.h"
#include "Reg.h"
#include "StdTypes.h"
/*********************************************_MACROS_********************************************************************/

#define  A   0
#define  B   1
#define  C   2
#define  D   3

#define  PA0_Pin 10
#define  PA1_Pin 11
#define  PA2_Pin 12
#define  PA3_Pin 13
#define  PA4_Pin 14
#define  PA5_Pin 15
#define  PA6_Pin 16
#define  PA7_Pin 17

#define  PB0_Pin 20
#define  PB1_Pin 21
#define  PB2_Pin 22
#define  PB3_Pin 23
#define  PB4_Pin 24
#define  PB5_Pin 25
#define  PB6_Pin 26
#define  PB7_Pin 27

#define  PC0_Pin 30
#define  PC1_Pin 31
#define  PC2_Pin 32
#define  PC3_Pin 33
#define  PC4_Pin 34
#define  PC5_Pin 35
#define  PC6_Pin 36
#define  PC7_Pin 37

#define  PD0_Pin 40
#define  PD1_Pin 41
#define  PD2_Pin 42
#define  PD3_Pin 43
#define  PD4_Pin 44
#define  PD5_Pin 45
#define  PD6_Pin 46
#define  PD7_Pin 47

#define  OUTPUT 1
#define  INPUT  2

#define  HIGH 1
#define  LOW  2

#define  ENABLE   1
#define  DISABLE  2


/*********************************************_PROTOTYPES_*****************************************************************/
void M_Dio_PinMode(u8,u8);
void M_Dio_PinWrite(u8,u8);
u8   M_Dio_PinRead(u8);
void M_Dio_PullUPRes(u8,u8);  
void M_Dio_PortMode(u8,u8);
void M_Dio_PortWrite(u8,u8);


  




#endif /* DIO_H_ */