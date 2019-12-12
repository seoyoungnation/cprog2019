#include<stdio.h>
#include<math.h>

int main(){
	double a, b, c, dis;
	
	printf("input a (coefficient): ");
	scanf("%lf", &a);

	printf("input b (coefficient): ");
	scanf("%lf", &b);

	printf("input c (coefficient): ");
	scanf("%lf", &c);

	if (a == 0) {
		if (b == 0) 
			c == 0 ? printf("There are too many solutions") : printf("There is no solution");
		else
			printf("The real root is %f.", -c/b);
	}
	else {
		dis = (b * b - 4.0 * a * c);
			if (dis >= 0) {
				printf("The real root is %f\n.", (-b + sqrt(dis))/(2.0 * a));
				printf("The real root is %f\n.", (-b - sqrt(dis))/(2.0 * a));
			}
			else
				printf("There is no real root\n");
}
	return 0;
}

