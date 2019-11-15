#include<stdio.h>
#include<string.h>
#define LINE_SIZE 256

struct word_cnt {
	int num;
	char word[20];
	int cnt;
};


void main(){
	int arr[100];
	struct word_cnt list[100];
	char buffer[LINE_SIZE];
	FILE *fp = fopen("london.txt", "r");
	char seps[] = " ,\t\n";
	char* token;
	int i;
	int j = 0;
	int check = 0;

	if (fp == NULL){
		printf("Failed to open file\n");
		return;
	}

	for (i = 0; i < 100; i++){
		strcpy(list[i].word, "");
		list[i].cnt = 0;
	}

	while(fgets(buffer, LINE_SIZE-1, fp) != NULL) {
		token = strtok(buffer, seps);
		while (token != NULL) {
			for (i = 0; i <= 100; i++) {
				if (strcmp(token, list[i].word) == 0) {
					list[i].cnt += 1;
					check = 1;
					break;		
				}
			}

			if (check == 1) {
				list[j].num = j;
				strcpy(list[j].word, token);
				list[j].cnt++;
				j++;
				check = 0;
			}
	
			token = strtok(NULL, seps);
		}
	}
	
	for (i = 0; i <= j; i++) {
		printf("%d. %s : %d\n", list[i].num, list[i].word, list[i].cnt);
	}

	fclose(fp);
}
