#include<stdio.h>

struct point {
	int x;
	int y;
};

struct circle {
	struct point p1;
	struct point p2;
};

int main(){
	struct circle c;
	int rad1, rad2;
	
	printf("첫번째 원의 중심의 좌표 입력: ");
	scanf("%d %d", &c.p1.x, &c.p1.y);	
	printf("첫번째 원의 반지름 입력: ");
	scanf("%d", &rad1);	
	
	printf("두번째 원의 중심의 좌표 입력: ");
	scanf("%d %d", &c.p2.x, &c.p2.y);
	printf("두번째 원의 반지름 입력: ");
	scanf("%d", &rad2);	

	if ((c.p1.x == c.p2.y) && (c.p1.y == c.p2.y) && (rad1 == rad2))
		printf("두 원은 같은 원\n");

	else
		printf("두 원은 다른 원\n");

	return 0;
}
