#include<stdio.h>
#include<string.h>

int search(char*);

int main(){
	char s[] = "language";
	char t[80];
	int loc = 0;
	int len = strlen(s);

	while (loc != -1 || len < 1){
		loc = search(s);
		memcpy(t, (s+loc+1), (len-loc));
		len = strlen(t);
		strcpy(s, t);
	}
}

int search(char* s){
	char c = 'g';
	char *p;
	int loc;
	static int total = 0;
	
	p = strchr(s, c);
	loc = (int)(p - s);
	total += loc;
	if (p != NULL){
		printf("Found at %d\n", total);
		return loc;
	}
	else
		return -1;
}
