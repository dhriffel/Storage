/**********************************************
* Name: Donald Riffel *
* Date: 1/30/18 *
* Assignment: Project 1: Integer Operations *
***********************************************
* Takes an 10-digit or less in length number from the user
and gives the number in reverse as well as the sum of all digits
in the number*
***********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reversePrint(char[] , int);
int sumPrint(char[], int);

int main() {

	char input[11];
	int number = 0;
	printf("Enter a number: ");
	scanf_s("%11s", input, 11);
	printf("\n");
	number = atoi(input);
	printf("Reversed: ");
	reversePrint(input, 0);
	printf("\n");
	printf("Sum of digits: %d", sumPrint(input, 0));




	return 0;
}

/**********************************************
* arr: char[] holding the input number
* start: the current index to look at
* returns: nothing
* Pre-condition: given char[] must be non-negative, 10 digits or less and all char must me numeral characters
* Post-condition: printed char[] is in reverse order from the given char[]
***********************************************/
void reversePrint(arr, start) {
	char temp[11];
	strcpy(temp,arr);
	//_itoa_s(arr, temp, 10, 10);
	if (temp[start + 1] != NULL) 
	{
			reversePrint(temp, start + 1);
	}
	printf("%c", temp[start]);
}

/**********************************************
* number: char[] holding the input number
* start: the current index to look at
* returns: int holding the sum
* Pre-condition: given char[] must be non-negative, 10 digits or less and all char must me numeral characters
* Post-condition: returned int is the sum of all digits in the given number
***********************************************/
int sumPrint(number, start) {
	char temp[11];
	strcpy(temp, number);
	//_itoa(number, temp, 12 ,12);
	if (temp[start] == NULL) {
		return 0;
	}
	return sumPrint(number, start + 1) + (temp[start] - '0');
}