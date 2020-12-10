#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <conio.h>
#define TAILLEMOT 20

int main() {
	char nom[TAILLEMOT];
	char prenom[TAILLEMOT];	

	printf("Entree votre nom : ");
	scanf_s("%s", nom ,_countof(nom));
	printf("Entree votre prenom : ");
	scanf_s("%s", prenom, _countof(prenom));
	printf("Etes-vous un (H)omme ou une (F)emme ?");

	char  ch = (char)toupper(_getch());

	switch (ch)
	{
	case 'F':
		printf("\nMadame %s %s", nom, prenom);
		break;
	case 'H':
		printf("\nMonsieur %s %s", nom, prenom);
		break;
	}
	return(EXIT_SUCCESS);
}