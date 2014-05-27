/*
 * Cabin.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "Cabin.h"
#include "FloorChooseButtons.h"
#include "ProxyTransceiverChooseButtons.h"
#include "FloorIndicator.h"
#include "ProxyTransceiverFloorIndicator.h"
#include "IOManager.h"
#include "UARTDispatcher.h"
#include "Doors.h"
#include "ProxyTransceiverDoors.h"

/**
 * @brief Constructor of Cabin. Generates the elements of the Cabin
 * @param void
 * @return
 */
Cabin::Cabin() {
	// TODO Auto-generated constructor stub
	IOMan = new IOManager();
	UARTDisp = new UARTDispatcher;
	ChooseBut = new FloorChooseButtons(IOMan);
	ChooseButProxy = new ProxyTransceiverChooseButtons('b', UARTDisp, ChooseBut, IOMan);
	FloorInd = new FloorIndicator(IOMan);
	FloorIndProxy = new ProxyTransceiverFloorIndicator('i', UARTDisp, FloorInd);
	doors = new Doors(IOMan);
	DoorsProxy = new ProxyTransceiverDoors('d', doors, UARTDisp);
}

/**
 * @brief Destructor of Cabin. Deletes the elements of Cabin.
 * @param void
 * @return
 */
Cabin::~Cabin() {
	// TODO Auto-generated destructor stub
}

void Cabin::setActualFloor(char char1) {
}

/**
 * @brief Periodic function of the Cabin, used for polling
 * @param void
 * @return
 */
void Cabin::periodicFunction(){
	IOMan->periodicFunction();
}
