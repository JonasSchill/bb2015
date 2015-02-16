#include "drive.h"

//write driving related functions here

//			Claw actions
//		up
	void raiseClaw () {
		set_servo_position(SERVO_UP_DOWN,CLAW_UP);
	}
//		down
	void lowerClaw () {
		set_servo_position(SERVO_UP_DOWN,CLAW_DOWN);
	}
//		open
	void openClaw () {
		set_servo_position(SERVO_OPEN_CLOSE,CLAW_OPEN);
	}
	
//		close
	void closeClaw () {
		set_servo_position(SERVO_OPEN_CLOSE,CLAW_CLOSE);
	}
	
//		dump
	void dumpClaw () {
		raiseClaw();
		openClaw();
		closeClaw();
		openClaw();
		closeClaw();
		openClaw();
		closeClaw();
	}

//			Driving
//	void driveForward(Speed,Distance) {
//		motor(MOTOR_LEFT,driveForward(float Speed);
//		msleep();
//		motor(MOTOR_RIGHT,driveForward(float Speed);
//		msleep();
//	}
