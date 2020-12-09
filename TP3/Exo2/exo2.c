
#include <stdio.h>
#include<stdlib.h>

int main() {
	unsigned int a = 2868838400; //AAFF0000 en hexadecimale

	int NBoctect = sizeof(a);
	printf("Le nombre %u est codee sur %d octect", a, NBoctect);

	int NbBit = sizeof(a) * 8;
	printf("\nle nombre %u est codee sur %d bit", a, NbBit);

	for (int i = 0; i < 32; i++) {
		if (i < 10) {
			if ((a & 1) == 1) {
				printf("\nbit %s%d : ON", " ", i);
			}
			else {
				printf("\nbit %s%d : OFF", " ", i);
			}
		}
		else {
			if ((a & 1) == 1) {
				printf("\nbit %d : ON", i);
			}
			else {
				printf("\nbit %d : OFF", i);
			}
		}
		a >>= 1;
	}
	printf("\nBye!");
}