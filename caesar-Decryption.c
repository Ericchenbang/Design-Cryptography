#include<stdio.h>
#include<string.h>
#define inputL 100

int main(){
	char input[inputL], output[inputL];
	printf("Please input the move: ");
	int move;
	scanf("%d", &move);
	getchar();

	printf("Please input the ciphertext: ");
	scanf("%s", input);

	char *p = input;
	int index = 0;
	for (; *p != '\0'; p++){
		output[index++] = 97 + ((*p - 97 - move) % 26);
	}
	output[index] = '\0';
	
	printf("The plaintext: %s", output);
	return 0;
}
	

