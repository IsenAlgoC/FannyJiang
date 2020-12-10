#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
#define TAILLEMOT 50

//fonction qui se débarasse des caractères non alphabétique
void clean(char tab[]) {
	int p = 0 ;             // position dans le tableau
	int n = 0 ;   //le nombre de caractere non numerique
	for (unsigned int i = 0; i < strlen(tab) + n; i++) {
		if (isalpha(tab[p]) == 0) {
			for (int j = p; j < strlen(tab); j++) {
				tab[j] = tab[j + 1];
				n++;
			}
		}
		else {
			p++;
		}
	}
}
// fonction qui supprime les caractère accentuer "courant" ps:c'est le seul moyen que j'ai trouver 
void clean2(char tab[]) {
	for (unsigned int i = 0; i < strlen(tab); i++) {

		if (tab[i] == 'é' || tab[i] == ' è' || tab[i] == ' ê' || tab[i] == ' ë' || tab[i] == 'É' || tab[i] == 'È' || tab[i] == ' Ê' || tab[i] =='Ë' ) {
			tab[i] = 'E';
		}
		if (tab[i] == 'à' || tab[i] == 'â' || tab[i] == 'À' || tab[i] == 'Â ' || tab[i] == 'Ä') {
			tab[i] = 'A';
		}
		if (tab[i] == 'î' || tab[i] == 'ï' || tab[i] == ' Î' || tab[i] == ' Ï') {
			tab[i] = 'I';
		}
		if (tab[i] == 'ù' || tab[i] == 'û' || tab[i] == 'ü' || tab[i] == 'Ù' || tab[i] == 'Û' || tab[i] == 'Ü') {
			tab[i] = 'U';
		}
		if (tab[i] == 'ô' || tab[i] == 'Ô' || tab[i] == ' Ö') {
			tab[i] = 'O';
		}
		if (tab[i] == 'ÿ ' || tab[i] == 'Ÿ') {
			tab[i] = 'Y';
		}
		if (tab[i] == 'ç' || tab[i] == 'Ç') {
			tab[i] = 'C';
		}
	}
}

int main() {
	setlocale(LC_ALL, "fr_FR");

	char mot[TAILLEMOT], C1, C2;
	printf("Entrer un mot : ");
	scanf_s("%s", mot, _countof(mot));

	int s = 1; // le test si palindrome = 1 sinon 0

	clean(mot);
	clean2(mot);

	for (unsigned int i = 0; i < strlen(mot) / 2; i++) {
		C1 = _toupper(mot[i]);
		C2 = _toupper(mot[strlen(mot) - i - 1]);
		if (C1 != C2) {
			s = 0;
		}
	}
	if (s == 0) {
		printf("\nCe n'est pas un palindrome");
	}
	else {
		printf("\nC'est un palindrome");
	}

	return(EXIT_SUCCESS);

}
