#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAILLEMOT 50

// voir string.h ,strcmp , strlen
//strchr le premier caractere et strrche le dernier caractere

int main() {
	char mot[TAILLEMOT], C1, C2;
	printf("Entrer un mot:");
	scanf_s("%s", mot, _countof(mot));
	int len = strlen(mot);
	int s = 1;

	for (int i = 0; i < len / 2; i++) {
		C1 = _toupper(mot[i]);
		C2 = _toupper(mot[len - i - 1]);
		if (C1 != C2) {
			s = 0;
		}
	}
	if (s == 0) {
		printf("Pas un palindrome");
	}
	else {
		printf("Un palindrome");
	}
}