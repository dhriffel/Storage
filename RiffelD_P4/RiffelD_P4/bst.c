#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



Node* buildNode(int k) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = k;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Node* insertNode(Node* node, int k) 
{
	if (node == NULL) return buildNode(k);

	if (k < node->key)
		node->left = insertNode(node->left, k);

	else if (k > node->key)
		node->right = insertNode(node->right, k);

	return node;
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

char* inorderTrav(Node* root, char* buff) 
{
	if (root != NULL)
	{
		buff = inorderTrav(root->left, buff);
		sprintf(buff, "%d", root->key);
		while (*buff != NULL) {
			buff++;
		}

		/*if (*buff == '-')
			buff++;
		buff++;*/
		sprintf(buff, ";");
		buff++;
		buff = inorderTrav(root->right, buff);
	}
	return buff;
}

void memRelease(struct bstNode* node) {
	if (node == NULL)
		return;
	if (node->key == NULL)
		return;

	memRelease(node->left);
	free(node->left);
	free(node->right);
	memRelease(node->right);
}

Node* deleteNode(Node* node, int key)
{
	if (node == NULL) return node;

	if (key < node->key)
		node->left = deleteNode(node->left, key);
	else if (key > node->key)
		node->right = deleteNode(node->right, key);
	else
	{
		if (node->left == NULL)
		{
			Node* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			Node* temp = node->left;
			free(node);
			return temp;
		}
		Node* temp = node->right;
		while (temp->left != NULL)
			temp = temp->left;
		
		node->key = temp->key;

		node->right = deleteNode(node->right, temp->key);
	}
	return node;
}