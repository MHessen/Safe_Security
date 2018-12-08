/*
 * Interrupt.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */

#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#define SetBit(Register,Pin) Register|=(1<<Pin)
#define ClrBit(Register,Pin) Register&=(~(1<<Pin))
#define get_bit(Register,Pin) ((Register >> Pin) & 1)


void DEI_Init (void)
{
	SetBit(SREG,7);
	SetBit(GICR,6);
	SetBit(MCUCR,0);			// Overwrite the default value which equal to 0
	SetBit(MCUCR,1);
}

void __vector_1 (void) __attribute__((signal,__INTR__ATTRS));		//the second line  __atrrribte__...... tells the Linker that previous fuction is not  normal one and  it's address refers to Vector table Address
void __vector_1 (void)
{
	DIO_vidSetBitValue(3,0,1);
}
