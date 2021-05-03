#include<stdio.h>
#include<stdlib.h>
#define	TEST_DATA_CNT	1000000

int main(){
	int i;
	int a;

	srand(2);
	for(i=0; i<TEST_DATA_CNT; i++){
		a = rand();
		printf("%d\n",a);
	}

	return 0;
}