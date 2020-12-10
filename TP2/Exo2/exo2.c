#include <stdlib.h>
#include <locale.h>
#include<stdio.h>

//ordonner dans l'ordre décoissant
void Ordonner(float a, float b, float c) {
	float tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c) {
		tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	printf("hauteur=%f ,largueur=%f ,profondeur=%f \n", a, b, c);
}

int main() {
	float hauteur;
	float largeur;
	float profondeur;
	int test = 0;    //prend le role d'un booléen si = 0 alors saisie non valide sinon =1
	int encore = 1;  //sert a savoir si on continu ou arrete le test joue le role d'un booléen

	while (encore == 1) {
		printf("Saisir la hauteur : ");
		scanf_s("%f", &hauteur);
		while (test == 0) {
			if (150 < hauteur || hauteur < 1) {
				printf(" Saisir une autre valeur pour la hauteur : ");
				scanf_s("%f", &hauteur);

			}
			else {
				test = 1;
			}
		}

		printf("Saisir la largeur : ");
		scanf_s("%f", &largeur);

		test = 0;
		while (test == 0) {
			if (150 < largeur || largeur < 1) {
				printf("Saisir une qutre valeur pour la largeur : ");
				scanf_s("%f", &largeur);

			}
			else {
				test = 1;
			}
		}

		printf("Saisir profondeur : ");
		scanf_s("%f", &profondeur);

		test = 0;
		while (test == 0) {
			if (150 < profondeur || profondeur < 1) {
				printf("Saisir une nouvelle valeur pour la profondeur : ");
				scanf_s("%f", &profondeur);

			}
			else {
				test = 1;
			}
		}

		Ordonner(hauteur, largeur, profondeur);

		float taille = 55 * 35 * 25;
		if (largeur * hauteur * profondeur > taille) {
			printf("/NON VALIDE/\n");
		}
		else {
			printf("/VALIDE/\n");
		}

		
		printf("Voulez-vous traiter un autre colis?\n [O]ui ou [N]on \n");
		
		char tmp = (char)toupper(_getch());
		
		switch (tmp) {
		case 'O':
			break;
		case 'N':
			encore = 0;
			break;
		}

	}

	return (EXIT_SUCCESS);
}