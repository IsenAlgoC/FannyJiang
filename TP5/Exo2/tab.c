#include<stdio.h>
#include<stdlib.h>
#include "tab.h"

// 1 - crée un nouveau TABLEAU en allouant une taille initiale pour les données.

Tableau newArray() {
	Tableau tab;

	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));

	if (tab.elt == NULL) {                  //condition de non-allocation
		printf("Allocation echoue");
		return tab;
	}

	else {                                  //allocation-> initialisation du tableau
		for (int i = 0; i < TAILLEINITIALE; i++) {
			*(tab.elt + i) = 0;
		}
		tab.eltsCount = 0;
		tab.size = TAILLEINITIALE;
		return tab;
	}
}

// 2 - modifie la taille du tableau

int incrementArraySize(Tableau* tab, int incrementValue) {
	int* oldtabelt = tab->elt;                              // sauvegarde l'ancienne pointeur de tab.elt
	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));

	if (tab->elt == NULL || incrementValue < 0) { // reallocation impossible
		tab->elt = oldtabelt;
		return -1;
	}
	else {                                  // reallocation possible ->nouvelle taille
		tab->size += incrementValue;
	}
	printf("La nouvelle taille du tableau est %d\n", tab->size);
}

// 3 - Ecrit un élément à une position donnée sans insertion 

int setElement(Tableau* tab, int pos, int element) {
	if (pos < tab->size) {          //si la position est a l'interieur du tab
		if (tab->elt[pos - 1] != 0) {// il y a deja un element -> erreur
			return 0;
		}
		else {                      // il n'y a pas d'element on place le nouvelle element
			*(tab->elt + pos - 1) = element;
			tab->eltsCount += 1;
		}
		printf("La position d'insertion est %d\n", pos);
	}
	else {                            // la position est a l'exterieur du tableau
		if (incrementArraySize(tab, pos - tab->size) == -1) {//allocation impossible
			return (0);
		}
		else {                                           //allocation posssible
			for (int i = tab->size + 1; i < pos; i++) {// on remlie par la valeur null les de la position 
				*(tab->elt + i) = 0;                    // pos a tan.size + 1
			}
			*(tab->elt + pos) = element;
			tab->size = pos;
			tab->eltsCount += 1;
		}
		printf("La position d'insertion est %d\n", pos);
	}
}

// 4 - Affiche une portion du tableau de l’indice début à l’indice fin
int displayElements(Tableau* tab, int startPos, int endPos) {
	if (endPos > tab->size || startPos > tab->size || endPos < 1 || startPos < 1) { // condition erreur
		return (-1);
	}
	else {
		if (startPos >= endPos) {//changement entre la valeur de debut et fin
			int tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		for (int i = startPos - 1; i < endPos; i++) { // affichage du tableau allant de startPos+1 a endPos
			printf("%d", *(tab->elt + i));

		}
		return 0;
	}
}
// 5 - Supprime des éléments avec compactage du tableau
int deleteElements(Tableau* tab, int startPos, int endPos) {

	int* oldtabelt = tab->elt;     // garde l'ancien le pointeur de tab.elt

	tab->elt = (int*)realloc(tab->elt, (tab->size - (endPos - startPos)) * sizeof(int));

	if (endPos > tab->size || startPos > tab->size || endPos < 1 || startPos < 1) { // erreur pour les meme condition que display
		return (-1);
	}
	else {
		if (startPos > endPos) {       //inversion de startPos et endPos
			int tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		if (tab->elt == NULL) {              // allocation echoue
			tab->elt = oldtabelt;
			return (-1);
		}
		else {                                         // allocation reussi changement de la taille
			tab->size = tab->size - (endPos - startPos + 1);
		}

		for (int i = startPos - 1; i < endPos; i++) {      // changement du nombre d'elements si element nul
			if (*(tab->elt + i) != 0) {
				tab->eltsCount = tab->eltsCount - 1;
			}
		}
		for (int i = 0; i < tab->size - endPos; i++) {               // deplace les element en endPos au niveau de startPos
			*(tab->elt + startPos - 1 + i) = *(tab->elt + endPos + i);
		}
		printf("\nLa nouvelle taille apres diminution de la taille du tableau est %d\n", tab->size);
	}
}