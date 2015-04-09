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
	turnLeft(-180);
	msleep(200);
	squareUp(1,3);
	closeClaw();
	driveForward(103, 1);
	turnRight(97); //bump turn
	driveForward(27,1);
	turnRight(130); //bumpy turn
	
	//drive down first alley for tribbles
	openClaw();
	lowerClaw();
	driveForward(85, 1);
	closeClaw();
	raiseClaw();
	//driveBackward(3,1);
	msleep(500);
	
	//turn around down other alley
	dualTurn(500);
	turnLeft(-95);
	squareUp(1, 1.5);
	msleep(500);
	turnRight(90);
	msleep(500);
	driveForward(70,1);
	lowerClaw();
	openClaw();
	driveForward(109, 1);
	closeClaw();
	raiseClaw();
	msleep(1000);
	turnRight(-95);
	squareUp(1,2);
	turnLeft(90);
	driveForward(58,1);
	turnRight(90);
	driveForward(30,1);
	turnLeft(90); //work on 
	driveForward(103, 1);
}
