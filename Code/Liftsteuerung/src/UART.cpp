/*
 * UART.cpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Jan Huggler
 */

#include "UART.h"
#include "uart.h"

UART::UART(Observer *obsv) {
	USART_InitTypeDef pUSART_InitStruct;
	USART_TypeDef UARTx;
	// TODO Auto-generated constructor stub

	observer = obsv;

	CARME_UART_GPIO_Init();

	pUSART_InitStruct.USART_BaudRate = 115200;
	pUSART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	pUSART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	pUSART_InitStruct.USART_Parity = USART_Parity_No;
	pUSART_InitStruct.USART_StopBits = USART_StopBits_1;
	pUSART_InitStruct.USART_WordLength = USART_WordLength_8b;

	CARME_UART_Init(&UARTx,  &pUSART_InitStruct);
	USART_ITConfig(&USARTx, USART_IT_..., ENABLE);
}

UART::~UART() {
	// TODO Auto-generated destructor stub
}

UART::UARTRecInt(){
	obsv->update();
}

UART::UARTSendInt(){

}

UART::sendString(String sendStr){
	temp = new char[UART_SND_BUF_SIZE];

	sendBufferList.push_back(temp);
}

String UART::receiveString(){

}
