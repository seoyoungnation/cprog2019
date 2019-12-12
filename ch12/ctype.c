#include<stdio.h>
#include<ctype.h>

void compare();
void search();

int main() {
	char dst[6];
	char src[6] = "Worlds";
	char str[12] = "Hello"
	
	strcpy(dst, src);
	strcat(str, src);

	compare();
	search();
}

void search(){
	char s[] = "language";
	char c = 'g';
	char* p;
	int loc;

	p = strchr(s, c);
	loc = (int)(p-s);
	if (p != NULL)
		printf("The first %c is found at %d\n", c, loc);
	else
		printf("%c is not found\n", c);
	return;
} 

void compare(){
	char s1[80];
	char s2[80];
	int result;

	printf("Type first word: ");
	scanf("%s", s1);
	printf("Type second word: ");
	scanf("%s", s2);

	result = strcmp(s1, s2);
	if (result < 0)
		printf("%s then %s\n", s1, s2);
	else if (result == 0)
		printf("%s and %s at the same time\n", s1, s2);
	else 
		printf("%s then %s\n", s1, s2);

	return;
}

