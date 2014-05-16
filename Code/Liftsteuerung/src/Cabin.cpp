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

Cabin::Cabin() {
	// TODO Auto-generated constructor stub
	IOMan = new IOManager();
	UARTDisp = new UARTDispatcher;
	ChooseBut = new FloorChooseButtons(IOMan);
	ChooseButProxy = new ProxyTransceiverChooseButtons('b', UARTDisp, ChooseBut);
	FloorInd = new FloorIndicator(IOMan);
	FloorIndProxy = new ProxyTransceiverFloorIndicator('i', UARTDisp, FloorInd);
}

Cabin::~Cabin() {
	// TODO Auto-generated destructor stub
}

void Cabin::setActualFloor(char char1) {
}
