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
	IOMan->registrate(this, SWITCH);
	Obsv = 0;
}

FloorChooseButtons::~FloorChooseButtons() {
	// TODO Auto-generated destructor stub
}

uint8_t FloorChooseButtons::getChosenFloor(){
	uint8_t temp;
	temp = newFloors;
	newFloors = 0;
	return temp;
}

void FloorChooseButtons::registrate(Observer *Obsv){
	this->Obsv = Obsv;
}

void FloorChooseButtons::unregistrate(Observer *Obsv){
	this->Obsv = 0;
}

void FloorChooseButtons::inform(){
	if(Obsv != 0){
		Obsv->update();
	}
}

void FloorChooseButtons::update(){
	newFloors |= IOMan->getSwitches();
	inform();
}
