#include<stdio.h>
#include<math.h>

double pita(double, double);

int main() {
	
	double a, b, c;
	
	printf("Input length of a: ");
	scanf("%lf", &a);
	
	printf("Input length of b: ");
	scanf("%lf", &b);
	
	c = pita(a, b);
	printf("a = %lf\nb = %lf\nc = %lf\n", a, b, c);

	return 0;
	}

double pita(double a, double b) {
	double c;	
	c = sqrt(pow(a, 2.0) - pow(b, 2.0));
	return c;
	}
