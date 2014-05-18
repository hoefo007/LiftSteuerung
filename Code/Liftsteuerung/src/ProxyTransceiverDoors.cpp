/*
 * ProxyTransceiverDoors.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#include "ProxyTransceiverDoors.h"

#include "Doors.h";
#include "UARTDispatcher.h"

ProxyTransceiverDoors::ProxyTransceiverDoors( char iChar, Doors *doors, UARTDispatcher *UARTDisp) {
	this->doors = doors;
	this->UARTDisp = UARTDisp;
	identChar = iChar;
	this->doors->registrate(this);
	this->UARTDisp->registrate(this, identChar);

}

ProxyTransceiverDoors::~ProxyTransceiverDoors() {
	// TODO Auto-generated destructor stub
}

void ProxyTransceiverDoors::update(){
	char *temp;
	char sendMsg[10];
	temp = UARTDisp->receive(this);
	if((temp[0] == identChar) && (temp[1] = 'r')){
		sendMsg[0] = identChar;
		sendMsg[1] = 'r';
		sendMsg[2] = static_cast<char>(doors->getDoorState());
		sendMsg[3] = 0;
		UARTDisp->send(sendMsg);
		UARTDisp->clearBuffer();
	}
	else{
		sendMsg[0] = identChar;
		sendMsg[1] = 'i';
		sendMsg[2] = static_cast<char>(doors->getDoorState());
		sendMsg[3] = 0;
		UARTDisp->send(sendMsg);
	}
}
