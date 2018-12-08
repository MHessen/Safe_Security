#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#include "SevnSegm.h"
#define F_CPU 8000000UL
#include "util/delay.h"


void SevSeg_vidInit(void)
{
	DIO_vidSetPortDirction(1,255) ;
}


void Draw_vidNumber (u8 num)
{
	switch  (num)
	{
		case 0 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b10100000 );
			break ;
		}

		case 1 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b11111001 );
			break ;
		}

		case 2 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b11000100 );
			break ;
		}

		case 3 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b11010000 );
			break ;
		}

		case 4 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b10011001 );
			break ;
		}

		case 5 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b10010010 );
			break ;
		}

		case 6 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b10000010 );
			break ;
		}

		case 7 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b11111000 );
			break ;
		}

		case 8 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b10000000 );
			break ;
		}

		case 9 :
		{
			DIO_vidSetPortValue ( SevSeg_Port ,0b10010000 );
			break ;
		}
	}

}
