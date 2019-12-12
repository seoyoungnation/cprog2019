#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {
	int number;
	char title[50];
};

int main() {
	struct Book *p;
	p = (struct Book *) malloc (2 * sizeof(struct Book));

	if (p == NULL) {
		printf("malloc error\n");
		exit(1);
	}

	p[0].number = 1;
	strcpy(p[0].title, "C Programming");
	p[1].number = 2;
	strcpy(p[1].title, "Data Structure");
	free(p);
	return 0;
}
