#include<stdio.h>
#include<string.h>

int check(char*);

int main(){
	int high, low;
	char str[100];
	int chk;
	
	printf("Type str: ");
	fgets(str, 100, stdin);
	
	chk = check(str);

	if (chk == 1)
		printf("not a palindrome\n");
	else
		printf("palindrome\n");

	return 0;
}


int check (char str[]){
	int high, low;

	high = strlen(str) - 2;
	low = 0;
	
	while(high > low) {
		if (str[high] != str[low])
			return 1;
		high--;
		low++;
	}
	return 0;
}
