#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
}Qnode;

void display(Qnode **head)
{
	Qnode *temp = *head;
	int i;

	printf("Elements are: \n");

	while(temp != NULL) {
		printf("%d\t", temp->data);	
		temp = temp->next;
	}

	printf("\n");
}

Qnode *create_node_and_link(Qnode **head, int data)
{
	Qnode *new = (Qnode *) malloc(sizeof(Qnode));
	if(!new)
		return NULL;

	new->data = data;
	new->next = NULL;
	new->prev = NULL;

	if((*head) == NULL) {
		*head = new;
	} else {
		Qnode *temp = *head, *prev;
		new->next = temp;
		*head = new;
	}
	
	return *head;
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "./a.out requires 2 variables : ./a.out [size of list] %d\n", argc);
		exit(-1);
	}
	int ch, i = 0, data = 0;
	Qnode *head = NULL, *temp; // NULL is mandatory to check the NULL status while storing the variables @first place

	while(1) {
		printf("Enter the choice:\n 1.Insert\n 2.delete\n 3.exit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the array values: \n");
				for(i=0;i<atoi(argv[1]);i++) {
					scanf("%d", &data);
					temp = create_node_and_link(&head, data);
				}
				break;
			case 2:
				display(&temp);
				break;
			case 3:
				break;
			default:
				break;

		};	
	}

	return 0;
}
