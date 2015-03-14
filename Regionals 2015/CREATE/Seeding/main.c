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
	raiseLowerArmNew(700);		//drives with raised arm
	msleep(500);
	createDrive(100, 25);
	raiseLowerArmNew(900);
	msleep(1000);
}

int main() {
	enableDevices();
	pingPongCollect();
}
