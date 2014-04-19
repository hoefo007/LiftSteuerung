/*
 * intRemap.c
 *
 *  Created on: Apr 17, 2014
 *      Author: Jan Huggler
 */

#include "intRemap.h"

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

void registerIRQ(uint8_t Int, void *func){
	switch(Int){
	case TIM2:	tim2IRQFunc = func;
				break;
	case USART: usartIRQFunc = func;
				break;
	default:	break;
	}
}

void unregisterIRQ(uint8_t Int){
	switch(Int){
		case TIM2:	tim2IRQFunc = 0;
					break;
		default:	break;
		}
}
