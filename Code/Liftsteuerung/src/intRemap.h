/*
 * intRemap.h
 *
 *  Created on: Apr 17, 2014
 *      Author: Jan Huggler
 */

#ifndef INTREMAP_H_
#define INTREMAP_H_

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum _IntType {
		TIM2=0,
		USART
	} IntType;


	void *tim2IRQFunc;//(void);
	void *usartIRQFunc;//(void);

	void TIM2_IRQHandler(void);
	void USART1_IRQHandler(void);
	void registerIRQ(uint8_t Int, void *func);
	void unregisterIRQ(uint8_t Int);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* INTREMAP_H_ */
