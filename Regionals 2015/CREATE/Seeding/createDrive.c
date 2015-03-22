#include "createDrive.h"

void driveAndServo(int end, int time, float d_speed, float distance)
{
	int offset = 75;
	servo_drive(SERVO_UP_DOWN_LEFT, end + offset, time, d_speed, distance);
	servo_drive(SERVO_UP_DOWN_RIGHT, 2047 - end - offset, time, d_speed, distance);
}

void raiseLowerArmNew(int destination, int time) {
	int offset = 75;
	servo_set(SERVO_UP_DOWN_LEFT, destination + offset, time);
	servo_set(SERVO_UP_DOWN_RIGHT, 2047 - destination - offset, time);
	//msleep(500);
}

void createDrive (float speed, float distance) {
	set_create_distance(distance*10);
	create_drive_straight(-speed);
	while (get_create_distance()*10 >= 0){}
	create_stop();
}

void createDriveBack (float speed, float distance) {
	set_create_distance(0);
	create_drive_straight(speed);
	while (get_create_distance()/10 <= distance){}
	create_stop();
}

void createTurnLeft(int degrees) {
	set_create_normalized_angle(0); //Reset the angle
	create_spin_CCW(250); //Spin at half power
	while(get_create_normalized_angle() < degrees - 20) {} //go most of the distance
	create_spin_CCW(50); //slow down as to not overshoot
	while(get_create_normalized_angle() < degrees) {} //and finish the turn
	create_stop();
}

void createTurnRight(int degrees) {
	set_create_normalized_angle(degrees); //Reset the angle
	create_spin_CW(250); //Spin at half power
	while(get_create_normalized_angle() > 20) {} //go most of the distance
	create_spin_CW(50); //slow down as to not overshoot
	while(get_create_normalized_angle() > 0) {} //and finish the turn
	create_stop();
}

void createBasketDump(){
	set_servo_position(SERVO_BASKET, BASKET_DUMPED);
	msleep(750);
	set_servo_position(SERVO_BASKET, 1200);
	msleep(250);
	set_servo_position(SERVO_BASKET, BASKET_DUMPED);
	msleep(250);
	set_servo_position(SERVO_BASKET, BASKET_RETURNED);
	msleep(750);
}

void createSquareUp(float speed,float time){
	create_drive_direct(-1*speed,-1*speed);
	msleep(time*1000);
	create_stop();
}

void enableDevices() {
	enable_servos();
	set_servo_position(SERVO_BASKET, BASKET_RETURNED);
	create_connect();
}


void servo_set(int port, int end, int time)
{
	float increment = 0.05; 
	float tune_time = 0.19;
	float curr, start = get_servo_position(port);
	float i = ((end-start)/(time*tune_time))*increment;
	if (start > end)
	{
		while(curr > end)
		{
			set_servo_position(port, curr);
			curr+=i;
			msleep((long)(increment*1000));
		}
	} 
	else if (start < end)
	{
		while (curr < end)
		{
			set_servo_position(port, curr);
			curr+=i;
			msleep((long)(increment*1000));
		}
	}
	set_servo_position(port, end);
}

void servo_drive(int s_port, int end, int time, float d_speed, float distance)
{
	float increment = 0.05; 
	float tune_time = 0.19;
	float curr, start = get_servo_position(s_port);
	float i = ((end-start)/(time*tune_time))*increment;
	int driven = 0;
	int check = 1;
	if (-d_speed < 0)
	{
		check = 1;
	}
	if (start > end)
	{
		set_create_distance(distance*10*check);
		create_drive_straight(-d_speed);
		while(curr > end)
		{
			if (get_create_distance()*10 >= 0 && -d_speed > 0)
			{
				create_stop();
				driven = get_servo_position(s_port);
			}
			else if (get_create_distance()/10 <= 0)
			{
				create_stop();
				driven = get_servo_position(s_port);
			}
			set_servo_position(s_port, curr);
			curr+=i;
			msleep((long)(increment*1000));
		}
		if (-d_speed > 0)
		{
			while (get_create_distance()*10-driven >= 0) {}
		} 
		else if (-d_speed < 0)
		{
			while (get_create_distance()/10-driven <= 0) {}
		}
		while (get_create_distance()*10 >= 0) {}
		create_stop();
	} 
	else if (start < end)
	{
		set_create_distance(distance*10*check);
		create_drive_straight(-d_speed);
		while (curr < end)
		{
			if (get_create_distance()*10 >= 0 && -d_speed > 0)
			{
				create_stop();
				driven = get_servo_position(s_port);
			}
			else if (get_create_distance()/10 <= 0)
			{
				create_stop();
				driven = get_servo_position(s_port);
			}
			set_servo_position(s_port, curr);
			curr+=i;
			msleep((long)(increment*1000));
		}
		if (-d_speed > 0)
		{
			while (get_create_distance()*10-driven >= 0) {}
		} 
		else if (-d_speed < 0)
		{
			while (get_create_distance()/10-driven <= 0) {}
		}
		create_stop();
	}
set_servo_position(s_port, end);
}
