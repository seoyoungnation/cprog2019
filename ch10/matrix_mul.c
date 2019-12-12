#include<stdio.h>
#define A_ROW 3
#define A_COL 2
#define B_ROW 2
#define B_COL 4
int main() {

	int a[A_ROW][A_COL] = { {0,1}, {1,1}, {1,0} };
	int b[B_ROW][B_COL] = { {1,1,0,1}, {0,1,0,0} };
	
	int i, j, k;

	int sum = 0;

	for (i = 0; i < A_COL; i++) {
		for (j = 0; j < A_ROW; j++)
			for (k = 0; k < B_COL; k++)
				sum += a[j][i] * b[i][k];		
		}

	printf("Sum = %d\n", sum);

	return 0;
}
