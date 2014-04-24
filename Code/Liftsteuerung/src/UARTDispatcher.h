/*
 * UARTDispatcher.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef UARTDISPATCHER_H_
#define UARTDISPATCHER_H_

#include "Informer.h"
#include "UARTC.h"
#include <string>
#include <map>

class UARTDispatcher: public Informer {
private:
	std::map<char, Observer*>charToObserver;
	UARTC *uart;
	void inform(std::string);
public:
	UARTDispatcher();
	virtual ~UARTDispatcher();
	void send(std::string);
	std::string receive(UARTObserver*);
	void update();
	void registrate(UARTObserver*);
	void unregistrate(UARTObserver*);
};

#endif /* UARTDISPATCHER_H_ */
