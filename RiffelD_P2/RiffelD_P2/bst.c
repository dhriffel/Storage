#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



Node* insertNode(Node* node, int k) {
	if (node->key == NULL) {
		
		node->key = k;
		node->left = malloc(sizeof(Node));
		node->left->key = NULL;
		node->right = malloc(sizeof(Node));
		node->right->key = NULL;
		return node;
	}

	else if (k < node->key) {
		node->left = insertNode(node->left, k);
	}

	else {
		node->right = insertNode(node->right, k);
	}

	return node;
}

int searchTree(Node* node, int k) {
	if (node->key == NULL) {
		return 0;
	}

	if (node->key == k) {
		return 1;
	}

	else if (k < node->key) {
		return searchTree(node->left, k);
	}

	else {
		return searchTree(node->right, k);
	}

	return 0;
}

void inorderTrav(Node* node, char* buff) {
	if (node->key != NULL) {

	


	inorderTrav(node->left, buff + 1);
	*buff = node->key;
	//sprintf(buff, "%c", node->key);
	inorderTrav(node->right, buff + 1);
}
}

void memRelease(struct bstNode* node) {
	if (node == NULL)
		return;

	memRelease(node->left);
	free (node->left);
	free(node->right);
	memRelease(node->right);
}
