//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
	int data;
	int x;
	int y;
	struct tree *left;
	struct tree *right;
}node;

node *create_node(int element)
{
	node *new = (node *) malloc(sizeof(node));
	if(!new)
		return NULL;

	new->data = element;
	new->left = NULL;
	new->right = NULL;
}

void display(node *root)
{
	if(!root)
		return;

	printf(" %d", root->data);
	display(root->left);
	display(root->right);
}

int find_height(node * root)
{
	if(!root) {
		return 1;
	} else {
	
		int lheight = find_height(root->left);
		int rheight = find_height(root->right);

		if(lheight > rheight)
			return 1 + lheight;
		else
			return 1 + rheight;
	}
}

void solve(node *root, int row, int **matrix, int *returnSize, int** returnColumnSizes)
{
	if(!root) {
		return;
	}
	printf(" %d", root->data);
	
	returnColumnSizes[row] = realloc(returnColumnSizes[row], (*(returnColumnSizes[row]) + 1) * 4);

	matrix[row][*(returnColumnSizes[row])] = root->data;

	*(returnColumnSizes[row]) += 1;

	/*Need to why row-1 is instead of *row*/
	solve(root->left, row-1, matrix, returnSize, returnColumnSizes);
	
	solve(root->right, row+1, matrix, returnSize, returnColumnSizes);
}

int** verticalTraversal(node* root, int* returnSize, int** returnColumnSizes)
{
	printf("Height of the tree : %d\n", find_height(root));
	
	int **matrix = (int **) malloc (sizeof(int *) * (find_height(root) + 3)); // 4 * 2 - based on the height of the tree because negative index is not there as per the youtube logic
	int beg = 3, end = 3;
	returnColumnSizes = (int **) malloc (sizeof(int *) * (find_height(root) + 3)); // 4 * 2 - based on the height of the tree because negative index is not there as per the youtube logic

	for (int i = 0; i < find_height(root)+3; i++) {
		returnColumnSizes[i] = malloc(sizeof(int));
		matrix[i] = malloc(sizeof(int) * 4);
		*matrix[i] = 0;
		*returnColumnSizes[i] = 0;
	}

	solve(root, beg, matrix, returnSize, returnColumnSizes);

	*returnSize = 4;

	return matrix;
}

node *build_bintree(int a[], int size, node *root, int *offset)
{
	node *temp;
	int i=1, left, right;

	if(*offset>=size)
		return NULL;

	temp = create_node(a[*offset]);
	if(!root)
		root = temp;

	printf("left node : 1 - yes/0 - No???\n");
	scanf("%d", &left);
	if(left == 1) {
		left = 0;
		++(*offset);
		temp->left = build_bintree(a, size, root, offset);
	}
		
	printf("right node : 1 - yes/0 - No???\n");
	scanf("%d", &right);
	if(right == 1) {
		++(*offset);
		right = 0;
		temp->right = build_bintree(a, size, root, offset);
	}

	return temp;
}

void print_matrix(int **matrix)
{
	printf("\n Matrix are: \n");

	for(int i = 2; i<6; i++) {
		printf("matrix[%d]: elements are : ", i);
		for(int j=0; j<4; j++) {
			printf("%d->", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

int main()
{
	int a[9] = {1,2,7,4,5,8,6,3};
	
	node *root = NULL;
	int returnSize = 0;
	int begin = 0;
	int *returnColumnSizes[10];
	
	root = build_bintree(a, sizeof(a)/sizeof(int), root, &begin);

	printf("Tree: \n");
	
	display(root);

	printf("\n");

	int **matrix = verticalTraversal(root, &returnSize, returnColumnSizes);
	
	printf("\n vertal Tree: \n");
	
	print_matrix(matrix);

	printf("\n");

	//TODO: Need to free the elements allocated for double pointer

	return 0;
}
