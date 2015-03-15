#include "template.h"

//main file gets run by robot calls methods in all other files

void dumpSequence() {
	enableDevices();
	raiseLowerArmNew(1300);
	msleep(2000);
	createSquareUp(200,3);
	createDriveBack(100,5);
	createTurnRight(15);
	createBasketDump();
	createTurnLeft(15);
	createDriveBack(100,50);
	raiseLowerArmNew(320);
}

void pingPongCollect() { //This is being programmed for the actual competion now
	raiseLowerArmNew(ARM_HIGH - 200);		//drives with raised arm
	createDrive(100, 26);
	raiseLowerArmNew(ARM_HIGH);
	msleep(500);
	createDriveBack(100, 8);
	msleep(500);
	raiseLowerArmNew(ARM_MEDIUM - 200);
	msleep(500);
	createTurnLeft(25);
	createDrive(100, 10);
	raiseLowerArmNew(ARM_MEDIUM);
	msleep(1000);
	createDriveBack(100, 10);
	msleep(500);
	raiseLowerArmNew(ARM_MEDIUM - 350);
	msleep(500);
	createTurnLeft(17);
	createDrive(100, 22);
	raiseLowerArmNew(ARM_LOW);
	createDriveBack(100, 15);
	createTurnLeft(49);
	createDrive(600, 250);
	createTurnRight(90);
}

int main() {
	enableDevices();
	pingPongCollect();
}
