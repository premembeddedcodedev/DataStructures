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

	list = (struct node *) malloc (sizeof(struct node *));
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
	int ch, i, val, n;
	int num;

	printf("1. add\n");
	printf("2. del_f\n");
	printf("3. list_rev\n");
	printf("4. del_last\n");
	printf("5. list sorting\n");
	printf("6. del_node_value\n");

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
			default:
				printf("\nEnter Number to be deleted: \n");
				scanf("%d", &num);
				del_node_value(num);
				print_list();
				break;

		};
	}

	return 0;
}
