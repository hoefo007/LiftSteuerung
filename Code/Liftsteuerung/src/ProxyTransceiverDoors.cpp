/*
 * ProxyTransceiverDoors.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#include "ProxyTransceiverDoors.h"

#include "Doors.h"
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
	if(temp[0] == identChar){
		if(temp[1] == 'r'){
			sendMsg[0] = identChar;
			sendMsg[1] = 'r';
			if(doors->getDoorState() == OPEN){
				sendMsg[2] = '1';
			}
			else{
				sendMsg[2] = '2';
			}
			sendMsg[3] = 0;
			UARTDisp->send(sendMsg);
			UARTDisp->clearBuffer();
		}
		else if(temp[1] == 'o'){
			doors->open();
		}
		else if(temp[1] == 'c'){
			doors->close();
		}
	}
	else{
		sendMsg[0] = identChar;
		sendMsg[1] = 'i';
		if(doors->getDoorState() == OPEN){
			sendMsg[2] = '1';
		}
		else{
			sendMsg[2] = '2';
		}
		sendMsg[3] = 0;
		UARTDisp->send(sendMsg);
	}
}
