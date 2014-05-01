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

typedef enum {TIM, USART, SEARCH} IntType;


extern void (*tim2IRQFunc)(void);
extern void (*usartIRQFunc)(void);

void TIM2_IRQHandler(void);
void USART1_IRQHandler(void);
void registerIRQ(IntType Int, void (*func)(void));
void unregisterIRQ(IntType Int);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* INTREMAP_H_ */
