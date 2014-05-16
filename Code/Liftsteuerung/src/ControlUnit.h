/*
 * ControlUnit.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef CONTROLUNIT_H_
#define CONTROLUNIT_H_
	class Motor;
	class CallButtons;
	class PositionSensors;
	class FloorChooseButtons;
	class FloorIndicator;
	class IOManager;


class ControlUnit {
private:
	int actualFloor;
	// abstahierte Hardware
	IOManager *IOMan;
	Motor *myMotor;
	CallButtons *myCallButtons;
	PositionSensors *myPositionSensors;
	FloorChooseButtons *myFloorChooseButtons;
	FloorIndicator *myFloorIndicator;
public:
	ControlUnit();
	virtual ~ControlUnit();
	void updateSensedPosition();
	void updateCall();
};

#endif /* CONTROLUNIT_H_ */
