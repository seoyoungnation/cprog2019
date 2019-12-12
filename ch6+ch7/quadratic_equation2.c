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
		if (b == 0) {
			if (c == 0) printf("infinite\n");
			else printf("none\n");
			}
		else printf("%f\n", -c/b);
		goto end;
	}

	dis = (b * b - 4.0 * a * c);
	if (dis < 0) {
		printf("none\n");
		goto end;
		}

	printf("The real root is %f\n.", (-b + sqrt(dis))/(2.0 * a));
	printf("The real root is %f\n.", (-b - sqrt(dis))/(2.0 * a));

end:
	return 0;
}
