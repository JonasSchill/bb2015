#include "template.h"

int main() {
	LINK_main();
	/*enable_servos();
	raiseClaw();
	driveBackward(40, 1);*/
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
	driveForward(30,1);
	//driveUntilLine(1);
	//msleep(500);
	//driveBackward(1, 1);
	msleep(1000);
	turnRight(85);
	msleep(2000);
	
	lowerClaw();
	openClaw();
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
