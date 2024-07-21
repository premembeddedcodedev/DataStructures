#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
}TreeNode;

void pre_order_trav(TreeNode *root)
{
	if(!root)
		return;

	printf("%d ", root->data);
	pre_order_trav(root->left);
	pre_order_trav(root->right);
}

TreeNode* create_tree()
{
	TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
	if(!root)
		return NULL;

	printf("Enter Node value: ");
	scanf("%d",&root->data);

	if(root->data == 0) {
		free(root);
		return NULL;
	}

	root->left = create_tree();
	root->right = create_tree();

	return root;
}

int main()
{
	TreeNode *root = create_tree();		
	if(!root)
		return -1;

	printf("Printing pre order traversal: ");
	pre_order_trav(root);

	return 0;
}
