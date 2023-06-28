#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

tree_t *root = NULL;

void tree_display(tree_t *node)
{
	if(!node)
		return;

	tree_display(node->left);
	tree_display(node->right);
	printf("%d->", node->data);
}

tree_t *create_node(int a[], int array_bound, int *offset)
{
	tree_t *temp;

	if(*offset >= array_bound)
		return NULL;

	tree_t *new = (tree_t *) malloc(sizeof(tree_t));
	if(!new)
		return NULL;

	new->data = a[*offset];
	new->left = NULL;
	new->right = NULL;

	printf("offset: %d\n", *offset);
	if(!root) {
		root = new;
		printf("Am root allocating resources for left and right: %d\n", a[*offset]);
	}

	// TODO: Offset re-rolling back to 0 due to recursion so taking offset as a reference

	printf("Left child ??  0-no / 1-yes \n");
	int i = 0;
	scanf("%d", &i);
	if(i == 1) {
		printf("\n L:%d => %d =>  ", new->data, a[*offset]);
		++(*offset);
		printf("Am Left allocating for: %d\n", a[*offset]);
		new->left = create_node(a, array_bound, offset);
		i = 0;
	}

	printf("Right child ??  0-no / 1-yes \n");
	int j = 0;
	scanf("%d", &j);
	if(j == 1) {
		printf("\n R: %d => %d => ", new->data, a[*offset]);
		++(*offset);
		printf("Am right allocating for: %d\n", a[*offset]);
		new->right = create_node(a, array_bound, offset);
		j = 0;
	}
	
	//if((lfstatus == true || rfstatus == true) || (lfstatus == false && rfstatus == false))
		return new;
	//else
	//	return NULL;
}

int height(tree_t *node)
{
	if(!node)
		return 1;
	else {
		int temp;

		int lheight = height(node->left);
		int rheight = height(node->right);

		if(lheight > rheight)
			return 1 + lheight;
		else
			return 1 + rheight;
	}
}

void bfs(int bound)
{
	tree_t *temp;

	enqueue(root, bound);

	while(!QEmpty()) {
		temp = dequeue();
		printf("dequeue: %d\n", temp->data);
		if(temp->left != NULL) {
			enqueue(temp->left, bound);
		}
		if(temp->right != NULL) {
			enqueue(temp->right, bound);
		}
	}
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};

	int iter = 0;

	root = create_node(a, sizeof(a)/sizeof(int), &iter);

	tree_display(root);

	bfs(sizeof(a)/sizeof(int));

	printf("Height : %d\n", height(root));

	return 0;
}
