#include<stdio.h>
#define SIZE 32

void print_bit(unsigned int);
int count_bit(unsigned int, unsigned int);

int main() {
	unsigned int n = 0;
	int cnt;
	
	printf("Insert Decimal: ");
	scanf("%u", &n);

	print_bit(n);	

	cnt = count_bit(n, SIZE);	
	printf("Numbers of 1 : %u\n", cnt);	
	
	return 0;
	}

void print_bit(unsigned int n) {
	unsigned int b = 1;
	for (int i = 31; i >= 0; i--){
		b = 1 << i;
		printf("%u", n & b ? 1 : 0);
		if (i % 8 == 0) 
			printf(" ");
	}
	printf("\n");
	return;	
}

int count_bit (unsigned int n, unsigned int i){
	int total = 0;

	if (i == -1)
		return 0;

	else {
		int a = 1, b;
		b = n & a << i-1 ? 1 : 0;
		total = b + count_bit(n, i-1);
		return total;
	}
	
}
