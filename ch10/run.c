#include<stdio.h>
#define STUDENTS 5

int main() {
	double time[STUDENTS] = {0};
	double temp;
	int i = 0;

	for (int i = 0; i < STUDENTS; i++) {
		printf("Student %d: ", i+1);
		scanf("%lf", &time[i]);
	}

	for (int j = 1; j < (STUDENTS-1); j++) {
		while (time[j] > time[i])
			i++;
		temp = time[j];

		for (int k = 0; k < j-i; k++) {
			time[j-k] = time[j-k-1];
		time[i] = temp;
		}
	}
	printf("==============\n");
	for (i = 0; i < STUDENTS; i++){
		printf("no.%d : %.2lf\n", i+1, time[i]);
	}
	return 0;
}
	
