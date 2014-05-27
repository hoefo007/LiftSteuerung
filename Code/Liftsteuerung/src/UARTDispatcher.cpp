/*
 * UARTDispatcher.cpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#include "UARTDispatcher.h"
#include "UARTC.h"

/**
 * @brief Constructor of UARTDispatcher. Initializes the variables.
 */
UARTDispatcher::UARTDispatcher() {
	// TODO Auto-generated constructor stub
	uart = new UARTC(this);
}

/**
 * @brief Destructor of UARTDispatcher.
 */
UARTDispatcher::~UARTDispatcher() {
	// TODO Auto-generated destructor stub
	//delete uart;
}

/**
 * @brief Sends a string.
 * @param input: string to send
 */
void UARTDispatcher::send(char *input){
	uart->sendString(input);
}

/**
 * @brief Returns received String.
 * @param obsv: which observer
 * @return received string
 */
char* UARTDispatcher::receive(Observer *obsv){
	return localBuffer;
}

/**
 * @brief Update function, called from UARTC if message received. Informs the observers.
 */
void UARTDispatcher::update(){
	char* temp;
	temp = uart->receiveString();
	strcpy(localBuffer, temp);
	inform(localBuffer);
	//delete localBuffer;
}

/**
 * @brief Inherited function from Informer. Informs the observers.
 * @param input: received string
 */
void UARTDispatcher::inform(char *input){
	if(charToObserver.find(input[0]) != charToObserver.end()){
		charToObserver[input[0]]->update();
	}
}

/**
 * @brief Inherited function from Informer. Registers an observer.
 * @param Obsv: observer to register
 */
void UARTDispatcher::registrate(Observer *obsv){
	observerList.push_back(obsv);
}

/**
 * @brief Inherited function from Informer. Registers an observer.
 * @param Obsv: observer to register
 */
void UARTDispatcher::registrate(Observer *obsv, char ident){
	charToObserver[ident] = obsv;
}

/**
 * @brief Inherited function from Informer. Unregisters an observer.
 * @param Obsv: observer to unregister
 */
void UARTDispatcher::unregistrate(Observer *obsv){
	observerList.remove(obsv);

}

/**
 * @brief Inherited function from Informer. Not used.
 */
void UARTDispatcher::inform(){

}

/**
 * @brief Clears the buffer.
 */
void UARTDispatcher::clearBuffer(){
	localBuffer[0] = 0;
}
