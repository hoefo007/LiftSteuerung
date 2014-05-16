/*
 * ControlUnit.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef CONTROLUNIT_H_
#define CONTROLUNIT_H_

#include <stdint.h>
	class Motor;
	class CallButtons;
	class PositionSensors;
	class FloorChooseButtons;
	class FloorIndicator;
	class IOManager;
	class ProxyChooseButtons;
	class ProxyFloorIndicator;
	class UARTDispatcher;


class ControlUnit {
private:
	uint8_t actualFloor;
	uint8_t nextFloor;
	// abstahierte Hardware
	IOManager *IOMan;
	Motor *myMotor;
	CallButtons *myCallButtons;
	PositionSensors *myPositionSensors;
	FloorChooseButtons *myFloorChooseButtons;
	FloorIndicator *myFloorIndicator;
	ProxyChooseButtons *ChooseButProxy;
	ProxyFloorIndicator *FloorIndProxy;
	UARTDispatcher *UARTDisp;
public:
	ControlUnit();
	virtual ~ControlUnit();
	void updateSensedPosition();
	void updateCall();
};

#endif /* CONTROLUNIT_H_ */
