#include "createDrive.h"

void raiseLowerArm(int destination, int time) {
	int offsetLeft = 75;
	int offsetRight = 170;
	int increment;
	int initAngle = get_servo_position(0);
	int angle = initAngle;
	if(angle < destination) {
		increment = 1;
	} else {
		increment = -1;
	}
	while(abs(angle - destination) > 5) {
		printf("%d\n", angle);
		angle+=increment;
		set_servo_position(SERVO_UP_DOWN_LEFT, angle + offsetLeft);
		set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - angle - offsetRight);
		msleep(time / abs(destination - initAngle));
	}
}

void armMove(int destination, float time, int distance, int speed) {
	int offsetLeft = 70;
	int offsetRight = 180;
	int increment;
	int initAngle = get_servo_position(0);
	int angle = initAngle;
	if(angle < destination) {
		increment = 5;
	} else {
		increment = -5;
	}
	create_drive_straight(-speed);
	if(speed > 0) {
		set_create_distance(distance*10);
	} else {
		set_create_distance(0);
	}
		
	while(abs(angle - destination) > 5) {
		printf("%d\n", angle);
		angle+=increment;
		set_servo_position(SERVO_UP_DOWN_LEFT, angle + offsetLeft);
		set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - angle - offsetRight);
		msleep(time / abs(destination - initAngle));
		if(speed > 0) {
			if(get_create_distance()*10 <= 0) {
				create_stop();
				set_create_distance(10); //Just make up a position more than 0 so it doesn't stop the create again, slowing the program
			}
		} else {
			if(get_create_distance()/10 >= distance) {
				create_stop();
				set_create_distance(0);
			}
		}
	}
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
	set_servo_position(SERVO_UP_DOWN_LEFT, 75);
	set_servo_position(SERVO_UP_DOWN_RIGHT, 1877);
	create_connect();
}


void servo_set(int end, int time)
{
	float increment = .01;
	float tune_time = 0.875;
	float curr,start = get_servo_position(SERVO_UP_DOWN_LEFT) + OFFSET;
	float i = ((end-start)/(time*tune_time))*increment;
	curr = start;
	//printf("start %f", start);
	//printf("increment  %f", i);
	while((start > end && curr > end) || (start < end && curr < end))
	{
		//printf("start %f", start);
		//printf("here %f\n",curr);
		set_servo_position(SERVO_UP_DOWN_LEFT, curr + OFFSET);
		set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - curr - (OFFSET + 95));
		curr+=i;
		msleep((long)(increment*1000));
	}
	set_servo_position(SERVO_UP_DOWN_LEFT, end + OFFSET);
	set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - end - (OFFSET + 95));
}

void servo_drive(int end, int time, float d_speed, float distance) //-d_speed means backwards
{
	set_create_distance(distance*10);
	if (d_speed > 0) 
	{
		set_create_distance(0);
	}
	printf("%d", get_create_distance());
	float increment = .01;
	float tune_time = 0.875;
	float curr,start = get_servo_position(SERVO_UP_DOWN_LEFT) + OFFSET;
	float i = ((end-start)/(time*tune_time))*increment;
	curr = start;
	create_drive_straight(-d_speed);
	while((start > end && curr > end) || (start < end && curr < end))
	{
		if((get_create_distance()*10 <= 0 && d_speed < 0) || (get_create_distance()/10 >= distance && d_speed > 0))
		{
			create_stop();
		}
		set_servo_position(SERVO_UP_DOWN_LEFT, curr + OFFSET);
		set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - curr - (OFFSET + 95));
		curr+=i;
		msleep((long)(increment*1000));
	}
	set_servo_position(SERVO_UP_DOWN_LEFT, end + OFFSET);
	set_servo_position(SERVO_UP_DOWN_RIGHT, 2047 - end - (OFFSET + 95));
	while ((get_create_distance()*10 >= 0 && d_speed < 0) || (get_create_distance()/10 <= distance && d_speed > 0)) {}
	create_stop();
	
	/*int offset = 75;
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
	create_stop();*/
}
