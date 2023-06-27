#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 15

int Q[MAX];

int rear = -1;
int front = -1;

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

void enqueue(int value, int abound)
{
	if(!QFull(abound))
		Q[++rear] = value;
}

void dequeue()
{
	if(!QEmpty())
		++front;		
}

void display()
{
	int i = front, j = rear;

	while(i <= j) {
		printf("%d=>", Q[i]);
		i++;
	}

	printf("\n");
}
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
