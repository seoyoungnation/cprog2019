#include<stdio.h>

int samdan(int n);

int main(){
	for(int i = 1; i <= 9; i++)
		printf("%3d", samdan(i));
	printf("\n");

	return 0;
	}

int samdan(int n) {
	int ans;
	if (n == 1)
		return 3;
	else {
		ans = samdan(n-1) + 3;
		return ans;
	}
}
