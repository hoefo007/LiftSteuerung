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

void UARTDispatcher::send(char *input){
	uart->sendString(input);
}

char* UARTDispatcher::receive(Observer *obsv){
	return localBuffer;
}

void UARTDispatcher::update(){
	char* temp;
	temp = uart->receiveString();
	strcpy(localBuffer, temp);
	inform(localBuffer);
	//delete localBuffer;
}

void UARTDispatcher::inform(char *input){
	if(charToObserver.find(input[0]) != charToObserver.end()){
		charToObserver[input[0]]->update();
	}
}

void UARTDispatcher::registrate(Observer *obsv){
	observerList.push_back(obsv);
}

void UARTDispatcher::registrate(Observer *obsv, char ident){
	charToObserver[ident] = obsv;
}

void UARTDispatcher::unregistrate(Observer *obsv){
	observerList.remove(obsv);

}

void UARTDispatcher::inform(){

}

void UARTDispatcher::clearBuffer(){
	localBuffer[0] = 0;
}
