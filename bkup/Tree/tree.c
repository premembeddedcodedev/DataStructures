#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int num;
	struct tree *left, *right;
}tree_struct;

tree_struct *root = NULL;

void pre_order_trav(tree_struct *node)
{
	if(!node)
		return;

	printf(" %d\t", node->num);

	pre_order_trav(node->left);
	pre_order_trav(node->right);

}

void post_order_trav(tree_struct *node)
{
	if(!node)
		return;
	pre_order_trav(node->left);
	pre_order_trav(node->right);
	printf(" %d\t", node->num);
}

void in_iorder_trav(tree_struct *node)
{
	if(!node)
		return;
	pre_order_trav(node->left);
	printf(" %d\t", node->num);
	pre_order_trav(node->right);
}

void print()
{
	tree_struct *temp = root;

	while(temp != NULL) {
		printf(" %d\t", temp->num);
		temp = temp->left;
		if(temp->right != NULL)
			printf(" %d\t", temp->right->num);

	}

	temp = root;

	while(temp != NULL) {
		printf("%d\t", temp->num);
		temp = temp->right;
	}
}

tree_struct *create_tree()
{
	int number;

	printf("enter the value: ");
	scanf("%d", &number);
	
	if(number == 0)
		return NULL;

	tree_struct *node;
	
	node = (tree_struct *)malloc(sizeof(tree_struct));
	if(node == NULL)
		return NULL;

	node->num = number;

	node->left = create_tree();
	node->right = create_tree();

	return node;
}

void main()
{

	printf("size : %ld\n", sizeof(tree_struct));

	root = create_tree();
	printf("\npre order traversal: \n");
	pre_order_trav(root);
	printf("\nin order traversal: \n");
	post_order_trav(root);
	printf("\npost order traversal: \n");
	post_order_trav(root);
}
