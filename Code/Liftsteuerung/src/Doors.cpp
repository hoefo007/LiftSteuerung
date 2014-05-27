/*
 * Doors.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#include "Doors.h"
#include "IOManager.h"
#include "UARTDispatcher.h"

/**
 * @brief Constructor for doors. Initializes the variables.
 * @param IOMan
 * @return
 */
Doors::Doors(IOManager *IOMan) {
	this->IOMan = IOMan;

	this->IOMan->registrate(this, BUTTON);

	Obsv = 0;
	doorState = OPEN;
}

/**
 * @brief Destructor of Doors.
 * @param void
 * @return
 */
Doors::~Doors() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Inherited function from Informer. Updates the Observer.
 * @param void
 */
void Doors::inform(){
	if(Obsv != 0){
		Obsv->update();
	}
}

/**
 * @brief Inherited function from Informer. Registrates the Observer.
 * @param Obsv
 */
void Doors::registrate(Observer *Obsv){
	this->Obsv = Obsv;
}

/**
 * @brief Inherited function from Informer. Unregistrates the Observer.
 * @param Obsv
 */
void Doors::unregistrate(Observer *Obsv){
	this->Obsv = 0;
}

/**
 * @brief Inherited function from Observer. Called when hardware changed.
 */
void Doors::update(){
	uint8_t temp;
	temp = IOMan->getButtons();
	if(temp & 0x01){
		doorState = OPEN;
		inform();
	}
	else if(temp & 0x02){
		doorState = CLOSED;
		inform();
	}
}

/**
 * @brief Returns the state of the door (closed or open)
 * @return
 */
DoorState Doors::getDoorState(){
	return doorState;
}

/**
 * @brief Opens the door. Left blank as no output is required in model.
 */
void Doors::open(){

}

/**
 * @brief Closes the door. Left blank as no output is required in model.
 */
void Doors::close(){

}
