#include<stdio.h>

int main() {
	int num;
	int a, b;
	int temp;

	printf("Input Number: ");
	scanf("%d", &num);
	
	while (1) {
		a = num / 10;
		b = num % 10;
		num = a - b*2;

		printf("%d - %d = %d\n", a, b*2, num);
		
		if (num < 10)
			break;
		}
	
	switch (num) {
		case 7:
		case 0:
		case -7:
		case -14:
			printf("It is multiple of 7\n");
			break;
		default:
			printf("It is not multiple of 7\n");
			break;
	}

	return 0;
	}
		
