/*
 * FloorChooseButtons.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "FloorChooseButtons.h"
#include "IOManager.h"

FloorChooseButtons::FloorChooseButtons(IOManager *IOManIn) {
	// TODO Auto-generated constructor stub
	IOMan = IOManIn;
}

FloorChooseButtons::~FloorChooseButtons() {
	// TODO Auto-generated destructor stub
}

uint8_t FloorChooseButtons::getChosenFloor(){
	return IOMan->getSwitches();
}
