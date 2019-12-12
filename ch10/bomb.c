#include<stdio.h>
#define SIZE 5
void bomb(int, int);
int area[SIZE][SIZE] = {0,};

int main() {
	int sum = 0;

	bomb(1, 1);
	bomb(0, 4);
	bomb(2, 3);

	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++)
			if (area[i][j] == 0) 
				sum++;
	}

	printf("%d areas left\n", sum);

	return 0;
	}

void bomb(int a, int b) {
	int p, q, x, y;
	
	switch (a) {
	case 0: p = 0; q = 1; break;
	case (SIZE-1): p = (SIZE-2); q = (SIZE-1); break;
	default : p = a-1; q = a+1; break;
	}
	
	switch (b) {
	case 0: x = 0; y = 1; break;
	case (SIZE-1): x = (SIZE-2); y = (SIZE-1); break;
	default: x = b-1; y = b+1; break;
	}
	
	for (int i = (a-1); i <= (a+1); i++) {
		for (int j = (b-1); j <= (b+1); j++)
			area[i][j] = 1;
	}
	
	return;
}
	
