#include "template.h"

//main file gets run by robot calls methods in all other files

int main() {
	create_connect();
<<<<<<< HEAD
	enable_servos();
	createDriveRaise(5, 800);
=======
	
>>>>>>> 5d02897bed0e79d896105b02710b69838ca6d5b4
	create_disconnect();
}

void create_Main() {
	//msleep(15000); //wait for LINK blocks dump
	createTurnLeft(90);
	
}
