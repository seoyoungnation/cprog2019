#include<stdio.h>


int main() {
	int midterm, final, assignment;
	double total;

	printf("input midterm, final, assignment scores: ");
	scanf("%d %d %d", &midterm, &final, &assignment);

	total = (midterm / 60.0 * 30) + (final / 70.0 * 30) + (assignment / 50.0* 40);

	printf("The total is %lf\n", total);

	return 0;
}
