#include "template.h"

int main() {
	LINK_main();
}

void LINK_main() {
	
	enableAllServos();
	raiseClaw();
	closeClaw();
	squareUp(0.5, 1);
	msleep(1500);
	
	driveForward(100,1);
	turnRight(90);
	msleep(1000);
	driveForward(28,1);
	driveUntilTape(1);
	msleep(1000);
	driveBackward(1, 1);
	msleep(1000);
	turnRight(85);
	msleep(2000);
	
	lowerClaw();
	openClaw();
	driveForward(80, 1);
	closeClaw();
	raiseClaw();
	squareUp(-0.8, 5);
	msleep(500);
	
	driveBackward(108, 1);
	turnRight(-90); //work on 
	msleep(200);
	driveForward(2, 1);
	turnLeft(90);
	
	lowerClaw();
	openClaw();
	driveForward(80, 1);
	closeClaw();
	raiseClaw();
	driveBackward(80, 1);
	
	turnLeft(-90); //work on 
	driveBackward(40, 1);
	turnRight(90);
	driveForward(103, 1);
}
