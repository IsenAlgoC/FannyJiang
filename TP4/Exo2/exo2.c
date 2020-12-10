#include <stdio.h>
#define SEPARATEUR '/'
#define TAILLETAB1 20
#include<stdlib.h>

int main() {
	int MyTab1[TAILLETAB1];
	int i;

	for (i = 1; i <= 20; i++) {
		MyTab1[i - 1] = i;
		printf("%d %c", MyTab1[i - 1],SEPARATEUR);
	}

	printf("\n");

	int* MyPtr1; 
	MyPtr1 = &MyTab1[TAILLETAB1 - 1];
	for (i = 1; i <= 20; i++) {
		printf("%d %c", *(MyPtr1 - i + 1) ,SEPARATEUR);
	}
	return(EXIT_SUCCESS);
}

