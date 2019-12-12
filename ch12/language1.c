#include<stdio.h>
#include<string.h>

void main(){
	char s[] = "language";
	char c = 'g';
	char* p;
	int idx = 0;
	
	while (1){
		p = strchr(&s[idx], c);
		if (p == NULL)
			return;
		idx = (int)(p-s);
		printf("found at %d\n",idx);
		idx++;
	}
}
