//define things for drive.c here

#define WHEEL_DIAMETER 4.4
#define MOTOR_LEFT 1
#define MOTOR_RIGHT 0
#define LEFT_FULL_POWER 97
#define RIGHT_FULL_POWER 100
#define SERVO_OPEN_CLOSE 1
#define SERVO_UP_DOWN 3
#define CLAW_OPEN CLAW_CLOSED+950
#define CLAW_DOWN 900
#define CLAW_OPEN_READY CLAW_CLOSED+600
#define CLAW_UP_READY 350
#define LS_LEFT 1
#define LS_RIGHT 0
#define TAPE_VALUE 880
#define PI 3.141592653589793236482
#define BLOCK_GRAB CLAW_CLOSED+200

//tuning constants
#define DrFLC 100/LEFT_FULL_POWER
#define DrFRC 92/RIGHT_FULL_POWER
#define veerFRC 96
#define DrBRC 94/RIGHT_FULL_POWER
#define DrBLC 100/LEFT_FULL_POWER
#define Rt 1 
#define Lt 1
#define CLAW_CLOSED 0
#define CLAW_UP 77

//tune this value to make driving as accurate as possible
#define CMTOBEMF (866/(PI*WHEEL_DIAMETER))

//claw actions
void enableAllServos();
void raiseClaw();
void raiseClawReady();
void lowerClaw();
void openClaw();
void closeClaw();
void clawCloseBack(float distance, float speed);
//drive actions
void driveForward(float distance, float speed);
void driveBackward(float distance, float speed);
void driveUntilTape(float speed);
void driveUntilLine(float speed);
void turnRight(float degrees/*, float radius*/);
void turnLeft(float degrees/*, float radius*/);
void squareUp(float speed,float time);
void veerForward(float distance, float speed);

//main

void LINK_main();
