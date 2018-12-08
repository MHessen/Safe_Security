/*
 * PubFun.c
 *
 *  Created on: ??�/??�/????
 *      Author: DR . radwa hussein
 */

/*
 * Public Functions Needed.
 */
#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_Config.h"
#include "PubFun.h"


void Name_in_Arabic(void)
{
	//-------------------------------------------------------------------------------
	LCD_vidWritecmnd(0b01000000);             // Goto CG-RAM
	//-------------------------------------------------------------------------------
	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00001111);        // �
	LCD_vidWriteCharacter(0b00001001);        // �
	LCD_vidWriteCharacter(0b00001001);        // �
	LCD_vidWriteCharacter(0b00011111);        // �
	LCD_vidWriteCharacter(0b00000000);        // �

	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00001110);        // �
	LCD_vidWriteCharacter(0b00001001);        // �
	LCD_vidWriteCharacter(0b00000001);        // �
	LCD_vidWriteCharacter(0b00000001);        // �
	LCD_vidWriteCharacter(0b00011111);        // �
	LCD_vidWriteCharacter(0b00000000);        // �

	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00001111);        // �
	LCD_vidWriteCharacter(0b00001001);        // �
	LCD_vidWriteCharacter(0b00001001);        // �
	LCD_vidWriteCharacter(0b00011111);        // �
	LCD_vidWriteCharacter(0b00000000);        // �

	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00000000);        // �
	LCD_vidWriteCharacter(0b00000001);        // �
	LCD_vidWriteCharacter(0b00000001);        // �
	LCD_vidWriteCharacter(0b00000001);        // �
	LCD_vidWriteCharacter(0b00001111);        // �
	LCD_vidWriteCharacter(0b00000000);        // �
	//------------------------------------------------------------------------------
	LCD_SetPosition(0,0);                     // Go Back to DD-RAM
	//--------------------------------------------------------------------------
	/*
	 * Displaying my name "����" in Arabic
	 * */
	/*
		LCD_vidWriteCharacter(3);                 // Print Address 3 which specified for CG-RAM
		LCD_vidWriteCharacter(2);                 // Print Address 2 which specified for CG-RAM
		LCD_vidWriteCharacter(1);                 // Print Address 1 which specified for CG-RAM
		LCD_vidWriteCharacter(0);                 // Print Address 0 which specified for CG-RAM
	 */
	/*
	 * END
	 * */
	//-----------------------------------------------------------------------------

}
