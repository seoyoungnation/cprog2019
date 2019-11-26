#include<stdio.h>

int main(){
	int num[5] = {3, 5, 7, 9, 10};
	int sum = 0;
	double avg;
	
	for (int i = 0; i < 5; i++) {
		sum += num[i];
	}
	avg = sum / 5.0;
	printf("%.2lf\n", avg);
}
