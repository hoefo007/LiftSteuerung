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

	myMotor=new Motor;
	myCallButtons= new CallButtons;
	myPositionSensors= new PositionSensors;
	myFloorChooseButtons= new FloorChooseButtons;
	myFloorIndicator= new FloorIndicator;
}

ControlUnit::~ControlUnit() {
	// TODO Auto-generated destructor stub
}

void ControlUnit::updateSensedPosition() {
	actualFloor = myPositionSensors->getSensedPosition();
	myFloorIndicator->setFloor(actualFloor);
}

void ControlUnit::updateCall() {
}
