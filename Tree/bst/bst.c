#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node {
	int data;
	struct tree_node *left;
       	struct tree_node *right;
}tnode;

tnode *troot = NULL;

void print_bst(tnode *root)
{
	printf("%d\t", root->data);
	print_bst(root->left);
	print_bst(root->right);
}

void create_bst(tnode *root, int data)
{
	tnode *node = (tnode *) malloc(sizeof(tnode));

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	if(!root) {
		troot = node;
		return;
	}

	if(data < root->data)
		create_bst(root->left, data);
	else
		create_bst(root->right, data);
}

int main(int argc, char *argv[]) {

	if(argc != 3) {
		fprintf(stderr, "./a.out requires %d elements\n", argc);
		return -1;
	}

	printf("input: %d\n", atoi(argv[1]));

	int choice = atoi(argv[1]);

	int max_array = atoi(argv[2]);

	int data[max_array], i;

	printf("Enter the array element: \n");
	for (i=0; i<max_array; i++)
		scanf("%d", &data[i]);

	while(1) {
		switch(choice) {
			case 1:
				printf("Creating BST - Please wait....\n");
				i = 0;
				for(i = 0; i< max_array; i++)
					create_bst(troot, data[i]);
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				break;
		}
		choice = 0;
	}

	return 0;
}
