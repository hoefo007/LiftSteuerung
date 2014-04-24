/*
 * ControlUnit.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef CONTROLUNIT_H_
#define CONTROLUNIT_H_

class ControlUnit {
private:
	int actualFloor;
public:
	ControlUnit();
	virtual ~ControlUnit();
	void updateSensedPosition();
	void updateCall();
};

#endif /* CONTROLUNIT_H_ */
