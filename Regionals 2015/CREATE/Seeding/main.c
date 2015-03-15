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
	createDrive(100, 25);
	raiseLowerArmNew(ARM_HIGH);
	createDriveBack(100, 2);
	raiseLowerArmNew(ARM_MEDIUM - 200);
	createDriveBack(100, 8);
	createTurnLeft(21);
	createDrive(100, 12);
	raiseLowerArmNew(ARM_MEDIUM);
	raiseLowerArmNew(ARM_MEDIUM - 350);
	createDriveBack(100, 10);
	createTurnLeft(16);
	createDrive(100, 22);
	raiseLowerArmNew(ARM_LOW);
}

int main() {
	enableDevices();
	pingPongCollect();
}
