#include<stdio.h>
#include<stdlib.h>
#include "tab.h"
#define TAB2SIZE 100
#define TAILLEAJOUT 50


int main() {

	int myTab1[10] = { 0,1,2,3,4,5,6,7,8,9 };

	initTab(myTab1, 10);

	afficheTab(myTab1, 10, 10);

	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;

	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) {
		initTab(myTab2, tabSize);
	}
	else {
		printf("mémoire insuffisante");
		return(-1);
	}

	for (int i = 0; i < 20; i++) {
		*(myTab2 + i) = i + 1;
	}
	afficheTab(myTab2, TAB2SIZE, 20);

	int a = 10;
	int b = 13;
	ajouteElementDansTableau(myTab2, &a, &b, 100);
	afficheTab(myTab2, TAB2SIZE, 13);

	free(myTab2);

	return EXIT_SUCCESS;
}
