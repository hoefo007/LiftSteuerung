/*
 * ProxyTransceiverChooseButtons.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYTRANSCEIVERCHOOSEBUTTONS_H_
#define PROXYTRANSCEIVERCHOOSEBUTTONS_H_

class ProxyTransceiverChooseButtons : public UARTObserver{
public:
	ProxyTransceiverChooseButtons(char);
	virtual ~ProxyTransceiverChooseButtons();
};

#endif /* PROXYTRANSCEIVERCHOOSEBUTTONS_H_ */
