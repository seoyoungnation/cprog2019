#include<stdio.h>
#include<ctype.h>

int main() {
	char str[100];

	printf("Type a string: ");
	fgets(str, 100, stdin);

	for (int i = 0; str[i] != '\0'; i++){
		if (islower(str[i]))
			str[i] = toupper(str[i]);
	}

	printf("BIG LETTER STRING = \"%s\"\n", str);

	return 0;
}
