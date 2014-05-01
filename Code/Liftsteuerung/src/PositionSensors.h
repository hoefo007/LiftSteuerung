/*
 * PositionSensors.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef POSITIONSENSORS_H_
#define POSITIONSENSORS_H_

class PositionSensors {
private:
char sensedPosition;
char notifyAt;

public:
	PositionSensors();
	virtual ~PositionSensors();
	int getSensedPosition();
	void setNotifyPosition(char);

};

#endif /* POSITIONSENSORS_H_ */
