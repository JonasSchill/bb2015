#include "template.h"

//main file gets run by robot calls methods in all other files

void pingPongHigh() {
	//raiseLowerArm(ARM_HIGH - 200, 0.5);		//drives with raised arm
	//createDrive(100, 26);	
	armMove(ARM_HIGH, 4000, 35, 130);	    //puts arm into position
//	raiseLowerArm(ARM_HIGH, 1);					//gets ping pong ball
	msleep(500);
	//createDriveBack(100, 8);
	//msleep(500);
}

void pingPongMedium() {
	//raiseLowerArm(ARM_MEDIUM - 200, 1);
	//msleep(500);
	createDriveBack(100, 2);
	armMove(ARM_MEDIUM + 200, 1000, 14, -100);		//gets into position
	createTurnLeft(24);
	createDrive(100, 10);
	raiseLowerArm(ARM_MEDIUM, 1000);				//gets ping pong
	msleep(500);
	//createDriveBack(100, 12);
	//msleep(500);
}
	
void pingPongLow() {
	//raiseLowerArm(ARM_LOW - 100, 1);
	createDriveBack(100, 2);
	armMove(ARM_LOW + 300, 1000, 7, -100);		//gets into position
	msleep(500);
	createTurnLeft(17);
	createDrive(100, 25);
	raiseLowerArm(ARM_LOW, 1000);		//gets ping pong	
	createDriveBack(100, 5);
	raiseLowerArm(ARM_DRIVE_HEIGHT, 500);
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
	createArmDrive(27);
	armMove(ARM_LOW, 2000, 8, 130);
	msleep(500);
}

void pingPongHigh2() {
	createDriveBack(100, 2);
	armMove(ARM_HIGH + 300, 100, 7, -100);		//gets into position
	msleep(500);
	createTurnRight(17);
	createDrive(100, 24);
	raiseLowerArm(ARM_HIGH, 1000);		//gets ping pong	
	createDriveBack(100, 5);
}

void pingPongMedium2() {
	createDriveBack(100, 2);
	armMove(ARM_MEDIUM + 200, 1000, 14, -100);		//gets into position
	createTurnRight(25);
	createDrive(100, 10);
	raiseLowerArm(ARM_MEDIUM, 1000);				//gets ping pong
	msleep(500);
}



void scrape(distance) {
	createTurnLeft(49);
	createDrive(100,distance);
	createTurnRight(90);
	raiseLowerArm(ARM_HIGH, 1);
	createSquareUp(100, 1);
	createDriveBack(100, 5);
	createTurnRight(360);
}

void preparePingPong() {
	createTurnLeft(57);
	createSquareUp(500, 3.75);
	createSquareUp(100, 1.3);
	createTurnRight(83);
	driveTouch(-100);	
}

void prepareDump(distance) {
	createTurnLeft(49);
	createSquareUp(80,2);
	createDriveBack(100,distance);
	createTurnRight(90);
	createDriveBack(100,5);
}

void dumpSequence() {
	createArmSquareUp(ARM_HIGH, 0.5, 2, 100);
	createDriveBack(100,5);
	createTurnRight(15);
	createBasketDump();
	createTurnLeft(15);
	armMove(ARM_LOW-100, 1, 50, -100);
}

void createMain() { //This is being programmed for the actual competion now
	pingPong();
	//scrape(28);
	preparePingPong(135);
//	pingPong2();
//	prepareDump(30);
//	dumpSequence();
}

int main() {
	enableDevices();
	createMain();
	return 0;
}
