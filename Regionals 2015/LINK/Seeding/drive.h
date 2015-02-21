//define things for drive.c here

#define WHEEL_DIAMETER 4.4
#define MOTOR_LEFT 1
#define MOTOR_RIGHT 0
#define LEFT_FULL_POWER 100
#define RIGHT_FULL_POWER 100
#define SERVO_OPEN_CLOSE 1
#define SERVO_UP_DOWN 3
#define CLAW_OPEN 900
#define CLAW_CLOSED 1600
#define CLAW_UP 300
#define CLAW_DOWN 790
#define LIGHT_LS 
#define RIGHT_LS

#define PI 3.14159265359

//tune this value to make driving as accurate as possible
#define CMTOBEMF (750/(PI*WHEEL_DIAMETER))

//claw actions
void enableAllServos();
void raiseClaw();
void lowerClaw();
void openClaw();
void closeClaw();

//drive actions
void driveForward(float distance, float speed);
void driveBackward(float distance, float speed);
void driveUntilLine(int direction, float speed);
void turnRight(float degrees, float radius);
void turnLeft(float degrees, float radius, float speed);
void squareUp(float speed,float time);

