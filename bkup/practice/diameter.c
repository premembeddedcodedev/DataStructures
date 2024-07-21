#include<stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}TreeNode;

TreeNode *create_tree()
{
	int value;

	printf("Enter the Node:");
	scanf("%d", &value);

	if(value == 0)
		return NULL;

	TreeNode *root = (TreeNode *) malloc (sizeof(TreeNode));
	if(!root)
		return NULL;

	root->val = value;

	root->left = create_tree();
	root->right = create_tree();

	return root;
}

void print_tree(TreeNode *root)
{
	if(!root)
		return;

	printf("%d, ", root->val);
	print_tree(root->left);
	print_tree(root->right);
}

int diameter = 0;

int height(TreeNode *root)
{
	if(!root)
		return 0;

	int clevel = height(root->left);
	int rlevel = height(root->right);

	int dia = clevel + rlevel + 1;
	diameter = diameter < dia ? dia : diameter;

	return ((clevel < rlevel) ? rlevel: clevel) + 1;
}

int main()
{
	TreeNode *root = create_tree();
	if(!root)
		return -1;

	print_tree(root);

	int value = 0;

	value = height(root);
	printf("Max height: %d\n", value);

	return 0;
}
