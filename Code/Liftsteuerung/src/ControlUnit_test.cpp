/*
 * LiftSteuerung_test.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */
#include<stdlib.h>
#include "UARTDispatcher.h"

#include "LiftSteuerung.h"
#include "IOManager.h"
#include "ControlUnit.h"

int a;



int main(int argc, char *argv[])
{
	uint8_t temp;
   /* Method data declaration      */
   /* Method code declaration      */
	//IOManager ioman;
	//UARTDispatcher uart;
	//uart.send("hallo");
	ControlUnit cUnit;
	while(1){
		cUnit.updateCall();
		cUnit.updateSensedPosition();
		//temp = ioman.getButtons();
		//ioman.setLeds(temp, 0xFF);
		//uart.send("hallo");
	}
   //system("PAUSE");
   return 0;
}
