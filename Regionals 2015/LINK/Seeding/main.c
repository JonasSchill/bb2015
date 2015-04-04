#include "template.h"

int main() {
	LINK_main();
	//enableAllServos();
	//msleep(300);
	//turnRight(90);
}

void LINK_main() {
	
	//start up
	enableAllServos();
	msleep(300);
	
	//blocks to basket
 	raiseClaw();
	driveForward(30, 1);
	turnLeft(90);
	driveForward(7,1);
	turnLeft(90);
	msleep(500);
	raiseClawReady();
	openClaw();
	
	
	
	//get into position to alley
	raiseClaw();
	turnLeft(-180);
	squareUp(1,3);
	closeClaw();
	driveForward(97, 1);
	turnRight(97); //bump turn
	driveForward(34, 1);
	turnRight(103); //bumpy turn
	
	//drive down first alley for tribbles
	openClaw();
	lowerClaw();
	driveForward(93, 1);
	closeClaw();
	raiseClaw();
	driveBackward(3,1);
	msleep(500);
	
	//turn around down other alley
	turnLeft(-90);
	squareUp(1, 2);
	msleep(500);
	turnRight(90);
	msleep(500);
	driveForward(65,1);
	lowerClaw();
	openClaw();
	driveForward(110, 1);
	closeClaw();
	raiseClaw();
	msleep(1000);
	turnRight(-90);
	squareUp(1,2);
	turnLeft(90);
	driveForward(50,1);
	turnRight(90);
	driveForward(30,1);
	turnLeft(90); //work on 
	driveForward(103, 1);
}
