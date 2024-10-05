#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inputL 100

void caesar(char *p, char *q, int move);

int main(void){
	int move;
	printf("Please input the number you want to move(for example: 1 is for a -> b): ");
 	scanf("%d", &move);
	if (move >= 26 || move <= -26){
		move %= 26;
	}
	printf("Move %d!\n", move);
	printf("Please input the plaintext: ");
	getchar();

	char input[inputL], ciphertext[inputL];
	fgets(input, 100, stdin);
	input[strcspn(input, "\n")] = 0;
	
	caesar(input, ciphertext, move);

	char *c = ciphertext;
	// printf("%s\n", input);
	printf("The ciphertext: %s\n", ciphertext);
	

	return 0;
}

void caesar(char *p, char *q, int move){
	int i = 0;
	while(p[i] != '\0'){
		if (p[i] == 32){
			q[i++] = 32;
			continue;
		}
		q[i] = 65 + ((p[i] - 97 + move) % 26);
		i++;
	}
	q[i] = '\0';
}

