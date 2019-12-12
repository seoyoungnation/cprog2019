#include<stdio.h>
#define ROWS 3
#define COLS 5
#define SUB 4

int main() {
	int a[ROWS][COLS] = {{87, 98, 80, 79, 3},
	{99, 89, 90, 90, 0},
	{65, 68, 50, 49, 0}};

	int i, j;
	for (i = 0; i < ROWS; i++) {
		double final_scores = a[i][0] * 0.3 + a[i][1] * 0.4 + a[i][2] * 0.2 + a[i][3] * 0.1 - a[i][4];
		printf("The final score of student %d : %3.2f\n", i+1, final_scores);
}

	//midterm, final, assingment, quiz;
	double b[SUB] = {0};
	for(i = 0; i < SUB; i++) {
		for (j = 0; j < ROWS; j++) 
			b[i] += a[j][i];
		b[i] = b[i] / ROWS;
		}

	printf("average of midterm : %3.2lf\n", b[0]);
	printf("average of fianl exam : %3.2lf\n", b[1]);
	printf("average of final assignment : %3.2lf\n", b[2]);
	printf("average of quiz : %3.2lf\n", b[3]);
	return 0;
}
