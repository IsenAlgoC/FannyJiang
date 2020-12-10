#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

int main() {
	setlocale(LC_ALL, "fr_FR");

	printf("Début du jeu\n");

	srand(time(NULL));
	int valeur = rand(); //la valeur a deviner
	int tmp;           //la valeur proposer par le joueur
	int score = 0;

	printf("Saisir un nombre entier:");
	scanf_s("%d", &tmp);

	while (tmp != valeur) {

		if (tmp < valeur) {
			printf("\nTrop petit\n");
			score++;
		}
		else {
			printf("\nTrop grand\n");
			score++;
		}

		printf("\nSaisir un autre nombre:");
		scanf_s("%d", &tmp);

	}

	printf("\nFin du jeu\n");

	printf("Votre score est %d\n", score);
}