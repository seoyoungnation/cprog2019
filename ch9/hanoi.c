#include<stdio.h>

int hanoi(int);

int main(){
	int n;
	int ans;

	printf("insert n: ");
	scanf("%d", &n);

	ans = hanoi(n);
	printf("you have to move %d times\n", ans);

	return 0;
	}

int hanoi(int n) {
	int move;

	if (n == 1)
		return 1;

	else {
		move = 2 * hanoi(n-1) + 1;
		return move;
	}
	}
