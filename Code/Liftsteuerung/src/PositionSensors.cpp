/*
 * PositionSensors.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "PositionSensors.h"
#include "IOManager.h"

PositionSensors::PositionSensors(IOManager *IOMan) {
	this->IOMan = IOMan;
}

PositionSensors::~PositionSensors() {
	// TODO Auto-generated destructor stub
}

uint8_t PositionSensors::getSensedPosition() {
	return IOMan->getSwitches();
}

void PositionSensors::setNotifyPosition(char char1) {
}
