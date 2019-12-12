#include <stdio.h>

int main() {
	int month, days;

	printf("input month: ");
	scanf("%d", &month);

	switch(month) {
		case 2:
			days = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;
			break;
		default:
			days = 31;
			break;
		}

	printf("month %d has %d days\n", month, days);
	return 0;
	}
