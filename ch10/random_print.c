#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	int ary[10];
	int check;

	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < 10; i++) {
		while (1) {
			check = 0;
			ary[i] = rand() % 100 + 1;
			for (int j = 0; j < i; j++) {
				if (ary[j] == ary[i])
					check = 1;
					break;
				}
			if (check == 0)
				break;
		}
		printf("%3d ", ary[i]);
	}
	
	printf("\n");
	return 0;

	}
		
