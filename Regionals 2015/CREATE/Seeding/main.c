#include "template.h"

//main file gets run by robot calls methods in all other files

void pingPongHigh() {
	//raiseLowerArm(ARM_HIGH - 200, 0.5);		//drives with raised arm
	//createDrive(100, 26);	
	createArmDrive(ARM_HIGH - 400, 2, 25, 80);	    //puts arm into position
	raiseLowerArm(ARM_HIGH, 1);					//gets ping pong ball
	msleep(500);
	//createDriveBack(100, 8);
	//msleep(500);
}

void pingPongMedium() {
	//raiseLowerArm(ARM_MEDIUM - 200, 1);
	//msleep(500);
	createArmDrive(ARM_MEDIUM - 200, 1, 8, -100);		//gets into position
	createTurnLeft(21);
	createDrive(100, 10);
	raiseLowerArm(ARM_MEDIUM, 1);				//gets ping pong
	msleep(500);
	//createDriveBack(100, 12);
	//msleep(500);
}
	
void pingPongLow() {
	//raiseLowerArm(ARM_LOW - 100, 1);
	createArmDrive(ARM_LOW - 100, 1, 12, -100);		//gets into position
	msleep(500);
	createTurnLeft(16);
	createDrive(100, 22);
	raiseLowerArm(ARM_LOW, 1);					//gets ping pong	
	createDriveBack(100, 15);
}

void pingPong() {
	pingPongHigh();
	pingPongMedium();
	pingPongLow();
}

void scrape(distance) {
	createTurnLeft(49);
	createDrive(100,distance);
	createTurnLeft(270);
	raiseLowerArm(ARM_HIGH, 1);
	createSquareUp(100, 1);
	createDriveBack(100, 5);
	createTurnRight(360);
}

void preparePingPong(distance) {
	createArmDrive(ARM_LOW-100, 1.5, 15, -100);
	createTurnLeft(90);
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
	createArmSquareUp(ARM_HIGH, 0.5, 2, 100);
	createDriveBack(100,5);
	createTurnRight(15);
	createBasketDump();
	createTurnLeft(15);
	createArmDrive(ARM_LOW-100, 1, 50, -100);
}

void createMain() { //This is being programmed for the actual competion now
	pingPong();
	scrape(21);
	preparePingPong(114);
	pingPong();
	prepareDump(30);
	dumpSequence();
}

int main() {
	enableDevices();
	raiseLowerArm(900, 3000);
	return 0;
}
