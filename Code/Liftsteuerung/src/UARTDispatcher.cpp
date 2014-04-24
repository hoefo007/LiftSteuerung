/*
 * UARTDispatcher.cpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#include "UARTDispatcher.h"
#include "UARTC.h"

UARTDispatcher::UARTDispatcher() {
	// TODO Auto-generated constructor stub
	uart = new UARTC(this);
}

UARTDispatcher::~UARTDispatcher() {
	// TODO Auto-generated destructor stub
}

void UARTDispatcher::send(std::string){

}

std::string UARTDispatcher::receive(Observer *obsv){

}

void UARTDispatcher::update(){
	std::string temp;
	temp = uart->receiveString();
	inform(temp);
}

void UARTDispatcher::inform(std::string inp){
	/*std::list<Observer*>::iterator ptr;
	ptr = observerList.begin();
	while((ptr != observerList.end()) && (ptr.identChar != inp[0])){
		ptr++;
	}*/
	if(charToObserver.find(inp[0]) != charToObserver.end()){
		charToObserver[inp[0]]->update();
	}
	//ptr->update(inp);
}

void UARTDispatcher::registrate(Observer *obsv){
	observerList.push_back(obsv);
}

void UARTDispatcher::unregistrate(Observer *obsv){
	std::list<Observer*>::iterator ptr;
	observerList.remove(obsv);
	/*ptr = observerList.begin();
	while(((ptr*) != obsv ) && (ptr != observerList.end())){
		if((ptr*) = obsv){
			//observerList.pop(ptr);
		}
		ptr++;
	}*/
}
