/*
 * PIT.c
 *
 *  Created on: 16 sep 2019
 *      Author: Lanix
 */

#include "MK64F12.h"
#include "PIT.h"

void PIT_clock_gating(void)
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;	// Set bit 23 - enable module PIT
}

void PIT_enable(void)
{
	PIT->MCR |= 0x0;	//PIT_MCR_MDIS_MASK;		// bit 1 - MDIS
}

void FRZ_enable(void)
{
	PIT->MCR |= PIT_MCR_FRZ_MASK;		// bit 0 - FRZ
}

void PIT_delay(PIT_timer_t pit_timer, My_float_pit_t system_clock , My_float_pit_t delay)
{
	switch (pit_timer)/** Selecting the PIT timer to be used */
	{
	case PIT_0: /** PIT_0 is selected*/
		PIT->CHANNEL[0] = 0x00000034; /** Load of number of cycles */
		break;
	case PIT_1: /** PIT_1 is selected*/
		 /** Load of number of cycles */
		break;
	case PIT_2: /** PIT_2 is selected*/
		 /** Load of number of cycles */
		break;
	case PIT_3: /** PIT_3 is selected*/
		 /** Load of number of cycles*/
		break;
	}		// end switch
}
