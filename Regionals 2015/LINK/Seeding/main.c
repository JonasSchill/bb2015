#include "template.h"

int main() {
	//LINK_main();
	
	/*turnLeft(-90);
	squareUp(1, 2);
	msleep(500);*/
	squareUp(1, 2);
	turnRight(90);
	/*msleep(500);
	driveForward(55,1);*/
	
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
	turnLeft(-165);
	closeClaw();
	driveForward(65, 1);
	turnRight(95); //bump turn
	driveForward(26, 1);
	turnRight(103); //bumpy turn
	
	//drive down first alley for tribbles
	openClaw();
	lowerClaw();
	driveForward(90, 1);
	closeClaw();
	driveBackward(4, 1);
	raiseClaw();
	
	//turn around down other alley
	turnLeft(-90);
	squareUp(1, 2);
	msleep(500);
	turnRight(90);
	msleep(500);
	driveForward(55,1);
	lowerClaw();
	openClaw();
	driveForward(110, 1);
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
