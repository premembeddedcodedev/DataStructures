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

void delete_key(Node **head, int key)
{
	Node *fast = *head, *slow = *head;

	while(key-- && fast)
	 	fast = fast->next;

	if(!fast) { //corner case is key is equal to number of elements in the linkedlist
		slow = slow->next;
		*head = slow;
		return;
	} else {
		while(fast->next) { // need to remember this ->next
			fast = fast->next;
			slow = slow->next;
		}
	}
	
	fast = slow->next;
	slow->next = slow->next->next;

	free(fast);
}

void push(Node **head, int val) {
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

int main()
{
	Node *head = NULL;
	int n, key;
	printf("How many nodes ?\n");
	scanf("%d", &n);

	printf("tell me which node to delete from last:\n");
	scanf("%d", &key);

	int i, node_val;

	printf("Please enter the node values ?? \n");
	for(i=0; i<n;i++) {
		scanf("%d", &node_val);
		push(&head,node_val);
	}

	printf("List is populated: \n");
	display(head);

	delete_key(&head, key);
	
	printf("Upon Deletion: \n");
	display(head);

	return 0;
}
