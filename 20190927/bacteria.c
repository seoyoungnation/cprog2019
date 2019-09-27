#include<stdio.h>
#define BACTERIA 10
#define TIME 7

int main() {
	
	int end = BACTERIA;

	for(int i = 1; i <= TIME; i++) {
		end *= 4;
		}
	
	printf("first:%d\ntime:%dhrs\nend:%d\n", BACTERIA,TIME,end);
	
	return 0;
	}	
