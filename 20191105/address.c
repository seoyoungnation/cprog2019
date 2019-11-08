#include<stdio.h>

int main(){
	char name[100];
	char address[100];

	printf("Type your name:");
	fgets(name, 100, stdin);
	printf("Type your current address: ");
	fgets(address, 100, stdin);
	puts(name);
	puts(address);
	return 0;
}
