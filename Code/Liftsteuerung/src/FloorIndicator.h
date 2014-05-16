/*
 * FloorIndicator.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef FLOORINDICATOR_H_
#define FLOORINDICATOR_H_

#include "IOManager.h"

class FloorIndicator {
	private:
	IOManager *IOMan;
	char actualFloor;
public:
	FloorIndicator(IOManager*);
	virtual ~FloorIndicator();
	void setFloor(char);
};

#endif /* FLOORINDICATOR_H_ */
