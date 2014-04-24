/*
 * Cabin.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef CABIN_H_
#define CABIN_H_

class Cabin {
private:
	char actualFloor;
public:
	Cabin();
	virtual ~Cabin();
	void setActualFloor(char);
};

#endif /* CABIN_H_ */
