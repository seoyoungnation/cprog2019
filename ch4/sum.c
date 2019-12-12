#include<stdio.h>

int main(){

	int x, y, z, sum;

	sum = 0;
	printf("input three integers: ");
	scanf("%d %d %d", &x, &y, &z);

	sum += x;
	sum += y;
	sum += z;

	printf("sum of three integers is %d\n", sum);
	
	return 0;
}
