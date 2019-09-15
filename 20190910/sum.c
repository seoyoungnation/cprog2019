#include<stdio.h>

int main(){
	int x;
	int y;
	int sum;

	printf("insert first number: ");
	scanf("%d", &x);

	printf("insert second number: ");
	scanf("%d", &y);

	sum = x + y;
	printf("sum of two numbers: %d\n", sum);

	return 0;
}
