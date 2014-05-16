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
#include "UARTDispatcher.h"
#include "ProxyChooseButtons.h"
#include "ProxyFloorIndicator.h"


ControlUnit::ControlUnit() {
	// TODO Auto-generated constructor stub

	IOMan = new IOManager();
	myMotor=new Motor;
	myCallButtons= new CallButtons;
	myPositionSensors= new PositionSensors(IOMan);
	myFloorChooseButtons= new FloorChooseButtons(IOMan);
	myFloorIndicator= new FloorIndicator(IOMan);
	UARTDisp = new UARTDispatcher();
	ChooseButProxy = new ProxyChooseButtons(UARTDisp);
	FloorIndProxy = new ProxyFloorIndicator(UARTDisp);

}

ControlUnit::~ControlUnit() {
	// TODO Auto-generated destructor stub
}

void ControlUnit::updateSensedPosition() {
	actualFloor = myPositionSensors->getSensedPosition();
	myFloorIndicator->setFloor(actualFloor);
	FloorIndProxy->setFloor(actualFloor);
}

void ControlUnit::updateCall() {
	nextFloor = ChooseButProxy->getChosenFloor();
}
