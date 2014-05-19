/*
 * ControlUnit.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */
#include "ControlUnit.h"
#include "Motor.h"
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

void ControlUnit::periodicFunction(){
	IOMan->periodicFunction();
}

void ControlUnit::update(){
	uint8_t sensedPosition;
	uint8_t cnt = 0;
	sensedPosition = myPositionSensors->getSensedPosition();
	while((sensedPosition & (1 << cnt)) == 0){
		cnt++;
	}
	position = cnt;

	IOMan->setLeds(sensedPosition, 0xFF);
	FloorIndProxy->setFloor(sensedPosition);

	requestedFloors |= CabinFloorChooseButtons->getChosenFloor();
	requestedFloors |= ExternFloorChooseButtons->getChosenFloor();
	//requestedFloors &= ~(sensedPosition);
	switch(state){
	case IDLE:		if((requestedFloors & (~(sensedPosition))) && (ProxyDoor->getDoorState() == OPEN)){
						state = CLOSEDOOR;
						ProxyDoor->closeDoor();
					}
					else if((requestedFloors & (~(sensedPosition))) && (ProxyDoor->getDoorState() == CLOSED)){
						if((direction == CUP) && (requestedFloors & (0xFF << (position + 1)))){
							myMotor->startMotor(UP);
							state = DRIVEUP;
						}
						else if((direction == CUP) && ((requestedFloors & (0xFF << (position + 1))) == 0)){
							myMotor->startMotor(DOWN);
							state = DRIVEDOWN;
							direction = CDOWN;
						}
						else if((direction == CDOWN) && (requestedFloors & (~(0xFF << position)))){
							myMotor->startMotor(DOWN);
							state = DRIVEDOWN;
						}
						else if((direction == CDOWN) && ((requestedFloors & (~(0xFF << position))) == 0)){
							myMotor->startMotor(UP);
							state = DRIVEUP;
							direction = CUP;
						}
					}
					break;
	case CLOSEDOOR:	if(ProxyDoor->getDoorState() == CLOSED){
						if((direction == CUP) && (requestedFloors & (0xFF << (position + 1)))){
							myMotor->startMotor(UP);
							state = DRIVEUP;
						}
						else if((direction == CUP) && ((requestedFloors & (0xFF << (position + 1))) == 0)){
							myMotor->startMotor(DOWN);
							state = DRIVEDOWN;
							direction = CDOWN;
						}
						else if((direction == CDOWN) && (requestedFloors & (~(0xFF << position)))){
							myMotor->startMotor(DOWN);
							state = DRIVEDOWN;
						}
						else if((direction == CDOWN) && ((requestedFloors & (~(0xFF << position))) == 0)){
							myMotor->startMotor(UP);
							state = DRIVEUP;
							direction = CUP;
						}
					}
					break;
	case DRIVEUP:	if((sensedPosition & requestedFloors)){
						state = OPENDOOR;
						ProxyDoor->openDoor();
						myMotor->stopMotor();
					}
					break;
	case DRIVEDOWN:	if((sensedPosition & requestedFloors)){
						state = OPENDOOR;
						ProxyDoor->openDoor();
						myMotor->stopMotor();
					}
					break;
	case OPENDOOR:	if(ProxyDoor->getDoorState() == OPEN){
						state = IDLE;
						requestedFloors &= ~(sensedPosition);
					}
					break;
	default:		state = IDLE;
					break;
	}
}
