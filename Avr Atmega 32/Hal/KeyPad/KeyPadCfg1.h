/*
 * KeyPadCfg1.h
 *
 * Created: 5/27/2022 7:46:58 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef KEYPADCFG1_H_
#define KEYPADCFG1_H_

/******************************SELECT_KEYPAD_Mode****************/
//option ->[Type_1]
//option ->[Type_2]

#define Keypad_Mode Type_1
/******************************SELECT_KEYPAD_PIN****************/
 #define KeyPad_R0_Pin PC3_Pin
 #define KeyPad_R1_Pin PC4_Pin
 #define KeyPad_R2_Pin PC5_Pin
 #define KeyPad_R3_Pin PC6_Pin
 
 #define KeyPad_C0_Pin PB4_Pin
 #define KeyPad_C1_Pin PB5_Pin
 #define KeyPad_C2_Pin PB6_Pin
 #define KeyPad_C3_Pin PB7_Pin
 
 #define KeyPad_Debouncing_Time 80

#endif /* KEYPADCFG1_H_ */