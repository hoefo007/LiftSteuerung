/*
 * Motor.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#include "Motor.h"

/**
 * @brief Constructor of Motor. Initializes the variables.
 */
Motor::Motor() {
	// TODO Auto-generated constructor stub
	motorState = STOP;
}

/**
 * @brief Destructor of Motor
 */
Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Starts the motor in a direction
 * @param direction: in which direction shall the motor turn
 */
void Motor::startMotor(MotorDir direction) {
	motorState = direction;
}

/**
 * @brief Stops the motor.
 */
void Motor::stopMotor() {
	motorState = STOP;
}
