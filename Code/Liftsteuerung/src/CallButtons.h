/*
 * CallButtons.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef CALLBUTTONS_H_
#define CALLBUTTONS_H_

class IOManager;

class CallButtons {
private:
	IOManager *IOMan;
public:
	CallButtons();
	virtual ~CallButtons();
	char getCallFloor();

};

#endif /* CALLBUTTONS_H_ */
