#include<stdio.h>
#include<stdlib.h>
#include "tab.h"

int main() {
	Tableau tab = newArray();
	printf("La taille initiale du tableau est %d\n", tab.size);
	printf("Il y a %d elements dans le tableau\n", tab.eltsCount);
	displayElements(&tab, 1, TAILLEINITIALE);

	printf("\ntest incrementation\n");
	incrementArraySize(&tab, 5);
	incrementArraySize(&tab, -1);

	printf("\ntest placement element\n");
	setElement(&tab, 1, 3);
	setElement(&tab, 2, 4);
	setElement(&tab, 3, 5);
	setElement(&tab, 4, 6);

	setElement(&tab, 4, 3);
	displayElements(&tab, 1, TAILLEINITIALE);
	printf("\nIl y a %d elements dans le tableau\n", tab.eltsCount);

	setElement(&tab, 115, 3);

	printf("Il y a %d elements dans le tableau\n", tab.eltsCount);
	printf("\nLa taille avant supression du tableau est %d\n", tab.size);
	printf("test supression\n");


	deleteElements(&tab, 1, 3);

	displayElements(&tab, 1, 16);
	printf("\non vient d'enlever 3 element sur 5\n");
	printf("\nIl y a %d elements dans le tableau\n", tab.eltsCount);


	return (EXIT_SUCCESS);
}