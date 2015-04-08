//define things for createDrive.c here

#define ARM_SERVO 0
#define SERVO_BASKET 3
#define BASKET_DUMPED 1500
#define BASKET_RETURNED 350
#define ARM_LOW 950
#define ARM_MEDIUM 750
#define ARM_HIGH 460
#define OFFSET 75
#define ARM_DRIVE_HEIGHT 1750

//create arm functions
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
