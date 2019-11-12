#include<stdio.h>

void encrypt(char cipher[], int shift);

int main(){
	char cipher[50];
	int shift=3;
	printf("Type string: ");
	fgets(cipher, 50, stdin);
	encrypt(cipher, shift);

	return 0;
}

void encrypt(char cipher[], int shift){
	int i = 0;
	while (cipher[i] != '\0'){
		if (cipher[i] >= 'a' && cipher[i] <= 'z'){
			cipher[i] += shift;
			if (cipher[i] > 'z')
				cipher[i] -= 26;
		}
		i++;
	}
	printf("Encrypted string: %s\n", cipher);
	}
