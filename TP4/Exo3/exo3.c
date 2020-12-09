#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <conio.h>
#define TAILLEMOT 20

int main() {
	char nom[TAILLEMOT];
	char prenom[TAILLEMOT];
	char sexe[1];
	char H, F, ch;

	printf("Entree votre nom:");// %s pour str sinon %c
	scanf_s("%s", nom, _countof(nom));
	printf("Entree votre prenom:");
	scanf_s("%s", prenom, _countof(prenom));
	printf("Entree votre sexe:");

	ch = (char)_getch();
	ch = (char)toupper(ch);

	switch (ch)
	{
	case 'F':
		printf("Madame %s %s", nom, prenom);
	case 'H':
		printf("Monsieur %s %s", nom, prenom);
	}



}