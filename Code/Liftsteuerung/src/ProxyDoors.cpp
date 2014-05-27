/*
 * ProxyDoors.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#include "ProxyDoors.h"
#include "UARTDispatcher.h"

/**
 * @brief Constructor of ProxyDoors. Initializes the variables.
 * @param iChar: ident char for UART messages
 * @param UARTDisp: corresponding UART dispatcher
 */
ProxyDoors::ProxyDoors(char iChar, UARTDispatcher *UARTDisp) {
	this->UARTDisp = UARTDisp;
	identChar = iChar;
	doorState = OPEN;
	this->UARTDisp->registrate(this, identChar);
}

/**
 * @brief Destructor of ProxyDoors.
 */
ProxyDoors::~ProxyDoors() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Inherited function from Informer. Registers an observer.
 * @param Obsv: observer to register
 */
void ProxyDoors::registrate(Observer *Obsv){
	this->Obsv = Obsv;
}

/**
 * @brief Inherited function from Informer. Unregisters an observer.
 * @param Obsv: observer to unregister
 */
void ProxyDoors::unregistrate(Observer *Obsv){
	this->Obsv = 0;
}

/**
 * @brief Inherited function from Informer. Updates the observers.
 */
void ProxyDoors::inform(){
	if(Obsv != 0){
		Obsv->update();
	}
}

/**
 * @brief Inherited function from Observer. Called if a new UART message has been received.
 */
void ProxyDoors::update(){
	char *temp;
	temp = UARTDisp->receive(this);
	if((temp[0] == identChar) && (temp[1] = 'i')){
		if(temp[2] == '1'){
			doorState = OPEN;
		}
		else{
			doorState = CLOSED;
		}
		UARTDisp->clearBuffer();
		inform();
	}
}

/**
 * @brief Returns the actual state of Door
 * @return state of door
 */
DoorState ProxyDoors::getDoorState(){
	return doorState;
}

/**
 * @brief Opens the door. Sends a message via UART to real door.
 */
void ProxyDoors::openDoor(){
	char sendMsg[10];
	sendMsg[0] = identChar;
	sendMsg[1] = 'o';
	sendMsg[2] = 0;
	UARTDisp->send(sendMsg);
}

/**
 * @brief Closes the door. Sends a message via UART to real door.
 */
void ProxyDoors::closeDoor(){
	char sendMsg[10];
	sendMsg[0] = identChar;
	sendMsg[1] = 'c';
	sendMsg[2] = 0;
	UARTDisp->send(sendMsg);
}
