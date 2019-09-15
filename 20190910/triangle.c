#include<stdio.h>

int main(){
	int height;
	int width;
	float area;

	printf("height: ");
	scanf("%d", &height);

	printf("width: ");
	scanf("%d", &width);

	area = (height * width) / 2.0;
	printf("area = %lf\n", area);

	return 0;
}	
