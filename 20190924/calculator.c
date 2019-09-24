#include<stdio.h>

int main(){
	char op;
	int x, y, result;

	printf("input equation\n");
	printf("ex: 2+5\n");
	printf(">>");
	scanf("%d %c %d", &x, &op, &y);

	switch(op) {
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;

		default:
			printf("It is not supported\n");
			break;
		}
	printf("%d %c %d = %d\n", x, op, y, result);
	return 0;
	}
