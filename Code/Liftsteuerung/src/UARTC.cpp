/*
 * UART.cpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#include "UARTC.h"
#include "UARTDispatcher.h"
#include "uart.h"
#include "intRemap.h"

UARTC::UARTC(UARTDispatcher *obsv) {
	// TODO Auto-generated constructor stub
    NVIC_InitTypeDef NVICInitStructure;
    USART_InitTypeDef      USARTInitStructre;
	observer = obsv;

	CARME_UART_GPIO_Init();

	/* USART1 configuration */
    USART_StructInit(&USARTInitStructre);
    USARTInitStructre.USART_BaudRate = 115200;
    CARME_UART_Init(CARME_UART0, &USARTInitStructre);

    /* Enabling interrupt from USART1 */
    NVICInitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVICInitStructure.NVIC_IRQChannelPreemptionPriority = 12;
    NVICInitStructure.NVIC_IRQChannelSubPriority = 0;
    NVICInitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVICInitStructure);

    /* Receive Data register not empty interrupt */
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    registerIRQ(USART, UARTRecInt);

    bufferIndex = 0;
}

UARTC::~UARTC() {
	// TODO Auto-generated destructor stub
}

void UARTC::UARTRecInt(){
	uint16_t temp;
	std::string tempString;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		temp = USART_ReceiveData(USART1);
		bufferIndex++;
		recvBuffer[bufferIndex] = static_cast<char>(temp);
		if(temp == 0){
			tempString = recvBuffer;
			recvBufferList.push_back(tempString);
			bufferIndex = 0;
			observer->update();
		}
	}
}

void UARTC::sendString(std::string sendStr){
	char temp[sendStr.size()];
	strcpy(temp, sendStr.c_str());
	CARME_UART_SendString(USART1, temp);
}

std::string UARTC::receiveString(){
	std::string temp = recvBufferList.front();
	recvBufferList.pop_front();
	return temp;
}
