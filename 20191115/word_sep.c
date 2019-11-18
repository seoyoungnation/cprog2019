#include<stdio.h>
#include<string.h>
#define LINE_SIZE 256

struct word_cnt {
	int num;
	char word[20];
	int cnt;
};


void main(){
	struct word_cnt list[100];
	char buffer[LINE_SIZE];
	FILE *fp = fopen("london.txt", "r");
	char seps[] = " ,\t\n";
	char* token;
	int j = 0;
	int check = 0;

	if (fp == NULL){
		printf("Failed to open file\n");
		return;
	}

	for (int i = 0; i < 100; i++){
		strcpy(list[i].word, " ");				//reset string with blank
		list[i].cnt = 0;						//reset every cnt to 0
		}

	while(fgets(buffer, LINE_SIZE-1, fp) != NULL) {
		token = strtok(buffer, seps);
		while (token != NULL) {
			check = 0;							//reset check
			for (int i = 0; i <= j; i++) {
				//compare token and the word in saved list 
				if (strcmp(token, list[i].word) == 0) {
					list[i].cnt += 1;			//add number of cnt
					check = 1;					//change check
					break;		
				}
			}

			if (check == 0) {				
				list[j].num = j;				//add number at num
				strcpy(list[j].word, token);	//copy token to the list
				list[j].cnt += 1;				//add number of cnt
				j++;							//add j
				}

			token = strtok(NULL, seps);
		}
	}

	//printing list	
	for (int i = 0; i < j; i++) {
		printf("%d. %s : %d\n", list[i].num, list[i].word, list[i].cnt);
	}

	fclose(fp);
}
