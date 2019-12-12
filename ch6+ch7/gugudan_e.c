#include<stdio.h>

int main(){
	
	for(int i = 2; i <= 9; i+=2) {
		for(int j = 1; j <= 9; j++) {
			printf("%2d * %2d = %2d\n", i, j, i*j);
		}
		printf("\n");
	}

	return 0;

	}
