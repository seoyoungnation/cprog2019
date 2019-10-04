#include<stdio.h>

int opt;
int n;
int stock = 100;

void dec_item(int);
void inc_item(int);
void print_item(void);

int main() {
	while(1) {
		printf("sale: 1 /  store: 2 / check stock: 3 / quit: 4\n");
		scanf("%d", &opt);

		if (opt < 3 && opt > 0) {
			printf("Input quantity: ");
			scanf("%d", &n);
		}

		switch (opt) {
		case 1:
			dec_item(n);
			break;
		case 2:
			inc_item(n);
			break;
		case 3:
			print_item();
			break;
		case 4:
			return 0;
		default:
			printf("wrong command\n");
		}
	}
}

void dec_item(int n) {
	stock -= n;
	return;
}

void inc_item(int n) {
	stock += n;
	return;
}

void print_item() {
	printf("We have %d dolls left\n", stock);
	return;
}
