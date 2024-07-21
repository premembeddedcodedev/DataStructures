#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *new_alloc(int data)
{
	struct node *head = (struct node *) malloc(sizeof(struct node));
	if(!head)
		return NULL;
	head->val = data;
	head->next = NULL;

	return head; //this is missed
}

struct node *creat_list(struct node **head)
{
	int value;

	printf("Enter the value:");
	scanf("%d", &value);

	struct node *new = new_alloc(value);
	if(!(*head))
		*head = new;
	else {
	//	new->next = *head;
	//	*head = new;
		struct node *temp = *head;
		while(temp->next)
			temp = temp->next;
		temp->next = new;
	}

	return *head;
}

struct node *rev_list(struct node *curr)
{
	struct node *prev;
	
	if(!(curr))
		return NULL;

	if(!curr->next) {
		prev = curr;
		return prev;
	}

	prev = rev_list(curr->next);
	struct node *q = curr->next;
	q->next = curr;
	curr->next = NULL;

	return prev;
}

void remove_dups_inlist(struct node *head)
{
	struct node *temp = head;

	while(temp->next) {
		struct node *prev = NULL;
		if(temp->val == temp->next->val) {
			prev = temp->next;
			if(temp->next->next) {
				temp->next = temp->next->next;
			} else {
				temp->next = NULL;
				break;
			}
		}
		if(prev) {
			free(prev);
			prev = NULL;
		} else
			temp = temp->next;
	}	
}

void print_list(struct node *head)
{
	struct node *temp = head;

	printf("Here's the list: ");
	while(temp) {
		printf("%d, ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	struct node *head = NULL; // this is missing
	int num_nodes = 0;

	printf("Enter num of nodes in the list: \n");
	scanf("%d", &num_nodes);

	for(int i= 0; i<num_nodes; i++)
		head = creat_list(&head);

	print_list(head);

	//struct node *rev = rev_list(head);
	//printf("Reverse list => ");
	//print_list(rev);
	
	remove_dups_inlist(head);
	print_list(head);

	return 0;
}
