/*
 * Reg.h
 *
 * Created: 5/20/2022 1:51:33 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef REG_H_
#define REG_H_
#include "StdTypes.h"
/********************************************_DIO_REGISTERS_*******************************************************/
#define   PINA        *(volatile u8*)0x39
#define   DDRA        *(volatile u8*)0x3A
#define   PORTA       *(volatile u8*)0x3B
 
#define   PINB        *(volatile u8*)0x36	  
#define   DDRB        *(volatile u8*)0x37
#define   PORTB       *(volatile u8*)0x38

#define   PINC        *(volatile u8*)0x33	  
#define   DDRC        *(volatile u8*)0x34
#define   PORTC       *(volatile u8*)0x35

#define   PIND        *(volatile u8*)0x30    	  
#define   DDRD        *(volatile u8*)0x31
#define   PORTD       *(volatile u8*)0x32

/********************************************_Sreg_Registers_*******************************************************/
#define   SREG       *(volatile u8*)0x5F
/********************************************_ExtInt_Registers_*******************************************************/
#define   MCUCR      *(volatile u8*)0x55
#define   GICR       *(volatile u8*)0x5B
/********************************************_ADC_Registers_*******************************************************/
#define ADMUX        *(volatile u8*)0x27
#define ADCSRA       *(volatile u8*)0x26
#define ADCH         *(volatile u8*)0x25
#define ADCL         *(volatile u8*)0x24

#define ADC_Value     *(volatile u16*)0x24

/********************************************_TIMER0_Registers_*******************************************************/
#define TCNT0       *(volatile u8*)0x52
#define TCCR0       *(volatile u8*)0x53
#define TIMSK       *(volatile u8*)0x59 
#define OCR0        *(volatile u8*)0x5C
/********************************************_TIMER1_Registers_*******************************************************/
#define TCNT1        *(volatile u16*)0x4C      // 2byte reg 
#define TCCR1A       *(volatile u8*)0x4F     
#define TCCR1B       *(volatile u8*)0x4E     
#define OCR1A        *(volatile u16*)0x4A     //2 byte reg
#define ICR1         *(volatile u16*)0x46     //2 byte reg
/********************************************_WDT_Registers_*******************************************************/
#define WDTCR        *(volatile u8*)0x41      // 2byte reg
 
/********************************************_USART_Registers_*******************************************************/
#define UDR         *(volatile u8*)0x2C
#define UCSRA       *(volatile u8*)0x2B
#define UCSRB       *(volatile u8*)0x2A
#define UCSRC       *(volatile u8*)0x40
#define UBRRL       *(volatile u8*)0x29
#define UCSRH       *(volatile u8*)0x40
/********************************************_SPI_Registers_*******************************************************/
#define SPDR       *(volatile u8*)0x2F
#define SPCR       *(volatile u8*)0x2D
#define SPSR       *(volatile u8*)0x2E
/********************************************_TWI_Registers_*******************************************************/

#define TWCR       *(volatile u8*)0x56
#define TWDR       *(volatile u8*)0x23
#define TWAR       *(volatile u8*)0x22
#define TWSR       *(volatile u8*)0x21
#define TWBR       *(volatile u8*)0x20

#endif /* REG_H_ */