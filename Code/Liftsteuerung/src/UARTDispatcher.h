/*
 * UARTDispatcher.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef UARTDISPATCHER_H_
#define UARTDISPATCHER_H_

#include "Informer.h"

#include "Observer.h"
#include <string>
#include <map>

class UARTC;

class UARTDispatcher: public Informer {
private:
	std::map<char, Observer*>charToObserver;
	UARTC *uart;
	void inform(std::string);
public:
	UARTDispatcher();
	virtual ~UARTDispatcher();
	void send(std::string);
	std::string receive(Observer*);
	void update();
	void registrate(Observer*);
	void unregistrate(Observer*);
};

#endif /* UARTDISPATCHER_H_ */
