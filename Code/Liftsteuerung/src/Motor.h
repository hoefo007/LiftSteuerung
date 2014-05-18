/*
 * Motor.h
 *
 *  Created on: Apr 10, 2014
 *      Author: dbrue
 */

#ifndef MOTOR_H_
#define MOTOR_H_

typedef enum {UP, DOWN, STOP} MotorDir;

class Motor {
private:
	MotorDir motorState;
public:
	Motor();
	virtual ~Motor();
	void startMotor(MotorDir);
	void stopMotor();
};

#endif /* MOTOR_H_ */
