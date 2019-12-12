#include<stdio.h>

int main() {
	char name[];
	
	printf("Type info\n");
	scanf("%s[a-z]", name);
	
	printf("Name: %s\n", name);
}
