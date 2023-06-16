#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Qnode;

Qnode *front = NULL;
Qnode *rear = NULL;

Qnode *create_node(int data)
{
	Qnode *NewNode = (Qnode *) malloc (sizeof(Qnode));
	if(!NewNode)
		return NULL;

	NewNode->data = data;
	NewNode->next = NULL;

	return NewNode;
}

void display(Qnode *Rrear, Qnode *Ffront)
{
	Qnode *Rtemp = rear, *Ftemp = front;

	if(!rear && !front) { // Need to check Q is empty or not before displaying
		printf("\t\t\t\tCQ is empty\n");
		return;
	}

	while(Ftemp != Rtemp) {
		printf("%d\t", Ftemp->data);	
		Ftemp = Ftemp->next;	
	}
	printf("%d\n", Ftemp->data);
}

void dequeue(Qnode **fnode, Qnode **rnode) //TODO: Need to take ** pointer to get the value from function arguement
{
	if(!*fnode && !*rnode) {
		printf("\t\t\t\t CQ is empty\n\n");
		return;
	}

	if(*fnode == *rnode) { // Corner Case : this condition would be required because there is only one element left in the Q
		Qnode *dat;
		dat = *fnode;
		printf("\t\t\t\t last element in Q is : %d\n", dat->data);
		free(dat);
		*fnode = *rnode = NULL;
		return;
	}

	Qnode *temp = *fnode;
	*fnode = temp->next;
	Qnode *i = *rnode;
	i->next = *fnode;
	printf("\t\t\t\t D'Qed Element is %d\n", temp->data);
	free(temp);
}

void enqueue(Qnode *rnode, int data)
{
	Qnode *new = create_node(data);
	if(!new)
		return;

	if(!rear && !front)
		rear = front = new;
	else {
		rear->next = new;
		new->next = front;
		rear = new;
	}
}

int main(int argc, char *argv[])
{
	if(argc != 1) {
		fprintf(stderr, "./a.out [NO] %d\n", argc);
		return -1;
	}

	int ch;
	int data;

	while(1) {
		printf("Enter the option: 1. Enqueue 2. Dequeue 3. display 4.exit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the value to enqueue: \n");
				scanf("%d", &data);
				enqueue(rear, data);
				break;
			case 2:
				dequeue(&front, &rear);
				break;
			case 3:
				display(rear, front);
				break;
			default:
				break;
		
		}	
	}	
}
