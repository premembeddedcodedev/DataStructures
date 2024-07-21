#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Qnode;

void swap(int *from, int *to)
{
	int temp = *from;
	*from = *to;
	*to  = temp;
}

void display(Qnode **head)
{
	Qnode *temp = *head;
	int i;

	printf("Sorted Elements are: \n");

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

	if((*head) == NULL) {
		*head = new;
		return *head;
	} else {
		Qnode *temp = *head, *prev;
#if 1
		if(temp->next == NULL) {
			temp->next = new;
			return *head;
		} else {
			//while(temp->next != NULL) {
			while(temp != NULL) {
				prev = temp;
				temp = temp->next;
			}
			prev->next= new;
#endif
#if 0
			while(temp != NULL) {
				if(temp->next == NULL) {
					temp->next = new;
					return *head;
				}
				prev = temp;
				temp = temp->next;
			}
			prev->next= new;
#endif
			return *head;
		}
	}
}

void MSort_mid(Qnode *head, Qnode **lb, Qnode **ub)
{
	Qnode *slow= head, *fast = slow->next;
	/* below loop : 
	 * slow: 0 --> fast: 2
	 * 1 --> 3
	 * 2 --> 4
	 */

	/*Finding mid element to divide list into 2 parts*/
	while(fast) {
		fast = fast->next;
		if(fast) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	//printf("mid point : %d\n", slow->data);

	*lb = head; // this will go as first loop after division
	*ub = slow->next; // this will go as second loop after division
	slow->next = NULL; // slow->next  should be NULL because first list should end in mid.
}

Qnode* SortNow(Qnode *lb, Qnode *ub)
{
	Qnode *result = NULL;
	
	if(!lb)
		return ub;
	if(!ub)
		return lb;


	if(lb->data <= ub->data) {
		result = lb;
		result->next = SortNow(lb->next, ub);
	} else {
		result = ub;
		result->next = SortNow(ub->next, lb);
	}

	return result;
}

void MSort(Qnode **source)
{
	Qnode *head = *source;
	Qnode *lb, *ub;

	if(!*source || !head->next)
		return;

	MSort_mid(head, &lb, &ub);

	MSort(&lb);
	MSort(&ub);

	*source = SortNow(lb, ub);

	//display(&head);
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
		printf("Enter the choice:\n 1.Sort\n 2.display\n 3.exit\n");
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
				//display(&head);
				break;
			case 3:
				MSort(&temp);
				break;
			default:
				break;

		};	
	}

	return 0;
}
