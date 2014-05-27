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

/**
 * @brief Constructor of ControlUnit. Creates the elements of ControlUnit and initializes the variables.
 * @param void
 * @return
 */
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

/**
 * @brief Destructor of ControlUnit. Deletes the elements of ControlUnit.
 * @param void
 * @return
 */
ControlUnit::~ControlUnit() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Periodic function of the ControlUnit, used for polling
 * @param void
 * @return
 */
void ControlUnit::periodicFunction(){
	IOMan->periodicFunction();
}

/**
 * @brief Inherited update function. Called if changes in hardware are detected. Gets the new values and calculates the desired action.
 * @param void
 * @return
 */
void ControlUnit::update(){
	uint8_t sensedPosition;
	uint8_t cnt = 0;
	sensedPosition = myPositionSensors->getSensedPosition();	//Get position in one-hot
	while((sensedPosition & (1 << cnt)) == 0){					//Convert to regular int
		cnt++;
	}
	position = cnt;

	IOMan->setLeds(sensedPosition, 0xFF);			//Display actual position
	FloorIndProxy->setFloor(sensedPosition);

	requestedFloors |= CabinFloorChooseButtons->getChosenFloor();	//Get requested Floors
	requestedFloors |= ExternFloorChooseButtons->getChosenFloor();
	//requestedFloors &= ~(sensedPosition);
	switch(state){
	case IDLE:		if((requestedFloors & (~(sensedPosition))) && (ProxyDoor->getDoorState() == OPEN)){		//If floors are requested and the door is open
						state = CLOSEDOOR;																	//Close the door
						ProxyDoor->closeDoor();
					}
					else if((requestedFloors & (~(sensedPosition))) && (ProxyDoor->getDoorState() == CLOSED)){ //If floors are requested and the door is closed
						if((direction == CUP) && (requestedFloors & (0xFF << (position + 1)))){				//If the cabin was driving upwards and a higher floor is requested
							myMotor->startMotor(UP);														//Drive upwards
							state = DRIVEUP;
						}
						else if((direction == CUP) && ((requestedFloors & (0xFF << (position + 1))) == 0)){	//If the cabin was driving upwards and a lower floor is requested
							myMotor->startMotor(DOWN);														//Drive downwards
							state = DRIVEDOWN;
							direction = CDOWN;
						}
						else if((direction == CDOWN) && (requestedFloors & (~(0xFF << position)))){			//If the cabin was driving downwards and a lower floor is requested
							myMotor->startMotor(DOWN);														//Drive downwards
							state = DRIVEDOWN;
						}
						else if((direction == CDOWN) && ((requestedFloors & (~(0xFF << position))) == 0)){	//If the cabin was driving downwards and a higher floor is requested
							myMotor->startMotor(UP);														//Drive upwards
							state = DRIVEUP;
							direction = CUP;
						}
					}
					break;
	case CLOSEDOOR:	if(ProxyDoor->getDoorState() == CLOSED){												//If the door is closed
						if((direction == CUP) && (requestedFloors & (0xFF << (position + 1)))){				//If cabin is driving up and requested floors are higher
							myMotor->startMotor(UP);														//Drive up
							state = DRIVEUP;
						}
						else if((direction == CUP) && ((requestedFloors & (0xFF << (position + 1))) == 0)){ //If Cabin was driving up and requested floors are lower
							myMotor->startMotor(DOWN);														//Drive down
							state = DRIVEDOWN;
							direction = CDOWN;
						}
						else if((direction == CDOWN) && (requestedFloors & (~(0xFF << position)))){			//If cabin was driving down and requested floors are lower
							myMotor->startMotor(DOWN);														//Drive down
							state = DRIVEDOWN;
						}
						else if((direction == CDOWN) && ((requestedFloors & (~(0xFF << position))) == 0)){	//If cabin was driving down and requested floors are higher
							myMotor->startMotor(UP);														//Drive up
							state = DRIVEUP;
							direction = CUP;
						}
					}
					break;
	case DRIVEUP:	if((sensedPosition & requestedFloors)){													//If Cabin is on requested floor
						state = OPENDOOR;																	//Open doors and stop motor
						ProxyDoor->openDoor();
						myMotor->stopMotor();
					}
					break;
	case DRIVEDOWN:	if((sensedPosition & requestedFloors)){													//If Cabin is on requested floor
						state = OPENDOOR;																	//Open doors and stop motor
						ProxyDoor->openDoor();
						myMotor->stopMotor();
					}
					break;
	case OPENDOOR:	if(ProxyDoor->getDoorState() == OPEN){													//If door is open
						state = IDLE;																		//Clear requested floor and go to wait
						requestedFloors &= ~(sensedPosition);
					}
					break;
	default:		state = IDLE;
					break;
	}
}
