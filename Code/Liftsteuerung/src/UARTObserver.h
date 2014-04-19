/*
 * UARTObserver.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef UARTOBSERVER_H_
#define UARTOBSERVER_H_

#include "Observer.h"

class UARTObserver: public Observer {
private:
	char identChar;
public:
	UARTObserver();
	virtual ~UARTObserver();
};

#endif /* UARTOBSERVER_H_ */
