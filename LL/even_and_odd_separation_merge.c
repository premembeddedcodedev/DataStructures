#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int num;
	struct node *next;
}list;

void list_create(list **head, int number)
{
	list *new = (list *) malloc (sizeof(list));
	new->num = number;
	new->next = NULL;

	if(!*head)
		*head = new;
	else {
		list *temp = *head;
		new->next = temp;
		*head = new;
	}
}

void even_odd_merge(list **head)
{
	list *odd = *head, *temp = *head, *even_next=temp->next, *odd_next = temp, *even = odd->next;

	while (even && even->next) {
		odd->next = odd->next->next; // this sequence is matter 
		even->next = even->next->next;// first we need to increment 
		even = even->next;
		odd = odd->next;
	}

	odd->next = even_next;
}

int main()
{
	int array_bound;
	list *head = NULL;

	printf("Enter the number of values:\n");
	scanf("%d", &array_bound);
	
	int a[array_bound], i;

	for(i=0;i<array_bound;i++) {
		scanf("%d", &a[i]);
		list_create(&head, a[i]);
	}

	list *temp = head;

	printf("Linked list elements are :\n ");

	while(temp) {
		printf("%d\t", temp->num);
		temp = temp->next;
	}
	
	printf("\n");
	
	even_odd_merge(&head);

	printf("Even odd package ndoes: \n");

	temp = head;
	while(temp) {
		printf("%d\t", temp->num);
		temp = temp->next;
	}

	return 0;
}
