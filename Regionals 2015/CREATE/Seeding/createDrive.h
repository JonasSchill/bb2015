//define things for createDrive.c here

#define SERVO_UP_DOWN_LEFT 0
#define SERVO_UP_DOWN_RIGHT 1
#define SERVO_LEFT_GROUND 500
#define SERVO_RIGHT_GROUND 1240
#define SERVO_BASKET 3
#define BASKET_DUMPED 1250
#define BASKET_RETURNED 400

//create arm functions
void raiseLowerArmNew (float destination) {}
void createBasketDump () {}
void createBasketReturn () {}

//create drive functions
void createDrive (float speed, float distance) {}
void createTurnLeft (int degrees) {}
void createTurnRight (int degrees) {}

//create main
void create_Main() {}
