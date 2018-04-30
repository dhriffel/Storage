#include "bst.h"
#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int uiMainMenu(Node* tree) {
	char input;
	printf("Enter (i)nsert, (d)elete, (s)earch, inorder (t)raversal, or (q)uit: ");
	scanf(" %c", &input);
	switch (input) {
	case 'i':
		uiInsert(tree);
		return 1;
	case 'd':
		if(tree != NULL)
			uiDeleteNode(tree);
		else
			printf("Invalid input!\n");
		return 1;
	case 's':
		if (tree != NULL)
			uiSearch(tree);
		else
			printf("Invalid input!\n");
		return 1;
	case 't':
		if (tree != NULL)
			uiPrintTree(tree);
		else
			printf("Invalid input!\n");
		return 1;
	case 'q':
		if (tree != NULL)
			memRelease(tree);
		else
			printf("Invalid input!\n");
		return 0;
	default:
		printf("Invalid input!\n");
		return 1;
	}
	return 1;
}

void uiInsert(Node* tree) {
	char* input = malloc(sizeof(char)*9);
	int num;
	printf("Enter a number to insert: ");
	scanf(" %s", input);
	num = atoi(input);
	insertNode(tree, num);
	return;
}

void uiSearch(Node* tree) {
	char* input = malloc(sizeof(char) * 9);
	int num;
	printf("Enter a number to search for: ");
	scanf(" %s", input);
	num = atoi(input);
	/*scanf(" %c", &input);
	num = input - '0';*/
	if (searchTree(tree, num) == 1)
		printf("%d is in the tree.\n", num);
	else
		printf("%d is not in the tree.\n", num);
	return;
}

void uiPrintTree(Node* tree) {
	char* buff = malloc(sizeof(char) * 10);
	char* tempbuff = buff;
	inorderTrav(tree, tempbuff, 0);
	while (*buff != NULL) {
		if(*buff == ';')
			printf(" ");
		else
			printf("%c", *buff);
		buff++;
	}
	printf("\n");

	return;
}

void uiDeleteNode(Node* tree) {
	char* input = malloc(sizeof(char) * 9);
	int num;
	printf("Enter a number to delete: ");
	scanf(" %s", input);
	num = atoi(input);
	if (searchTree(tree, num) == 1) {
		deleteNode(tree, num);
		printf("%d has been deleted.\n", num);
	}
	else
		printf("%d is not in the tree.\n", num);
	return;
}
