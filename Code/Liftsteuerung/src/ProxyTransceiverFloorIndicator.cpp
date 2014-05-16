/*
 * ProxyTransceiverFloorIndicator.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#include "ProxyTransceiverFloorIndicator.h"
#include "FloorIndicator.h"
#include "UARTDispatcher.h"

ProxyTransceiverFloorIndicator::ProxyTransceiverFloorIndicator(char iChar, UARTDispatcher *UARTDispa, FloorIndicator *FloorInd) {
	// TODO Auto-generated constructor stub
	this->identChar = iChar;
	this->FloorInd = FloorInd;
	this->UARTDisp = UARTDispa;
	UARTDispa->registrate(this, iChar);
}

ProxyTransceiverFloorIndicator::~ProxyTransceiverFloorIndicator() {
	// TODO Auto-generated destructor stub
}

void ProxyTransceiverFloorIndicator::update(){
	char *temp;
	temp = UARTDisp->receive(this);
	FloorInd->setFloor(temp[2]);
}
