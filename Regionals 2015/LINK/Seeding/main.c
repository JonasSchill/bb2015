#include "template.h"

int main() {
	LINK_main();
}

void LINK_main() {
	
	enableAllServos();
	squareUp(0.5, 1);
	msleep(1000);
	
 	raiseClaw();
	driveForward(30, 1);
	turnLeft(90);
	driveForward(7,1);
	turnLeft(85);
	msleep(500);
	raiseClawReady();
	openClaw();
	
	turnLeft(-160);
	driveForward(60, 1);
	turnRight(90);
	driveForward(35, 1);
	turnRight(90);
	
	driveForward(80, 1);
	closeClaw();
	raiseClaw();
	squareUp(-0.8, 5);
	msleep(100);
	
	driveBackward(108, 1);
	turnRight(-90); //work on 
	msleep(200);
	//driveBackward(1.5, 1);
	turnLeft(90);
	
	lowerClaw();
	openClaw();
	driveForward(85, 1);
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
