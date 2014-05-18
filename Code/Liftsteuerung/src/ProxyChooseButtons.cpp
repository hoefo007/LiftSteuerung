/*
 * ProxyChooseButtons.cpp
 *
 *  Created on: May 16, 2014
 *      Author: Jan Huggler
 */

#include "ProxyChooseButtons.h"
#include "UARTDispatcher.h"

ProxyChooseButtons::ProxyChooseButtons(UARTDispatcher *UARTDisp, char iChar) {
	this->UARTDisp = UARTDisp;
	UARTDisp->registrate(this, 'b');
	chosenFloor = 0;
	Obsv = 0;
	identChar = iChar;
}

ProxyChooseButtons::~ProxyChooseButtons() {
	// TODO Auto-generated destructor stub
}

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

void ProxyChooseButtons::registrate(Observer *Obsv){
	this->Obsv = Obsv;
}

void ProxyChooseButtons::unregistrate(Observer *Obsv){
	this->Obsv = 0;
}

void ProxyChooseButtons::inform(){
	if(Obsv != 0){
		Obsv->update();
	}
}
