/**
	\file
	\brief
		This is a starter file to implement a function able to produce an accurate delay
		using the PIT module.

	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	17/09/2018
 */

#include "MK64F12.h"
#include "PIT.h"
#include "NVIC.h"
#include "GPIO.h"
#include "Bits.h"

#define SYSTEM_CLOCK (21000000U)
#define DELAY (0.01F)			// 0.025	seg
								// 0.01785	seg
								// 0.00050	seg
//#define DEBUG_ON

int main(void)
{
	uint8_t pit_inter_status = FALSE;
	uint32_t current_time = 0;

	gpio_pin_control_register_t pin_control_register_bit_d_0 = GPIO_MUX1;
	GPIO_clock_gating(GPIO_D);	 						   // Pin 0 del puerto D
	GPIO_pin_control_register(GPIO_D, bit_0, &pin_control_register_bit_d_0);	// GPIO
	GPIO_data_direction_pin(GPIO_D,GPIO_OUTPUT, bit_0);							// Output
	GPIO_set_pin(GPIO_D, bit_0);						   // Safe value - 1
	PIT_clock_gating();		// Habilita modulo PIT
	PIT_enable();			// Habilita PIT Timers
	FRZ_enable();	// For enter in Debug Mode

//	/**Sets the threshold for interrupts, if the interrupt has higher priority constant that the BASEPRI, the interrupt will not be attended*/
//	NVIC_set_basepri_threshold(PRIORITY_10);
	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ, PRIORITY_10);	// Setup pin + threshold
	NVIC_global_enable_interrupts;					// Habilita interrupciones globales

	PIT_delay(PIT_0, SYSTEM_CLOCK, DELAY);	 // Timer0 , Clk del MCU , specific Delay

#ifndef DEBUG_ON
	current_time = PIT->CHANNEL[PIT_0].CVAL; /** Visualize the current time of the Timer */
#endif


	for (;;)
	{
		do
		{
			pit_inter_status = PIT_get_interrupt_flag_status();
		} while (FALSE == pit_inter_status);

		GPIO_toogle_pin(GPIO_D, bit_0);

		PIT_clear_interrupt_flag();
	}

	return 0;
}
