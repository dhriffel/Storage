#include "bst.h"
#include "io.h"

#include <stdio.h>
#include <stdlib.h>

void main() {
	Node* tree = malloc(sizeof(Node));
	tree->key = NULL;
	tree->left = malloc(sizeof(Node)); tree->right = malloc(sizeof(Node));
	tree->left->key = NULL;
	tree->right->key = NULL;
	while (uiMainMenu(tree) == 1) {}
	return;
}