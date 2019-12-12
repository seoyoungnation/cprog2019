#include<stdio.h>

int main() {
	int array[] = {3, 2, 9, 7, 1, 4, 8, 0, 6, 5};
	int size = sizeof(array) / sizeof(int);
	int temp, least;

	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	for (int i = 0; i < size -1; i++) {
		least = i;
		for (int j = i+1; j < size; j++) {
			if (array[least] > array[j])
				least = j;
		}
		temp = array[i];
		array[i] = array[least];
		array[least] = temp;
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}
