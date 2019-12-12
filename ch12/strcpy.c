#include<stdio.h>

int main(){
	char  src[] = "The worst things to eat before you sleep";
	char dst[100];
	int i;
	
	printf("The original string = %s\n", src);
	for(i = 0; src[i] != '\0'; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	printf("The copied string = %s\n", dst);

	return 0;
}
