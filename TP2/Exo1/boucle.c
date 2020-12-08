#include <stdlib.h>
#include <locale.h>
#include<stdio.h>

int main() {

	//somme des n premier entier
	int s = 0;
	int n = 2;

	// for(){}
	for (n; n < 100; n++) {
		s = n + s;
	}
	printf("La somme des 100 premier entier avec la boucle for est %d pour n > 1 \n", s);

	//while(){}
	s = 0;
	n = 2;
	while (n < 100) {
		s = n + s;
		n += 1;
	}
	printf("\nLa somme des 100 premier entier avec la boucle while est %d pour n > 1\n", s);

	//do{}while()
	s = 0;
	n = 2;
	do {
		s += n;
		n += 1;
	} while (n < 100);
	printf("\nLa somme des 100 premier entier avec la boucle do...while est %d pour n > 1\n", s);

	// Trouver la valeur maximum sans depassement
	s = 0;
	n = 2;
	int d = 65536;// valeur  max n 2 puissance 16 comme codée sur 2 octets 65 536 bits

	while (n <= 1000) {    // 1000 est uen valeur quelconque       
		s = s + n;
		n = n + 1;
		if (d - s <= n) {
			printf("\nDepassement de capacite , n ne doit pas depasser %d\n", n - 1);
			break;
		}
	}

	//Demander la valeur de n a l'utilisateur
	s = 0;
	n = 2;
	unsigned short k = 0; // ici mon n vaut k comme je l'avais deja ulitisé

	printf("\nEntrez la valeur de n : ");
	scanf_s("%hu", &k);

	// boucle for

	for (n; n <= k; n++) {
		s = n + s;
	}
	printf("\nLa somme des %d premier entier vaut %d pour n > 1\n", n - 1, s);

	//Recommencer tant que n est trop grand
	s = 0;
	n = 2;
	k = 0;

	unsigned short m;
	printf("\nSaisir la valeur de n : ");
	scanf_s("%hu", &k);

	if (k >= 361) {
		printf("\nAfficher un entier plus petit :");
		scanf_s("%hu", &k);
	}
	for (n; n <= k; n++) {
		s = s + n;
	}
	printf("\nLa somme des %d premier entier vaut %d pour n > 1 \n", n - 1, s);
}


