/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */

#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#include "UART.h"
#define SetBit(Register,Pin) Register|=(1<<Pin)
#define ClrBit(Register,Pin) Register&=(~(1<<Pin))
#define get_bit(Register,Pin) ((Register >> Pin) & 1)




void UART_vidInit(void)
{
	DIO_vidSetBitDirction(2,0,0);					// pinD-0 RX in
	DIO_vidSetBitDirction(2,1,1);

	SetBit(SREG,7);									// Global In
	SetBit(UCSRB,3);
	SetBit(UCSRB,4);

	SetBit(UCSRC,1);
	SetBit(UCSRC,2);

	UBRRL = MyBRR ;
	UBRRH = 0b00000000 ;
}

void UART_vidTransData (u8 Data)
{
	while ( 0 == ( get_bit(UCSRA,5) ) ) ;
	UDR = Data ;
}

u8 UART_u8RecData (void)
{
	while ( 0 == ( get_bit(UCSRA,7) ) );
	return UDR ;
}
