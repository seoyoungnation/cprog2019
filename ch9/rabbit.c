#include<stdio.h>

int rabbit(int);

int main(){
	int n;
	int final;

	printf("Input months: ");
	scanf("%d", &n);

	final = rabbit(n);
	printf("After %d months, there will be %d pairs\n", n, final);

	return 0;
	}

int rabbit(int n) {
	int ans;
	if (n < 2)
		return 1;
	
	else {
		ans = rabbit(n-1) + rabbit(n-2);
		return ans;
		}
	}
