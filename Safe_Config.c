/*
 * Safe_Config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */
#include "Types.h"
#include "DIO.h"
#include "Keybad_Config.h"
#include "Keybad.h"
#include "LCD_Config.h"
#include "LCD.h"
#include "SevnSegm.h"
#include "Safe_Config.h"
#define F_CPU 8000000UL
#include <util/delay.h> // To enable use of the function _delay_ms()


// Variables
u8 ButtonPress , EnterButton=0;
u32 PassValue=0 ;

// LCD Phrases
//extern u8 Welcome [] = "Welcome" ;
u8 EntrPass [] = "Enter Password" ;//
//extern u8 Right_Pass [] = "Right Password" ;
//extern u8 Wrong_Pass [] = "Wrong Password" ;
//extern u8 TryAgain [] = "Try Again" ;
//extern u8 LastTry [] = "Last Tray" ;
u8 OpenSafe [] = "Opening Safe" ;//
u8 ClsSafe [] = "Closing Safe" ;//
//extern u8 LckSafe [] = "Safe Locked" ;
//extern u8 CallWaled [] = "Call Walied..." ;



void Safe_vidInit (void)
{
	/********************************* Port'nPin Implementation********************
		LCD --------------------- Port-D & Port-C Pin{0,1,2}
		Keypad ------------------ Port-A
		Sev-Segment ------------- Port_B
		DIP-Switch -------------- Port-C Pin{3}
		LED --------------------- Port-C Pin{4}
		Motor ------------------- Port-C Pin{5,6}
		Buzzer ------------------ Port-C Pin{7}
	 *******************************************************************************/


	/*******************************************************************************
	  	  	  	  	  	  	  	  Initializing Our Project
	 *******************************************************************************/

	LCD_Init();											// Initializing The LCD
	keybad_Init();										// Initializing The KeyBad
	SevSeg_vidInit();									// Initializing The Seven-Segment

	// DIP Switch
	DIO_vidSetBitDirction(2,3,0);						//  Port-C Pin-3 i/p " PullUp Resistance "
	DIO_vidSetBitValue(2,3,1);							// & High volt on't For DIP-Switch
	// LED
	DIO_vidSetBitDirction(2,4,1);						// Port-C Pin-4 output For LED
	// Motor
	DIO_vidSetBitDirction(2,5,1);						// Port-C Pin-5 output For Motor
	DIO_vidSetBitDirction(2,6,1);						// Port-C Pin-6 output For Motor
	//Buzzer
	DIO_vidSetBitDirction(2,7,1);						// Port-C Pin-7 output For Buzzer

}



void Get_SafePass (void)
{
	//Resetting Password Value & Enter-Key Button
	PassValue = 0 ;
	EnterButton = 0 ;
	// Checking For Number
	while ( 0 == EnterButton)
	{// Polling For Enter-Key
		for ( u8 i=0 ; i<12 ; i++ )
		{
			ButtonPress = Keybad_GetButtonStatus(i);

			if ( 0==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1);
				//***************Display*****************************
				LCD_vidWritecmnd(0x01);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);

			}
			else if ( 1==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1) ;
				//***************Display*****************************
				LCD_vidWritecmnd(0x01);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 2==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1) ;
				//***************Display*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 3==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1) ;
				//***************Display*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 4==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1) ;
				//***************Display*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 5==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1) ;
				//***************Display*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 6==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1) ;
				//***************Display*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 7==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1) ;
				//***************Display*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 8==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				PassValue +=(i+1) ;
				//***************Display*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 9==i && 1==ButtonPress )
			{
				PassValue *= 10 ;
				//***************Display*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 10==i && 1==ButtonPress )
			{//Reset
				PassValue = 0 ;
				//***************ReSet*****************************
				LCD_vidWritecmnd(0b00000001);
				LCD_SetPosition(0,0);
				LCD_WriteString( EntrPass,sizeof(EntrPass) );					// Waiting For Password
				LCD_SetPosition(1,0);
				LCD_WriteNumber(PassValue);
			}
			else if ( 11==i && 1==ButtonPress )
			{//Enter
				LCD_vidWritecmnd(0b00000001);
				EnterButton = 1 ;												// Out Of Polling
			}

		}// For loop

	}//polling Wile loop

}


void Open_Safe (void)
{
	LCD_vidWritecmnd(0x01);
	LCD_SetPosition(0,0);
	LCD_WriteString( OpenSafe,sizeof(OpenSafe));
	//****************************************************************************************************************
	//--------------------------------------------- Be Careful Here --------------------------------------------------
	//****************************************************************************************************************
	DIO_vidSetBitValue(2,5,0);												// Restricted To Prevent SHORT CIRCUIT
	DIO_vidSetBitValue(2,6,0);												//
	_delay_ms(200);
	DIO_vidSetBitValue(2,5,0);
	DIO_vidSetBitValue(2,6,1);
	_delay_ms(2000);
	LCD_vidWritecmnd(0x01);
	DIO_vidSetBitValue(2,5,0);												// Restricted To Prevent SHORT CIRCUIT
	DIO_vidSetBitValue(2,6,0);												//
	//-----------------------------------------------------------------------------------------------------------------
}

void Close_Safe (void)
{
	//-----------------------------------------------------------------------------------------------------------------
	LCD_vidWritecmnd(0x01);
	LCD_SetPosition(0,0);
	LCD_WriteString( ClsSafe,sizeof(ClsSafe) );
	//****************************************************************************************************************
	//--------------------------------------------- Be Careful Here --------------------------------------------------
	//****************************************************************************************************************
	DIO_vidSetBitValue(2,5,0);												// Restricted To Prevent SHORT CIRCUIT
	DIO_vidSetBitValue(2,6,0);												//
	_delay_ms(200);
	DIO_vidSetBitValue(2,5,1);
	DIO_vidSetBitValue(2,6,0);
	_delay_ms(2000);
	DIO_vidSetBitValue(2,5,0);												// Restricted To Prevent SHORT CIRCUIT
	DIO_vidSetBitValue(2,6,0);												//
	//-----------------------------------------------------------------------------------------------------------------
}
