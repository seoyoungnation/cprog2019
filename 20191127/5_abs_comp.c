#include<stdio.h>
#include<stdlib.h>

void print_equal(int, int, int(*func)(int, int));
int abs_comp(int, int);

int main() {
	int x, y;

	printf("Type two integers: ");
	scanf("%d %d", &x, &y);
	print_equal(x, y, abs_comp);

	return 0;
}

void print_equal(int a, int b, int (*func)(int, int)) {
	if (func(a,b))
		printf("Equal\n");
	else
		printf("Not equal\n");
}

int abs_comp(int a, int b) {
	return abs(a) == abs(b) ? 1 : 0;
}
