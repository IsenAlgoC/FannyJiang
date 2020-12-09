#include "exo1.h"
#include<stdio.h>

main() {
	HEURE HeureDebut = { 12 , 30 };
	HEURE HeureFin;
	HEURE Duree = { 00 , 45 };
	int m = (HeureDebut.minute + Duree.minute) / 60;

	HeureFin.minute = (HeureDebut.minute + Duree.minute) % 60;
	HeureFin.heure = HeureDebut.heure + Duree.heure + m;

	printf("Heure Debut = (%d,%d)", HeureDebut.heure, HeureDebut.minute);
	printf("\nDuree = (%d,%d)", Duree.heure, Duree.minute);
	printf("\nHeurefin = (%d,%d)", HeureFin.heure, HeureFin.minute);
}

