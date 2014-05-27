/*
 * ProxyFloorIndicator.cpp
 *
 *  Created on: May 16, 2014
 *      Author: Jan Huggler
 */

#include "ProxyFloorIndicator.h"
#include "UARTDispatcher.h"

/**
 * @brief Constructor of ProxyFloorIndicator
 * @param UARTDisp
 */
ProxyFloorIndicator::ProxyFloorIndicator(UARTDispatcher *UARTDisp) {
	this->UARTDisp = UARTDisp;
}

/**
 * @brief Destructor of ProxyFloorIndicator.
 */
ProxyFloorIndicator::~ProxyFloorIndicator() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Set the displayed floor. Sends a UART message to real FloorIndicator.
 * @param inFloor: floor to display
 */
void ProxyFloorIndicator::setFloor(uint8_t inFloor){
	char temp[10];
	temp[0] = 'i';
	temp[1] = 's';
	temp[2] = inFloor;
	temp[3] = 0;
	UARTDisp->send(temp);
}
