#include<stdio.h>
#include<ctype.h>
#define SIZE 26

void main() {
	char str[] = "The worst things to eat before you sleep";
	char c;
	int alpha[SIZE] = {0};
	int i;

	for (i = 0; str[i] != '\0'; i++){
		c = str[i];
		if(islower(c))
			c = toupper(c);
		alpha[c - 'A'] += 1;
	}
	
	for (i = 0; i < SIZE; i++){
		printf("%3d", alpha[i]);
	}
}
