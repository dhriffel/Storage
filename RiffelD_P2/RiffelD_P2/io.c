#include "bst.h"
#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int uiMainMenu(Node* tree) {
	char input;
	printf("Enter (i)nsert, (s)earch, inorder (t)raversal, or (q)uit: ");
	scanf(" %c", &input);
	switch (input) {
	case 'i':
		uiInsert(tree);
		return 1;
	case 's':
		uiSearch(tree);
		return 1;
	case 't':
		uiPrintTree(tree);
		return 1;
	case 'q':
		memRelease(tree);
		return 0;
	default:
		printf("Invalid input!\n");
		return 1;
	}
	return 1;
}

void uiInsert(Node* tree) {
	char input;
	int num;
	printf("Enter a number to insert: ");
	scanf(" %c", &input);
	num = input - '0';
	insertNode(tree, num);
	return;
}

void uiSearch(Node* tree) {
	char input;
	int num;
	printf("Enter a number to search for: ");
	scanf(" %c", &input);
	num = input - '0';
	if(searchTree(tree, num) == 1)
		printf("%d is in the tree.\n", num);
	else
		printf("%d is not in the tree.\n", num);
	return;
}

void uiPrintTree(Node* tree) {
	char* buff = malloc(sizeof(char) * 10);
	inorderTrav(tree, buff);
	while (*buff != NULL) {
		printf("%c", *buff);
		buff++;
	}
	
	return;
}
