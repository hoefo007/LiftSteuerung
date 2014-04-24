/*
 * UARTObserver.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef UARTOBSERVER_H_
#define UARTOBSERVER_H_

#include "Observer.h"
#include <string>;

class UARTObserver: public Observer {
protected:
	char identChar;
public:
	virtual void update(std::string)=0;
};

#endif /* UARTOBSERVER_H_ */
