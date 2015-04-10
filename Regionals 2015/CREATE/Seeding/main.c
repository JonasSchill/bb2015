#include "template.h"

//main file gets run by robot calls methods in all other files

void pingPongHigh() {
	//raiseLowerArm(ARM_HIGH - 200, 0.5);		//drives with raised arm
	//createDrive(100, 26);	
	armMove(ARM_HIGH, 3500, 32, 110);	    //puts arm into position
//	raiseLowerArm(ARM_HIGH, 1);					//gets ping pong ball
	msleep(500);
	//createDriveBack(100, 8);
	//msleep(500);
}

void pingPongMedium() {
	//raiseLowerArm(ARM_MEDIUM - 200, 1);
	//msleep(500);
	createDriveBack(200, 2);
	armMove(ARM_MEDIUM + 300, 1000, 15, -100);		//gets into position
	createTurnLeft(19);
	createDrive(300, 15);
	raiseLowerArm(ARM_MEDIUM, 500);				//gets ping pong
	msleep(500);
	//createDriveBack(100, 12);
	//msleep(500);
}
	
void pingPongLow() {
	//raiseLowerArm(ARM_LOW - 100, 1);
	createDriveBack(200, 3);
	armMove(ARM_LOW + 350, 1000, 9, -150);		//gets into position
	msleep(500);
	createTurnLeft(16);
	createDrive(300, 26);
	raiseLowerArm(ARM_LOW-100, 500);		//gets ping pong	
	createDriveBack(200, 5);
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
	createTurnRight(17);
	armMove(ARM_VERY_HIGH-100, 3000, 29, 210);		//gets ping pong	
	createDriveBack(100, 10);
}

void pingPongMedium2() {
	createDriveBack(100, 2);
	armMove(ARM_MEDIUM + 300, 1000, 14, -100);		//gets into position
	createTurnRight(18);
	createDrive(150, 21);
	raiseLowerArm(ARM_MEDIUM - 150, 1000);				//gets ping pong
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
	createDrive(100, 6);
	createTurnRight(270);
}

void preparePingPong() {
	createTurnLeft(56);
	createSquareUp(500, 3.9);
	createSquareUp(100, 2.3);
	createTurnRight(84);
	driveTouch(-100);	
}

void dump() {
	raiseLowerArm(ARM_DRIVE_HEIGHT, 1000);
	createTurnRight(49);
	createDrive(200, 110);
	raiseLowerArm(ARM_VERY_HIGH-100, 1000);
	createTurnLeft(94);
	createSquareUp(200, 2);
	createBasketDump();
}

void dump2() {
	createDriveBack(100, 40);
	createTurnRight(3);
	raiseLowerArm(ARM_DOWN, 1000);
	msleep(5000);
	raiseLowerArm(ARM_VERY_HIGH-100, 1000);
	createTurnLeft(3);
	createSquareUp(300, 3);
	createTurnLeft(2);
	createBasketDump();
}

void createMain() { //This is being programmed for the actual competion now
	pingPong();
	preparePingPong();
	pingPong2();
	dump();
	dump2();
	scrape();
}

int main() {
	enableDevices();
	createMain();
	return 0;
}
