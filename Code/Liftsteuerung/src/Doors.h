/*
 * Doors.h
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#ifndef DOORS_H_
#define DOORS_H_

#include "Observer.h"
#include "Informer.h"

class IOManager;

typedef enum {OPEN, CLOSED} DoorState;

class Doors: public Informer, public Observer {
private:
	IOManager *IOMan;
	Observer *Obsv;
	void inform();
	DoorState doorState;
public:
	Doors(IOManager*);
	virtual ~Doors();
	void registrate(Observer*);
	void unregistrate(Observer*);
	void update();
	DoorState getDoorState();
	void close();
	void open();
};

#endif /* DOORS_H_ */
