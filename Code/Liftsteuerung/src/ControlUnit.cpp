/*
 * ControlUnit.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "ControlUnit.h"
#include "Motor.h"
#include "CallButtons.h"
#include "PositionSensors.h"
#include "FloorIndicator.h"
#include "FloorChooseButtons.h"

ControlUnit::ControlUnit() {
	// TODO Auto-generated constructor stub

	// Instanzieren der abstahierten Hardware
	Motor myMotor();
	CallButtons myCallButtons();
	PositionSensors myPositionSensors();
	FloorChooseButtons myFloorChooseButtons();
	FloorIndicator myFloorIndicator();
}

ControlUnit::~ControlUnit() {
	// TODO Auto-generated destructor stub
}

void ControlUnit::updateSensedPosition() {
	actualFloor = myPositionSensors.getSensedposition();
	myFloorIndicator.setFloor(actualFloor);
}

void ControlUnit::updateCall() {
}
