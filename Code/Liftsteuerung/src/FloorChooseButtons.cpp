/*
 * FloorChooseButtons.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "FloorChooseButtons.h"
#include "IOManager.h"

/**
 * @brief Constructor of FloorChooseButtons. Initializes the variables.
 * @param IOManIn: corresponding IOManager
 */
FloorChooseButtons::FloorChooseButtons(IOManager *IOManIn) {
	// TODO Auto-generated constructor stub
	IOMan = IOManIn;
	IOMan->registrate(this, SWITCH);
	Obsv = 0;
}

/**
 * @brief Destructor of FloorChooseButtons
 */
FloorChooseButtons::~FloorChooseButtons() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Returns the chosen floor
 * @return chosen floors
 */
uint8_t FloorChooseButtons::getChosenFloor(){
	uint8_t temp;
	temp = newFloors;
	newFloors = 0;
	return temp;
}

/**
 * @brief Inherited function from Informer, registers observer
 * @param Obsv: observer to register
 */
void FloorChooseButtons::registrate(Observer *Obsv){
	this->Obsv = Obsv;
}

/**
 * @brief Inherited function from Informer, unregisters observer
 * @param Obsv: observer to unregister
 */
void FloorChooseButtons::unregistrate(Observer *Obsv){
	this->Obsv = 0;
}

/**
 * @brief Inherited function from Informer, updates the observer
 */
void FloorChooseButtons::inform(){
	if(Obsv != 0){
		Obsv->update();
	}
}

/**
 * @brief Inherited function from Observer, called if hardware changes
 */
void FloorChooseButtons::update(){
	newFloors |= IOMan->getSwitches();
	inform();
}
