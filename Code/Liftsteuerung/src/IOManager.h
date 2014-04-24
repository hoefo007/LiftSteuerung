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
#include "carme_io2.h"
#include <stdint.h>
#include <list>
#include <map>

class IOManager : public Informer {
private:
	void ButtonInt();
	void SwitchInt();
	void TimerInt();
	std::list<Observer*> observerList;
	std::map<Observer*, uint8_t>switchMap;
	std::map<Observer*, uint8_t>buttonMap;
public:
	IOManager();
	virtual ~IOManager();
	uint8_t getButtons();
	uint8_t getSwitches();
	void setLeds(uint8_t, uint8_t);
	void registrate(Observer*, uint8_t, uint8_t);
	void unregistrate(Observer*);
	uint16_t getADVal(CARME_IO2_ADC_CHANNEL);
	void inform(uint8_t, uint8_t);
};

#endif /* IOMANAGER_H_ */
