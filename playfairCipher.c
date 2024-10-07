#include<stdio.h>
#include<string.h>

#define CSIZE 5
#define PSIZE 100

int findXY(char cipher[][CSIZE], char target);

int main(void){
	// The 5*5 table.
	char cipher[CSIZE][CSIZE];
	// Count which alphabet is lost.
	int counter[CSIZE * CSIZE];
	printf("Please input the playfair cipher: \n");
	for (int i = 0; i < CSIZE; i++){
		for (int j = 0; j < CSIZE; j++){
			scanf("%c", &cipher[i][j]);
			counter[cipher[i][j] - 65]++;
		}
		getchar();
	}

	char lastAlpha, shareAlpha;
	for (int i = 0; i < CSIZE*CSIZE; i++){
		if (counter[i] != 1){
			lastAlpha = i + 65;
			break;
		}
	}
	printf("Please input the alphabet's share the position with lost one: ");
	scanf("%c", &shareAlpha);

	char plaintext[PSIZE], ans[PSIZE];
	printf("Please input the plain-text: ");
	getchar();
	fgets(plaintext, PSIZE, stdin);
	plaintext[strcspn(plaintext, "\n")] = 0;
	
	int pL = strlen(plaintext);
	// Count the ans index.
	int count = 0;
	for (int i = 0; i < pL; i++){
		char a, b;
		a = plaintext[i];
		if (a == lastAlpha){
			a = shareAlpha;
		}

		if (i == pL - 1){
			b = 'X';
		}else if (plaintext[i + 1] == a){
			b = 'X';
		}else{
			b = plaintext[i + 1];
			if (b == lastAlpha){
				b = shareAlpha;
			}

			if (a == b){
				b = 'X';
			}else{
				i += 1;
			}
		}
		//printf("a = %c, b = %c, i = %d\n", a, b, i);


		int aX, aY, bX, bY;
		aX = findXY(cipher, a);
		aY = aX % 5;
		aX /= 5;
		bX = findXY(cipher, b);
		bY = bX % 5;
		bX /= 5;
		//printf("aX = %d aY = %d bX = %d bY = %d\n", aX, aY, bX, bY);
		

		if (aX == bX){
			ans[count++] = cipher[aX][(aY + 1) % 5];
			ans[count++] = cipher[bX][(bY + 1) % 5];
		}else if(aY == bY){
			ans[count++] = cipher[(aX + 1) % 5][aY];
			ans[count++] = cipher[(bX + 1) % 5][bY];
		}else{
			ans[count++] = cipher[aX][bY];
			ans[count++] = cipher[bX][aY];
		}

		//printf("ans[%d] = %c ans[%d] = %c\n", count-2,ans[count-2],count-1,ans[count-1]);
	}
	
	for (int i = 0; i < count; i++){
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}

int findXY(char cipher[][CSIZE], char target){
	for (int i = 0; i < CSIZE; i++){
		for (int j = 0; j < CSIZE; j++){
			if (target == cipher[i][j]){
				return i * 5 + j;
			}
		}
	}
	return -1;
}
