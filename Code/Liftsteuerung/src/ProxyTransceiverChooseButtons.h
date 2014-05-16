/*
 * ProxyTransceiverChooseButtons.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYTRANSCEIVERCHOOSEBUTTONS_H_
#define PROXYTRANSCEIVERCHOOSEBUTTONS_H_

#include "UARTObserver.h"

class UARTDispatcher;
class FloorChooseButtons;
class Informer;

class ProxyTransceiverChooseButtons : public Observer {
private:
	char identChar;
	UARTDispatcher *UARTDisp;
	FloorChooseButtons *ChooseBut;
public:
	ProxyTransceiverChooseButtons(char, UARTDispatcher*, FloorChooseButtons*);
	virtual ~ProxyTransceiverChooseButtons();

	void update();
};

#endif /* PROXYTRANSCEIVERCHOOSEBUTTONS_H_ */
