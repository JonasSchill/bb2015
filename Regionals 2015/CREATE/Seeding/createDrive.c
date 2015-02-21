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
