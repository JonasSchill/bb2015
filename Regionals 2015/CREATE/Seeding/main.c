#include "template.h"

//main file gets run by robot calls methods in all other files

void pingPongHigh() {
	//raiseLowerArm(ARM_HIGH - 200, 0.5);		//drives with raised arm
	//createDrive(100, 26);	
	armMove(ARM_HIGH-50, 3500, 32, 110);	    //puts arm into position
//	raiseLowerArm(ARM_HIGH, 1);					//gets ping pong ball
	msleep(500);
	//createDriveBack(100, 8);
	//msleep(500);
}

void pingPongMedium() {
	//raiseLowerArm(ARM_MEDIUM - 200, 1);
	//msleep(500);
	createDriveBack(100, 2);
	armMove(ARM_MEDIUM + 275, 1000, 15, -100);		//gets into position
	createTurnLeft(19);
	createDrive(100, 17);
	raiseLowerArm(ARM_MEDIUM-100, 1000);				//gets ping pong
	msleep(500);
	//createDriveBack(100, 12);
	//msleep(500);
}
	
void pingPongLow() {
	//raiseLowerArm(ARM_LOW - 100, 1);
	createDriveBack(100, 3);
	armMove(ARM_LOW + 350, 1000, 9, -100);		//gets into position
	msleep(500);
	createTurnLeft(16);
	createDrive(100, 27);
	raiseLowerArm(ARM_LOW-50, 1000);		//gets ping pong	
	createDriveBack(100, 5);
	raiseLowerArm(ARM_DRIVE_HEIGHT-50, 500);
}

void pingPong() {
	pingPongHigh();
	pingPongMedium();
	pingPongLow();
}

void pingPong2() {
	pingPongLow2();
	pingPongMedium2();
	pingPongHigh2();
}

void pingPongLow2() {
	armMove(ARM_LOW+400, 1000, 10, 100);
	createDrive(100, 12);
	raiseLowerArm(ARM_LOW-50, 1000);
}

void pingPongHigh2() {
	createDriveBack(100, 2);
	armMove(ARM_HIGH + 500, 2000, 8, -130);		//gets into position
	msleep(500);
	createTurnRight(18);
	armMove(ARM_HIGH-100, 2500, 27, 250);		//gets ping pong	
	createDriveBack(100, 10);
}

void pingPongMedium2() {
	createDriveBack(100, 2);
	armMove(ARM_MEDIUM + 300, 1000, 14, -100);		//gets into position
	createTurnRight(19);
	createDrive(150, 21);
	raiseLowerArm(ARM_MEDIUM - 100, 1000);				//gets ping pong
	msleep(500);
}



void scrape() {
	raiseLowerArm(100, ARM_HIGH-100);
	driveTouch(-200);
	createTurnLeft(40);
	createTurnRight(40);
	createSquareUp(200, 3.3);
	createDriveBack(100, 10);
	createTurnRight(90);
	createDrive(100, 7);
	createTurnRight(270);
/*	createTurnLeft(15);
	createDrive(100, 8);
	raiseLowerArm(ARM_HIGH-100, 1000);
	createDriveBack(100, 2);
	createTurnRight(15);*/
/*	create_drive_direct(300, 0);
	msleep(500);
	create_stop();
	create_drive_direct(0, 300);
	msleep(500);
	create_stop();
	driveTouch(-200);
//	createTurnRight(360);
//	driveTouch(-200);
	createTurnRight(40);
	set_servo_position(SERVO_BASKET, 100);
	msleep(1000);
	createTurnLeft(40);
	createDrive(100, 36);
	*/
}

void preparePingPong() {
	createTurnLeft(56);
	createSquareUp(500, 3.9);
	createSquareUp(100, 2.3);
	createTurnRight(83);
	driveTouch(-100);	
}

void dump() {
	raiseLowerArm(ARM_DRIVE_HEIGHT, 1000);
	createTurnRight(49);
	createDrive(200, 110);
	raiseLowerArm(ARM_VERY_HIGH, 1000);
	createTurnLeft(94);
	createSquareUp(200, 2);
	createBasketDump();
}

void createMain() { //This is being programmed for the actual competion now
	pingPong();
	preparePingPong();
	pingPong2();
	dump();
	scrape();
}

int main() {
	enableDevices();
//	createMain();
	scrape();
	return 0;
}
