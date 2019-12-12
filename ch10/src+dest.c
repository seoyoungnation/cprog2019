#include<stdio.h>

int main() {

	int src[10000] = {0};
	int dest[10000] = {0};
	int size;
	
	size = sizeof(src) / sizeof(int);

	for(int i = 0; i < size; i++)
		src[i] = i;

	for(int i = 0; i < size; i++) {
		dest[i] = src[size - 1 -i];
	}
	
	printf(" src\t dest\n");

	for (int i = 0; i <size; i++) 
		printf("%3d %3d\n", src[i], dest[i]);
	
	return 0;
	}
