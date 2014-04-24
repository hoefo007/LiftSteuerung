/*
 * Motor.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef MOTOR_H_
#define MOTOR_H_

class Motor {
private:
	char motorState;
public:
	Motor();
	virtual ~Motor();
	void startMotor(char);
	void stopMotor();
};

#endif /* MOTOR_H_ */
