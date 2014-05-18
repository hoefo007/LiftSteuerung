/*
 * ProxyChooseButtons.h
 *
 *  Created on: May 16, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYCHOOSEBUTTONS_H_
#define PROXYCHOOSEBUTTONS_H_
#include <stdint.h>
#include "FloorChooseButtons.h"
#include "Observer.h"
#include "Informer.h"

class UARTDispatcher;

class ProxyChooseButtons: public Observer, public Informer {
private:
	UARTDispatcher *UARTDisp;
	volatile bool waitResponse;
	uint8_t chosenFloor;
	Observer *Obsv;
	char identChar;
public:
	ProxyChooseButtons(UARTDispatcher*, char);
	virtual ~ProxyChooseButtons();
	uint8_t getChosenFloor();
	void update();
	void registrate(Observer*);
	void unregistrate(Observer*);
	void inform();
};

#endif /* PROXYCHOOSEBUTTONS_H_ */
