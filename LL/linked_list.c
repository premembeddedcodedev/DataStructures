#include <stdio.h>
#include <malloc.h>
struct node {
	int value;
	struct node *next;
};

struct node *head;

void print_list()
{
	struct node *temp, *prev = NULL, *next;

	if(!head) {
		printf("List is empty\n");
		return;
	}

	temp = head;

	while(temp) {
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

void list_rec_reverse(struct node *p)
{
	if(!p) {
		printf("List is empty\n");
		return;
	}
	if(!p->next) {
		head = p;
		return;
	}

	printf(" p: %p\n", p);
	if(p->next);
		printf("p->next is exist, %p, \n", p->next);
	list_rec_reverse(p->next);
	if(p->next);
		printf("After: p->next is exist %p, p: %p\n", p->next, p);

	struct node *q = p->next;
	q->next = p;
	p->next = NULL;
}

void list_find_mid()
{
	struct node *curr = head, *fast = head;

	if(!curr) {
		printf("List is empty\n");
		return;
	}

	while(fast && fast->next) {
		curr = curr->next;
		fast = fast->next->next;
	}

	printf("Mid node: %d\n", curr->value);
}

void list_subset_reverse(int up, int lb)
{
	if(!head || !head->next) {
		printf("List is empty or List has only element\n");
		return;
	}

	struct node *last = head, *curr = head, *prev = NULL, *next, *temp;
	
	int i;

	printf("up: %d, lb:%d\n", up, lb);

	for (i = 0; curr && i<lb-1; i++) {
		printf("1st for: i is %d\n", i);
		next = curr->next;
		prev = curr;
		curr = next;
	}
	
	last = prev;

	printf("i is %d\n", i);

	while(curr && i<= up-lb) {
		printf("2nd for: i is %d\n", i);
		next = curr->next;
		curr->next = next->next;
		next->next = prev->next;
		prev->next = next;
		i++;
	}
}


void list_reverse(struct node *head1)
{

	if(!head) {
		printf("List is empty\n");
		return;
	}
	
	if(!head1)
		head1 = head;

	struct node *curr = head1, *prev = NULL, *next;

	while(curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
}

void list_sort()
{
	struct node *temp, *next;
	int temp_val;

	temp = head;
	next = head->next;

	while(temp) {
		while(next) {
			if(temp->value > next->value) {
				temp_val = temp->value;
				temp->value = next->value;
				next->value = temp_val;		
			}
			next = next->next;
		}
		temp = temp->next;
		if(!temp->next || !temp)
			return;
		next = temp->next;
	}
}

void list_rev()
{
	struct node *temp, *prev = NULL, *next;

	temp = head;

	while(temp) {
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
}

void del_first()
{
	struct node *temp, *prev;

	if(!head) {
		printf("del_fst: Empty...\n");
		return;
	}

	temp = head;
	prev = temp;
	temp = temp->next;
	head = temp;

	free(prev);
}

void del_last()
{
	struct node *temp, *prev;

	if(!head) {
		printf("del_lst: Empty...\n");
		return;
	}

	temp = head;
	
	if(!temp->next) {
		printf("del_lst: only one element\n");
		head = NULL;
		return;
	}

	while(temp) {
		printf("check %d\n", temp->value);
		if(!temp->next) {
			//printf("del_lst: lst elemen %d %d %d\n", prev->value, temp->value, temp->value);
			prev->next = NULL;
			temp = prev->next;
			//free(temp->next);
		} else { 
			//printf("interrupt....%d\n", temp->value);	
			prev = temp;
			temp = temp->next;
		}
	}
#if 0

	if(!temp->next) {
		printf("del_lst: only one element\n");
		head = NULL;
		return;
	}

	while(temp->next->next)
		temp = temp->next;

	prev = temp->next;


	temp->next = NULL;

	free(prev);
#endif
}

void del_node_value(int value)
{
#if 0
	struct node *prev = NULL, *current = head;

	while (current) {
		if (current->value == value) {
			if(current == head){
				head = head->next;
				free(current);
				current = head;
			}
			else{
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else{ 
			prev = current;
			current = current->next;
		}
	}

	// key not found in list
	if (!current) {
		printf("not found in regular list\n");
		return ;
	}

	return ;
#endif
#if 1
	struct node *temp, *prev = NULL;

	if(!head) {
		printf("List is empty\n");
		return;
	}

	temp = head;

	while(temp) {
		if(temp->value == value) {
			if(temp == head) {
				prev = temp->next;
				head = prev;
			} else { 
			//if (!temp->next) {
			//	prev->next = temp->next;
			//} else {
				prev->next = temp->next;
			//	temp = temp->next;
			//}
			}
			free(temp);
			return;
		} 
		prev = temp;
		temp = temp->next;
	}

	if (temp->value != value) {
		printf("Not found\n");
		return;
	}
#endif
}

void add(int val)
{
	struct node *list, *new = head, *prev;

	list = (struct node *) malloc (sizeof(struct node));
	if(!list)
		return;
	list->value = val;
	list->next = NULL;

	if(!head) {
		head = list;
		return;
	} else {
		while(new) {
			prev = new;
			new = new->next;
		}
		prev->next = list;
	}
}

int main()
{
	int ch, i, val, n, n2;
	int num;

	printf("1. add\n");
	printf("2. del_f\n");
	printf("3. list_rev\n");
	printf("4. del_last\n");
	printf("5. list sorting\n");
	printf("6. list reverse\n");
	printf("7. del_node_value\n");
	printf("8. find mid\n");
	printf("9. ll node subset reverse\n");

	while(1) {
		printf("\nchoice: \n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter Number of elements: \n");
				scanf("%d", &n);
				printf("\nEnter elements: \n");
				for(i=0;i<n;i++) {
					scanf("%d", &val);
					add(val);
				}
				printf("\nElementes are: \n");
				print_list();
				break;
			case 2:
				del_first();
				printf("\nEnter Number of elements: \n");
				print_list();
				break;
			case 3:
				list_rev();
				printf("\nEnter Number of elements: \n");
				print_list();
				break;
			case 4:
				del_last();
				printf("\nEnter Number of elements: \n");
				print_list();
				break;
			case 5:
				list_sort();
				printf("\nsorting elements are: \n");
				print_list();
				break;
			case 6:
				list_reverse(head);
				printf("\nreversing elements are: \n");
				print_list();
				break;
			case 7:
				printf("\nEnter Number to be deleted: \n");
				scanf("%d", &num);
				del_node_value(num);
				print_list();
				break;
			case 8:
				printf("\nFinding middle of element: \n");
				list_find_mid();
				print_list();
				break;
			case 9:
				printf("\nLinked list Reverse from between nodes\n");
				printf("\nEnter Number upper bound and lower bound: \n");
				scanf("%d %d", &n, &n2);
				list_subset_reverse(n, n2);
				print_list();
				break;
			case 10:
				printf("\nRecursive linked list: \n");
				list_rec_reverse(head);
				print_list();
				break;
			default:
				printf("\nexit from the default...\n");
				print_list();
				break;

		};
	}

	return 0;
}
