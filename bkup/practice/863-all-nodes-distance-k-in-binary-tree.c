#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
typedef struct node* TreeNode;

#define MAX 10

typedef struct node {
	int data;
	TreeNode left;
	TreeNode right;
}Tree;

typedef struct queue {
	Tree *nodes[MAX];	
	int rear;
	int front;
	int vis[MAX];
}q_data;

typedef struct map {
	Tree *parent[MAX];
	int data[MAX];	
}Mp;

void print(Tree *root)
{
	if(!root)
		return;

	printf("%d, ", root->data);
	print(root->left);
	print(root->right);
}

Tree *create_tree()
{
	Tree *root = (Tree *) malloc (sizeof(Tree));

	if(!root)
		return NULL;

	printf("Enter the node: ");
	scanf("%d", &root->data);

	if(root->data == 0) {
		free(root);
		return NULL;
	}

	root->left = create_tree();
	root->right = create_tree();

	return root;
}

bool qfull(q_data *q)
{
	if(q->rear >= MAX)
		return true;

	return false;
}

bool qempty(q_data *q)
{
	if(q->front == q->rear)
		return true;

	return false;
}

void enqueue(q_data *q, Tree *node)
{
	if(!qfull(q))
		q->nodes[++q->rear] = node;
}

Tree *dequeue(q_data *q)
{
	return q->nodes[++q->front];
}

int q_size(q_data *q)
{
	return q->rear - q->front;
}

Tree *findnode(Tree *root, int value)
{
	if(!root)
		return NULL;

	if(root->data == value)
		return root;

	Tree *temp = findnode(root->left, value);
	if(!temp)
		temp = findnode(root->right, value);

	return temp;
}

int *kth_distance(Tree *root, Tree *destnode, int k, int *count)
{
	int *result = (int *) malloc (sizeof(int) * 10);

	q_data q;
	Mp map;

	q.front = -1;
	q.rear = -1;

	enqueue(&q, root);
	memset(q.vis, 0, MAX);
	map.parent[root->data] = NULL;

	while(!qempty(&q)) {
		Tree *temp = dequeue(&q);
		//q.vis[temp->data] = 1;
		printf("%d, ", temp->data);
		if(temp->left) {
			map.parent[temp->left->data] = temp;	
			enqueue(&q, temp->left);
		} if(temp->right) {
			map.parent[temp->right->data] = temp;	
			enqueue(&q, temp->right);
		}
	}

	q_data kq;

	memset(&kq, 0, sizeof(kq));

	kq.front = -1;
	kq.rear = -1;
	// node is not root node here.. its searching node
	enqueue(&kq, destnode);
	memset(kq.vis, 0, 40);
	kq.vis[destnode->data] = 1;
	int cur_level = 0;
	while(!qempty(&kq)) {
		int size = q_size(&kq);
		if(cur_level++ == k)
			break;
		for(int i=0; i<size; i++) {
			Tree *temp = dequeue(&kq);
			if(temp->left && kq.vis[temp->left->data] != 1) {
				enqueue(&kq, temp->left);
				kq.vis[temp->left->data] = 1;
			} 
			
			if(temp->right && kq.vis[temp->right->data] != 1) {
				enqueue(&kq, temp->right);
				kq.vis[temp->right->data] = 1;
			}

			if(map.parent[temp->data] && (kq.vis[map.parent[temp->data]->data] != 1)) {
				enqueue(&kq, map.parent[temp->data]);
				kq.vis[map.parent[temp->data]->data] = 1;
			}
		}
	}

	int i = 0;

	while(!qempty(&kq)) {
		Tree *temp = dequeue(&kq);
		result[i++] = temp->data;	
	}

	*count = i;

	return result;
}

void bfs(Tree *root)
{
	q_data q;

	q.front = -1;
	q.rear = -1;

	enqueue(&q, root);
	memset(q.vis, 0, MAX);

	while(!qempty(&q)) {
		Tree *temp = dequeue(&q);
		q.vis[temp->data] = 1;
		printf("%d, ", temp->data);
		if(temp->left)
			enqueue(&q, temp->left);
		if(temp->right)
			enqueue(&q, temp->right);
	}
}

int main()
{
	Tree *root = create_tree();	

	print(root);
	printf("\n");

	//bfs(root);

	int srch_ele;
	printf("enter the node to search\n");
	scanf("%d", &srch_ele);
	Tree *node = findnode(root, srch_ele);
	if(!node)
		printf("NULL node\n");
	printf("element %s found\n", node->data < 0 ? "not" : "");

	int k = 0;
	printf("enter the distance:");
	scanf("%d", &k);
	int count = 0;
	int *ptr = kth_distance(root, node, k, &count);
	printf("\ntarget: %d, distance : %d elements are [", srch_ele, k);
	for(int i = 0; i<count; i++)
		printf("%d, ", ptr[i]);

	printf("]\n");

	return 0;
}
