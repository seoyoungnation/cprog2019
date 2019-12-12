#include<stdio.h>
#define SIZE 5

void print_array(int*);
void sum_array(int*, int*);

int main() {
	int sum = 0;
	int arr[5] = {2, 4, 6, 8, 10};
	
	print_array(arr);
	sum_array(arr, &sum);

	printf("sum = %d\n", sum);
}

void print_array(int* arr){
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}

void sum_array(int* arr, int* psum){
	for (int i = 0; i < SIZE; i++) 
		*psum += *(arr+i);
}
	
