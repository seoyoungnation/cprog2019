#include<stdio.h>

int binary_search(int[], int, int);

int main() {
	int array[] = {2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47};
	int size = sizeof(array) / sizeof(int);
	int key;
	
	printf("insert key: ");
	scanf("%d", &key);
	printf("Search result: %d\n", binary_search(array, size, key));
	
	return 0;
}

int binary_search(int array[], int size, int key) {
	int high, low, middle;
	low = 0;
	high = size-1;

	while (low <= high) {
		middle = (low + high) / 2;
		if (key == array[middle])
			return middle;
		else if (key > array[middle])
			low = middle + 1;
		else 
			high = middle - 1;
	}
	return -1;
}
