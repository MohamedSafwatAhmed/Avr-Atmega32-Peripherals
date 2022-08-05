/*
 * LcdCfg.h
 *
 * Created: 5/24/2022 10:36:56 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef LCDCFG_H_
#define LCDCFG_H_
#include "Dio.h"
/*****************************************_SELECT_LCD_MODE_************************************/
//Option of operation mode:
//1-[_8_Bit_Mode]
//2-[_4_Bit_Mode]
#define Lcd_Mode    _4_Bit_Mode
/*****************************************_SELECT_LED_PIN_***************************************/
                          /*****************_DATA_PIN_***************/
#define  Lcd_Data_Port PORTA
#define  Lcd_data0_Pin PA0_Pin
#define  Lcd_data1_Pin PA1_Pin
#define  Lcd_data2_Pin PA2_Pin
#define  Lcd_data3_Pin PA3_Pin
#define  Lcd_data4_Pin PA4_Pin
#define  Lcd_data5_Pin PA5_Pin
#define  Lcd_data6_Pin PA6_Pin
#define  Lcd_data7_Pin PA7_Pin
                          /*****************_ENABE_PIN_***************/

#define  Lcd_Rs_Pin    PB1_Pin
#define  Lcd_Rw_Pin    PB2_Pin
#define  Lcd_En_Pin    PB3_Pin




#endif /* LCDCFG_H_ */