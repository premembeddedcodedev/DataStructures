#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 15

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
}tree_t;

typedef struct tree_queue {
	tree_t *nodes[MAX];
	int front;
	int rear;
}QueueTree;

int rear = -1;
int front = -1;

QueueTree Queue;

bool QEmpty()
{
	if(front == rear) {
		printf("empty\n");
		return true;
	} else
		return false;
}

bool QFull(int bound)
{
	if(rear == bound-1) {
		printf("FULL\n");
		return true;
	} else
		return false;
}

void enqueue(tree_t *node, int abound)
{
	if(!QFull(abound))
		Queue.nodes[++rear] = node;
}

tree_t *dequeue()
{
	if(!QEmpty()) {
		++front;
		return Queue.nodes[front];
	}
		
}

void display()
{
	int i = front, j = rear;

	while(i <= j) {
		tree_t *temp = Queue.nodes[i];
		printf("%d=>", temp->data);
		i++;
	}

	printf("\n");
}
#if 0
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};

	int iter = 0;

	for(int i = 0; i<sizeof(a)/sizeof(int); i++)
		enqueue(a[i], (sizeof(a)/sizeof(int)));

	for(int i = 0; i<11; i++)
		dequeue();

	display();

	return 0;
}
#endif
