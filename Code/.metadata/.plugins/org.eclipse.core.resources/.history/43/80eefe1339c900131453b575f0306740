/*
 * UARTDispatcher.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef UARTDISPATCHER_H_
#define UARTDISPATCHER_H_

#include "Informer.h"

class UARTDispatcher: public Informer {
private:
	UART uart;
public:
	UARTDispatcher();
	virtual ~UARTDispatcher();
	void send(string);
	void receive(UARTObserver*);
	void update();
};

#endif /* UARTDISPATCHER_H_ */
