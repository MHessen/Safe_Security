/*
 * Timer1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */
#include "Registers.h"
#include "Types.h"
#define ZeroAngle_OCR 17
#define SetBit(Register,Pin) Register|=(1<<Pin)
#define ClrBit(Register,Pin) Register&=(~(1<<Pin))
#define get_bit(Register,Pin) ((Register >> Pin) & 1)



void Timer1_Init ()
{
	TCCR1A = 0b00000000 ;
	TCCR1B = 0b01000001 ;
	SetBit(SREG,7);									 	// General Interrupt Enable
	SetBit(TIMSK,5);									// Peripheral Interrupt Enable
	SetBit(TIMSK,2);									// Setting the Overload Counts
}

//-----------------------------

void Servo_Angle (u8 Angle)
{
	u8 var_part;
	{
		var_part = (63 * Angle) / 180 ;
		OCR1A = var_part + ZeroAngle_OCR ;
	}

}


//-----------------------------
u8 flag ;
u32 C1 ,C2,C3;
u32 T1_Counter;
//-----------------------------
void __vector_6 (void) __attribute__((signal,__INTR__ATTRS));		//the second line  __atrrribte__...... tells the Linker that previous fuction is not  normal one and  it's address refers to Vector table Address
void __vector_6 (void)
{
	if ( 0 == flag )										// First Rising Edge
	{
		C1 = ICR1L ;
		ClrBit(TCCR1B,6) ;									// Set this Bit to 0 to Detect Next Falling Edge
		T1_Counter = 0 ;
	}
	else if ( 1 == flag )
	{
		C2 = ICR1L + (T1_Counter*65535) ;
		SetBit(TCCR1B,6);									// Set this Bit to 1 to Detect Next Rising Edge
	}
	else if ( 2 == flag )
	{
		C3 = ICR1L + ( T1_Counter*65535);
		ClrBit(TIMSK,5);									// Manually Clear the Flag ::DataSheet P.92,93
	}
	flag ++ ;

}


//----------------------------
void __vector_9 (void) __attribute__((signal,__INTR__ATTRS));		//the second line  __atrrribte__...... tells the Linker that previous fuction is not  normal one and  it's address refers to Vector table Address
void __vector_9 (void)
{
	T1_Counter ++ ;
}
