/*
 * IOManager.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef IOMANAGER_H_
#define IOMANAGER_H_

#include "IOObserver.h"
#include "Informer.h"
#include "carme.h"
#include "carme_io1.h"
#include "carme_io2.h"
#include <stdint.h>
#include <list>
#include <map>

typedef enum {SWITCH, BUTTON, PORTA} IOType;

class IOManager : public Informer {
private:
	uint8_t previousButtons;
	uint8_t previousSwitches;
	uint8_t previousPortA;
	uint8_t changedButtons;
	uint8_t changedSwitches;
	uint8_t changedPortA;
	Observer *buttonObserver;
	Observer *switchObserver;
	Observer *portAObserver;
public:
	IOManager();
	virtual ~IOManager();
	uint8_t getButtons();
	uint8_t getSwitches();
	uint8_t getPortA();
	void setLeds(uint8_t, uint8_t);
	void registrate(Observer*);
	void registrate(Observer*, IOType);
	void unregistrate(Observer*);
	uint16_t getADVal(CARME_IO2_ADC_CHANNEL);
	void inform();
	void periodicFunction();
};

#endif /* IOMANAGER_H_ */
