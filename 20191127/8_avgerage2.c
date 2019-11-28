#include<stdio.h>
#define ROW 5
#define COL 3

double get_row_avg(int m[][COL], int c) {
	int *p, *ep;
	double sum = 0.0;

	p = &m[0][c];
	ep = &m[ROW][c];

	while(p < ep) {
		printf("%d\n", *p);
		sum += *p;
		p += COL;
	}
	return sum / ROW;
}

int main() {
	int m[ROW][COL];

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			m[i][j] = i + j;
		}
	}

	double avg = get_row_avg(m, 2);
	
	printf("%f\n", avg);

	return 0;
}	
