/*
 * UARTDispatcher.cpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#include "UARTDispatcher.h"

UARTDispatcher::UARTDispatcher() {
	// TODO Auto-generated constructor stub

}

UARTDispatcher::~UARTDispatcher() {
	// TODO Auto-generated destructor stub
}

UARTDispatcher::send(string){

}

UARTDispatcher::receive(Observer){

}

UARTDispatcher::update(){
	String temp;
	temp = uart.receiveString();
	inform(temp);
}

UARTDispatcher::inform(string inp){
	std::list<UARTObserver*>::iterator ptr;
	ptr = observerList.begin();
	while((ptr != observerList.end()) && (ptr.identChar != inp[0])){
		ptr++;
	}
	ptr->update(inp);
}

UARTDispatcher::registrate(UARTObserver *obsv){
	observerList.push_back(obsv);
}

UARTDispatcher::unregistrate(UARTObserver *obsv){
	std::list<UARTObserver*>::iterator ptr;
	ptr = observerList.begin();
	while((ptr != obsv ) && (ptr != observerList.end())){
		if(ptr = obsv){
			observerList.pop(ptr);
		}
		ptr++;
	}
	return;
}
