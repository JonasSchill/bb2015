#include "template.h"

//main file gets run by robot calls methods in all other files

int main() {
	enableDevices();
	raiseLowerArmNew(ARM_DEFAULT);
	createDriveBack(100, 10);
	msleep(3000);
	/*raiseLowerArmNew(1200);
	msleep(2000);
	createSquareUp(100,8);
	createDriveBack (-100,10);
	create_stop();
	createBasketDump();
	msleep(2000);
	createBasketReturn();
	msleep(2000);
	enable_servos();
	raiseLowerArmNew(1300);
	msleep(2000);*/
}

	
void create_Main() {
	//msleep(15000); //wait for LINK blocks dump
	createTurnLeft(90);
}
