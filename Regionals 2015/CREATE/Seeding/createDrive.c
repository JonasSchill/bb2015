#include "drive.h"

//write driving related functions here

 void raiseArm() {
	clear_motor_position_counter()
	while(get_motor_position_counter(MOTOR_UP_DOWN)<---) {
		//--- means unknown number
		//I need to add in the part where you can adjust the height of the arm
		motor(MOTOR_UP_DOWN,MOTOR_UP_DOWN_SPEED);
	}
 }

 void raiseArmNew() {
	//Touching grount to fully raised is 0-100
	//Arm can go about 100 degrees
	//We only want to use about 100-1900 on the servo
	//We are using 5/9 or 0.555555... of the servo if it is exactly 180 degrees
	//We start at pos0 or pos1
	//We use about 1000 of the servo considering the angle
	enable_servos();
	int destination = 100;
	int pos0 = get_servo_position(0);
	int pos1 = get_servo_position(1);
	int dest0 = pos0 + destination * 1000;
	int dest1 = pos1 + destination * 1000;
	set_servo_position(0, dest0);
	set_servo_position(1, dest1);
 }	
