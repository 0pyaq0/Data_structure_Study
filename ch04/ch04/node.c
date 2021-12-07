#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};
struct node *CREATE(char item)
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));

	ptr->llink = NULL;
	ptr->data = item;
	ptr->rlink = NULL;
	return ptr;
};
void DELETE(struct node* Delnode) {
	if (Delnode != NULL) {
		DELETE(Delnode->llink);
		DELETE(Delnode->rlink);
		free(Delnode);
	}
}
void PREORDER(struct node* ptr) {
	if (ptr != NULL) {
		printf("%c  ", ptr->data);
		PREORDER(ptr->llink);
		PREORDER(ptr->rlink);
	}
}
void INORDER(struct node* ptr) {
	if (ptr != NULL) {
		INORDER(ptr->llink);
		printf("%c  ", ptr->data);
		INORDER(ptr->rlink);
	}
}
void POSTORDER(struct node* ptr) {
	if (ptr != NULL) {
		POSTORDER(ptr->llink);
		POSTORDER(ptr->rlink);
		printf("%c  ", ptr->data);
	}
}

int main(void) {
	struct node* root = CREATE('A');
	root->llink = CREATE('B');
	root->rlink = CREATE('C');

	root->llink->llink = CREATE('D');
	root->llink->rlink = CREATE('E');
	root->llink->llink->rlink = CREATE('G');

	root->rlink->llink = CREATE('F');
	root->rlink->llink->llink = CREATE('H');
	root->rlink->llink->rlink = CREATE('I');
	root->rlink->llink->rlink->llink = CREATE('J');

	printf("傈困 款青 : "); PREORDER(root); printf("\n");
	printf("吝困 款青 : "); INORDER(root); printf("\n");
	printf("饶困 款青 : "); POSTORDER(root); printf("\n");

	DELETE(root);
	return 0;
}