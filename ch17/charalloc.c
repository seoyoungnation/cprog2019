#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRSIZE 100
#define LINES 5

int main() {
	char* str[LINES];

	for (int i = 0; i < LINES; i++) {
		str[i] = (char *) malloc(STRSIZE * sizeof(char));
		if (str[i] == NULL) {
			printf("malloc error\n");
			exit(1);
		}
		strcpy(str[i], "test string");
	}

	for (int i = 0; i < LINES; i++) {
		printf("[%d]: %s\n", i, str[i]);
	}

	return 0;
}
