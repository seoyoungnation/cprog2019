#include<stdio.h>

int main() {
	FILE *fp = NULL;
	fp = fopen("data.txt", "w");
	int num = 1048576;

	if(fp == NULL) {
		printf("Failed to open file\n");
		return -1;
	}

	fprintf(fp, "%d", num);

	fclose(fp);
	return 0;
}
