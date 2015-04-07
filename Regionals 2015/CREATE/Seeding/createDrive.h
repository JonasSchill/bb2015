//define things for createDrive.c here

#define SERVO_UP_DOWN_LEFT 0
#define SERVO_UP_DOWN_RIGHT 1
#define SERVO_BASKET 3
#define BASKET_DUMPED 1500
#define BASKET_RETURNED 350
#define ARM_LOW 1300
#define ARM_MEDIUM 1600
#define ARM_HIGH 1850
#define OFFSET 75

//create arm functions
void servo_drive(int end, int time, float d_speed, float distance);
void servo_drive(int end, int time, float d_speed, float distance);
void raiseLowerArm (int destination, int time);
void armMove(int destination, float time, int distance, int speed);
void createBasketDump ();
void enableDevices ();

//create drive functions
void createDrive (float speed, float distance);
void createDriveBack (float speed, float distance);
void createTurnLeft (int degrees);
void createTurnRight (int degrees);
void createSquareUp(float speed,float time);

//create main
void create_Main();
