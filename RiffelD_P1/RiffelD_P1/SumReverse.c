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

void reversePrint(char[] , int);
int sumPrint(int, int);

int main() {

	char input[10];
	int number = 0;
	printf("Enter a number: ");
	scanf_s("%10s", input, 10);
	//reversePrint(input, 0);
	number = atoi(input);
	printf("%d", sumPrint(number, 0));




	return 0;
}

/*void reversePrint(arr, start) {
	int length = strlen(arr);
	char temp[length];
	if (length != start){
		reversePrint(arr, start + 1);
}
	printf("%c", temp[start]);
}*/

int sumPrint(number, start) {
	char temp[10];
	_itoa_s(number, temp, 10 ,10);
	if (temp[start] == NULL) {
		return 0;
	}
	return sumPrint(number, start + 1) + (temp[start] - '0');
}