#include "template.h"

//main file gets run by robot calls methods in all other files

void pingPongHigh() {
	//raiseLowerArm(ARM_HIGH - 200, 0.5);		//drives with raised arm
	//createDrive(100, 26);	
	armMove(ARM_HIGH, 4000, 34, 130);	    //puts arm into position
//	raiseLowerArm(ARM_HIGH, 1);					//gets ping pong ball
	msleep(500);
	//createDriveBack(100, 8);
	//msleep(500);
}

void pingPongMedium() {
	//raiseLowerArm(ARM_MEDIUM - 200, 1);
	//msleep(500);
	createDriveBack(100, 2);
	armMove(ARM_MEDIUM + 200, 1000, 13, -100);		//gets into position
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
	armMove(ARM_LOW+300, 1000, 10, 100);
	createDrive(100, 12);
	raiseLowerArm(ARM_LOW, 1000);
}

void pingPongHigh2() {
	createDriveBack(100, 2);
	armMove(ARM_HIGH + 500, 2000, 7, -130);		//gets into position
	msleep(500);
	createTurnRight(17);
	armMove(ARM_HIGH, 2500, 28, 200);		//gets ping pong	
	createDriveBack(100, 5);
}

void pingPongMedium2() {
	createDriveBack(100, 2);
	armMove(ARM_MEDIUM + 200, 1000, 14, -100);		//gets into position
	createTurnRight(19);
	createDrive(150, 21);
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
	createTurnLeft(58);
	createSquareUp(500, 4.15);
	createSquareUp(100, 2.3);
	createTurnRight(83);
	driveTouch(-100);	
}

void prepareDump() {
	createTurnRight(49);
	createDrive(100, 10);
	createTurnLeft(90);
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
	preparePingPong();
	pingPong2();
//	gprepareDump(60);
//	dumpSequence();
}

int main() {
	enableDevices();
	createMain();
	return 0;
}
