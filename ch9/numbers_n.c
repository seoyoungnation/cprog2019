#include<stdio.h>
#include<sys/time.h>

int main() {
	long sum, i;
	struct timeval t_start, t_end;
		
	gettimeofday(&t_start, NULL);

	sum = 0;
	for(i = 0; i < 100000000; i++) 
		sum += i;
	printf("sum = %ld\n", sum);

	gettimeofday(&t_end, NULL);

	printf("%f sec\n", (t_end.tv_sec - t_start.tv_sec + (t_end.tv_usec - t_start.tv_usec) / 1000000.0));

	return 0;
}

