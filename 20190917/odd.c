#include<stdio.h>

int main() {
	
	int num;

	printf("input number: ");
	scanf("%d", &num);

	(num % 2 == 0) ? printf("1") : printf("0");
	printf("\n");

	return 0;
}
