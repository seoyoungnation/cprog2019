#include<stdio.h>

int main(){

	int month;
	
	printf("input your birth month: ");
	scanf("%d", &month);
	
	switch(month){
		case 12:
		case 1:
		case 2:
			printf("You are born in winter\n");
			break;
		case 3:
		case 4:
		case 5:
			printf("You are born in spring\n");
			break;
		case 6:
		case 7:
		case 8:
			printf("You are born in summer\n");
			break;
		case 9:
		case 10:
		case 11:
			printf("You are born in autumn\n");
			break;
	}
	return 0;
	}
