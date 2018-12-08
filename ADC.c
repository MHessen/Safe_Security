/*
 * ADC.c
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

void ADC_Init (void)
{
	//ADNNUX = 0b01100000
	ClrBit (ADMUX,0);
	ClrBit (ADMUX,1);
	ClrBit (ADMUX,2);
	ClrBit (ADMUX,3);
	ClrBit (ADMUX,4);
	SetBit (ADMUX,5);
	SetBit (ADMUX,6);
	ClrBit (ADMUX,7);

	//ADCSRA = 0b10000000
	ClrBit (ADCSRA,0);
	ClrBit (ADCSRA,1);
	ClrBit (ADCSRA,2);
	ClrBit (ADCSRA,3);
	ClrBit (ADCSRA,4);
	ClrBit (ADCSRA,5);
	ClrBit (ADCSRA,6);
	SetBit (ADCSRA,7);

}

u8 ADC_u8ReadOut(void)
{
	//Start Conversion
	SetBit(ADCSRA,6);

	while (get_bit(ADCSRA,4)==0)
	{
		// Do Nothing.
	}
	SetBit(ADCSRA,4);
	return ADCH ;
}
