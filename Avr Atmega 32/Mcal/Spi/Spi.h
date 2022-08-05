/*
 * Spi.h
 *
 * Created: 6/22/2022 9:52:02 AM
 *  Author: Mohamed Safwat
 */ 


#ifndef SPI_H_
#define SPI_H_
/*****************************************_INCLUDES_*********************************************/
#include "SpiCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
/*****************************************_MACROS_*********************************************/
/////SPCR_REGISTER_PINS////
#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0
/////SPSR_REGISTER_PINS////
#define SPIF 7
#define Master 1
#define Slave 2
/*****************************************_PROTOTYPES_*********************************************/

void M_Spi_Init(void);
u8   M_Spi_Transive(u8);



#endif /* SPI_H_ */