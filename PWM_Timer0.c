/*
 * PWM_Timer0.c
 *
 *  Created on: ??�/??�/????
 *      Author: DR . radwa hussein
 */
#include "Registers.h"
#include "Types.h"

void PWM_Timer0_Init ()
{
	TCCR0 = 0b01101101;
}
