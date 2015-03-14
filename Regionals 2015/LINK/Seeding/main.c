#include "template.h"

int main() {
	LINK_main();
	
}

void LINK_main() {
	
	//start up
	enableAllServos();
	//squareUp(0.5, 1);
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
	turnLeft(-165);
	closeClaw();
	driveForward(65, 1);
	turnRight(95); //bump turn
	driveForward(25, 1);
	turnRight(103); //bumpy turn
	
	//drive down first alley for tribbles
	openClaw();
	lowerClaw();
	driveForward(90, 1);
	closeClaw();
	raiseClaw();
	squareUp(-0.8, 5);
	msleep(100);
	
	//back out of close alley
	driveBackward(105, 1);
	turnRight(-90); //work on 
	msleep(200);
	turnLeft(90);
	
	//down second alley
	lowerClaw();
	openClaw();
	driveForward(80, 1);
	closeClaw();
	raiseClaw();
	msleep(1000);
	squareUp(-0.8, 5);
	
	driveBackward(90, 1);
	
	turnLeft(-90); //work on 
	driveBackward(40, 1);
	turnRight(90);
	driveForward(103, 1);
}
