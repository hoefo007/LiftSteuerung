/*
 * ProxyTransceiverFloorIndicator.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#include "ProxyTransceiverFloorIndicator.h"
#include "FloorIndicator.h"
#include "UARTDispatcher.h"

/**
 * @brief Constructor of ProxyTransceiverFloorIndicator. Inizializes the variables.
 * @param iChar: ident char for UART dispatcher
 * @param UARTDispa: corresponding UART dispatcher
 * @param FloorInd: real FloorIndicator
 */
ProxyTransceiverFloorIndicator::ProxyTransceiverFloorIndicator(char iChar, UARTDispatcher *UARTDispa, FloorIndicator *FloorInd) {
	// TODO Auto-generated constructor stub
	this->identChar = iChar;
	this->FloorInd = FloorInd;
	this->UARTDisp = UARTDispa;
	UARTDispa->registrate(this, iChar);
}

/**
 * @brief Destructor of ProxyTransceiverFloorIndicator
 */
ProxyTransceiverFloorIndicator::~ProxyTransceiverFloorIndicator() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Inherited function from Observer. Called if command has been received.
 */
void ProxyTransceiverFloorIndicator::update(){
	char *temp;
	temp = UARTDisp->receive(this);
	FloorInd->setFloor(temp[2]);
}
