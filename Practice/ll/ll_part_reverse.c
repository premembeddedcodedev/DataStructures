#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *link;
}list;

list *head = NULL;

void display()
{
	list *temp = head;

	if(!temp)
		return;

	while(temp) {
		printf("%d->", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

list *find_mid(list **pprev, list **last)
{
	list *slow = head, *fast = head->link, *prev;

	if(!head || !head->link)
		return head;

	while(slow && fast && fast->link) {
		slow = slow->link;
		prev = fast;
		fast = fast->link->link;
	}

	printf("\nmid is : %d\n", slow->data);

	if(prev->link)
		*last = prev->link;
	else
		*last = prev;

	return slow;
}

void ll_alternate_first_last()
{
	list *next, *pprev, *prev=NULL, *last;

	list *mid = find_mid(&pprev, &last);

	list *temp = mid;

	if(!mid)
		return;

	list *curr = mid->link;

	while(curr) {
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}

	mid->link = prev;

	printf("mid reverse : \n");
	display(head);

	curr = head;
	list *iter = temp->link, *niter;

	while(iter) {
		next = curr->link;
		niter = iter->link;
		curr->link = iter;
		iter->link = next;
		iter = niter;
		curr = next;
	}

	temp->link = NULL;

	printf("first and last exchanges: \n");
	display(head);
}

void ll_part_reverse(int lb, int ub)
{
	int templrb = 0;

	list *last, *curr = head, *prev = NULL/*imp*/, *newend, *next;
	if(!curr)
		return;

	while(curr && templrb != lb) {
		prev = curr;
		templrb++;
		curr = curr->link;
	}

	last = prev;
	newend = curr;

	while(curr && templrb != ub) {
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
		templrb++;
	
	}

	if(last)
		last->link = prev;
	else
		head = prev;

	newend->link = curr;
}

void create_node(int element)
{
	list *temp = head, *new, *prev;

	new = (list *) malloc(sizeof(list));
	if(!new)
		return;

	new->data = element;
	new->link = NULL;

	if(!temp) {
		head = new;
		return;
	}
	
	//TODO : need to write the code which is first node;

	while(temp) {
		prev = temp;
		temp = temp->link;
	}

	prev->link = new;
}

int main() 
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};

	for(int i = 0; i<sizeof(a)/sizeof(int); i++)
		create_node(a[i]);

	display();

	int lb, ub;

	printf("Enter lb and ub\n");
	scanf("%d%d", &lb, &ub);

	ll_alternate_first_last();

	ll_part_reverse(lb, ub);

	display();

	return 0;
}
