/*
 * ProxyTransceiverFloorIndicator.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYTRANSCEIVERFLOORINDICATOR_H_
#define PROXYTRANSCEIVERFLOORINDICATOR_H_

#include "UARTObserver.h"

class ProxyTransceiverFloorIndicator : public Observer {
private:
	char identChar;
public:
	ProxyTransceiverFloorIndicator(char);
	virtual ~ProxyTransceiverFloorIndicator();
	void update(std::string);
};

#endif /* PROXYTRANSCEIVERFLOORINDICATOR_H_ */
