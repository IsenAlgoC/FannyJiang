#include <stdio.h>
#include<locale.h>
#define SEPARATEUR '/'
#define TAILLETAB1 20

int main() {
	int MyTab1[TAILLETAB1];
	int i;

	for (i = 1; i <= 20; i++) {
		MyTab1[i - 1] = i;
		printf("%d/", MyTab1[i - 1]);
	}

	printf("\n");

	int* MyPtr1;
	MyPtr1 = &MyTab1[TAILLETAB1 - 1];
	for (i = 1; i <= 20; i++) {
		printf("%d/", *MyPtr1 - i + 1);
	}
}

