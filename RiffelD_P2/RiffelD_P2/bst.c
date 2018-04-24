#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



Node* buildNode(int k){
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->key = k;
newNode->left = NULL;
newNode->right = NULL;

return newNode;
}

void insertNode(Node* node, int k) {
	if (node == NULL) {
		return;
	}
	if (node->key == NULL || node->key == 0) {
		node->key = k;
		return;
	}

		
	if (node->key > k) {
		if (node->left == NULL)
		{
			node->left = buildNode(k);
			return;
		}
		insertNode(node->left, k);
	}
	else {
		if (node->right == NULL)
		{
			node->right = buildNode(k);
			return;
		}

		insertNode(node->right, k);
	}
}

int searchTree(Node* node, int k) {
	if (node == NULL) {
		return 0;
	}

	if (node->key > k)
	{
		return searchTree(node->left, k);
	}
	else if (node->key < k)
	{
		return searchTree(node->right, k);
	}

	return 1;
}

char* inorderTrav(Node* node, char* buff, int level) {
	
	
	int temp = 0;
	while (temp < level)
	{
		++temp;
	}

	if (node->left != NULL)
	{
		
		buff = inorderTrav(node->left, buff, level + 1);
	}
sprintf(buff, "%d", node->key);
	buff ++;
	if (node->right != NULL)
	{
		
		buff = inorderTrav(node->right, buff, level + 1);
	}
	
}

void memRelease(struct bstNode* node) {
	if (node == NULL)
		return;
	if (node->key == NULL)
		return;

	memRelease(node->left);
	free (node->left);
	free(node->right);
	memRelease(node->right);
}
