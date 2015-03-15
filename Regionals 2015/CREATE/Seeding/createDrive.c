#include "createDrive.h"


void raiseLowerArmNew(int destination) {
	int offset = 75;
	set_servo_position(SERVO_UP_DOWN_LEFT, destination + offset);
	set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - destination - offset);
	msleep(500);
}

void createDrive (float speed, float distance) {
	set_create_distance(distance*10);
	create_drive_straight(-speed);
	while (get_create_distance()*10 >= 0){}
	create_stop();
}

void createDriveBack (float speed, float distance) {
	set_create_distance(0);
	create_drive_straight(speed);
	while (get_create_distance()/10 <= distance){}
	create_stop();
}

void createTurnLeft(int degrees) {
	set_create_normalized_angle(0); //Reset the angle
	create_spin_CCW(250); //Spin at half power
	while(get_create_normalized_angle() < degrees - 20) {} //go most of the distance
	create_spin_CCW(50); //slow down as to not overshoot
	while(get_create_normalized_angle() < degrees) {} //and finish the turn
	create_stop();
}

void createTurnRight(int degrees) {
	set_create_normalized_angle(degrees); //Reset the angle
	create_spin_CW(250); //Spin at half power
	while(get_create_normalized_angle() > 20) {} //go most of the distance
	create_spin_CW(50); //slow down as to not overshoot
	while(get_create_normalized_angle() > 0) {} //and finish the turn
	create_stop();
}

void createBasketDump(){
	set_servo_position(SERVO_BASKET, BASKET_DUMPED);
	msleep(750);
	set_servo_position(SERVO_BASKET, 1200);
	msleep(250);
	set_servo_position(SERVO_BASKET, BASKET_DUMPED);
	msleep(250);
	set_servo_position(SERVO_BASKET, BASKET_RETURNED);
	msleep(750);
}

void createSquareUp(float speed,float time){
	create_drive_direct(-1*speed,-1*speed);
	msleep(time*1000);
	create_stop();
}

void enableDevices() {
	enable_servos();
	create_connect();
}




