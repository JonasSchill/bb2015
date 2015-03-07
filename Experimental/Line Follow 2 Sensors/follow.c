// Created on Sat February 7 2015

#define benchmark 800

int main()
{
	while(1) {
		motor(0, 100);
		motor(1, 100);
		while(analog(0) > 900 && analog(1) > 900) {}
		ao();
		if(analog(0) < 900) {
			motor(1, 100);
			while(analog(0) < 900) {}
		}
		if(analog(1) < 900) {
			motor(0, 100);
			while(analog(1) < 900) {}
		}
	}
	return 0;
}
