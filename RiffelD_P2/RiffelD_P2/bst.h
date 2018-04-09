typedef struct bstNode{
	int key;
	struct bstNode* left;
	struct bstNode* right;
} Node;

Node* insertNode(struct bstNode*, int);
int searchTree(struct bstNode*, int);
void inorderTrav(struct bstNode*, char*);
void memRelease(struct bstNode*);

