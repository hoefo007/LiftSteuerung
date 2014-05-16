/*
 * ProxyTransceiverFloorIndicator.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYTRANSCEIVERFLOORINDICATOR_H_
#define PROXYTRANSCEIVERFLOORINDICATOR_H_

#include "UARTObserver.h"

class FloorIndicator;
class UARTDispatcher;

class ProxyTransceiverFloorIndicator : public Observer {
private:
	char identChar;
	FloorIndicator *FloorInd;
	UARTDispatcher *UARTDisp;
public:
	ProxyTransceiverFloorIndicator(char, UARTDispatcher*, FloorIndicator*);
	virtual ~ProxyTransceiverFloorIndicator();
	void update();
};

#endif /* PROXYTRANSCEIVERFLOORINDICATOR_H_ */
