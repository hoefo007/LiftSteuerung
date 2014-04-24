/*
 * IOObserver.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef IOOBSERVER_H_
#define IOOBSERVER_H_

#include "Observer.h"
#include <stdint.h>

class IOObserver: public Observer {
private:
	uint8_t switches;
	uint8_t buttons;
public:
	IOObserver();
	virtual ~IOObserver();
};

#endif /* IOOBSERVER_H_ */
