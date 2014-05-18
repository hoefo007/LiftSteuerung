/*
 * ControlUnit.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef CONTROLUNIT_H_
#define CONTROLUNIT_H_

#include <stdint.h>

#include "Observer.h"
#include "Doors.h"

typedef enum {IDLE, CLOSEDOOR, DRIVEUP, DRIVEDOWN, OPENDOOR} UnitState;
typedef enum {CUP, CDOWN} CabinDir;

	class Motor;
	class CallButtons;
	class PositionSensors;
	class FloorChooseButtons;
	class FloorIndicator;
	class IOManager;
	class ProxyChooseButtons;
	class ProxyFloorIndicator;
	class UARTDispatcher;
	class ProxyDoors;


class ControlUnit : public Observer {
private:
	uint8_t position;
	CabinDir direction;
	uint8_t requestedFloors;
	DoorState doors;
	UnitState state;
	bool driving;
	// abstrahierte Hardware
	IOManager *IOMan;
	Motor *myMotor;
	CallButtons *myCallButtons;
	PositionSensors *myPositionSensors;
	FloorChooseButtons *ExternFloorChooseButtons;
	FloorIndicator *myFloorIndicator;
	ProxyChooseButtons *CabinFloorChooseButtons;
	ProxyFloorIndicator *FloorIndProxy;
	UARTDispatcher *UARTDisp;
	ProxyDoors *ProxyDoor;
public:
	ControlUnit();
	virtual ~ControlUnit();
	void updateSensedPosition();
	void updateCall();
	void periodicFunction();
	void update();
};

#endif /* CONTROLUNIT_H_ */
