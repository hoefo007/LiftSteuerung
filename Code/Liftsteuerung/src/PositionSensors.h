/*
 * PositionSensors.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef POSITIONSENSORS_H_
#define POSITIONSENSORS_H_

#include <stdint.h>

class IOManager;

class PositionSensors {
private:
	char sensedPosition;
	char notifyAt;
	IOManager *IOMan;
public:
	PositionSensors(IOManager*);
	virtual ~PositionSensors();
	uint8_t getSensedPosition();
	void setNotifyPosition(char);

};

#endif /* POSITIONSENSORS_H_ */
