/*
 * ProxyTransceiverDoors.h
 *
 *  Created on: May 18, 2014
 *      Author: Jan Huggler
 */

#ifndef PROXYTRANSCEIVERDOORS_H_
#define PROXYTRANSCEIVERDOORS_H_

#include "Observer.h"

class Doors;
class UARTDispatcher;

class ProxyTransceiverDoors : public Observer {
private:
	Doors *doors;
	UARTDispatcher *UARTDisp;
	char identChar;
public:
	ProxyTransceiverDoors(char, Doors*, UARTDispatcher*);
	virtual ~ProxyTransceiverDoors();
	void update();

};

#endif /* PROXYTRANSCEIVERDOORS_H_ */
