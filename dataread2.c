#include<stdio.h>
#define BUFF_SIZE 256

int main(){
	FILE *fp = NULL;
	char buff[256];
	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("Failed to open file %s\n", "data.txt");
		return -1;
	}

	while(fgets(buff, BUFF_SIZE, fp) != NULL){
		printf("%s\n", buff);
	}
	fclose(fp);
	return 0;
}
