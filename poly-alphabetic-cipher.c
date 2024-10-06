#include<stdio.h>
#include<string.h>
#define L 100

void polyAlphaCipher(char *input, char *output, char *key);
int main(){
	char key[L], plaintext[L], ciphertext[L];
	printf("Please input the key: ");
	scanf("%s", key);

	printf("Please input the plaintext: ");
	scanf("%s", plaintext);
	
	polyAlphaCipher(plaintext, ciphertext, key);
	printf("The ciphertext: %s\n", ciphertext);
	
	return 0;
}


void polyAlphaCipher(char *input, char *output, char *key){
	int inputL = strcspn(input, "\0");
	int keyL = strcspn(key, "\0");

	int i;	
	for (i = keyL; i < inputL; i++){
		key[i] = key[i % (keyL)];
	}
	/**for (i = 0; i < inputL; i++){
		printf("%c", key[i]);
	}*/
	printf("\n");
	for (i = 0; i < inputL; i++){
		output[i] = (input[i] - 97 + key[i] - 97) % 26 + 97;
	}
}



	
	
