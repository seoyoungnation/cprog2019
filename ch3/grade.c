#include<stdio.h>

int main(){
	double Astudents;
	double Bstudents;
	double Cstudents;
	int students;

	printf("Number of students: ");
	scanf("%d", &students);

	Astudents = students * 0.2;
	Bstudents = students * 0.6;
	Cstudents = students * 0.2;

	printf("A: %lf\nB: %lf\nC: %lf\n", Astudents, Bstudents, Cstudents);

	return 0;
}
