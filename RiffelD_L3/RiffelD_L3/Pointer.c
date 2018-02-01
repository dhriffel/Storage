#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toCaps(char*);
void reverseName(char*, int);

int main() {
	char js[] = "John Smith";
	char mc[] = "Mary Cohen";
	char cw[] = "Carl Williams";
	toCaps(&js);
	toCaps(&mc);
	toCaps(&cw);

	reverseName(&js[9], 10);
	reverseName(&mc[9], 10);
	reverseName(&cw[12], 13);

	return 0;
}

void toCaps(char* pointer) 
{
	for (pointer; *pointer != NULL; pointer++)
		*pointer = toupper(*pointer);
}

void reverseName(char* pointer, int len) 
{
	char* temp = pointer;
	
	for (pointer; pointer != (temp-len); pointer--)
	{
		char let = *pointer;
		printf("%c",let);
	}
	printf("\n");
}