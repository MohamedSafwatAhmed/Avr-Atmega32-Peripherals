/*
 * Push.h
 *
 * Created: 6/7/2022 12:10:41 AM
 *  Author: Mohamed Safwat
 */ 


#ifndef PUSH_H_
#define PUSH_H_
/******************************************_SELECT_PUSH_BUTTON_MODE_*********************************************/
// option 1 -> [ ACTIVE_HIGH ]
// option 2 -> [ ACTIVE_LOW  ]
#define PUSH_BUTTON_MODE       ACTIVE_HIGH
/**********************************_SELECT_PUSH_BUTTON_DEBOUNCING_TIME_******************************************/
#define PUSH_BUTTON_DEBOUNCING_TIME    50
/*********************************************_SELECT_PB_PIN_****************************************************/
#define PUSH_BUTTON0_PIN               PB0_Pin
#define PUSH_BUTTON1_PIN               PD6_Pin
#define PUSH_BUTTON2_PIN               PD2_Pin


#endif /* PUSH_H_ */