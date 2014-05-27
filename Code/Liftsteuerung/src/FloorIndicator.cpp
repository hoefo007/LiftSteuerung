/*
 * FloorIndicator.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "FloorIndicator.h"
#include "IOManager.h"

/**
 * @brief Constructor of FloorIndicator, initializes the variables
 * @param IOMan: corresponding IOManager
 */
FloorIndicator::FloorIndicator(IOManager *IOMan) {
	// TODO Auto-generated constructor stub
	this->IOMan = IOMan;
}

/**
 * @brief Destructor of FloorIndicator
 */
FloorIndicator::~FloorIndicator() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Sets the indicator to a floor
 * @param floor: floor to set in one-hot coding
 */
void FloorIndicator::setFloor(char floor){
	actualFloor = floor;
	IOMan->setLeds(floor, 0xFF);
}
