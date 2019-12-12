#include<stdio.h>

int main(){
	char str[30] = "C language is easy";
	int i = 0;

	while (str[i] != 0)
		i++;

	printf("The length of string \"%s\" is %d.\n", str, i);

	return 0;
}
