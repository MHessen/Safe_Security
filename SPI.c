/*
 * SPI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */
#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#include "SPI.h"
#define get_bit(Register,Pin) ((Register >> Pin) & 1)


#define Enable 1
#define Disable 0
#define Master Disable
#define Slave Enable

#define Mode_S 0
enum Mode {SelectMaster , SelectSlave , Select=Mode_S};

void SPI_vidInit (void)
{
#if ( Master == Enable )
	{
		{//Master
			DIO_vidSetBitDirction(1,4,1) ;			// SS  		 o/p
			DIO_vidSetBitDirction(1,7,1) ;			// clk	     o/p
			DIO_vidSetBitDirction(1,5,1) ;			// MISO		 o/p
			DIO_vidSetBitDirction(1,6,0) ;			// MOSI		 i/p

			SPCR = 0b01010001 ;						// Master
		}
	}
#endif
#if  ( Slave == Enable )
		{
			void SPI_vidInit (void)
			{//Slave
				DIO_vidSetBitDirction(1,4,0) ;			// SS  		 o/p
				DIO_vidSetBitDirction(1,7,0) ;			// clk	     o/p
				DIO_vidSetBitDirction(1,5,0) ;			// MISO		 o/p
				DIO_vidSetBitDirction(1,6,1) ;			// MOSI		 i/p

				SPCR = 0b01010001 ;						// Master
			}
	}
#endif
}


u8 SPI_u8TranRec (u8 Data)
{
	SPDR = Data ;
	while ( 0 == ( get_bit(SPSR,7) ) ) ;
	return SPDR ;
}
