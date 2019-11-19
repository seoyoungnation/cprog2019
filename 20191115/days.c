#include<stdio.h>
enum days {SUN = 7, MON = 1, TUE, WED, THU, FRI, SAT};
char *days_name[] = {
"sunday", "monday", "tuesday", "thursday", "friday", "saturday" };

int main() {
	enum days d;
	d = WED;
	printf("%d번째 요일은 %s입니다\n", d, day_name[d]);
	return 0;
}
