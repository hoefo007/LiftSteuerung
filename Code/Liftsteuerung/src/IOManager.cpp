/*
 * IOManager.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "IOManager.h"

IOManager::IOManager() {
	// TODO Auto-generated constructor stub
	CARME_IO1_Init();
	CARME_IO2_Init();

	//CARME_IO1_PIO_Control(CARME_IO1_PORT_A_IN);

	buttonObserver = 0;
	switchObserver = 0;
	portAObserver = 0;

	previousButtons = 0;
	previousSwitches = 0;
	changedButtons = 0;
	changedSwitches = 0;
	//TODO Timer init
	//registerIRQ(TIM, TimerInt);

}

IOManager::~IOManager() {
	// TODO Auto-generated destructor stub
	//unregisterIRQ(TIM);
}

uint8_t IOManager::getSwitches(){
	return changedSwitches;
}

uint8_t IOManager::getButtons(){
	return changedButtons;
}

uint8_t IOManager::getPortA(){
	return changedPortA;
}

void IOManager::setLeds(uint8_t value, uint8_t mask){
	CARME_IO1_LED_Set(value, mask);
}

uint16_t IOManager::getADVal(CARME_IO2_ADC_CHANNEL channel){
	uint16_t temp;
	CARME_IO2_ADC_Get(channel, &temp);
	return temp;
}

void IOManager::registrate(Observer *obsv, IOType type){
	switch(type){
		case SWITCH:	switchObserver = obsv;
		break;
		case BUTTON:	buttonObserver = obsv;
		break;
		case PORTA:		portAObserver = obsv;
		break;
		default:		break;
	}
}

void IOManager::registrate(Observer *obsv){
	observerList.push_back(obsv);
}

void IOManager::unregistrate(Observer *obsv){
	if(switchObserver == obsv){
		switchObserver = 0;
	}
	else if(buttonObserver == obsv){
		buttonObserver = 0;
	}
	else if(portAObserver == obsv){
		portAObserver = 0;
	}
}

void IOManager::inform(){
	if((switchObserver != 0) && (changedSwitches != 0)){
		switchObserver->update();
	}
	if((buttonObserver != 0) && (changedButtons != 0)){
		buttonObserver->update();
	}
	if((portAObserver != 0) && (changedPortA != 0)){
		portAObserver->update();
	}
}

void IOManager::periodicFunction(){
	uint8_t temp;
	uint16_t temp16;
	CARME_IO1_SWITCH_Get(&temp);
	changedSwitches = previousSwitches ^ temp;
	changedSwitches &= temp;
	previousSwitches = temp;
	CARME_IO1_BUTTON_Get(&temp);
	changedButtons = previousButtons ^ temp;
	changedButtons &= temp;
	previousButtons = temp;
	//CARME_IO1_PIO_Read(CARME_IO1_PORT_A, &temp);
	temp16 = getADVal(CARME_IO2_ADC_PORT0);
	temp16 = ((temp16 & 0x380) >> 7) & 0x07;
	temp16 = 1 << temp16;
	changedPortA = previousPortA ^ temp16;
	changedPortA &= temp16;
	previousPortA = temp16;
	if((changedSwitches != 0) || (changedButtons != 0) || (changedPortA != 0)){
		inform();
	}
}
