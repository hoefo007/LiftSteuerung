/*
 * ProxyChooseButtons.cpp
 *
 *  Created on: May 16, 2014
 *      Author: Jan Huggler
 */

#include "ProxyChooseButtons.h"
#include "UARTDispatcher.h"

/**
 * @brief Constructor of ProxyChooseButtons. Initializes the variables.
 * @param UARTDisp: corresponding UART dispatcher
 * @param iChar: ident char for UART messages
 */
ProxyChooseButtons::ProxyChooseButtons(UARTDispatcher *UARTDisp, char iChar) {
	this->UARTDisp = UARTDisp;
	UARTDisp->registrate(this, 'b');
	chosenFloor = 0;
	Obsv = 0;
	identChar = iChar;
}

/**
 * @brief Destructor of ProxyChooseButtons
 */
ProxyChooseButtons::~ProxyChooseButtons() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Returns the chosen floors
 * @return chosen floors
 */
uint8_t ProxyChooseButtons::getChosenFloor(){
	/*char temp[10];
	temp[0] = identChar;
	temp[1] = 'r';
	temp[2] = 0;
	UARTDisp->send(temp);
	waitResponse = true;
	while(waitResponse == true){

	};*/
	return chosenFloor;
}

/**
 * @brief Inherited function from Observer. Called if a command has been received. Gets the commands and informs the observers.
 */
void ProxyChooseButtons::update(){
	char *temp;
	temp = UARTDisp->receive(this);
	if(temp[0] == identChar){
		if(temp[1]  == 'i'){
			chosenFloor = temp[2];
			inform();
		}
		else if(temp[1] == 'r'){
			chosenFloor = temp[2];
			//waitResponse = false;
		}
		UARTDisp->clearBuffer();
	}
}

/**
 * @brief Inherited function from Informer. Registers an observer.
 * @param Obsv: observer to register
 */
void ProxyChooseButtons::registrate(Observer *Obsv){
	this->Obsv = Obsv;
}

/**
 * @brief Inherited function from Informer. Unregisters an observer.
 * @param Obsv: observer to unregister
 */
void ProxyChooseButtons::unregistrate(Observer *Obsv){
	this->Obsv = 0;
}

/**
 * @brief Inherited function from Informer. Updates the observers.
 */
void ProxyChooseButtons::inform(){
	if(Obsv != 0){
		Obsv->update();
	}
}
