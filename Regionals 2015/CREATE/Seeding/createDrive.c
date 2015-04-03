#include "createDrive.h"

void raiseLowerArmNew(int destination, int time) {
	
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


void servo_set(int end, int time)
{
	/*int offset = 75;
	float increment = 0.01; 
	float tune_time = 0.02;
	float curr, start = get_servo_position(SERVO_UP_DOWN_LEFT + offset);
	float i = ((end-start)/(time*tune_time))*increment;
	curr = start;
	if (start > end)
	{
		while(curr > (end + offset))
		{
			set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - curr - offset);
			set_servo_position(SERVO_UP_DOWN_LEFT, curr + offset);
			curr+=i;
			msleep((long)(increment*1000));
		}
	} 
	else if (start < end)
	{
		while (curr < (end + offset))
		{
			set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - curr - offset);
			set_servo_position(SERVO_UP_DOWN_LEFT, curr + offset);
			curr+=i;
			msleep((long)(increment*1000));
		}
	}
	/*set_servo_position(SERVO_UP_DOWN_LEFT, end + offset);
	set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - end - offset);*/
	float increment = .01;
	//printf("servo %d",port);
	int offset = 75;
	float tune_time = 1;
	float curr,start = get_servo_position(SERVO_UP_DOWN_RIGHT + offset);
	float i = ((end-start)/(time*tune_time))*increment;
	curr = start;
	if (start > end)
	{
		while(curr > end)
		{
			//printf("%f\n",curr);
			set_servo_position(SERVO_UP_DOWN_LEFT, 2047 - curr - offset);
			set_servo_position(SERVO_UP_DOWN_RIGHT, curr + offset);
			curr+=i;
			msleep((long)(increment*1000));
		}
	}
	else if (start < end)
	{
		while(curr < end)
		{
			//printf("%f\n",curr);
			set_servo_position(SERVO_UP_DOWN_LEFT, 2047 - curr - offset);
			set_servo_position(SERVO_UP_DOWN_RIGHT, curr + offset);
			curr+=i;
			msleep((long)(increment*1000));
		}
	}
	set_servo_position(SERVO_UP_DOWN_LEFT, 2047 - curr - offset);
	set_servo_position(SERVO_UP_DOWN_RIGHT, curr + offset);
}

void servo_drive(int end, int time, float d_speed, float distance)
{
	int offset = 75;
	float increment = 0.05; 
	float tune_time = 0.19;
	float curr, start = get_servo_position(SERVO_UP_DOWN_LEFT + offset);
	float i = ((end-start)/(time*tune_time))*increment;
	int driven = 0;
	int check = 0;
	if (-d_speed >= 0)
	{
		check = 1;
	}
	if (start > end)
	{
		set_create_distance(distance*10*check);
		create_drive_straight(-d_speed);
		while(curr > end - offset)
		{
			if (get_create_distance()*10 >= 0 && -d_speed > 0)
			{
				create_stop();
			}
			else if (get_create_distance()/10 <= 0)
			{
				create_stop();
			}
			set_servo_position(SERVO_UP_DOWN_LEFT, curr + offset);
			set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - curr - offset);
			curr+=i;
			printf("1");
			msleep((long)(increment*1000));
			printf("1");
		}
		if (-d_speed > 0)
		{
			while (get_create_distance()*10 >= 0) {
			printf("4");
				}
		} 
		else if (-d_speed < 0)
		{
			while (get_create_distance()/10 <= 0) {}
		}
		create_stop();
	} 
	else if (start < end - offset)
	{
		set_create_distance(distance*10*check);
		create_drive_straight(-d_speed);
		while (curr < end)
		{
			if (get_create_distance()*10 >= 0 && -d_speed > 0)
			{
				create_stop();
			}
			else if (get_create_distance()/10 <= 0)
			{
				create_stop();
			}
			set_servo_position(SERVO_UP_DOWN_LEFT, curr + offset);
			set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - curr - offset);
			curr+=i;
			printf("2");
			msleep((long)(increment*1000));
			printf("2");
		}
		if (-d_speed > 0)
		{
			while (get_create_distance()*10 >= 0) {
			printf("3");	
				}
			create_stop();
		} 
		else if (-d_speed < 0)
		{
			while (get_create_distance()/10 <= 0) {}
			create_stop();
		}
	}
	set_servo_position(SERVO_UP_DOWN_LEFT, end + offset);
	set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - end - offset);
	create_stop();
}
