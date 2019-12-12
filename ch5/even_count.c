#include<stdio.h>
#include<sys/time.h>

#define MAX_LIMIT 100

int main() {
	struct timeval t_start, t_end;
	int i, cnt;

	//get start time
	gettimeofday(&t_start, NULL);

	i = 0;
	cnt = 0;

	while (i < MAX_LIMIT) {
		if ((i % 2) == 0)
			cnt++;
		i++;
	}
	printf("even numbers = %d\n", cnt);

	//get end time
	gettimeofday(&t_end,NULL);

	//print time duration
	/*printf("%f secs\n", (t_end.tv_sec - t_start.tv_sec + (t_end.tv_usec -t_start.tv_usec) / 1000000.0));*/

	//print usec
	printf("%f usecs\n", (t_end.tv_sec - t_start.tv_sec) * 1000000.0 + (t_end.tv_usec - t_start.tv_usec));

	return 0;
}
