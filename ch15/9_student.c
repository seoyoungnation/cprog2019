#include<stdio.h>
#define SIZE 3

struct student {
	int number;
	char name[20];
	double gpa;
};

int main() {
	struct student table [SIZE] = {
		{ 1, "KIM", 3.99 },
		{ 2, "MIN", 2.68 },
		{ 3, "LEE", 4.01 }
	};
	struct student s;
	FILE *fp = NULL;
	int i;

	if ((fp = fopen("student.dat", "wb")) == NULL) {
		fprintf(stderr, "cannot open file\n");
		exit(1);
	}

	fwrite(table, sizeof(struct student), SIZE, fp);
	fclose(fp);

	if ((fp = fopen("student.dat", "rb")) == NULL) {
		fprintf(stderr, "cannot open file \n");
		exit(1);
	}

	for (i = 0; i < SIZE; i++) {
		fread(&s, sizeof(struct student), 1, fp);
		printf("number = %d, name = %s, GPA = %f\n", s.number, s.name, s.gpa);
	}

	fclose(fp);
	return 0;
}
