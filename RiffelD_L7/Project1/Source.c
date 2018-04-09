#include <stdio.h>
#include <stdlib.h>



typedef struct list {
	int item;
	struct list *next;
}List;

void delete(List **lpp, int i);
void insert(List **lpp, int i);

int main(int argc, const char *argv[]) {

	List *node3 = malloc(sizeof(List));
	node3->item = 3;
	node3->next = NULL;

	List *node2 = malloc(sizeof(List));
	node2->item = 2;
	node2->next = node3;

	List *list = malloc(sizeof(List));
	list->item = 1;
	list->next = node2;

	List **lpp = &list;
	int i = 1;
	
	//delete(lpp, i);
	insert(lpp, i);
	

	return 0;
}

void delete(List **lpp, int i) {
	for (lpp; *lpp != NULL; lpp = &(*lpp)->next) {
		if ((*lpp)->item == i) {
				*lpp = (*lpp)->next;
				break;
		}
	}
}

void insert(List **lpp, int i) {
	for (*lpp; (*lpp)->next != NULL; lpp = &(*lpp)->next) {
		if ((*lpp)->next->item >= i) {
			List *newNode = malloc(sizeof(List));
			newNode->item = i;

			newNode->next = (*lpp)->next;
			(*lpp)->next = newNode;
			return;
		}
	}
	List *newNode = malloc(sizeof(List));
	newNode->item = i;
	newNode->next = NULL;
	(*lpp)->next = newNode;
}