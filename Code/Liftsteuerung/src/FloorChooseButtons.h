/*
 * FloorChooseButtons.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef FLOORCHOOSEBUTTONS_H_
#define FLOORCHOOSEBUTTONS_H_

#include <stdint.h>

#include "Observer.h"
#include "Informer.h"

class IOManager;

class FloorChooseButtons : public Observer, public Informer {
private:
	IOManager *IOMan;
	uint8_t newFloors;
	Observer *Obsv;
public:
	FloorChooseButtons(IOManager*);
	virtual ~FloorChooseButtons();
	uint8_t getChosenFloor();
	void registrate(Observer*);
	void unregistrate(Observer*);
	void update();
	void inform();
};

#endif /* FLOORCHOOSEBUTTONS_H_ */
