/*
 * ProxyTransceiverChooseButtons.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYTRANSCEIVERCHOOSEBUTTONS_H_
#define PROXYTRANSCEIVERCHOOSEBUTTONS_H_

#include "UARTDispatcher.h"

class UARTDispatcher;
class FloorChooseButtons;
class Informer;
class IOManager;

class ProxyTransceiverChooseButtons : public Observer {
private:
	char identChar;
	UARTDispatcher *UARTDisp;
	FloorChooseButtons *ChooseBut;
	IOManager *IOMan;
public:
	ProxyTransceiverChooseButtons(char, UARTDispatcher*, FloorChooseButtons*, IOManager*);
	virtual ~ProxyTransceiverChooseButtons();

	void update();
};

#endif /* PROXYTRANSCEIVERCHOOSEBUTTONS_H_ */
