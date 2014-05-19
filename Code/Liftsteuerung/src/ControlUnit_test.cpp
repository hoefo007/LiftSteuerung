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
   /* Method data declaration      */
   /* Method code declaration      */
	ControlUnit cUnit;
	while(1){
		cUnit.periodicFunction();
	}
   //system("PAUSE");
   return 0;
}
