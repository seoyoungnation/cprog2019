#include<stdio.h>
#include<string.h>
int check(char s[], char a[], char ch);
int main() {
	char solute[100] = "superorganism";
	char answer[100] = "_____________";
	char ch;
	int cnt = 12;
	while(cnt > 0) {
		printf("chances left: %d\n", cnt);
		printf("Type string: %s\n", answer);
		printf("Guess the string: ");
		scanf("%c", &ch);
		if (check(solution, answer, ch) == 1)
			break;
		cnt = cnt-1;
		}
	return 0;
}

int check(char s[], char a[], char ch) {
	int i;
	for (i =  0; s[i]!='\0'; i++){
		if(s[i] == ch)
			a[i] = ch;
	}
	if (strcmp(s,a) == 0) return 1;
	else return 0;
}
