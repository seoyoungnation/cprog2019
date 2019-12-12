#include<stdio.h>

void stock_manage(int, int);

int main() {
	int stock = 100;
	int n;
	int opt;
	
	while(1) {
		printf("sale: 1 /  store: 2 / check stock: 3 / quit: 4\n");
		scanf("%d", &opt);

		if (opt < 3 && opt > 0) {
			printf("Input quantity: ");
			scanf("%d", &n);
		}

		switch (opt) {
		case 1:
		case 2:
		case 3:
			stock_manage(opt, n);
			break;
		case 4:
			return 0;
		default:
			printf("wrong command\n");
		}
	}
}

void stock_manage(int opt, int n) {
	static int stock = 100;
	
	switch(opt) {
	case 1:
		stock += n;
		break;
	case 2:
		stock -= n;
		break;
	case 3:
		printf("You have %d dolls left\n", stock);
		break;
	}

	return;
}

