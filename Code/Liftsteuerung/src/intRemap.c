/*
 * intRemap.c
 *
 *  Created on: Apr 17, 2014
 *      Author: Jan Huggler
 */

#include "intRemap.h"

	void (*tim2IRQFunc)(void);
	void (*usartIRQFunc)(void);

void TIM2_IRQHandler(){
	if(tim2IRQFunc != 0){
		tim2IRQFunc();
	}
}

void USART1_IRQHandler(void){
	if(usartIRQFunc != 0){
		usartIRQFunc();
	}
}

void registerIRQ(IntType Int, void (*func)(void)){
	switch(Int){
	case TIM:	tim2IRQFunc = func;
				break;
	case USART: usartIRQFunc = func;
				break;
	default:	break;
	}
}

void unregisterIRQ(IntType Int){
	switch(Int){
		case TIM:	tim2IRQFunc = 0;
					break;
		case USART:	usartIRQFunc = 0;
					break;
		default:	break;
		}
}
