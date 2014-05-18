/*
 * PositionSensors.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "PositionSensors.h"
#include "IOManager.h"
#include "Observer.h"

PositionSensors::PositionSensors(IOManager *IOMan) {
	this->IOMan = IOMan;
	this->IOMan->registrate(this, PORTA);
	Obsv = 0;
}

PositionSensors::~PositionSensors() {
	// TODO Auto-generated destructor stub
}

uint8_t PositionSensors::getSensedPosition() {
	return sensedPosition;
}

void PositionSensors::setNotifyPosition(char char1) {
}

void PositionSensors::registrate(Observer *obsv){
	Obsv = obsv;
}

void PositionSensors::unregistrate(Observer *obsv){
	Obsv = 0;
}

void PositionSensors::inform(){
	Obsv->update();
}

void PositionSensors::update(){
	uint8_t temp;
	temp = IOMan->getPortA();
	if(temp != sensedPosition){
		sensedPosition = temp;
		inform();
	}
}
