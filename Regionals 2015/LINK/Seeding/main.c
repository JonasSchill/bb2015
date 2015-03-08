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
	driveForward(23,1);
	driveUntilTape(1);
	msleep(1000);
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
	
	driveBackward(112, 1);
	turnRight(-90); //work on 
	msleep(200);
	driveBackward(2, 1);
	turnLeft(90);
	
	lowerClaw();
	openClaw();
	driveForward(90, 1);
	closeClaw();
	raiseClaw();
	msleep(1000);
	squareUp(-0.8, 5);
	
	driveBackward(80, 1);
	
	turnLeft(-90); //work on 
	driveBackward(40, 1);
	turnRight(90);
	driveForward(103, 1);
}
