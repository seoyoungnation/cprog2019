#include<stdio.h>

int main() {
	
	int x, y;

	printf("first number: ");
	scanf("%d", &x);

	printf("second number: ");
	scanf("%d", &y);

	printf("big number = %d\n", (x > y) ? x : y);
	printf("small number = %d\n", (x < y) ? x : y);

	return 0;
}
