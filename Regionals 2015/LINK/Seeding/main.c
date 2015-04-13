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
	driveForward(50, 1);
	turnRight(108); //bump turn
	driveForward(24,1);
	turnRight(103); //bumpy turn	
	/*driveForward(49, 1);
	turnRight(103); //bump turn
	driveForward(28,1);
	turnRight(112); //bumpy turn*/
	turnLeft(4);
	
	//drive down first alley for tribbles
	openClaw();
	lowerClaw();
	driveForward(71, 1);
	closeClaw();
	raiseClaw();
	//driveBackward(3,1);
	msleep(500);
	
	//turn around down other alley
	raiseClaw();
	turnRight(92);
	squareUp(1, 0.5);
	turnLeft(-40);
	squareUp(1, 1.5);
	turnRight(-20);
	turnLeft(-20);
	squareUp(1, 1);
	msleep(500);
	driveForward(1, 1);
	turnRight(98);
	msleep(500);
	lowerClaw();
	openClaw();
	
<<<<<<< Updated upstream
	driveForward(60,1);
	closeClaw();
	raiseClaw();
	driveForward(15, 1);
=======
	veerForward(78,1);
>>>>>>> Stashed changes
	lowerClaw();
	openClaw();
	driveForward(90, 1);
	closeClaw();
	raiseClaw();
	msleep(1000);
	
	turnRight(74);
	squareUp(1, 0.5);
	turnLeft(-35);
	squareUp(1, 1.5);
	turnRight(-20);
	turnLeft(-20);
	squareUp(1, 1);
	msleep(500);
	turnRight(100);
	lowerClaw();
	openClaw();
	driveForward(37, 1);
	closeClaw();
	raiseClaw();
	driveForward(22, 1);
	turnRight(90);
	driveForward(30,1);
	turnLeft(90);
	raiseClawReady();
	dumpClaw();
}
