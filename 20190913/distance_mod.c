#include<stdio.h>

int main(){
	
	double light_speed = 300000;
	double distance = 149600000;

	double time;
	int min, sec;

	time = distance / light_speed;

	min = time / 60.0;
	sec = (int)time % 60;
	
	printf("The speed of light is %fkm/s\n", light_speed);
	printf("The distance between the Sun and the Earth is %fkm\n", distance);
	printf("The time is %dmin %dsec\n", min, sec);

	return 0;
}
