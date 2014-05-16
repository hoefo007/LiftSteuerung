/*
 * UART.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef UART_H_
#define UART_H_


#include <stdint.h>
#include <string>
#include <string.h>
#include <list>


#define UART_REC_BUF_SIZE 10
#define UART_SND_BUF_SIZE 10

class UARTDispatcher;

class UARTC {
private:
	static std::list<char*> recvBufferList;
	static UARTDispatcher *observer;
	static int bufferIndex;
	static char recvBuffer[UART_REC_BUF_SIZE];
	static void UARTRecInt();
	//void UARTSendInt();
public:
	UARTC(UARTDispatcher*);
	virtual ~UARTC();
	void sendString(std::string);
	char* receiveString();
};

#endif /* UART_H_ */
