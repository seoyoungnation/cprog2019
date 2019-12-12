#include<stdio.h>

int main(){
	double light_speed = 300000;
	double distance = 149600000;

	double time;

	time = distance / light_speed;

	printf("The speed of light is %fkm/s\n", light_speed);
	printf("The distance between the Sun and the Earth is %fkm\n", distance);
	printf("The time is %fsec\n", time);

	return 0;
}
