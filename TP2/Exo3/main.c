#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<locale.h>

int main() {

	setlocale(LC_ALL, "fr-FR");

	bool bissextile;
	int annee;
	printf("Entrez une année :");
	scanf_s("%d", &annee);

	while (annee > 10000) {
		printf("Entrez une année plus petite :");
		scanf_s("%d", &annee);
	}
	//expression logique
	bissextile = (annee % 400 == 0) || (annee % 4 == 0) && !(annee % 100 == 0);
	printf("\n L'an %d", annee);
	bissextile ? printf(" est ") : printf(" n'est pas ");
	printf("une année bissestile\n");

	//instruction if...else
	printf("\nEntrez une année :");
	scanf_s("%d", &annee);

	while (annee > 10000) {
		printf("\nEntrez une année plus petite :");
		scanf_s("%d", &annee);
	}

	if (annee % 4 == 0) {
		if (annee % 100 == 0) {
			if (annee % 400 == 0) {
				printf("\nL'an %d est une année bissextile\n", annee);
			}
			else {
				printf("\nL'an %d n'est pas une année bissextile\n", annee);
			}
		}
		else {
			printf("\nL'an %d est une année bissextile\n", annee);
		}
	}
	else {
		printf("\nL'an %d n'est pas une année bissextile\n", annee);
	}

}