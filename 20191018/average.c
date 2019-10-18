#include<stdio.h>
#define STUDENTS 5

int get_average(int[], int n);
int get_max(int[], int n);
int get_min(int[], int n);

int main() {
	int scores[STUDENTS] = {1, 2, 3, 4, 5};
	int avg, max, min;

	avg = get_average(scores, STUDENTS);
	max = get_max(scores, STUDENTS);
	min = get_min(scores, STUDENTS);

	printf("The average is %d.\n", avg);
	printf("The maximum is %d.\n", max);
	printf("The minimum is %d.\n", min);

	return 0;
}

int get_average(int scores[], int n) {
	int sum = 0;

	for (int i = 0; i < n ; i++)
		sum += scores[i];
	
	return sum / n;
}

int get_max(int scores[], int n) {
	int max = scores[0];

	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (max < scores[j]) 
				max = scores[j];
		}
	}
	return max;
}

int get_min(int scores[], int n) {
	int min = scores[0];

	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (min > scores[n]) 
				min = scores[n];
		}
	}
	return min;
}
