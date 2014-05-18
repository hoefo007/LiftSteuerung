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
#include "ProxyDoors.h"


ControlUnit::ControlUnit() {
	// TODO Auto-generated constructor stub

	IOMan = new IOManager();
	myMotor=new Motor;
	myCallButtons= new CallButtons;
	myPositionSensors= new PositionSensors(IOMan);
	ExternFloorChooseButtons= new FloorChooseButtons(IOMan);
	myFloorIndicator= new FloorIndicator(IOMan);
	UARTDisp = new UARTDispatcher();
	CabinFloorChooseButtons = new ProxyChooseButtons(UARTDisp, 'b');
	FloorIndProxy = new ProxyFloorIndicator(UARTDisp);
	CabinFloorChooseButtons->registrate(this);
	ProxyDoor = new ProxyDoors('d', UARTDisp);
	ProxyDoor->registrate(this);

	position = 0;
	requestedFloors = 0;
	direction = CUP;
	driving = false;

	myPositionSensors->registrate(this);
	CabinFloorChooseButtons->registrate(this);
	ExternFloorChooseButtons->registrate(this);

}

ControlUnit::~ControlUnit() {
	// TODO Auto-generated destructor stub
}

void ControlUnit::updateSensedPosition() {
	//actualFloor = myPositionSensors->getSensedPosition();
	//myFloorIndicator->setFloor(actualFloor);
	//FloorIndProxy->setFloor(actualFloor);
}

void ControlUnit::updateCall() {
	//requestedFloors |= ChooseButProxy->getChosenFloor();
}

void ControlUnit::periodicFunction(){
	IOMan->periodicFunction();
}

void ControlUnit::update(){
	uint8_t sensedPosition;
	uint8_t cnt = 1;
	sensedPosition = myPositionSensors->getSensedPosition();
	while((sensedPosition & (1 << cnt)) == 0){
		cnt++;
	}
	position = cnt;

	requestedFloors |= CabinFloorChooseButtons->getChosenFloor();
	requestedFloors |= ExternFloorChooseButtons->getChosenFloor();
	switch(state){
	case IDLE:		if(requestedFloors & (~(1<<position))){
						state = CLOSEDOOR;
						ProxyDoor->closeDoor();
					}
					break;
	case CLOSEDOOR:	if(ProxyDoor->getDoorState() == CLOSED){
						if((direction == CUP) && (requestedFloors & (0xFF << position))){
							myMotor->startMotor(UP);
							state = DRIVEUP;
						}
						else if((direction == CDOWN) && (requestedFloors & (~(0xFF << position)))){
							myMotor->startMotor(DOWN);
							state = DRIVEDOWN;
						}
					}
					break;
	case DRIVEUP:	if((sensedPosition & (1 << position))){
						state = OPENDOOR;
						ProxyDoor->openDoor();
					}
					break;
	case DRIVEDOWN:	if((sensedPosition & (1 << position))){
						state = OPENDOOR;
						ProxyDoor->openDoor();
					}
					break;
	case OPENDOOR:	if(ProxyDoor->getDoorState() == OPEN){
						state = IDLE;
					}
					break;
	default:		state = IDLE;
					break;
	}
}
