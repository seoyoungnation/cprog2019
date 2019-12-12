#include<stdio.h>
#include<stdlib.h>

int main() {
	int* list;
	int i, students;

	printf("Number of students: ");
	scanf("%d", &students);
	list = (int *) malloc(students * sizeof(int));

	if (list == NULL) {
		printf("malloc error");
		exit(1);
	}

	for (i = 0; i < students; i++) {
		printf("Student #%d grade: ", i + 1);
		scanf("%d", &list[i]);
	}

	printf("============================\n");
	for (i = 0; i < students; i++) {
		printf("Student #%d grade: ", i + 1, list[i]);
	}	
	printf("============================\n");

	free(list);
	return 0;
}
