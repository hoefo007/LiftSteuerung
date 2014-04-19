/*
 * UART.h
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#ifndef UART_H_
#define UART_H_

#define UART_REC_BUF_SIZE 10
#define UART_SND_BUF_SIZE 10

class UART {
private:
	std::list<char[UART_REC_BUF_SIZE]> recvBufferList;
	std::list<char[UART_SND_BUF_SIZE]> sendBufferList;
	Observer *observer;
//	char recvBuffer[UART_REC_BUF_SIZE];
//	char sendBuffer[UART_SND_BUF_SIZE];
	void UARTRecInt();
	void UARTSendInt();
public:
	UART(Observer*);
	virtual ~UART();
	void sendString(String);
	String receiveString();
};

#endif /* UART_H_ */
