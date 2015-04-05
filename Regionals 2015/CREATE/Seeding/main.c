armMove#include "template.h"

//main file gets run by robot calls methods in all other files

void pingPongSequence() {
	//raiseLowerArm(ARM_HIGH - 200, 0.5);		//drives with raised arm
	//createDrive(100, 26);
	armMove(ARM_HIGH - 400, 0.5, 100, 25);
	raiseLowerArm(ARM_HIGH, 1);
	msleep(500);
	//createDriveBack(100, 8);
	//msleep(500);
	//raiseLowerArm(ARM_MEDIUM - 200, 1);
	//msleep(500);
	armMove(ARM_MEDIUM - 200, 1, -100, 8);
	createTurnLeft(21);
	createDrive(100, 10);
	raiseLowerArm(ARM_MEDIUM, 1);
	msleep(500);
	//createDriveBack(100, 12);
	//msleep(500);
	//raiseLowerArm(ARM_LOW - 100, 1);
	armMove(ARM_LOW - 100, 1, -100, 12);
	msleep(500);
	createTurnLeft(16);
	createDrive(100, 22);
	raiseLowerArm(ARM_LOW, 1);
	createDriveBack(100, 15);
}

void preparePingPong {
	createTurnLeft(49);
	createDrive(100, 135);
	createTurnLeft(90);
	createSquareUp(100,3);
	createDriveBack(80,5);
	createTurnRight(180);	
	createDriveBack(80,5);
}

void dumpSequence() {
	enableDevices();
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
	pingPongSequence();
	preparePingPong();
	pingPongSequence();
}

int main() {
	enableDevices();
	createMain();
	return 0;
}
