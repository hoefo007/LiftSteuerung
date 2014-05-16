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


class UARTDispatcher;

class ProxyChooseButtons: public Observer {
private:
	UARTDispatcher *UARTDisp;
	volatile bool waitResponse;
	uint8_t chosenFloor;
public:
	ProxyChooseButtons(UARTDispatcher*);
	virtual ~ProxyChooseButtons();
	uint8_t getChosenFloor();
	void update();
};

#endif /* PROXYCHOOSEBUTTONS_H_ */
