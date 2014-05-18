/*
 * UARTDispatcher.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef UARTDISPATCHER_H_
#define UARTDISPATCHER_H_
#include <map>


#include "Informer.h"

//#include "Observer.h"
class Observer;

class UARTC;

class UARTDispatcher: public Informer {
private:
	std::map<char, Observer*>charToObserver;
	UARTC *uart;
	char localBuffer[10];
	void inform();
	void inform(char*);
public:
	UARTDispatcher();
	virtual ~UARTDispatcher();
	void send(char*);
	char* receive(Observer*);
	void update();
	void registrate(Observer*);
	void registrate(Observer*, char);
	void unregistrate(Observer*);
	void clearBuffer();
	//void inform(char*);
};

#endif /* UARTDISPATCHER_H_ */
