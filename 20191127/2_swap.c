#include<stdio.h>

void swap(char **, char **);

int main() {
	char *p = "Hello";
	char *q = "Goodbye";

	printf("%s\n", p);
	printf("%s\n", q);

	swap(&p, &q);

	printf("%s\n", p);
	printf("%s\n", q);

	return 0;
}

void swap(char **p, char **q) {
	char *temp;
	
	temp = *p;
	*p = *q;
	*q = temp;

	return;
}
