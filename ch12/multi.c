#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	int a, b;

	if (argc < 3) {
		printf("Usage: ./multi 3 10\n");
		return 0;
	}

	/*
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	*/

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d\n", a*b);

	return 0;
}
