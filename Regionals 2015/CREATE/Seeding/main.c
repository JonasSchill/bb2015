#include "template.h"

//main file gets run by robot calls methods in all other files

void pingPongHigh() {
	//raiseLowerArm(ARM_HIGH - 200, 0.5);		//drives with raised arm
	//createDrive(100, 26);	
	armMove(ARM_HIGH - 400, 0.5, 25, 25);	    //puts arm into position
	raiseLowerArm(ARM_HIGH, 1);					//gets ping pong ball
	msleep(500);
	//createDriveBack(100, 8);
	//msleep(500);
}

void pingPongMedium() {
	//raiseLowerArm(ARM_MEDIUM - 200, 1);
	//msleep(500);
	armMove(ARM_MEDIUM - 200, 1, -100, 8);		//gets into position
	createTurnLeft(21);
	createDrive(100, 10);
	raiseLowerArm(ARM_MEDIUM, 1);				//gets ping pong
	msleep(500);
	//createDriveBack(100, 12);
	//msleep(500);
}
	
void pingPongLow() {
	//raiseLowerArm(ARM_LOW - 100, 1);
	armMove(ARM_LOW - 100, 1, -100, 12);		//gets into position
	msleep(500);
	createTurnLeft(16);
	createDrive(100, 22);
	raiseLowerArm(ARM_LOW, 1);					//gets ping pong	
	createDriveBack(100, 15);
}

void pingPong() {
	pingPongHigh();
//	pingPongMedium();
//	pingPongLow();
}

void preparePingPong(distance) {
	createTurnLeft(49);
	createDrive(100, distance);
	createTurnLeft(90);
	createSquareUp(100,3);
	createDriveBack(100,5);
	createTurnRight(180);	
	createDriveBack(100,5);
}

void prepareDump(distance) {
	createTurnLeft(49);
	createSquareUp(80,2);
	createDriveBack(100,distance);
	createTurnRight(90);
	createDriveBack(100,5);
}

void dumpSequence() {
	raiseLowerArm(1300, 1);
	msleep(2000);
	createSquareUp(200,3);
	createDriveBack(100,5);
	createTurnRight(15);
	createBasketDump();
	createTurnLeft(15);
	createDriveBack(100,50);
	raiseLowerArm(320, 1);
}

void createMain() { //This is being programmed for the actual competion now
	pingPong();
//	preparePingPong(135);
//	pingPong();
//	prepareDump();
}

int main() {
	enableDevices();
	raiseLowerArm(1300, 3000);
	return 0;
}
