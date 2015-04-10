#include "template.h"

int main() {
	LINK_main();
	/*enableAllServos();
	raiseClaw();
	msleep(300);
	turnLeft(360);*/
}

void LINK_main() {
	
	//start up
	enableAllServos();
	msleep(300);
	
	//blocks to basket
 	raiseClaw();
	driveForward(30, 1);
	msleep(200);
	turnLeft(90);
	driveForward(7,1);
	msleep(200);
	turnLeft(90);
	msleep(500);
	raiseClawReady();
	openClaw();
	
	
	
	//get into position to alley
	raiseClaw();
	driveBackward(5, 1);
	turnLeft(-90);
	squareUp(1,3);
	msleep(200);
	
	raiseClaw();
	driveForward(5, 1);
	turnRight(90);
	closeClaw();
	driveForward(44, 1);
	turnRight(97); //bump turn
	driveForward(23,1);
	turnRight(108); //bumpy turn
	turnLeft(4);
	
	//drive down first alley for tribbles
	openClaw();
	lowerClaw();
	driveForward(70, 1);
	closeClaw();
	raiseClaw();
	//driveBackward(3,1);
	msleep(500);
	
	//turn around down other alley
	raiseClaw();
	turnRight(92);
	squareUp(1, 2);
	turnRight(-20);
	turnLeft(-20);
	squareUp(1, 1);
	msleep(500);
	turnRight(90);
	msleep(500);
	
	driveForward(65,1);
	lowerClaw();
	openClaw();
	driveForward(92, 1);
	closeClaw();
	raiseClaw();
	msleep(1000);
	
	turnRight(74);
	squareUp(1, 0.5);
	turnLeft(-20);
	squareUp(1, 1.5);
	turnRight(-20);
	turnLeft(-20);
	squareUp(1, 1);
	msleep(500);
	turnRight(90);
	driveForward(62,1);
	turnRight(90);
	driveForward(30,1);
	turnLeft(90); //work on 
	driveForward(30, 1);
	turnLeft(90);
}
