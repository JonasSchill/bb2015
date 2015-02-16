#include "drive.h"

//---------Claw actions---------//

	void enableAllServos() {
		lowerClaw();
		openClaw();
			enable_servos();
	}
	
	void raiseClaw () {
		set_servo_position(SERVO_UP_DOWN,CLAW_UP);
	}
	
	void lowerClaw () {
		set_servo_position(SERVO_UP_DOWN,CLAW_DOWN);
	}
	
	void openClaw () {
		set_servo_position(SERVO_OPEN_CLOSE,CLAW_OPEN);
	}
	
	void closeClaw () {
		set_servo_position(SERVO_OPEN_CLOSE,CLAW_CLOSE);
	}
	
	void dumpClaw () {
		closeClaw();
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
