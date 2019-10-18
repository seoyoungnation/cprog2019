#include<stdio.h>

void get_sum(int[], int);

int main() {
	int size = 10;
	int arr[size];
 
	for (int i = 0; i < size; i++)
		arr[i] = i;

	get_sum(arr, size);
	
	for (int i = 0; i < size; i++) 
		printf("%d\n", arr[i]);

	return 0;
	}

void get_sum (int arr[], int n) {
	int a, b;
	
	a = arr[0];
	
	for (int i = 1; i < n; i++){ 
		b = arr[i];
		arr[i] = a + b;
		a = b; 
	}
	return;
}
