#include<stdio.h>

int main() {
	char c;
	char name[80], city[80];

	printf("Type your name and address(city): ");
	scanf("%s%c%s", name, &c, city);

	printf("%s lives in %s.\n", name, city);
}
