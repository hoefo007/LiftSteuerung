/*
 * FloorIndicator.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "FloorIndicator.h"

FloorIndicator::FloorIndicator(IOManager *ioMan) {
	// TODO Auto-generated constructor stub
	this->IOMan = ioMan;
}

FloorIndicator::~FloorIndicator() {
	// TODO Auto-generated destructor stub
}

void FloorIndicator::setFloor(char floor){
	actualFloor = floor;
	IOMan->setLeds(floor, 0xFF);
}
