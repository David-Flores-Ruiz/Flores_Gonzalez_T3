/*
 * PIT.c
 *
 *  Created on: 16 sep 2019
 *      Author: Lanix
 */

#include "MK64F12.h"
#include "PIT.h"

/*! This variable hold the PIT clock	  	*/
uint32_t clock_PIT;

/*! This variable hold the PIT period	  	*/
uint32_t period_PIT;

/*! This variable is the cycles to spend	*/
uint32_t cycles_number;


void PIT_clock_gating(void)
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;	// Set bit 23 - enable module PIT
}

void PIT_enable(void)
{
	PIT->MCR |= 0x0;	//PIT_MCR_MDIS_MASK;		// bit 1 - MDIS enable PIT section
}

void FRZ_enable(void)
{
	PIT->MCR |= PIT_MCR_FRZ_MASK;		// bit 0 - FRZ enable Mode Debug
}

void PIT_delay(PIT_timer_t pit_timer, My_float_pit_t system_clock , My_float_pit_t delay)
{
		clock_PIT  = system_clock/2;
		period_PIT = 1/clock_PIT;

		cycles_number = (delay/period_PIT);
		PIT->CHANNEL[pit_timer].LDVAL = cycles_number - 1; 	/** Load of number of cycles */
		PIT->CHANNEL[pit_timer].TCTRL |= PIT_TCTRL_TIE_MASK;	// set TIE - enable interrupts Timer
		PIT->CHANNEL[pit_timer].TCTRL |= PIT_TCTRL_TEN_MASK;	// set TEN - start Timer
}
