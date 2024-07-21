#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct tnode *Treeptr;

typedef struct tnode {
	int data;
	Treeptr left;
	Treeptr right;
}TreeNode;

TreeNode *create_tree()
{
	int value;

	printf("Node Value: ");
	scanf("%d", &value);

	if(value == 0)
		return NULL;

	TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));

	if(!root)
		return NULL;

	root->data = value;

	root->left = create_tree();
	root->right = create_tree();

	return root;
}

void print_tree(TreeNode *root)
{
	if(!root)
		return;

	printf("%d", root->data);
	print_tree(root->left);
	print_tree(root->right);
}


int maxdepth(TreeNode *root, int level, int *max)
{
	if(!root)
		return level - 1;

	int leftlevel = maxdepth(root->left, level+1, max);
	int rlevel = maxdepth(root->right, level+1, max);

	if(leftlevel > rlevel)
		*max = leftlevel;
	else
		*max = rlevel;

	return *max;
}

TreeNode *find_node(TreeNode *root, int se, int *pos, int lev)
{
	if(!root)
		return NULL;

	if(root->data == se) {
		*pos = lev;
		return root;
	}

	*pos = lev+1;
	printf("pos  : %d\n", *pos);

	find_node(root->left, se, pos, lev);
	find_node(root->right, se, pos, lev);
	
	return NULL;
}

int* distanceK(TreeNode* root, TreeNode* target, int k, int* returnSize)
{
	int pos = 0;

	int *elements = malloc(sizeof(int) * 10);
	
	find_node(root, target->data, &pos, 1);

}

int main()
{
	TreeNode *root;
	int max = 0, pos = 0;

	root = create_tree();	

	printf("level: %d\n", maxdepth(root, 1, &max));

	printf("pre-order traversal : ");
	print_tree(root);
	printf("\n");

	int search_element;
	printf("Enter the node to search : \n");
	scanf("%d", &search_element);
	printf("Node %d exist ?? %p@%d\n", search_element, find_node(root, search_element, &pos, 1), pos);

	return 0;
}
