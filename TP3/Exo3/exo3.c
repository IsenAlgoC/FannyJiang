#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<math.h>
#include<locale.h>

#define NBMAXNOTES 30
#define carre(x) (x)*(x)

//initialisation du tableau
void Initialisation(float tab[]) {
	for (int i = 0; i < NBMAXNOTES; i++) {
		tab[i] = -2;
	}
}
//copier un tableau
void copie_tableau(float tab1[], float tab2[]) {
	for (int i = 0; i < NBMAXNOTES; i++) {
		tab2[i] = tab1[i];
	}
}

int main() {
	float sum = 0.00;
	int abs = 0;
	int i = 0;     //le compteur
	int present = 0;
	float note[NBMAXNOTES];
	char c;

	setlocale(LC_ALL, "fr_FR");
	Initialisation(note);

	//Enter les notes

	while (i < NBMAXNOTES) {
		printf("\nEntrer la note no %d :", i + 1);
		scanf_s("%f", &note[i]);

		if (note[i] < 0 || note[i] > 20) {

			printf("Vous avez tapé une invalide, l'élève est-il (A)bsent ou voulez vous arrêter la saisie (O)ui ou (N)on ? ");
			do {
				c = (char)toupper(_getch());
			} while ((c != 'A') && (c != 'O') && (c != 'N'));


			switch (c)
			{
			case 'A':
				note[i] = -1;
				printf("\nL'élève no %d est absent ", i + 1);
				abs++;
				i++;
				break;

			case 'O':
				i = NBMAXNOTES;
				break;

			case 'N':
				printf("\nEntrer  à nouveau la note no % d :", i + 1);
				scanf_s("%f", &note[i]);
				sum = sum + note[i];
				present += 1;
				i++;
				break;

			}
		}
		else {
			sum = sum + note[i];
			present++;
			i++;
		}
	}
	if (present == 0) {
		goto fin;
	}
	float moyenne = sum / present;
	printf("\nLa moyenne de ces %d notes est : %.2f", present, moyenne);
	printf("\n\nIl y a %d absences", abs);

	//chercher le Max et le Min
	float Min = 20;
	float Max = 0;
	int j = 0;

	for (i = 0; i < NBMAXNOTES; i++) {
		if (note[i] > -1) {
			if (Max < note[i]) {
				Max = note[i];
			}
			if (Min > note[i]) {
				Min = note[i];
			}
		}
	}
	printf("\nLa plus petite note est %.2f , la plus grande est %.2f\n", Min, Max);

	//L'écart type
	float variance = 0;
	for (i = 0; i < NBMAXNOTES; i++) {
		if (note[i] > -1) {
			variance += carre(note[i] - moyenne);
		}
	}
	variance = variance / (present - 1);
	double ecart_type = sqrt(variance);
	printf("L'écart type vaut : %f\n", ecart_type);

	// Afficher les notes
	printf("%-4s No note  Valeur note \n", " ");
	int n[NBMAXNOTES] = { 0 }; //Tableau du numero de la note
	int no = 1;              //Le numero
	for (i = 0; i < NBMAXNOTES; i++) {
		if (note[i] > -1) {
			n[i] = no++;
			printf("%-5s %d %-5s %.2f\n", " ", n[i], " ", note[i]);
		}
	}

	//classement des notes ordre decroissant
	float tab[NBMAXNOTES];
	copie_tableau(note, tab);

	for (i = 0; i < NBMAXNOTES; i++) {
		for (int j = 0; j < NBMAXNOTES - 1; j++) {
			if (tab[j] < tab[j + 1]) {
				float tmp;
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				int tmps;
				tmps = n[j];
				n[j] = n[j + 1];
				n[j + 1] = tmps;
			}
		}
	}

	printf("%-4s Rang :  No note  Valeur note \n", " ");
	int r = 0; //le rang de la note
	for (i = 0; i < NBMAXNOTES - abs; i++) {
		if (note[i] > -1) {
			r++;
			printf("%-5s %d %-5s %d %-5s %.2f\n", " ", r, " ", n[i], " ", tab[i]);
		}
	}

	// Fin
fin:
	printf("\nBye !\n");
	system("pause");
}

