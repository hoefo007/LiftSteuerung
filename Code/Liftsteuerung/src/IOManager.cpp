/*
 * IOManager.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "IOManager.h"
#include "carme.h"
#include "carme_io1.h"
#include "carme_io2.h"
#include "stm32f4xx_tim.h"
#include "intRemap.h"

IOManager::IOManager() {
	// TODO Auto-generated constructor stub
	CARME_IO1_Init();
	CARME_IO2_Init();

	//TODO Timer init
	registerIRQ(TIM2, this->TimerInt);
}

IOManager::~IOManager() {
	// TODO Auto-generated destructor stub
	unregisterIRQ(TIM2);
}

uint8_t IOManager::getSwitches(){
	uint8_t temp;
	CARME_IO1_SWITCH_Get(&temp);
	return temp;
}

uint8_t IOManager::getButtons(){
	uint8_t temp;
	CARME_IO1_BUTTON_Get(&temp);
	return temp;
}

IOManager::setLeds(uint8_t value, uint8_t mask){
	CARME_IO1_LED_Set(value, mask);
}

IOManager::getADVal(uint8_t channel){
	uint16_t temp;
	CARME_IO2_ADC_Get(channel, &temp);
	return temp;
}

IOManager::registrate(IOObserver *obsv){
	observerList.push_back(obsv);
}

IOManager::unregistrate(IOObserver obsv){
	std::list<IOObserver>::iterator ptr;
	ptr = observerList.begin();
	while((ptr != obsv ) && (ptr != observerList.end())){
		if(ptr = obsv){
			observerList.pop(ptr);
		}
		ptr++;
	}
	return;
}

IOManager::inform(uint8_t switches, uint8_t buttons){
	std::list<IOObserver>::iterator ptr;
	ptr = observerList.begin();
	while(ptr != observerList.end()){
		if(((ptr.switches & switches)|(ptr.buttons & buttons)) != 0){
			ptr.update();
		}
		ptr++;
	}
	return;
}

IOManager::timerInt(){

}

IOManager::ButtonInt(){

}

IOManager::SwitchInt(){

}
