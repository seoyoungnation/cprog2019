#include<stdio.h>
#include<string.h>
#define LINE_SIZE 256

void main(){

	char buffer[LINE_SIZE];
	FILE *fp = fopen("london.txt", "r");
	char seps[] = " ,\t\n";
	char* token;

	if (fp == NULL){
		printf("Failed to open file\n");
		return;
	}

	while(fgets(buffer, LINE_SIZE-1, fp) != NULL) {
		token = strtok(buffer, seps);
		while (token != NULL) {
			printf("%s\n", token);
			token = strtok(NULL, seps);
		}
	}

//	print(words, wordsnum, wordslen);

	fclose(fp);
}
