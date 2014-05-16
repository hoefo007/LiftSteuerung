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
	char* temp;
	char* localBuffer = new char[UART_REC_BUF_SIZE];
	temp = uart->receiveString();
	strcpy(localBuffer, temp);
	inform(localBuffer);
	delete localBuffer;
}

void UARTDispatcher::inform(char *input){
	/*if(charToObserver.find(input*) != charToObserver.end()){
		charToObserver[input*]->update();
	}*/
	if(){
		(charToObserver[input*])*
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
