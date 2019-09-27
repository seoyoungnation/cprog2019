#include<stdio.h>

int main() {
	int i = 1;

	while (i <= 100) {
		if (i % 3 == 0) {
			printf("%5d", i);
			}
		i++;	
	}

	printf("\n");
	
	return 0;

}
