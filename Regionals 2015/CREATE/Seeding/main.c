#include "template.h"

//main file gets run by robot calls methods in all other files

int main() {
	
}

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
}
