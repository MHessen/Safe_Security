/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */

#include "Safe_Config.h"
#include "Types.h"
#include "DIO.h"
#include "LCD_Config.h"
#include "LCD.h"
#include "Keybad_Config.h"
#include "Keybad.h"
#include "SevnSegm.h"
//#include "LCD_Phrases.h"
//#include "Safe_Config.h"
#define CorrectPassword 8112
#define F_CPU 8000000UL
#include <util/delay.h> // To enable use of the function _delay_ms()


int main (void)
{

	//********************** Variables ************************************************************
	u8 DipSwich , EntryCount=0 , ResetFlag=0;
	//--------------------------------
	extern u32 PassValue ;
	//--------------------------------

	// Initializations
	Safe_vidInit();

	//LCD Phrases
	u8 Welcome [] = "Welcome" ;//
	u8 EntrPass [] = "Enter Password" ;
	u8 Right_Pass [] = "Right Password" ;//
	//u8 Wrong_Pass [] = "Wrong Password" ;
	u8 TryAgain [] = "Tray Again" ;//
	u8 LastTry [] = "Last Try" ;//
	//u8 OpenSafe [] = "Opening Safe" ;
	//u8 ClsSafe [] = "Closing Safe" ;
	u8 LckSafe [] = "Safe Locked" ;//
	u8 CallWaled [] = "Call Waleed -_-" ;//

	while (1)
	{// Super Loop
		LCD_vidWritecmnd(0x01);
		DipSwich = DIO_u8ReadBitValue(2,3);
		Draw_vidNumber(0);
		while (0 == DipSwich)
		{// Main System Key
			//*********************** Main Software***************************************************
			LCD_vidWritecmnd(0x01) ;
			LCD_SetPosition(0,0);
			LCD_WriteString( Welcome,sizeof(Welcome) );						// Welcome For 3 Seconds
			_delay_ms(3000);
			LCD_vidWritecmnd(0x01) ;
			LCD_WriteString(EntrPass,sizeof(EntrPass));

			while ( EntryCount != 3 )
			{
				Get_SafePass();
				if (PassValue == CorrectPassword)
				{
					LCD_vidWritecmnd(0x01);
					LCD_SetPosition(0,0);
					LCD_WriteString( Right_Pass,sizeof(Right_Pass));
					_delay_ms(1000);
					Open_Safe();											// Opening Safe
					_delay_ms(2000);
					Close_Safe();											// Closing Safe
					ResetFlag = 1 ;
					break ;													// PassValue=0 "Review Get_Pass() Function" , EntryCount=0 ,
				}
				else if ( PassValue != CorrectPassword )
				{
					EntryCount++;

					if (1 == EntryCount)
					{
						Draw_vidNumber(EntryCount);
						LCD_vidWritecmnd(0x01);
						LCD_SetPosition(0,0);
						LCD_WriteString( TryAgain,sizeof(TryAgain));
						LCD_SetPosition(1,0);
						_delay_ms(2000);
						LCD_vidWritecmnd(0x01);
						LCD_WriteString( EntrPass,sizeof(EntrPass) );
						continue ;
					}
					else if ( 2 == EntryCount)
					{
						Draw_vidNumber(EntryCount);
						LCD_vidWritecmnd(0x01);
						LCD_SetPosition(0,0);
						LCD_WriteString( LastTry,sizeof(LastTry));
						LCD_SetPosition(1,0);
						_delay_ms(2000);
						LCD_vidWritecmnd(0x01);
						LCD_WriteString( EntrPass,sizeof(EntrPass) );
						continue ;
					}
					else  if ( 3 == EntryCount)
					{
						Draw_vidNumber(EntryCount);
						LCD_vidWritecmnd(0x01);
						LCD_SetPosition(0,0);
						LCD_WriteString( LckSafe,sizeof(LckSafe));
						LCD_SetPosition(1,0);
						LCD_WriteString( CallWaled,sizeof(CallWaled));
						DIO_vidSetBitValue(2,4,1);											// Red LED ON
						DIO_vidSetBitValue(2,7,1);											// Buzzer ON
						_delay_ms(5000);
						continue ;
					}
				}

			}

			DipSwich = DIO_u8ReadBitValue(2,3);									// Reading the DIP-Switch Value

			if (1 == ResetFlag || 3 == EntryCount )
			{
				DIO_vidSetBitValue(2,4,0);											// Red LED OFF
				DIO_vidSetBitValue(2,7,0);											// Buzzer OFF
				LCD_vidWritecmnd(0x01);
				EntryCount = 0 ;													// Resetting Counter & ResetFlag
				ResetFlag = 0 ;
				Draw_vidNumber(EntryCount);
				_delay_ms(2000);
			}
		}
		//**********************************End of Main Software*******************************
	}


	return 0 ;
}
