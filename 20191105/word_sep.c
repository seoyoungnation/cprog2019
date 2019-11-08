#include<stdio.h>
#include<string.h>
#define LINE_SIZE 5

void print(char words[][26], int* wordsnum, int len);

void main(){

	char buffer[LINE_SIZE];
	FILE *fp = fopen("london.txt", "r");
	char words[300][26];
	int wordsnum[300] = {0,};
	char seps[] = " ,\t\n";
	int wordslen = 0;
	int chk;
	char* token;

	if (fp == NULL){
		printf("Failed to open file\n");
		return;
	}

	while(fgets(buffer, LINE_SIZE-1, fp) != NULL) {
		token = strtok(buffer, seps);
		while (token != NULL) {
			chk = 0;
			for(int i = 0; i <= wordslen; i++) {
				if (*token == words[i][0]) {
					wordsnum[i]++;
					chk = 1;
					break;
				}
			}
			if (chk == 0) {
				strcpy(words[wordslen], token);
				wordsnum[wordslen]++;
				wordslen++;
			}			
		token = strtok(buffer, seps);
		}
	}

	print(words, wordsnum, wordslen);

	fclose(fp);
}		

void print(char words[][26], int* wordsnum, int len) {

	for (int i = 0; i <= len; i++)
		printf("%3d %s\n", wordsnum[i], words[i]);

	return;
}
