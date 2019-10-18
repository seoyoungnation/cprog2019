#include<stdio.h>

void square_array(int a[], int size);
void print_array(int a[], int size);

int main() {
	int list[7] = { 1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(list)/sizeof(int);
	
	print_array(list, size);
	square_array(list, size);
	print_array(list, size);

	return 0;
	}

void square_array(int a[], int size) {
	for (int i = 0; i < size; i++)
		a[i] = a[i] * a[i];
	}

void print_array(int a[], int size) {
	for (int i = 0; i < size; i++)
		printf("%3d", a[i]);
	printf("\n");
}
