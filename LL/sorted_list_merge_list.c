#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *create(int number)
{
	struct ListNode *new = (struct ListNode *) malloc (sizeof(struct ListNode));

	new->val = number;
	new->next = NULL;

	return new;
}

void display(struct ListNode *list)
{
	struct ListNode *temp = list;

	while(temp) {
		printf("%d\t", temp->val);
		temp = temp->next;
	}
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	if(!list1 && !list2)
		return NULL;;
	if(!list2 && list1)
		return list1;
	if(!list1 && list2)
		return list2;

	struct ListNode *temp1 = list1, *temp2 = list2, *new = create(5);
	struct ListNode *tnew = new, *mid;
	int val, temp = 1;


	while(temp1 && temp2){
		if(temp1->val < temp2->val) {
			val = temp1->val;
			mid = temp1;
			temp1 = temp1->next;
		} else {
			val = temp2->val;
			mid = temp2;
			temp2 = temp2->next;
		}

		tnew->val = val;
		tnew->next = mid; // we have to avoid but how TODO:
		mid = tnew;
		tnew = tnew->next;
	}

	tnew = mid;
	// since we are pointing oldnode in above for the avoiding NULL pointer 
	// so restoring with prev mid pointer to avoid duplication of subsequent 

	while(temp1) {
		tnew->next = temp1;
		temp1 = temp1->next;
		tnew = tnew->next;
	}

	while(temp2) {
		tnew->next = temp2;
		temp2 = temp2->next;
		tnew = tnew->next;
	}

	printf("\n");

	return new;

}

void list_push(struct ListNode **node, int number)
{
	struct ListNode *new;

	new = create(number);

	if(!(*node))
		*node = new;
	else {
		struct ListNode *temp = *node;
		new->next = temp;
		*node = new;
	}
}

int main()
{
	/*Dont forgot to point the head to NULL - otherwise it goes with junk*/
	struct ListNode *list1 = NULL, *list2 = NULL, *result = NULL;
	int i, num, element;

	printf("Enter the List count :\n");
	scanf("%d", &num);

	for(i=0; i<num; i++) {
		scanf("%d", &element);
		list_push(&list1, element);
	}

	printf("Enter the List count :\n");
	scanf("%d", &num);
	for(i=0; i<num; i++) {
		scanf("%d", &element);
		list_push(&list2, element);
	}

	display(list1);
	display(list2);

	printf("\n");

	result = mergeTwoLists(list1, list2);

	printf("Sorted List is: \n");
	display(result);

	return 0;
}
