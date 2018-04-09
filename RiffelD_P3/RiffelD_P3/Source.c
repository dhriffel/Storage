#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *, int *);
int sortLists(int**, int);
int sortArray(int**);
int printAll(int**);
int freeAll(int**, int);



void main(char args[]) {

	FILE* file;
	fopen_s(&file, "c:/Users/riffe/Documents/GitHub Repos/Storage/RiffelD_P3/test.txt", "r");
	int ** arrays = NULL;
	int temp = 0;

	if (file) {

		temp = fgetc(file) - '0';
		fgetc(file);
		printf("%i Lists:\n", temp);
		arrays = malloc((sizeof(int*) * temp)+1);
		int ** pArrow = arrays;
		char inStrings[255];
		while (fgets(inStrings, 255, file)) {
			int numCount = atoi(&inStrings[0]) +1;
			int i = 0;
			int j = 0;
			*pArrow = malloc(sizeof(int) * numCount);
			while (i < numCount) {
				if ((char)inStrings[j] == '-') {
					(*((*pArrow) + i)) = (atoi(&inStrings[j+1]))*(-1);
					j++;
					i++;
				}

				else if ((char)inStrings[j] != ':' & (char)inStrings[j] != ',' & (char)inStrings[j] != ' ') {
					(*((*pArrow) + i)) = atoi(&inStrings[j]);
					i++;
				}
				j++;
			}
			pArrow++;
		}
		*pArrow = NULL;
	}

	fclose(file);
	sortLists(arrays, temp);
	sortArray(arrays);
	printAll(arrays);
	freeAll(arrays, temp);
}

void swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int sortArray(int** arr) {
	while (*arr != NULL) {
		int len = **arr;
		int i, j;
		for (i = 0; i < (len - 1); i++) {

			for (j = 1; j < (len - i); j++)
				if (*(*(arr) + j) > *(*(arr) + j + 1))
					swap(*(arr) + j, *(arr) + j + 1);
		}
		arr++;
	}
	return 1;
}

int sortLists(int** arr, int temp) {
	int i, j;
	for (i = 0; i < (temp - 1); i++) {
 
		for (j = 0; j < (temp - i - 1); j++)
			if (**(arr + j) > **(arr + j + 1))
				swap((arr + j), (arr + j + 1));
	}
	return 1;
}

int printAll(int** arr) {

	while (*arr != NULL) {
		int len = **arr;
		int i;
		for (i = 0; i < len; i++) {
			if (i + 1 != len) {
				printf("%i, ", *(*(arr)+i + 1));
			}
				
			else {
				printf("%i ", *(*(arr)+i + 1));
			}

			
		}
		printf("\n");
		arr++;
	}
	return 1;
}

int freeAll(int ** array, int temp) {
	for (int i = temp-1; i >= 0; i--) {
		free(*(array + i));
	}
	array = NULL;
	return 1;
}