/*
 * ProxyFloorIndicator.cpp
 *
 *  Created on: May 16, 2014
 *      Author: Jan Huggler
 */

#include "ProxyFloorIndicator.h"
#include "UARTDispatcher.h"

ProxyFloorIndicator::ProxyFloorIndicator(UARTDispatcher *UARTDisp) {
	this->UARTDisp = UARTDisp;
}

ProxyFloorIndicator::~ProxyFloorIndicator() {
	// TODO Auto-generated destructor stub
}

void ProxyFloorIndicator::setFloor(uint8_t inFloor){
	char temp[10];
	temp[0] = 'i';
	temp[1] = 's';
	temp[2] = inFloor;
	temp[3] = 0;
	UARTDisp->send(temp);
}
