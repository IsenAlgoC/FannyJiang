#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	unsigned int MyAdresse_w;
	printf("Entrer un l'adresse w :");
	scanf_s("%u", &MyAdresse_w);
	while (MyAdresse_w > 255 || MyAdresse_w < 0) {
		printf("/ERROR/\n");
		printf("Entrer un l'adresse w :");
		scanf_s("%u", &MyAdresse_w);
	}
	unsigned int MyAdresse_x;
	printf("Entrer un l'adresse x :");
	scanf_s("%u", &MyAdresse_x);
	while (MyAdresse_x > 255 || MyAdresse_x < 0) {
		printf("/ERROR/\n");
		printf("Entrer un masque valide :");
		scanf_s("%u", &MyAdresse_x);
	}

	unsigned int MyAdresse_y;
	printf("Entrer un l'adresse y :");
	scanf_s("%u", &MyAdresse_y);
	while (MyAdresse_y > 255 || MyAdresse_y < 0) {
		printf("/ERROR/\n");
		printf("Entrer un masque valide :");
		scanf_s("%u", &MyAdresse_y);
	}
	unsigned int MyAdresse_z;
	printf("Entrer un l'adresse z :");
	scanf_s("%u", &MyAdresse_z);
	while (MyAdresse_z > 255 || MyAdresse_z < 0) {
		printf("/ERROR/\n");
		printf("Entrer un masque valide :");
		scanf_s("%u", &MyAdresse_z);
	}
	unsigned int IPv4MaskLength;
	printf("Entrer un masque :");
	scanf_s("%u", &IPv4MaskLength);
	while (IPv4MaskLength > 32 || IPv4MaskLength < 0) {
		printf("/ERROR/\n");
		printf("Entrer un masque valide :");
		scanf_s("%u", &IPv4MaskLength);
	}

	printf("adresse %-4s IPv4 = %u.%u.%u.%u / %u\n", " ", MyAdresse_w, MyAdresse_x, MyAdresse_y, MyAdresse_z, IPv4MaskLength);

	unsigned int n = 0;  // le masque
	for (unsigned int i = 0; i < IPv4MaskLength; i++) {
		n += pow(2, 31 - i);
	}

	unsigned int Adresse_machine = (MyAdresse_w << 24) + (MyAdresse_x << 16) + (MyAdresse_y << 8) + MyAdresse_z;
	
	unsigned int Adresse_reseau = Adresse_machine & n;
	unsigned int tmp = Adresse_reseau;
	printf("\nadresse du reseau = ");
	printf("%d", Adresse_reseau >> 24);
	Adresse_reseau <<= 8;
	Adresse_reseau >>= 8;
	printf(".%d", (Adresse_reseau >> 16));
	Adresse_reseau <<= 16;
	Adresse_reseau  >>= 16;
	printf(".%d", Adresse_reseau >> 8);
	Adresse_reseau  <<= 24;
	Adresse_reseau >>= 24;
	printf(".%d", Adresse_reseau);
	printf(" / %d\n", IPv4MaskLength);

	Adresse_reseau = tmp;
	unsigned int Adresse_Broadcast = Adresse_reseau |~ n;
	printf("\nadresse broascast = ");
	printf("%d", Adresse_Broadcast >> 24);
	Adresse_Broadcast <<= 8;
	Adresse_Broadcast >>= 8;
	printf(".%d", Adresse_Broadcast >> 16);
	Adresse_Broadcast <<= 16;
	Adresse_Broadcast >>= 16;
	printf(".%d", Adresse_Broadcast >> 8);
	Adresse_Broadcast <<= 24;
	Adresse_Broadcast >>= 24;
	printf(".%d\n", Adresse_Broadcast);

	system("pause");
	return (EXIT_SUCCESS);

}