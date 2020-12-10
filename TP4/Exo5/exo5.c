#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCARACTERE 1024

int main() {
	char buffer[MAXCARACTERE];
//entrer une phrase au clavier
	printf("Entrer une phrase :\n ");
	gets_s(buffer,sizeof(buffer));

//compte le nombre de mot et la longueur moyenne des mot
	int longueur = 0;
	int moyenne = 0;
	int nbmot = 0;

	for (unsigned int i = 0; i < strlen(buffer); i++) {
		if (isalpha(buffer[i])) {
			longueur += 1;
		}
		else {
			nbmot++;
			moyenne += longueur;
			longueur = 0;
		}
	}

	printf("Vous avez taper : %d mot de longueur moyenne : %d\n", nbmot, moyenne/nbmot);

	system("pause");
	return(EXIT_SUCCESS);
}