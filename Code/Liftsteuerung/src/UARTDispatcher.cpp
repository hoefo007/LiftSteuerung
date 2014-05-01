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
	//delete uart;
}

void UARTDispatcher::send(std::string input){
	uart->sendString(input);
}

std::string UARTDispatcher::receive(Observer *obsv){

}

void UARTDispatcher::update(){
	std::string temp;
	temp = uart->receiveString();
	inform(temp);
}

void UARTDispatcher::inform(std::string inp){
	if(charToObserver.find(inp[0]) != charToObserver.end()){
		charToObserver[inp[0]]->update();
	}
}

void UARTDispatcher::registrate(Observer *obsv){
	observerList.push_back(obsv);
}

void UARTDispatcher::unregistrate(Observer *obsv){
	observerList.remove(obsv);

}

void UARTDispatcher::inform(){

}
