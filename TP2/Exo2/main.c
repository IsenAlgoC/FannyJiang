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
	int test = 0;
	int encore = 1;

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

		Ordonner(hauteur, profondeur, largeur);

		float taille = 55 * 35 * 25;
		if (largeur * hauteur * profondeur > taille) {
			printf("/NON VALIDE/\n");
		}
		else {
			printf("/VALIDE/\n");
		}

		char tmp;
		printf("Voulez-vous traiter un autre colis?\n [O]ui ou [N]on \n");
		
		tmp = (char)toupper(_getch());
		
		if (tmp == 'O') {
			encore == 1;
		}
		else {
			encore = -1;
		}

	}

	return (EXIT_SUCCESS);
}