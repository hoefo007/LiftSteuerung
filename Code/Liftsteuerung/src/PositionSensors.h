/*
 * PositionSensors.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef POSITIONSENSORS_H_
#define POSITIONSENSORS_H_

#include <stdint.h>
#include "Informer.h"

class IOManager;
class Observer;

class PositionSensors : public Observer, public Informer {
private:
	uint8_t sensedPosition;
	char notifyAt;
	IOManager *IOMan;
	Observer *Obsv;
	void inform();
public:
	PositionSensors(IOManager*);
	virtual ~PositionSensors();
	uint8_t getSensedPosition();
	void setNotifyPosition(char);
	void registrate(Observer*);
	void unregistrate(Observer*);
	void update();
};

#endif /* POSITIONSENSORS_H_ */
