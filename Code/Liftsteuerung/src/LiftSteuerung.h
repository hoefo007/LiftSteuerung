/*
 * LiftSteuerung.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef LIFTSTEUERUNG_H_
#define LIFTSTEUERUNG_H_

	class Controlunit;
	class Cabin;

class LiftSteuerung {
private:
		Controlunit  *myControlUnit;
		Cabin *myCabin;
public:
	LiftSteuerung();
	virtual ~LiftSteuerung();
};

#endif /* LIFTSTEUERUNG_H_ */
