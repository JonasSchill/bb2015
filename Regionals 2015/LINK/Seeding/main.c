#include "template.h"

int main() {
	enableAllServos();
	msleep(200);
	closeClaw();
	msleep(3000);
	raiseClaw();
	msleep(3000);
	driveForward(10,1);
	msleep(3000);
}
