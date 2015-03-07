#include "template.h"

int main() {
	enableAllServos();
	raiseClaw();
	msleep(500);
	closeClaw();
	driveForward(103.34,1);
	turnRight(90);
	driveForward(40.5,1);
	turnRight(90);
}
