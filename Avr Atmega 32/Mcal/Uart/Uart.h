/*
 * Uart.h
 *
 * Created: 6/20/2022 9:27:51 AM
 *  Author: Mohamed Safwat
 */ 


#ifndef UART_H_
#define UART_H_
/********************************_INCLUDES_************************/
#include "UartCfg.h"
#include "StdTypes.h"
#include "Reg.h"
#include "BitMath.h"
/********************************_MACROS_************************/

#define  Parity_Disable  1
#define  Parity_Odd      2
#define  Parity_Even     3

/********************************_PROTOTYPES_************************/
void M_Uart_Init(void);
void M_Uart_Transmit(u8);
u8   M_Uart_Rec(void);






#endif /* UART_H_ */