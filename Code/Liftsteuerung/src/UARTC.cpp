/*
 * UART.cpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#include <sstream>

#include "UARTC.h"
#include "UARTDispatcher.h"
#include "uart.h"
#include "intRemap.h"

std::list<char*> UARTC::recvBufferList;
UARTDispatcher *UARTC::observer;
int UARTC::bufferIndex;
char UARTC::recvBuffer[UART_REC_BUF_SIZE];




UARTC::UARTC(UARTDispatcher *obsv) {
	// TODO Auto-generated constructor stub
    NVIC_InitTypeDef NVICInitStructure;
    USART_InitTypeDef      USARTInitStructre;
	observer = obsv;

	CARME_UART_GPIO_Init();

	USART_StructInit(&USARTInitStructre);
	/* USART1 configuration */
    USARTInitStructre.USART_BaudRate = 115200;
    /*USARTInitStructre.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USARTInitStructre.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USARTInitStructre.USART_Parity = USART_Parity_No;
    USARTInitStructre.USART_StopBits = USART_StopBits_1;
    USARTInitStructre.USART_WordLength = USART_WordLength_8b;*/
    CARME_UART_Init(CARME_UART0, &USARTInitStructre);

    /* Enabling interrupt from USART1 */
    NVICInitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVICInitStructure.NVIC_IRQChannelPreemptionPriority = 5;
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
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		temp = USART_ReceiveData(USART1);
		recvBuffer[bufferIndex] = static_cast<char>(temp);
		bufferIndex++;
		if(temp == 0){
			bufferIndex = 0;
			observer->update();
		}
	}
}

void UARTC::sendString(char* sendStr){
	CARME_UART_SendString(CARME_UART0, sendStr);
}

char* UARTC::receiveString(){
	return recvBuffer;
}
