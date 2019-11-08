#include<stdio.h>
#include<stdlib.h>

int main(){
	char s1[] = "100";
	char s2[] = "12.93";
	char buffer[100];
	int i;
	double d, result;

	i = atoi(s1);
	d = atof(s2);
	result = i + d;

	sprintf(buffer, "%f", result);
	printf("The result is %s\n", buffer);
	return 0;
}
