#include<stdio.h>

int main() {
	FILE *fp = NULL;
	fp = fopen("data.bin", "wb");
	int num = 1048576;

	if(fp == NULL) {
		printf("Failed to open file\n");
		return -1;
	}

	fwrite(&num, sizeof(int), 1, fp);

	fclose(fp);
	return 0;
}
