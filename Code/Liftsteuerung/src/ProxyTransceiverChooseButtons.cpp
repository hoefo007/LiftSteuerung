/*
 * ProxyTransceiverChooseButtons.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#include "ProxyTransceiverChooseButtons.h"
#include "UARTDispatcher.h"
#include "FloorChooseButtons.h"

ProxyTransceiverChooseButtons::ProxyTransceiverChooseButtons(char iChar, UARTDispatcher *UARTDispa, FloorChooseButtons *ChooseBut) {
	// TODO Auto-generated constructor stub
	identChar = iChar;
	UARTDisp = UARTDispa;
	UARTDisp->registrate(this, iChar);
	this->ChooseBut = ChooseBut;
}

ProxyTransceiverChooseButtons::~ProxyTransceiverChooseButtons() {
	// TODO Auto-generated destructor stub
}

void ProxyTransceiverChooseButtons::update(){
	char *temp;
	char sendMsg[10];
	temp = UARTDisp->receive(this);
	if(temp[1] = 'r'){
		sendMsg[0] = 'b';
		sendMsg[1] = 'r';
		sendMsg[2] = ChooseBut->getChosenFloor();
		sendMsg[3] = 0;
		UARTDisp->send(sendMsg);
	}
}
