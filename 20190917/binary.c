#include<stdio.h>

int main() {
	unsigned int num;

	printf("decimal number: ");
	scanf("%u", &num);

	unsigned int mask = 1 << 7; //mask == 10000000

	printf("binary number: ");

	int cnt = 0;
	
	for (int i = 0; i < 8; i++) {
		((num & mask) == 0) ? printf("0") : printf("1");
		((num & mask) == 0) ? cnt += 0 : cnt++;
		if (i == 7) {
			printf("\n");
			break;
		}
		mask = mask >> 1;
	}
	
	printf("count = %d\n", cnt);

	return 0;
}
