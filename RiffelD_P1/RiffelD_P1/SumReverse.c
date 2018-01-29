/**********************************************
* Name: Donald Riffel *
* Date: (THE DUE DATE) *
* Assignment: Project 1: Integer Operations *
***********************************************
* (WRITE A DESCRIPTION OF THE PROGRAM) *
***********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reversePrint(int , int);
int sumPrint(int, int);

int main() {

	char input[10];
	int number = 0;
	printf("Enter a number: ");
	scanf_s("%10s", input, 10);
	printf("\n");
	number = atoi(input);
	printf("Reversed: ");
	reversePrint(number, 0);
	printf("\n");
	printf("Sum of digits: %d", sumPrint(number, 0));




	return 0;
}

void reversePrint(arr, start) {
	char temp[10];
	char out[10];
	_itoa_s(arr, temp, 10, 10);
	if (temp[start + 1] != NULL) {
			reversePrint(arr, start + 1);
	}
	printf("%d", temp[start] - '0');
}

int sumPrint(number, start) {
	char temp[10];
	_itoa_s(number, temp, 10 ,10);
	if (temp[start] == NULL) {
		return 0;
	}
	return sumPrint(number, start + 1) + (temp[start] - '0');
}