/*
 * ProxyDoors.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#include "ProxyDoors.h"
#include "UARTDispatcher.h"

ProxyDoors::ProxyDoors(char iChar, UARTDispatcher *UARTDisp) {
	this->UARTDisp = UARTDisp;
	identChar = iChar;
	doorState = OPEN;
	this->UARTDisp->registrate(this, identChar);
}

ProxyDoors::~ProxyDoors() {
	// TODO Auto-generated destructor stub
}

void ProxyDoors::registrate(Observer *Obsv){
	this->Obsv = Obsv;
}

void ProxyDoors::unregistrate(Observer *Obsv){
	this->Obsv = 0;
}

void ProxyDoors::inform(){
	if(Obsv != 0){
		Obsv->update();
	}
}

void ProxyDoors::update(){
	char *temp;
	temp = UARTDisp->receive(this);
	if((temp[0] == identChar) && (temp[1] = 'i')){
		if(temp[2] == '1'){
			doorState = OPEN;
		}
		else{
			doorState = CLOSED;
		}
		UARTDisp->clearBuffer();
		inform();
	}
}

DoorState ProxyDoors::getDoorState(){
	return doorState;
}

void ProxyDoors::openDoor(){
	char sendMsg[10];
	sendMsg[0] = identChar;
	sendMsg[1] = 'o';
	sendMsg[2] = 0;
	UARTDisp->send(sendMsg);
}

void ProxyDoors::closeDoor(){
	char sendMsg[10];
	sendMsg[0] = identChar;
	sendMsg[1] = 'c';
	sendMsg[2] = 0;
	UARTDisp->send(sendMsg);
}
