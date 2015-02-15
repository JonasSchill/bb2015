//all other files include template.h
//include and define global things here

//comment out the one you are not using, using create and commenting out link by default

#define CREATE
//#define LINK

//include global things here
#include <stdio.h>

#ifdef CREATE
	//include create specific things here
	#include "./createDrive.h"
#endif

#ifdef LINK
	//include link specific things here
	#include "./drive.h"
#endif

//define more things here use the defined create or link at the top to define the correct things