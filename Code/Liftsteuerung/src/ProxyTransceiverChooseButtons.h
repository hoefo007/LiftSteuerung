/*
 * ProxyTransceiverChooseButtons.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYTRANSCEIVERCHOOSEBUTTONS_H_
#define PROXYTRANSCEIVERCHOOSEBUTTONS_H_

#include "UARTObserver.h"

class ProxyTransceiverChooseButtons : public Observer {
private:
	char identChar;
public:
	ProxyTransceiverChooseButtons(char);
	virtual ~ProxyTransceiverChooseButtons();

	void update(std::string);
};

#endif /* PROXYTRANSCEIVERCHOOSEBUTTONS_H_ */
