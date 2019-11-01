#include<stdio.h>
#define SIZE 5

void check(int*, int*, int*);

int main() {

	int arr[5] = {10, 2, 6, 8 ,4};
	int min, max;

	check(arr, &min, &max);

	printf("min = %d, max = %d\n", min, max);

	return 0;
}

void check(int* arr, int* pmin, int* pmax){

	*pmin = arr[0];
	*pmax = arr[0];

	for (int i = 1; i < SIZE; i++) {
		if (*pmin > arr[i])
			*pmin = arr[i];
		if (*pmax < arr[i])
			*pmax = arr[i];
	}
}
