#include "createDrive.h"

void raiseArmNew(int destination) {
	/*-----------------------------------------------\
	| If looking at the Link screen right side up... |
	| Servo 0 is the left one						 |
	| Servo 1 is the right one						 |
	| Servo 0 ground is 500; increasing raises arm   |
	| Servo 1 ground is 1240; decreasing raises arm  |
	\_______________________________________________*/

	//0 is ground, 520 is horizontal
	int offset = 200;
	set_servo_position(SERVO_UP_DOWN_LEFT, 500 + destination - offset);
	set_servo_position(SERVO_UP_DOWN_RIGHT, 1240 - destination + offset);
}	
