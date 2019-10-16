#include<stdio.h>

int factorial(int);

int main() {
	int n;
	int ans;

	printf("insert n: ");
	scanf("%d", &n);

	ans = factorial(n);
	printf("%d! = %d\n", n, ans);

	return 0;
	}

int factorial(int n) {
	int ans = 1;

	if (n == 1) 
		return 1;
	else {
		ans = n * factorial(n-1);
		return ans;
	}
	}
