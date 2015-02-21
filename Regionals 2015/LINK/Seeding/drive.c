/**
	drive.c
	Purpose: Holds functions that move different parts of the robot.
	@author Jonas Schill, Andy Wang
	@version 1.1 2/16/2015
*/

#include "drive.h"

//---------Claw actions---------//

	void enableAllServos() {
		enable_servos();
		lowerClaw();
		closeClaw();
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
		set_servo_position(SERVO_OPEN_CLOSE,CLAW_CLOSED);
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

//---------Drive Actions---------//
	
	/**
		Drives the robot forward a specified distance at a specified speed.
		
		@param distance : The distance is measured in cm
		@param speed : The speed is a number between 0 and 1
	*/
	void driveForward(float distance, float speed) {
		clear_motor_position_counter(MOTOR_LEFT);
		clear_motor_position_counter(MOTOR_RIGHT);
		motor(MOTOR_LEFT, speed*LEFT_FULL_POWER);
		motor(MOTOR_RIGHT, speed*RIGHT_FULL_POWER);
		printf("%d", get_motor_position_counter(MOTOR_LEFT));
		while(get_motor_position_counter(MOTOR_LEFT)< distance*CMTOBEMF  && get_motor_position_counter(MOTOR_RIGHT) < distance*CMTOBEMF) {
		}
		printf("%d", get_motor_position_counter(MOTOR_LEFT));
		ao();
	}
	
	/**
		Drives the robot backward a specified distance at a specified speed.
		
		@param distance : The distance is measured in cm
		@param speed : The speed is a number between 0 and 1
	*/
	void driveBackward(float distance, float speed) {
		
	}
	
	/**
		Drives the robot in a specified direction until it reaches a black line.
		
		@param direction : 0 is forward and 1 is backward
		@param distance : The distance is measured in cm
		@param speed : The speed is a number between 0 and 1
	*/
	void driveUntilLine(int direction, float speed) {
		
	}
	
	/**
		Makes the robot follow a line forward for a specified distance at a specified speed.
	
		@param distance : The distance the robot should go in cm
		@param speed : a number between 0 and 1
	*/
	void lineFollowForward(float distance, float speed) {
		
	}
	
	/**
		Makes the robot follow a line forward for a specified distance at a specified speed.
	
		@param distance : The distance the robot should go in cm
		@param speed : a number between 0 and 1
	*/
	void lineFollowBackward(float distance, float speed) {
		
	}
	
	/**
		Drives the robot a specified number of degrees around a circle of specified radius.
	
		@param degrees : How many degrees the robot should move around the arc
		@param radius : The radius of the arc the robot will travel in (in cm)
		@param speed : The speed is a number between 0 and 1
	*/
	void turnRight(float degrees, float radius, float speed) {
		
	}
	
	/**
		Drives the robot forward a specified distance at a specified speed.
		
		@param degrees : The distance is measured in cm
		@param radius : The radius of the arc the robot will travel in (in cm)
		@param speed The speed is a number between 0 and 1
	*/
	void turnLeft(float degrees, float radius, float speed) {
		
	}
	
	void squareUp(float speed,float time) {
		motor(MOTOR_RIGHT,speed*-1*LEFT_FULL_POWER);
		motor(MOTOR_LEFT,speed*-1*RIGHT_FULL_POWER);
		msleep(time*1000);
	}
