#include<stdio.h>

void menu();
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main() {
	int choice, res, x, y;
	int (*pf[4])(int, int) = {add, sub, mul, div};

	while(1) {
		menu();
		printf("Select Menu :");
		scanf("%d", &choice);
		
		if (choice < 0 || choice >= 4)
			break;

		printf("Input two integers :");
		scanf("%d %d", &x, &y);

		res = pf[choice](x, y);
		printf("Result = %d\n", res);
	}
	return 0;
}

void menu() {
	printf("=======================\n");
	printf("0. addition\n");
	printf("1. substraction\n");
	printf("2. multiple\n");
	printf("3. division\n");
	printf("4. quit\n");
	printf("=======================\n");
}

int add(int x, int y) {
	return x+y;
}

int sub(int x, int y) {
	return x-y;
}

int mul(int x, int y) {
	return x*y;
}

int div(int x, int y) {
	return x/y;
}
