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

class Cabin {
private:
	char actualFloor;
	ProxyTransceiverFloorIndicator *FloorIndProxy;
	ProxyTransceiverChooseButtons *ChooseButProxy;
	FloorIndicator *FloorInd;
	FloorChooseButtons *ChooseBut;
	UARTDispatcher *UARTDisp;
	IOManager *IOMan;
public:
	Cabin();
	virtual ~Cabin();
	void setActualFloor(char);
};

#endif /* CABIN_H_ */
