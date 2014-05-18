/*
 * ProxyTransceiverChooseButtons.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: Jan Huggler
 */

#include "ProxyTransceiverChooseButtons.h"
#include "UARTDispatcher.h"
#include "FloorChooseButtons.h"
#include "IOManager.h"

ProxyTransceiverChooseButtons::ProxyTransceiverChooseButtons(char iChar, UARTDispatcher *UARTDispa, FloorChooseButtons *ChooseBut, IOManager *IOMan) {
	// TODO Auto-generated constructor stub
	identChar = iChar;
	UARTDisp = UARTDispa;
	UARTDisp->registrate(this, iChar);
	this->IOMan = IOMan;
	//this->IOMan->registrate(this, true);
	this->ChooseBut = ChooseBut;
	this->ChooseBut->registrate(this);
}

ProxyTransceiverChooseButtons::~ProxyTransceiverChooseButtons() {
	// TODO Auto-generated destructor stub
}

void ProxyTransceiverChooseButtons::update(){
	char *temp;
	uint8_t tempSwitches;
	char sendMsg[10];
	temp = UARTDisp->receive(this);
	if((temp[0] == identChar) && (temp[1] = 'r')){
		sendMsg[0] = identChar;
		sendMsg[1] = 'r';
		sendMsg[2] = ChooseBut->getChosenFloor();
		sendMsg[3] = 0;
		UARTDisp->send(sendMsg);
		UARTDisp->clearBuffer();
	}
	tempSwitches = IOMan->getSwitches();
	if(tempSwitches != 0){
		sendMsg[0] = identChar;
		sendMsg[1] = 'i';
		sendMsg[2] = ChooseBut->getChosenFloor();
		sendMsg[3] = 0;
		UARTDisp->send(sendMsg);
	}
}
