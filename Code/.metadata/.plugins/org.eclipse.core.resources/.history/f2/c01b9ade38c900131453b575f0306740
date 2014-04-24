/*
 * IOManager.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef IOMANAGER_H_
#define IOMANAGER_H_

class IOManager : public Informer {
private:
	void ButtonInt();
	void SwitchInt();
	void TimerInt();
	std::list<IOObserver> observerList;
public:
	IOManager();
	virtual ~IOManager();
	uint8_t getButtons();
	uint8_t getSwitches();
	void setLeds(uint8_t, uint8_t);
	void registrate(IOObserver, uint8_t, uint8_t);
	void unregistrate(IOObserver);
	uint16_t getADVal(uint8_t);
	void inform(uint8_t, uint8_t);
};

#endif /* IOMANAGER_H_ */
