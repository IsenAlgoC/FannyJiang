#include <stdlib.h>
#include <stdio.h>
#include<locale.h>

#define carre(x) (x)*(x) // modification rajout de parenthese sur x*x

int main() {
	setlocale(LC_ALL, "fr_FR");

	int Nb = 5;

	printf(" Le carré de Nb est %d ", carre(Nb));
	printf("\n Le carré de Nb est %d ", carre(Nb + 1));
}