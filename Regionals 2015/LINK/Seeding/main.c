#include "template.h"

int main() {

	enableAllServos();
	raiseClaw();
	closeClaw();
	msleep(500);
	
	driveForward(103.34,1);
	turnRight(90);
	driveForward(30,1);
	turnRight(92);
	
	lowerClaw();
	openClaw();
	driveForward(80, 1);
	closeClaw();
	raiseClaw();
	driveForward(25, 0.8);
	
	driveBackward(80, 1);
	turnRight(-90); //work on 
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
