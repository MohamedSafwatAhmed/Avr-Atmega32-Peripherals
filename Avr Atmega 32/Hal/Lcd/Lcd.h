/*
 * Lcd.h
 *
 * Created: 5/24/2022 10:35:45 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef LCD_H_
#define LCD_H_
/*****************************************_INCLUDES_*********************************************/
#include "LcdCfg.h"
#include "Dio.h"
#include "StdTypes.h"
# define F_CPU 16000000UL
#include <util/delay.h>
/*****************************************_MACROS_***********************************************/
#define _8_Bit_Mode                      1
#define _4_Bit_Mode                      2
#define Lcd_8_Bit_Mode                 0x38
#define Lcd_4_Bit_Mode_1               0x33
#define Lcd_4_Bit_Mode_2               0x32
#define Lcd_4_Bit_Mode_3               0x28

#define  Lcd_Display_On_Cursor_off       0x0c
#define  Lcd_Clear                       0x01
#define  Lcd_Return_Home                 0x02
#define  Null_                           '\0'
#define  Lcd_Shift_Right                 0x05
#define  Lcd_Shift_Left                  0x07

/*****************************************_PROTOTYPES_*******************************************/
void H_Lcd_Init(void);
void H_Lcd_WriteCharacter(u8);
void H_Lcd_WriteCommand(u8);
void H_Lcd_WriteString(u8*);
void H_Lcd_WriteNumber(s32);
void H_Lcd_Clr(void);
void H_Lcd_GoTO(u8,u8);
void H_Lcd_ShiftRight(void);
void H_Lcd_ShiftLeft(void);

#endif /* LCD_H_ */