#include<stdio.h>

int main(){
	FILE *fp = NULL;
	char buff[100];
	fp = fopen("data.txt", "r");

	if(fp == NULL){
		printf("Failed to open file %s\n", "data.txt");
		return -1;
	}

	while(fscanf(fp, "%s", buff) != EOF){
		printf("%s\n", buff);
	}
	fclose(fp);
	return 0;
}
