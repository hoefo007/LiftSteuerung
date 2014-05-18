/*
 * Motor.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "Motor.h"

Motor::Motor() {
	// TODO Auto-generated constructor stub
	motorState = STOP;
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::startMotor(MotorDir direction) {
	motorState = direction;
}

void Motor::stopMotor() {
	motorState = STOP;
}
