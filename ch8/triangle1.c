#include<stdio.h>
#include<math.h>

double get_height(double, double);

int main() {
	
	double a, b, degree, radians;
	
	printf("Input length of a: ");
	scanf("%lf", &a);
	
	printf("Input degree (in degrees): ");
	scanf("%lf", &degree);
	
	radians = (90 - degree) * (3.141592 / 180.0);

	b = get_height(a, radians);
	printf("b = %lf\n", b);

	return 0;
	}

double get_height(double a, double rads) {
	return a * sin(rads);
	}
