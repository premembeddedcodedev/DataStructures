#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}TreeNode;

void print(TreeNode *root)
{
	if(!root)
		return;

	printf("%d, ", root->val);
	print(root->left);
	print(root->right);
}

TreeNode *findnode(TreeNode *root, int node_val)
{
	if(!root)
		return NULL;

	if(root->val == node_val)
		return root;

	TreeNode *temp = findnode(root->left, node_val);
	if(!temp)
		temp = findnode(root->right, node_val);

	return temp;
}

int findlevel(TreeNode *root, int node_val, int level)
{
	if(!root)
		return -1;

	if(root->val == node_val)
		return level;

	int temp = findlevel(root->left, node_val, level + 1);
	if(temp == -1)
		temp = findlevel(root->right, node_val, level + 1);

	return temp;
}

bool isSibling(TreeNode *root, TreeNode* x, TreeNode* y)
{
	if(!root)
		return false;

	return (((root->left == x) && (root->right == y)) || ((root->left == y) && (root->right == x)) || isSibling(root->left, x, y) || isSibling(root->right, x, y));
}

bool isCousins(TreeNode *root, int x, int y)
{
	if(!root)
		return false;
	
	TreeNode *nodeX = findnode(root, x);
	TreeNode *nodeY = findnode(root, y);

	if(!nodeX || !nodeY)
		return false;

	return ((findlevel(root, x, 0) == findlevel(root, y, 0)) && (!isSibling(root, nodeX, nodeY)));
}


TreeNode* creat_tree()
{
	int value;
	printf("enter the node : \n");
	scanf("%d", &value);
	
	if(value == 0)
		return NULL;

	TreeNode* root = (TreeNode *) malloc (sizeof(TreeNode));
	if(!root)
		return NULL;

	root->val = value;

	root->left = creat_tree();
	root->right = creat_tree();

	return root;
}

int main()
{
	TreeNode *root = creat_tree();

	print(root);

	int x, y;
	printf("enter x and y");
	scanf("%d %d", &x, &y);
	printf("is cousins : %s\n", isCousins(root, x, y) ? "Yes" : "No");

	return 0;
}
