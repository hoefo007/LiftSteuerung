/*
 * ProxyTransceiverDoors.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#include "ProxyTransceiverDoors.h"

#include "Doors.h"
#include "UARTDispatcher.h"

/**
 * @brief Constructor of ProxyTransceiveDoors. Initializes the variables.
 * @param iChar: ident char for UART dispatcher
 * @param doors: real doors
 * @param UARTDisp: corresponding UART dispatcher
 */
ProxyTransceiverDoors::ProxyTransceiverDoors( char iChar, Doors *doors, UARTDispatcher *UARTDisp) {
	this->doors = doors;
	this->UARTDisp = UARTDisp;
	identChar = iChar;
	this->doors->registrate(this);
	this->UARTDisp->registrate(this, identChar);

}

/**
 * @brief Destructor of ProxyTransceiverDoors.
 */
ProxyTransceiverDoors::~ProxyTransceiverDoors() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Inherited function from Observer. Called if a UART message has been received or a door action happened.
 */
void ProxyTransceiverDoors::update(){
	char *temp;
	char sendMsg[10];
	temp = UARTDisp->receive(this);
	if(temp[0] == identChar){				//If a message has been received
		if(temp[1] == 'r'){					//If the state is requested
			sendMsg[0] = identChar;			//Send answer
			sendMsg[1] = 'r';
			if(doors->getDoorState() == OPEN){
				sendMsg[2] = '1';
			}
			else{
				sendMsg[2] = '2';
			}
			sendMsg[3] = 0;
			UARTDisp->send(sendMsg);
			UARTDisp->clearBuffer();
		}
		else if(temp[1] == 'o'){			//If a open door command has been received
			doors->open();					//Open door
		}
		else if(temp[1] == 'c'){			//If a close door command has been received
			doors->close();					//Close door
		}
	}
	else{									//Otherwise update is called from IOManager
		sendMsg[0] = identChar;				//Send state of door
		sendMsg[1] = 'i';
		if(doors->getDoorState() == OPEN){
			sendMsg[2] = '1';
		}
		else{
			sendMsg[2] = '2';
		}
		sendMsg[3] = 0;
		UARTDisp->send(sendMsg);
	}
}
