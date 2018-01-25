#include <stdio.h>
#include <string.h>
#include <ctype.h>

int duplicateChar(char[]);

//File at given address exists, Length of name does not exceed 30 characters
int main() {

	FILE *fp;
	fopen_s(&fp, "c:/Users/riffe/Documents/GitHub Repos/Storage/RiffelD_L2/Names.txt", "r");

	if (fp == NULL) {
		printf("Error opening file\n");
	}
	else {
		char name[30];
		while (fscanf_s(fp, "%30s", name, 30) != EOF) {
			int ifCopies = duplicateChar(name);

			printf_s("Hello %s", name);
			if (ifCopies == 1)
				printf_s(", (yes)\n");
			else
				printf_s(", (no)\n");
		}
	}
	int fclose(fp);
	return 0;
}
//All names in file and condition of character duplicates written to console, returns 0

//name != NULL
int duplicateChar(char name[]) {
	int copy = 0;
	for (unsigned int i = 0; i < strlen(name); i++) {
		for (unsigned int j = (i + 1); j < strlen(name); j++) {
			if (tolower(name[j]) == tolower(name[i]))
				copy = 1;
		}
	}
	return copy;
}
//Copy = 1 if duplicates, 0 if none, returns copy