#include <stdio.h>
#include <malloc.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
} Node;

void display(Node *head)
{
	Node *temp = head;

	while(temp) {
		printf(" %d\t", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void intersect_ll(Node **head_f, Node **head_s, int soff, int fon)
{
	Node *new_f = *head_f, *new_s = *head_s, *new_r;
	int i = soff-1, j = fon-1; // 0 started offset so give offset by considering 0th offset
	
	while(i--)
		new_f = new_f->next;
	
	while(j--)
		new_s = new_s->next;

	printf("intersect @ %d\n", new_f->val);
	printf("intersect @ %d\n", new_s->val);

	new_s->next = new_f;
}

void push(Node **head, int val)
{
	Node *new = (Node *) malloc(sizeof(Node));
	new->val = val;
	new->next = NULL;

	if(!*head)
		*head = new;
	else {
		new->next = *head;
		*head = new;	
	}
}

Node* find_intersect(Node **head_f, Node **head_s)
{
	Node *new_f = *head_f, *new_s = *head_s, *new_r;

	while(new_f != new_s) {
		new_f = (new_f == NULL) ? *head_s : new_f->next;
		new_s = (new_s == NULL) ? *head_f : new_s->next;
	}

	return new_f;
}

int main()
{
	Node *head_f = NULL, *head_s = NULL, *head_r = NULL;
	int n;
	printf("How many first list nodes ?\n");
	scanf("%d", &n);

	int i, node_val;

	printf("Please enter first list for the node values ?? \n");
	for(i=0; i<n;i++) {
		scanf("%d", &node_val);
		push(&head_f,node_val);
	}
	i = 0;	
	printf("How many 2nd list nodes ?\n");
	scanf("%d", &n);
	printf("Please enter second list for the node values ?? \n");
	for(i=0; i<n;i++) {
		scanf("%d", &node_val);
		push(&head_s,node_val);
	}

	printf("First List is populated: \n");
	display(head_f);
	printf("Second List is populated: \n");
	display(head_s);

	int fon, son;
	printf("fist on : second on: \n");
	printf("Build intersect ....\n");
	scanf("%d %d", &fon, &son);

	if(fon == 0 || son == 0) // to remove the intersect
		printf("No intersect created\n");
	else
		intersect_ll(&head_f, &head_s, fon, son);

	printf("Upon Addition: \n");
	display(head_f);
	display(head_s);

	printf("Finding the intersect...\n");
	Node *temp = find_intersect(&head_f, &head_s);
	printf("@location : %d\n", temp->val);

	return 0;
}
