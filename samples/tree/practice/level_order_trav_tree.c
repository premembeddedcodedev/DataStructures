#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 10

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
}TreeNode;

void pre_order_trav(TreeNode *node)
{
	if(!node)
		return;

	printf(" %d\t", node->data);
	pre_order_trav(node->left);
	pre_order_trav(node->right);

}

typedef struct Queue {
	int front;
	int rear;
	TreeNode *node[MAX];
}qdata;

void enqueue(qdata *Q, TreeNode *node)
{
	//if(Q->front < Q->rear) {
	if(Q->rear < 5) {
		Q->rear++;
		Q->node[Q->rear] = node;
	} else
		return;
}

TreeNode *dequeue(qdata *Q)
{
	if(Q->front == Q->rear)
		return NULL;
	else
		return Q->node[++Q->front];
}

bool qempty(qdata *Q)
{
	if(Q->front == Q->rear)
		return true;

	return false;
}

void bfs(TreeNode *root)
{
	if(!root)
		NULL;

	qdata Q;
	Q.front = 0;
	Q.rear = 0;
	Q.rear++;
	enqueue(&Q, root);

	while(!qempty(&Q)) {
		TreeNode *temp = dequeue(&Q);
		printf("%d ", temp->data);

		if(temp->left) {
			enqueue(&Q, temp->left);
		} if(temp->right) {
			enqueue(&Q, temp->right);
		}

	}
}

TreeNode *alloc_node(int data)
{
	TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	return new;
}

TreeNode *create_node()
{
	int data, choice;

	printf("Enter the node:\n");
	scanf("%d", &data);

	if(data == 0)
		return NULL;

	TreeNode *new = alloc_node(data);
	if(!new)
		return NULL;

	new->left = create_node();
	new->right = create_node();

	return new;
}

int** levelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	if(!root)
		NULL;
	
	int **retArray = (int **) malloc(sizeof(int *) * 10); // assuming 10 arrays
	qdata Q;
	
	*returnSize = 0;
	Q.front = 0;
	Q.rear = 0;
//	Q.rear++;

	enqueue(&Q, root);

	*returnColumnSizes = (int *) malloc(sizeof(int)*10); // assuming 10 arrays sizes
	while(!qempty(&Q)) {
		int levelSize = Q.rear - (Q.front);
		for(int i = 0; i<=levelSize; i++) {
			TreeNode *temp = dequeue(&Q);
			printf("%d ", temp->data);
			*returnColumnSizes[*returnSize] = levelSize + 1;
			retArray[*returnSize] = (int *) malloc(sizeof(int) * (levelSize + 1));
			retArray[*returnSize][i] = temp->data;
			if(temp->left) {
				enqueue(&Q, temp->left);
			} if(temp->right) {
				enqueue(&Q, temp->right);
			}

		}
		(*returnSize)++;
	}

	return retArray;
}

int main()
{
	TreeNode *root;

	root = create_node();

	pre_order_trav(root);

	printf("\nBFS is : \n");

//	bfs(root);

	int returnSize, **returnColumnSizes;

	levelOrder(root, &returnSize, returnColumnSizes);

	return 0;
}
