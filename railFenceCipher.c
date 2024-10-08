#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 100

int main(){
	int rail;
	printf("Please input the number of rails: ");
	scanf("%d", &rail);

	char plaintext[SIZE], ciphertext[SIZE];
	
	printf("Please input the plaintext: ");
	getchar();
	fgets(plaintext, SIZE, stdin);
	plaintext[strcspn(plaintext, "\n")] = 0;
	int pL = strlen(plaintext);

	int pIndex, cIndex = 0;
	for (int i = 1; i <= rail; i++){
		pIndex = i - 1;
		bool firstStep = true;	
		while(pIndex < pL){
			if (i == 1 || i == rail){	
				ciphertext[cIndex++] = plaintext[pIndex];
				pIndex += (rail - 1) * 2;
			}else{
				ciphertext[cIndex++] = plaintext[pIndex];
				if (firstStep){
					pIndex += (rail - i) * 2;
					firstStep = false;
				}else{
					pIndex += (i - 1) * 2;
					firstStep = true;
				}
			}
		}
	}

	printf("%s", ciphertext);
	return 0;
}
		

