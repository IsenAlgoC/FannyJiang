#include<stdio.h>
#include<stdlib.h>
#include "tab.h"
#define TAB2SIZE 100
#define TAILLEAJOUT 50
//Exo1
//1.Fonction avec passage d'un tableau en argument

int initTab(int* tab, int size) {
	tab[size];
	//test si le tableau est null
	if (tab == NULL || size < 0) {
		return -1;
	}
	//le tableau n'est pas null remplace toute les valeur par 0
	for (int i = 0; i < size; i++) {
		*(tab + i) = 0;
	}
	printf("\n%d\n", size);
}

int afficheTab(int* tab, int size, int nbElts) {
	tab[size];
	//condition du retour -1
	if (tab == NULL || size < 0 || size < nbElts) {
		return -1;
	}
	//afficahge des nbElts element du tableau et de 0 pour montrer que cela a marché
	for (int i = 0; i < nbElts; i++) {
		printf(" %d ", *(tab + i));
	}
	printf("\n0\n");
}

// 2.Agrandissemennt d'un tableau alloué dynamiquement

int* ajouteElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (*size > * nbElts) { // cas ou on est pas obliger de changer la taille du tableau
		tab[*nbElts] = element;
		*nbElts = *nbElts + 1;
		return tab;
	}
	int* tmp;
	tmp = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));

	if (tmp == NULL) {  // le realloc n'a pas marché 
		printf("Ajout impossible");
		return -1;
	}
	else {
		tab = tmp;                  // realloc a marché 
		*size = *size + TAILLEAJOUT;
		*(tab + *nbElts) = element;
		nbElts = nbElts + 1;
		return tab;
	}
}

