#include<stdio.h>

int main() {
	FILE *fp = NULL;
	fp = fopen("data.txt", "w");

	if(fp == NULL){
		printf("Failed to open file %s\n", "data.txt");
		return -1;
		}

	fprintf("fp", "My first data file\n");
	fclose(fp);
	return 0;
}
