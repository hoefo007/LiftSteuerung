/*
 * intRemap.c
 *
 *  Created on: Apr 17, 2014
 *      Author: Jan Huggler
 */

#include "intRemap.h"

	void (*tim2IRQFunc)(void);
	void (*usartIRQFunc)(void);

/**
 * @brief Timer-IRQ function, calls the registered function
 */
void TIM2_IRQHandler(){
	if(tim2IRQFunc != 0){
		tim2IRQFunc();
	}
}

/**
 * @brief USART-IRQ function , call the registered function
 */
void USART1_IRQHandler(void){
	if(usartIRQFunc != 0){
		usartIRQFunc();
	}
}

/**
 * @brief Register an IRQ-Function. The IRQ will be remapped to the function
 * @param Int: desired Interrupt
 * @param func: function to which the interrupt shall be remapped
 */
void registerIRQ(IntType Int, void (*func)(void)){
	switch(Int){
	case TIM:	tim2IRQFunc = func;
				break;
	case USART: usartIRQFunc = func;
				break;
	default:	break;
	}
}

/**
 * @brief Unregister an IRQ-Function.
 * @param Int: which interrupt to unregister
 */
void unregisterIRQ(IntType Int){
	switch(Int){
		case TIM:	tim2IRQFunc = 0;
					break;
		case USART:	usartIRQFunc = 0;
					break;
		default:	break;
		}
}
