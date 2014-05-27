/*
 * PositionSensors.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "PositionSensors.h"
#include "IOManager.h"
#include "Observer.h"

/**
 * @brief Constructor of PositionSensors. Initializes the variables.
 * @param IOMan: corresponding IOManager
 */
PositionSensors::PositionSensors(IOManager *IOMan) {
	this->IOMan = IOMan;
	this->IOMan->registrate(this, PORTA);
	Obsv = 0;
}

/**
 * @brief Destructor of PositionSensor
 */
PositionSensors::~PositionSensors() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Returns the actual sensed Position of the cabin.
 * @return sensed position
 */
uint8_t PositionSensors::getSensedPosition() {
	return sensedPosition;
}

/**
 * @brief Set the Position when observer should be informed
 * @param char1
 */
void PositionSensors::setNotifyPosition(char char1) {
}

/**
 * @brief Inherited function from Informer. Registers an observer.
 * @param obsv: observer to register
 */
void PositionSensors::registrate(Observer *obsv){
	Obsv = obsv;
}

/**
 * @brief Inherited function from Informer. Unregisters an observer.
 * @param obsv: observer to unregister
 */
void PositionSensors::unregistrate(Observer *obsv){
	Obsv = 0;
}

/**
 * @brief Inherited function from Informer. Updates the observer
 */
void PositionSensors::inform(){
	if(Obsv != 0){
		Obsv->update();
	}
}

/**
 * @brief Inherited function form Observer. Called if the position changed.
 */
void PositionSensors::update(){
	uint8_t temp;
	temp = IOMan->getPortA();
	if(temp != sensedPosition){
		sensedPosition = temp;
		inform();
	}
}
