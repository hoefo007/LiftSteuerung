/*
 * ProxyChooseButtons.cpp
 *
 *  Created on: May 16, 2014
 *      Author: Jan Huggler
 */

#include "ProxyChooseButtons.h"
#include "UARTDispatcher.h"

ProxyChooseButtons::ProxyChooseButtons(UARTDispatcher *UARTDisp) {
	this->UARTDisp = UARTDisp;
	UARTDisp->registrate(this, 'i');
	chosenFloor = 0;
}

ProxyChooseButtons::~ProxyChooseButtons() {
	// TODO Auto-generated destructor stub
}

uint8_t ProxyChooseButtons::getChosenFloor(){
	char temp[10];
	temp[0] = 'b';
	temp[1] = 'r';
	temp[2] = 0;
	waitResponse = true;
	while(waitResponse == true){

	};
	return chosenFloor;
}


void ProxyChooseButtons::update(){
	char *temp;
	temp = UARTDisp->receive(this);
	chosenFloor = temp[2];
	waitResponse = false;
}
