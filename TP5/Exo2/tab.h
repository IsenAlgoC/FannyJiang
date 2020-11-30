#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef struct Tableau {
	int* elt;          // le tableau d'entier
	int size;          //la taille de ce tableau d'entier
	int eltsCount;     // le nombre d'élements dans le tableau
}Tableau;

#define TAILLEINITIALE 100


Tableau newArray();

int incrementArraySize(Tableau* tab, int incrementValue);

int setElement(Tableau* tab, int pos, int element);

int displayElements(Tableau* tab, int startPos, int endPos);

int deleteElements(Tableau* tab, int startPos, int endPos);
