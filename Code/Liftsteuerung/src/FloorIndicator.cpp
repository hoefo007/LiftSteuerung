/*
 * FloorIndicator.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "FloorIndicator.h"
/*
FloorIndicator::FloorIndicator() {
	// TODO Auto-generated constructor stub
}*/

FloorIndicator::~FloorIndicator() {
	// TODO Auto-generated destructor stub
}
FloorIndicator::FloorIndicator(IOManager *ioMan) {
	// TODO Auto-generated constructor stub
	IOMan = ioMan;
}

void FloorIndicator::setFloor(char floor){
	actualFloor = floor;
	IOMan->setLeds(floor, 0xFF);
}
