/*
 * ProxyTransceiverFloorIndicator.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYTRANSCEIVERFLOORINDICATOR_H_
#define PROXYTRANSCEIVERFLOORINDICATOR_H_

class ProxyTransceiverFloorIndicator : public UARTObserver {
public:
	ProxyTransceiverFloorIndicator(char);
	virtual ~ProxyTransceiverFloorIndicator();
};

#endif /* PROXYTRANSCEIVERFLOORINDICATOR_H_ */
