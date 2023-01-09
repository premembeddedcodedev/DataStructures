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

//TODO: 1st argument is still double pointer because taking same address from callee
Node* push_at_end(Node **head, int val) {
        Node *new = (Node *) malloc(sizeof(Node));
        new->val = val;
        new->next = NULL;

        if(!*head)
                *head = new;
        else {
		Node *temp = *head, *prev;
        	while(temp->next)
			temp = temp->next;
		temp->next = new;
	}

	return *head;
}
//TODO: Why 3rd argument is double pointer 
void addition_ll(Node **head_f, Node **head_s, Node **head_r)
{
	Node *new_f = *head_f, *new_s = *head_s, *new_r;
	int carry = 0, sum = 0;

	new_r = push_at_end(head_r, 0);
	//TODO: 1st argument is not a pointer 
	*head_r = new_r;	

	while(new_f || new_s) {
		if(new_f && !new_s) {
			sum = new_f->val + carry;
			carry = sum / 10;
			sum %= 10;
			push_at_end(&new_r, sum);
			new_f = new_f->next;
		} else if(new_s && !new_f){
			sum = new_s->val + carry;
			carry = sum / 10;
			sum %= 10;
			push_at_end(&new_r, sum);
			new_s = new_s->next;
		} else {
			sum = new_f->val + new_s->val + carry;
			carry = sum / 10;
			sum %= 10;
			push_at_end(&new_r, sum);
			new_f = new_f->next;
			new_s = new_s->next;
		}
	}
	if(carry) {
		push_at_end(&new_r, carry);			
	}
	//skipping the first node
	Node *temp = *head_r;
	*head_r = temp->next;
	free(temp);
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

	addition_ll(&head_f, &head_s, &head_r);
	
	printf("Upon Addition: \n");
	display(head_r);

	return 0;
}
