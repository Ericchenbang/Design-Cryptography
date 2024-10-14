#include<stdio.h>
#include<string.h>
#define L 100

int main(){
	char key[L], plaintext[L], ciphertext[L];
	printf("Please input the key: ");
	scanf("%s", key);
	getchar();

	printf("Please input the ciphertext: ");
	scanf("%s", ciphertext);
	getchar();

	int i = 0;
	int cL = strlen(ciphertext);
	int kL = strlen(key);
	for (; i < cL; i++){
		int e = (ciphertext[i] - 97 - (key[i % kL] - 97)) % 26;
		if (e < 0) e += 26;
		plaintext[i] = 97 + e - 1; 
	}
	plaintext[i] = '\0';
		
	printf("The plaintext: %s", plaintext);
	return 0;
}
