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
}

void pingpongsequence() {
	enableDevices();	//enables devices
	raiseLowerArmNew (300);		//drives with raised arm
	msleep(1000);
	createDrive (100, 21);
	raiseLowerArmNew (780);		//picks up front ping pong
	msleep(1500);
	createSquareUp(100,3.6);	//gets in pos. for next ping pong
	raiseLowerArmNew (1240);	//picks up next ping pong
	msleep(1500);
	createSquareUp (100,1.5);	
	raiseLowerArmNew (1690);
	msleep(1000);
	createDriveBack (100,9);	//gets in pos. for next ping pong
	createTurnLeft (15);
	/*
	createDrive(100,8);			//picks up next one
	raiseLowerArmNew(800);
	createDriveBack (100,7);	//gets in pos. for next one
	createTurnLeft (15);
	createDrive (100,21);
	raiseLowerArmNew(1000);		//picks up next one
	*/
}

int main() {
	dumpSequence();
}
