/*
 * Doors.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#include "Doors.h"
#include "IOManager.h"
#include "UARTDispatcher.h"

Doors::Doors(IOManager *IOMan, UARTDispatcher *UARTDisp) {
	this->IOMan = IOMan;
	this->UARTDisp = UARTDisp;

	this->IOMan->registrate(this, BUTTON);

	Obsv = 0;
	doorState = OPEN;
}

Doors::~Doors() {
	// TODO Auto-generated destructor stub
}

void Doors::inform(){

}

void Doors::registrate(Observer *Obsv){
	this->Obsv = Obsv;
}

void Doors::unregistrate(Observer *Obsv){
	this->Obsv = 0;
}

void Doors::update(){
	uint8_t temp;
	temp = IOMan->getButtons();
	if(temp & 0x01){
		doorState = OPEN;
		inform();
	}
	else if(temp & 0x02){
		doorState = CLOSED;
		inform();
	}
}

DoorState Doors::getDoorState(){
	return doorState;
}
