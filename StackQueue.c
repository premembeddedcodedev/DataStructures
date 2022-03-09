#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAXSIZE 5

int top = -1, front = -1, rear = -1;

bool isStackFull()
{
	if(top > MAXSIZE-1)
		return true;

	return false;
}

void dump(int a[])
{
	int i;
	printf("Stack Elements are: \t");
	for(i = top-1; i >= 0; i--) {
		printf("\n");
		printf("---> %d \t", a[i]);
	}
}

bool isStackEmpty()
{
	if(top == -1)
		return true;

	return false;
}

void pop(int a[])
{
	if(!isStackEmpty()) {
		printf(" %d \n", a[--top]);
	} else
		printf(" Stack is Empty");
}

void push(int a[], int num)
{
	if(!isStackFull() && top++ < MAXSIZE - 1) {
		printf("top: %d\n", top);
		a[top] = num;
	} else
		printf("Stack is Full\n");
}

void enqueue(int a[], int n)
{
	if(front == -1)
		front = 0;

	if(rear == MAXSIZE - 1) {
		printf("Overflow.....\n");
		return;
	}

	rear++;
	a[rear] = n;
}

void dequeue(int a[])
{
	if(front == -1 || front > rear)
		printf("Under flow: front : %d rear:%d \n", front, rear);
	else
		printf("Element deleted from queue: %d\n", a[front++]);
}

void dumpQ(int a[])
{
	int i;

	for(i = front; i<=rear; i++)
	{
		printf("\n");
		printf(" ===> %d", a[i]);
	
	}
}

void popStack_enqueue(int S[], int Q[])
{
	if(top <= 0) {
		enqueue(Q, S[top]);
		return;
	}

	top--;

	printf("top is dequeing: %d\n", top);

	popStack_enqueue(S, Q);
	enqueue(Q, S[top]);
}

void enqueuefromStack(int S[], int Q[])
{
	if(!isStackEmpty()) {
		popStack_enqueue(S, Q);
	} else {
		printf("Stack is empty\n");
		return;
	}
}

void DequeuefromStack(int Q[])
{
	dequeue(Q);
}

int main(int argc, char *argv[])
{
	int a[MAXSIZE], Q[MAXSIZE], n; 

	if(argc!=2) {
		fprintf(stderr, "./a.out needs parameteri %d\n", argc);
		exit(-1);
	}

	printf("%d\n", atoi(argv[1]));

	uint8_t ch, num;

	while(1) {
		printf("\nSelection: <1-8> ? : 1.push, 2.pop, 3.top, 4.dump, 5.enq, 6.deq, 7.front/rear, 8.dump, 9.StackEnq 10.StackDeq\n");
		switch(scanf("%d", &ch) ? ch : -1) {
			case 1:
				printf("Insert elements please: \n");
				push(a, scanf("%d", &n) ? n : -1); //TODO: scanf return its taking....
				break;
			case 2:
				pop(a);
				break;
			case 3:
				printf("Stack Top: %d\n", top);
				break;
			case 4: 
				dump(a);
				break;
			case 5:
				printf("Enqueue: Insert elements please: \n");
				scanf("%d", &n);
				enqueue(a, n);
				break;
			case 6:
				printf("Dequeuing.....\n");
				dequeue(a);
				break;
			case 7:
				printf("Q: Front: %d Rear: %d \n", front, rear);
				break;
			case 8: 
				dumpQ(a);
				break;
			case 9:
				enqueuefromStack(a, Q);
				break;
			case 10:
				printf("Dequeuing.....\n");
				DequeuefromStack(a);
				break;
			default:
				printf("Invalid : %d\n", ch);
				exit(-1);;
		}
	}

	return 0;
}
