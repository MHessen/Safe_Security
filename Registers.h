/*
 * Registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_


/*
	Header File includes Registers Address of ATmega32L
*/


/*
	For DDR Registers
*/

#define DDRA *((volatile u8*) 0x3A)
#define DDRB *((volatile u8*) 0x37)
#define DDRC *((volatile u8*) 0x34)
#define DDRD *((volatile u8*) 0x31)

/*
	For PORT Registers

*/

#define PORTA *((volatile u8*) 0x3B)
#define PORTB *((volatile u8*) 0x38)
#define PORTC *((volatile u8*) 0x35)
#define PORTD *((volatile u8*) 0x32)

/*
	For PIN Registers
*/

#define PINA *((volatile u8*) 0x39)
#define PINB *((volatile u8*) 0x36)
#define PINC *((volatile u8*) 0x33)
#define PIND *((volatile u8*) 0x30)

/*
	For Interrupt
 */

#define SREG *((volatile u8*) 0x5F)
#define GICR *((volatile u8*) 0x5B)
#define MCUCR *((volatile u8*) 0x55)


/*
  	  For ADC Registers
 */

#define ADMUX *((volatile u8*) 0x27)
#define ADCSRA *((volatile u8*) 0x26)
#define ADCH *((volatile u8*) 0x25)

/*
 *  For Timer
 * */

#define TCCR0 *((volatile u8*) 0x53)
#define TIMSK *((volatile u8*) 0x59)
#define TIFR *((volatile u8*) 0x38)
#define OCR0 *((volatile u8*) 0x5c)

/*
 * For Timer1
 */

#define TCCR1A *((volatile u8*) 0x4F)
#define TCCR1B *((volatile u8*) 0x4E)
#define TCNT1H *((volatile u8*) 0x4D)
#define ICR1L *((volatile u16*) 0x46)
#define TIMSK *((volatile u8*) 0x59)
#define OCR1A *((volatile u16*) 0x4A)

/*
 * For UART
 */

#define UCSRB *((volatile u8*) 0x2A)
#define UCSRC *((volatile u8*) 0x40)
#define UBRRH *((volatile u8*) 0x40)
#define UBRRL *((volatile u8*) 0x29)
#define UCSRA *((volatile u8*) 0x2B)
#define UDR *((volatile u8*) 0x2C)


/*
 * For SPI
 */
#define SPCR *((volatile u8*) 0x2D)
#define SPSR *((volatile u8*) 0x2E)
#define SPDR *((volatile u8*) 0x2F)


#endif /* REGISTERS_H_ */
