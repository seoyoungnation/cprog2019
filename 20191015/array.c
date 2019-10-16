#include<stdio.h>

int main() {
	int ary[] = {3, 8, 1, 1, 2, 5, 2, 4, 3, 6};
	int length;
	length = sizeof(ary) / sizeof(int);

	for (int i = 0; i < length - 2; i++) {
		for (int j = i+1; j < length; j++) {
			if ((ary[i] + ary[j]) >= 10) {
				printf("ary[%d] = %d, ary[%d] = %d\n", i, ary[i], j, ary[j]);
			}
		}
	}

	return 0;
}

