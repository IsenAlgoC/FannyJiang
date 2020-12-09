#include<stdio.h>
#include<stdlib.h>

int main() {
	unsigned int MyAdresse_w;

	unsigned int MyAdresse_x;

	unsigned int MyAdresse_y;

	unsigned int MyAdresse_z;

	unsigned int IPv4MaskLengh;

	unsigned int masque;
	printf("Entrer un masque :");
	scanf_s("%u", &masque);
	while (masque > 32 || masque < 0) {
		printf("/ERROR/");
		printf("Entrer un masque valide :");
		scanf_s("%u", &masque);
	}


}