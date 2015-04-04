#include "template.h"

//main file gets run by robot calls methods in all other files

void dumpSequence() {
	enableDevices();
	raiseLowerArmNew(1300, 1);
	msleep(2000);
	createSquareUp(200,3);
	createDriveBack(100,5);
	createTurnRight(15);
	createBasketDump();
	createTurnLeft(15);
	createDriveBack(100,50);
	raiseLowerArmNew(320, 1);
}

/*void createMain() { //This is being programmed for the actual competion now
	//raiseLowerArmNew(ARM_HIGH - 200, 0.5);		//drives with raised arm
	//createDrive(100, 26);
	driveAndServo(ARM_HIGH - 400, 0.5, 100, 25);
	raiseLowerArmNew(ARM_HIGH, 1);
	msleep(500);
	//createDriveBack(100, 8);
	//msleep(500);
	//raiseLowerArmNew(ARM_MEDIUM - 200, 1);
	//msleep(500);
	driveAndServo(ARM_MEDIUM - 200, 1, -100, 8);
	createTurnLeft(21);
	createDrive(100, 10);
	raiseLowerArmNew(ARM_MEDIUM, 1);
	msleep(500);
	//createDriveBack(100, 12);
	//msleep(500);
	//raiseLowerArmNew(ARM_LOW - 100, 1);
	driveAndServo(ARM_LOW - 100, 1, -100, 12);
	msleep(500);
	createTurnLeft(16);
	createDrive(100, 22);
	raiseLowerArmNew(ARM_LOW, 1);
	createDriveBack(100, 15);
	createTurnLeft(49);
	createDrive(175, 25);
	//createTurnRight(90);
}*/

int main() {
	enableDevices();
	//createMain();
	servo_drive(ARM_HIGH, 1, 100, 20);
	/*int offset = 75;
	set_servo_position(SERVO_UP_DOWN_RIGHT, ARM_HIGH + offset);
	set_servo_position(SERVO_UP_DOWN_LEFT, 2047 - ARM_HIGH - offset);*/
}
