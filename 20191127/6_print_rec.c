#include<stdio.h>

struct rect {
	int w;
	int h;
};

int compare(struct rect, struct rect);
void print_rect(struct rect, struct rect, int (*func)(struct rect, struct rect));

int main() {
	struct rect x = {2, 4};
	struct rect y = {3, 3};

	print_rect(x, y, compare);

	return 0;
}

int compare(struct rect x, struct rect y) { 
	int a, b;

	a = x.w * x.h;
	b = y.w * y.h;
	
	return a - b;
	}

void print_rect(struct rect a, struct rect b, int (*func)(struct rect, struct rect)) {
	printf("Result\n");

	if (func(a, b) > 0)
		printf("(%d,%d) (%d,%d)\n", a.w, a.h, b.w, b.h);
	else
		printf("(%d,%d) (%d,%d)\n", b.w, b.h, a.w, a.h);

	return;
}
