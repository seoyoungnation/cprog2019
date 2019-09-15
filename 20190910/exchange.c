#include<stdio.h>

int main(){
	double rate;
	double usd;
	int krw;

	printf("input currency: ");
	scanf("%lf", &rate);

	printf("input krw: ");
	scanf("%d", &krw);

	usd = krw / rate;

	printf("krw %d won is %lf dollar.\n", krw, usd);

	return 0;
}
