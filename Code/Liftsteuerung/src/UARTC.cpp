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

//Static objects for Interrupt
std::list<char*> UARTC::recvBufferList;
UARTDispatcher *UARTC::observer;
int UARTC::bufferIndex;
char UARTC::recvBuffer[UART_REC_BUF_SIZE];
volatile bool UARTC::received;


/**
 * @brief Constructor of UARTC. Inizializes the UART and the variables.
 * @param obsv: corresponding UARTDispatcher
 */
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

    received = false;
    bufferIndex = 0;
}

/**
 * @brief Destructor of UARTC.
 */
UARTC::~UARTC() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief UART receive interrupt. Saves the received chars and calls dispatcher if full string has been received.
 */
void UARTC::UARTRecInt(){
	uint16_t temp;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		temp = USART_ReceiveData(USART1);				//get received char
		recvBuffer[bufferIndex] = static_cast<char>(temp);//save it in buffer
		bufferIndex++;
		if(temp == 0){									//If string termination
			bufferIndex = 0;							//update UARTDispatcher
			received = true;
			observer->update();
		}
	}
}

/**
 * @brief Sends a null terminated string.
 * @param sendStr: string to send
 */
void UARTC::sendString(char* sendStr){
	CARME_UART_SendString(CARME_UART0, sendStr);
	CARME_UART_SendChar(CARME_UART0, '\0');
}

/**
 * @brief Returns the received string.
 * @return received string
 */
char* UARTC::receiveString(){
	return recvBuffer;
}
