/*
 * PIT.h
 *
 *  Created on: Jan 29, 2015
 *      Author: Luis Pizano
 */

#ifndef PIT_H_
#define PIT_H_


#include "stdint.h"
#include "MK64F12.h"


typedef float My_float_pit_t;
<<<<<<< HEAD
typedef float My_double_pit_t;
=======
typedef double My_double_pit_t;
>>>>>>> f949995d5439477464a058785ed51397fbb4b482

/*! This enumerated constant are used to select the PIT to be used*/
typedef enum {PIT_0,PIT_1,PIT_2,PIT_3} PIT_timer_t;


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function configure the PIT to generate a delay base on the system clock.
 	 It is important to note that this strictly is not device driver since everything is
 	 contained in a single function,  in general you have to avoid this practices, this only
 	 for the propose of the homework

 	 \param[in]  pit_timer channel to be used.
	 \param[in]  system_clock system clock use in the K64 (defult = 21e6).
	 \param[in]  delay the amount of time the delay the microcontroller
 	 \return void
 */
void PIT_delay(PIT_timer_t pit_timer, My_float_pit_t system_clock , My_float_pit_t delay);

/********************************************************************************************/
/*!
 	 \brief	 This function enable the clock signal of the pit

 	 \param[in]  void.
 	 \return void
 */
void PIT_clock_gating(void);

/********************************************************************************************/
/*!
 	 \brief	It return the status of the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
uint8_t PIT_get_interrupt_flag_status(PIT_timer_t pit_timer);	// Add one param

/********************************************************************************************/
/*!
 	 \brief	It return clears the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
void PIT_clear_interrupt_flag(void);

/********************************************************************************************/
/*!
 	 \brief	Enable of the module MDIS (PIT section);

 	 \param[in]  void.
 	 \return 	 void.
 */
void PIT_enable(void);

/********************************************************************************************/
/*!
 	 \brief	Stop the timers in Debug Mode;

 	 \param[in]  void.
 	 \return 	 void.
 */
void FRZ_enable(void);		// new

/********************************************************************************************/
/*!
 	 \brief	It return clears the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
void PIT_enable_interrupt(PIT_timer_t pit);



#endif /* PIT_H_ */
