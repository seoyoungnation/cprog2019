#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

	int dice[10] = { 1, 1, 1, 2, 2, 2, 3, 4, 5, 6 };
	int num;

	srand((unsigned int)time(NULL));

	printf("%d\n", dice[rand() % 10]);

	return 0;
	}
