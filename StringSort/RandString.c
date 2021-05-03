#include<stdio.h>
#include<stdlib.h>
#define	TEST_DATA_CNT	1000000
#define TEST_TEXT_LEN	100

int main(){
	char alphabet[26] = {"adcdefghijklmnopqrstuvwxyz"};
	char text[105];
	int i,j;

	srand(2);
	for(i=0; i<TEST_DATA_CNT; i++){
		for(j=0; j<TEST_TEXT_LEN; j++){
			text[j] = alphabet[( (rand()%26) )];
		}
		printf("%s\n",text);
	}

	 return 0;
}