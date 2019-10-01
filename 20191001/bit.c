#include<stdio.h>

unsigned int get_bit(unsigned int, unsigned int);
unsigned int set_bit(unsigned int, unsigned int, unsigned int);
unsigned int clear_bit(unsigned int, unsigned int);
void print_bit(unsigned int);

unsigned int get_bit(unsigned int n, unsigned int i) {
	int a = 1, b;
	b = n & a << i-1 ? 1 : 0;
	return b;
	}

unsigned int set_bit(unsigned int n, unsigned int i, unsigned int v) {
	if (v == 1)
		n |= 1 << i-1;
	else
		n & ~(1 << i-1);
	return n;
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

int main() {
	unsigned int n = 0;
	unsigned int i, v, rv;

	print_bit(n);
	printf("Type position and value you want to change: ");
	scanf("%u %u", &i, &v);
	n = set_bit(n, i, v);
	rv = get_bit(n, i);
	
	if (rv != v) {
		printf("wrong bit setting\n");
		return -1;
	}
	
	print_bit(n);
	return 0;
	}
