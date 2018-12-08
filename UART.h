/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */
#include "Registers.h"


#ifndef UART_H_
#define UART_H_

#define BoRa 9600
#define Freq 8000000
#define MyBRR ((Freq/16/BoRa)-1)

void UART_vidInit(void) ;
void UART_vidTransData (u8 Data);
u8 UART_u8RecData (void) ;


#endif /* UART_H_ */
