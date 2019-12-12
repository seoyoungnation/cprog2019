#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NUM 100

enum TYPES { SHIRTS=1, PANTS, DRESS };

struct item {
	int type;
	int temp;
	union {
		char sml[4];
		int num;
	}size;
};

int main() {
	struct item prod[MAX_NUM];

	FILE* fp = fopen("item.dat", "r");
	
	if(!fp) {
		printf("Failed to open file\n");
		return -1;
	}

	int type;
	char size[100];
	int cnt = 0;
	
	while(!feof(fp)){
		fscanf(fp, "%d %s\n", &type, size);
		
		prod[cnt].type = type;

		if (size[0] - '0' > 9)
			prod[cnt].temp = 1;
		else
			prod[cnt].temp = 2;
		
		switch(prod[cnt].temp) {
			case 1:
				strcpy(prod[cnt].size.sml, size);
				break;
			case 2:
				prod[cnt].size.num = atoi(size);
				break;	
		}
		cnt++;
	}

	for(int i = 0; i < cnt; i++){
		switch(prod[i].type) {
			case SHIRTS:
				printf("셔츠 ");
				break;
			case PANTS:
				printf("바지 ");
				break;
			case DRESS:
				printf("원피스 ");
				break;
			}
		
		switch(prod[i].temp) {
			case 1:
				printf("%s사이즈\n", prod[i].size.sml);
				break;
			case 2:
				printf("%d호\n", prod[i].size.num);
				break;
		}
	}
}			
				
