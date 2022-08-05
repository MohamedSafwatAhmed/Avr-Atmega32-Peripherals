/*
 * Eeprom.h
 *
 * Created: 7/14/2022 12:20:55 AM
 *  Author: Mohamed Safwat
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_

/*****************************************_INCLUDES_*********************************************/
#include "EepromCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
/*****************************************_MACROS_***********************************************/

/*****************************************_PROTOTYPES_*******************************************/

void H_Eeprom_Init(void);
void H_Eeprom_Write(u8,u8,u8);
u8   H_Eeprom_Read(u8,u8);

#endif /* EEPROM_H_ */