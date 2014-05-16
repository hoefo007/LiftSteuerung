/*
 * ProxyFloorIndicator.h
 *
 *  Created on: May 16, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYFLOORINDICATOR_H_
#define PROXYFLOORINDICATOR_H_
#include <stdint.h>
#include "FloorIndicator.h"


class UARTDispatcher;

class ProxyFloorIndicator {
private:
	UARTDispatcher *UARTDisp;
public:
	ProxyFloorIndicator(UARTDispatcher*);
	virtual ~ProxyFloorIndicator();
	void setFloor(uint8_t);
};

#endif /* PROXYFLOORINDICATOR_H_ */
