#include "template.h"

//main file gets run by robot calls methods in all other files

int main() {
	create_connect();
	createDrive(50, 0);
	create_disconnect();
	
}
	
void create_Main() {
	//msleep(15000); //wait for LINK blocks dump
	createTurnLeft(90);
}
