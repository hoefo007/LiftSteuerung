/*
 * Cabin.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef CABIN_H_
#define CABIN_H_

class ProxyTransceiverFloorIndicator;
class ProxyTransceiverChooseButtons;
class FloorIndicator;
class FloorChooseButtons;
class UARTDispatcher;
class IOManager;
class Doors;
class ProxyTransceiverDoors;

class Cabin {
private:
	char actualFloor;
	ProxyTransceiverFloorIndicator *FloorIndProxy;
	ProxyTransceiverChooseButtons *ChooseButProxy;
	FloorIndicator *FloorInd;
	FloorChooseButtons *ChooseBut;
	UARTDispatcher *UARTDisp;
	IOManager *IOMan;
	ProxyTransceiverDoors *DoorsProxy;
	Doors * doors;
public:
	Cabin();
	virtual ~Cabin();
	void setActualFloor(char);
	void periodicFunction();
};

#endif /* CABIN_H_ */
