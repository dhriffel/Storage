typedef struct bstNode {
	int key;
	struct bstNode* left;
	struct bstNode* right;
} Node;

Node* buildNode(int);
Node* insertNode(struct bstNode*, int);
int searchTree(struct bstNode*, int);
char* inorderTrav(struct bstNode*, char*);
void memRelease(struct bstNode*);
Node* deleteNode(Node*, int);

