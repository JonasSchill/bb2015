#include "template.h"

//main file gets run by robot calls methods in all other files

int main() {
	enable_servos();
	create_connect()
	raiseArmNew(300);
	msleep(2000);
	create_disconnect()
}
