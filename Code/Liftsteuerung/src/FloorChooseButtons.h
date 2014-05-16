/*
 * FloorChooseButtons.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef FLOORCHOOSEBUTTONS_H_
#define FLOORCHOOSEBUTTONS_H_

#include <stdint.h>

class IOManager;

class FloorChooseButtons {
private:
	IOManager *IOMan;
public:
	FloorChooseButtons(IOManager*);
	virtual ~FloorChooseButtons();
	uint8_t getChosenFloor();
};

#endif /* FLOORCHOOSEBUTTONS_H_ */
