#include<stdio.h>

void set_pointer(char** q);

int main() {
	char *p;
	set_pointer(&p);

	printf("Aphorism of Today: %s\n", p);
	return 0;
}


void set_pointer(char** q) {
	*q = "All that gliters is not gold";
}
