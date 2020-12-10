#include<stdio.h>
#include<stdlib.h>
#include< string.h>
#include<time.h>
#include<locale.h>

#define TAILLE 100

//initialisation du tableau
void init(int tab[]) {
	srand(time(NULL));	//obtenir des valeurs listes à chaque lancement
	int i = 0;
	for ( i ; i < TAILLE ; i++) {
		tab[i] = rand() % 21 ;
	}
}


int main() {
	setlocale(LC_ALL, "fr_FR"); 

	int tab[TAILLE];     //Notre tableau de valeur
	init(tab);        
	int i = 0;           //initialisation de l'indice
//afficher toutes les valeur du tableau pour la vérification
	for ( i ; i < TAILLE; i++) {
		printf("| %d |",tab[i]);
	}

	int val;              //la valaue que l'on choisi
	int* Curseur;          
	Curseur = &tab[0];

	printf("\nEntrez la valeur recherchée : ");
	scanf_s("%d", &val );

	int trouve = 0 ;       // obtnir le nombre de fois ou on a trouver la valeur en question
	int tmp[TAILLE] = {0}; // tableau ou se trouvera les différentes position val
	int j = 0 ;			   //indice permettant de se deplacer dans le tableau tmp
	i = 0;  

//remplissage des position de la valeur dans tmp
	while( i < TAILLE ) {
		if (*(Curseur + i) == val ) {
			trouve++;
			tmp[j] = i;
			j++;
		}
		i++;
	}

//affichage
	if (trouve == 0) {
		printf("La valeur %d n'a pas été trouvée", val);
	}
	else {
		i = 0;
		printf("La valeur %d a été trouvée en ", val);
		while ( i < trouve - 1 ) {
			printf("%d , puis en ", tmp[i]);
			i++;
		}
		printf("puis en %d.", tmp[i]);
	}

	system("pause");
	return(EXIT_SUCCESS);
}