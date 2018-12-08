/*
 * Timer.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: DR . radwa hussein
 */
#include  "Registers.h"
#include "Types.h"
#include "DIO.h"
#define get_bit(Register,Pin) ((Register >> Pin) & 1)
#define SetBit(Register,Pin) Register|=(1<<Pin)
#define Toggle_bit(Register,Pin) Register ^= (1<<Pin)

void Timer_Init()
{
	SetBit(SREG,7);
	TCCR0 = 0b00001001;
	TIMSK = 0b00000010;
	 OCR0 = 0b01100100;
}

u32 T0_counter=0 ;

//ISR File for Timer
//10 for CTC
//11 For Free Running

void __vector_10 (void) __attribute__((signal,__INTR__ATTRS));		//the second line  __atrrribte__...... tells the Linker that previous fuction is not  normal one and  it's address refers to Vector table Address
void __vector_10(void)
{
	T0_counter++;
	if (80000 == T0_counter)
	{
		T0_counter = 0 ;
		Toggle_bit(PORTA,0);
	}
}
