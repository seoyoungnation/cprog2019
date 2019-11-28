#include<stdio.h>
#define ROW 3
#define COL 3

double get_row_avg(int m[][COL], int);

int main() {
	int m[ROW][COL];
	double res;
	
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			m[i][j] = i+j;
		}
	}

	for (int i = 0; i < ROW; i++) {
		res = get_row_avg(m, i);
		printf("%d = %.3lf\n", i, res);
	}
	
	return 0;
}

double get_row_avg(int m[][COL], int r){
	int *p, *endp;
	double sum = 0.0;
	
	p = &m[r][0];
	endp = &m[r][COL];

	while(p < endp)
		sum += *p++;

	sum /= COL;
	return sum;
}
