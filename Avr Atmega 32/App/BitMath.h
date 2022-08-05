/*
 * BitMath.h
 *
 * Created: 5/19/2022 11:17:32 PM
 *  Author: Mohamed Safwat
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_
/*******************************_MACROS_****************************************/

#define SetBit(Reg,Bit)     Reg|=(1<<Bit)
#define ClrBit(Reg,Bit)     Reg&=~(1<<Bit)
#define TogBit(Reg,Bit)     Reg=^(1<<Bit)
#define GetBit(Reg,Bit)     (1 & (Reg >> Bit))



#endif /* BITMATH_H_ */