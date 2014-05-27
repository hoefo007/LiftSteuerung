/*
 * IOManager.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "IOManager.h"

/**
 * @brief Constructor of IOManager. Initializes the variables.
 */
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

/**
 * @brief Destructor of IOManager.
 */
IOManager::~IOManager() {
	// TODO Auto-generated destructor stub
	//unregisterIRQ(TIM);
}

/**
 * @brief Get the changed switches
 * @return changed switches
 */
uint8_t IOManager::getSwitches(){
	return changedSwitches;
}

/**
 * @brief Get the changed buttons
 * @return changed buttons
 */
uint8_t IOManager::getButtons(){
	return changedButtons;
}

/**
 * @brief Get the changed pins on PORTA
 * @return changed PORTA
 */
uint8_t IOManager::getPortA(){
	return changedPortA;
}
 /**
  * @brief Sets the leds
  * @param value: value to write to leds
  * @param mask: write mask for leds
  */
void IOManager::setLeds(uint8_t value, uint8_t mask){
	CARME_IO1_LED_Set(value, mask);
}

/**
 * @brief Gets the value of the AD-converter
 * @param channel: which channel to convert
 * @return converted value
 */
uint16_t IOManager::getADVal(CARME_IO2_ADC_CHANNEL channel){
	uint16_t temp;
	CARME_IO2_ADC_Get(channel, &temp);
	return temp;
}

/**
 * @brief Inherited function from Informer. Registers an observer.
 * @param obsv: observer to register
 * @param type: which input changes shall be reported to the observer
 */
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

/**
 * @brief Inherited function from Informer. Registers an observer.
 * @param obsv
 */
void IOManager::registrate(Observer *obsv){
	observerList.push_back(obsv);
}

/**
 * @brief Inherited function from Informer. Unregisters an observer.
 * @param obsv: wich observer shall be unregistred
 */
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

/**
 * @brief Inherited function from Informer. Calls the corresponding observers.
 */
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

/**
 * @brief Periodic function, polls the states of buttons, switches, PORTA and the value of the potentiometer.
 */
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
