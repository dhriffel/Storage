#include "bst.h"
#include "io.h"

#include <stdio.h>
#include <stdlib.h>

void main() {
	Node* tree = buildNode(NULL);
	while (uiMainMenu(tree) == 1) {}
	return;
}