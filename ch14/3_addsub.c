#include<stdio.h>

int add(int, int);
int sub(int, int);

int main(){
	int res;
	int x, y;
	int (*pf)(int, int);

	printf("Type two integers: ");
	scanf("%d %d", &x, &y);

	pf = add;
	res = pf(x, y);
	printf("%d + %d = %d\n", x, y, res);

	pf = sub;
	res = pf(x, y);
	printf("%d - %d = %d\n", x, y, res);

	return 0;
}

int add(int x, int y) {
	return x+y;
}

int sub(int x, int y) {
	return x-y;
}
