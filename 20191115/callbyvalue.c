#include<stdio.h>

struct student {
	int number;
	char name[20];
	double grade;
};

int equal(struct student *p1, struct student *p2) {
	if(p1 -> number == p2 -> number)
		return 1;
	else
		return 0;
}

void inc_grade(struct student *p){
	(p -> grade)++;
	printf("name: %s, grade: %lf\n", p->name, p->grade);
}

int main(){
	struct student a = {1, "hong", 3.8};
	struct student b = {2, "kim", 4.0};
	if (equal(&a, &b) == 1){
		printf("same student\n");
	}
	else {
		printf("different student\n");
	}
	inc_grade(&a);
	inc_grade(&b);
}

