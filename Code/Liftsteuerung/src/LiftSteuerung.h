/*
 * LiftSteuerung.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef LIFTSTEUERUNG_H_
#define LIFTSTEUERUNG_H_

#include "ControlUnit.h"
#include "Cabin.h"

class LiftSteuerung {
private:
		ControlUnit  myControlUnit;
		Cabin myCabin;
public:
	LiftSteuerung();
	virtual ~LiftSteuerung();
};

#endif /* LIFTSTEUERUNG_H_ */
