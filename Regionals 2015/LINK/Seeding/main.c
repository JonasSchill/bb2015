#include "template.h"

int main() {
	LINK_main();
/*	enableAllServos();
	raiseClaw();
	msleep(300);
	turnRight(360);*/
}

void LINK_main() {
	
	//start up
	enableAllServos();
	msleep(300);
	
	//blocks to basket
	raiseClawReady();
	driveForward(30, 1);
	msleep(200);
	turnLeft(90);
	driveForward(7,1);
	msleep(200);
	turnLeft(85);
	msleep(500);
	raiseClawReady();
	openClaw();
	msleep(400);
	closeClaw();
	
	
	
	//get into position to alley
	raiseClaw();
	driveBackward(5, 1);
	turnLeft(-100);
	squareUp(1,3);
	msleep(200);
	
	raiseClaw();
	driveForward(5, 1);
	turnRight(90);
	closeClaw();
	/*driveForward(50, 1);
	turnRight(108); //bump turn
	driveForward(24,1);
	turnRight(103); //bumpy turn	*/
	driveForward(51, 1);
	turnRight(106); //bump turn
	driveForward(28,1);
	turnRight(95); //bumpy turn*/
	lowerClaw();
	turnRight(15);
	turnLeft(4);
	
	//drive down first alley for tribbles
	openClaw();
	//lowerClaw();
	driveForward(95, 1);
	driveBackward(4,1);
	closeClaw();
	raiseClaw();
	driveBackward(5,1);
	msleep(500);
	
	//turn around down other alley
	raiseClaw();
	turnRight(100);//
	squareUp(1, 2);
	turnLeft(-30);
	squareUp(1, 2);
	//turnRight(-20);
	turnLeft(-20);
	//squareUp(1, 1);
	msleep(500);
	driveForward(1, 1);
	turnRight(98);
	msleep(500);
	lowerClaw();
	openClaw();
	
	veerForward(43,1);
	closeClaw();
	raiseClaw();
	driveForward(35,1);
	lowerClaw();
	openClaw();
	driveForward(110, 1);
	driveBackward(4,1);
	closeClaw();
	raiseClaw();
	msleep(1000);
	driveBackward(5,1);
	
	//
	//
	turnRight(100);
	squareUp(1, 2);
	//msleep()
	turnLeft(-30);
	squareUp(1, 2);
	//turnRight(-20);
	turnLeft(-30);
	//squareUp(1, 1);
	msleep(500);
	turnRight(100);
	lowerClaw();
	openClaw();
	driveForward(42, 1);
	closeClaw();
	raiseClaw();
	driveForward(30, 1);
	//msleep(3000)
	turnRight(85);
	driveForward(25,1);
	turnLeft(60);
	raiseClawReady();
	dumpClaw();
	driveBackward(50,1);
}
