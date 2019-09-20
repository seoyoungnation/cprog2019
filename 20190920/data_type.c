#include<stdio.h>

int main() {
	int a, b;
	double num;

	printf("input a: ");
	scanf("%d", &a);

	printf("input b: ");
	scanf("%d", &b);

	num = a / (double)b;

	printf("%d / %d = %lf\n", a, b, num);

	return 0;
}
