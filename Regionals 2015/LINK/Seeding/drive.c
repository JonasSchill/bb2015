#include "drive.h"

<<<<<<< HEAD
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
=======
//---------Claw actions---------//

	void enableAllServos() {
			
	}
	
	void raiseClaw () {
		set_servo_position(SERVO_UP_DOWN,CLAW_UP);
	}
	
	void lowerClaw () {
		set_servo_position(SERVO_UP_DOWN,CLAW_DOWN);
	}
	
>>>>>>> FETCH_HEAD
	void openClaw () {
		set_servo_position(SERVO_OPEN_CLOSE,CLAW_OPEN);
	}
	
<<<<<<< HEAD
//		close
=======
>>>>>>> FETCH_HEAD
	void closeClaw () {
		set_servo_position(SERVO_OPEN_CLOSE,CLAW_CLOSE);
	}
	
<<<<<<< HEAD
//		dump
	void dumpClaw () {
=======
	void dumpClaw () {
		closeClaw();
>>>>>>> FETCH_HEAD
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
