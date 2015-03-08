#include "template.h"

int main() {

	enableAllServos();
	raiseClaw();
	closeClaw();
	msleep(500);
	
	driveForward(103.34,1);
	turnRight(90);
	driveForward(40.5,1);
	turnRight(90);
	
	lowerClaw();
	openClaw();
	driveForward(80, 1);
	closeClaw();
	raiseClaw();
	driveBackward(80, 1);
	
	turnRight(-90);
	turnLeft(90);
	
	lowerClaw();
	openClaw();
	driveForward(80, 1);
	closeClaw();
	raiseClaw();
	driveBackward(80, 1);
	
	turnLeft(90);
	driveBackward(40, 1);
	turnRight(90);
	driveForward(103, 1);
}
