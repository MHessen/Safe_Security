/*
 * LCD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */
#include "Types.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_Config.h"
#define F_CPU 8000000UL
#include <util/delay.h> // To enable use of the function _delay_ms()



void LCD_vidWriteCharacter (u8 Character)
{
	DIO_vidSetPortValue (LCD_port , Character);
	DIO_vidSetBitValue (LCD_control_port , RS ,1);
	DIO_vidSetBitValue (LCD_control_port , RW ,0);
	DIO_vidSetBitValue (LCD_control_port , E ,1);
	_delay_ms(1);
	DIO_vidSetBitValue (LCD_control_port , E ,0);
}
//
void LCD_vidWritecmnd (u8 cmnd)
{
	DIO_vidSetPortValue (LCD_port , cmnd);
	DIO_vidSetBitValue (LCD_control_port , RS ,0);
	DIO_vidSetBitValue (LCD_control_port , RW ,0);
	DIO_vidSetBitValue (LCD_control_port , E ,1);
	_delay_ms(1);
	DIO_vidSetBitValue (LCD_control_port , E ,0);
}

void LCD_Init(void)
{
	DIO_vidSetPortDirction(LCD_port,255);
	DIO_vidSetBitDirction(LCD_control_port,RS,1);
	DIO_vidSetBitDirction(LCD_control_port,RW,1);
	DIO_vidSetBitDirction(LCD_control_port,E,1);
	_delay_ms(50);
	LCD_vidWritecmnd (0b00111000);
	_delay_ms(2);

	LCD_vidWritecmnd (0b00001100);
	_delay_ms(2);

	LCD_vidWritecmnd (0b00000001);
	_delay_ms(2);

}


void LCD_WriteString(u8 str [],int count)
{

	for (int i=0 ; i<count-1 ;i++)
	{
		LCD_vidWriteCharacter (str[i]);
		//_delay_ms(1000);
	}
	//_delay_ms(2000);
	//LCD_vidWritecmnd(0b00000001);          // Clear
}


void LCD_SetPosition (u8 row , u8 colm)
{
	if (0==row)
	{
		LCD_vidWritecmnd (128+colm);        // 128 = 0b10000000 "ReView set DDRAM Address" in LCD Data Sheet
	}
	else if (1==row)
	{
		LCD_vidWritecmnd (128+64+colm);    // 64 cause first beginning address in LCD new line starts from 64
	}
}


void LCD_WriteNumber(u64 num)
{
	u8 temp ;
	u64 rev_num = 1;

	if (0==num)
	{
		LCD_vidWriteCharacter('0');
	}
	else
	{
		while (num != 0)
		{
			temp = num % 10 ;
			num = num / 10 ;
			rev_num = (rev_num * 10) + temp ;
		}

		while (rev_num != 1)
		{
			temp = rev_num % 10 ;
			rev_num = rev_num / 10 ;
			LCD_vidWriteCharacter((temp+48));
		}
	}
}

