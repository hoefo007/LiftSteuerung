/*
 * Informer.h
 *
 *  Created on: Apr 14, 2014
 *      Author: Jan Huggler
 */

#ifndef INFORMER_H_
#define INFORMER_H_

#include "Observer.h"
#include <list>

class Informer {
protected:
	std::list<Observer*> observerList;
	virtual void inform()=0;
public:
	virtual void registrate(Observer*)=0;
	virtual void unregistrate(Observer*)=0;
};

#endif /* INFORMER_H_ */
