/*
 * ProxyDoors.h
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYDOORS_H_
#define PROXYDOORS_H_

#include "Observer.h"
#include "Informer.h"
#include "Doors.h"

class UARTDispatcher;

class ProxyDoors : public Informer, public Observer {
private:
	char identChar;
	UARTDispatcher *UARTDisp;
	Observer *Obsv;
	DoorState doorState;
	void inform();
public:
	ProxyDoors(char, UARTDispatcher*);
	virtual ~ProxyDoors();
	void registrate(Observer*);
	void unregistrate(Observer*);
	void update();
	DoorState getDoorState();
	void closeDoor();
	void openDoor();
};

#endif /* PROXYDOORS_H_ */
