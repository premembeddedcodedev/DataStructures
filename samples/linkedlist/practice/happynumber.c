#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tree {
	int data;
	struct tree *next;
};

struct tree *alloc_free(int n)
{
	struct tree *new = (struct tree *)malloc(sizeof(struct tree));

	new->data = n;
	new->next = NULL;

	return new;
}

int add_power_extract(int n)
{
	int temp = 0, power = 0;	

	while(n>0) {
		temp = n % 10;
		power += temp * temp;
		n = n/10;
	}

	return power;
}

void add_node(struct tree **head, int value)
{
	struct tree *temp = *head;

	while(temp->next)
		temp = temp->next;

	temp->next = alloc_free(value);
}

int list_add(struct tree **root, int n)
{
	if(!(*root)) {
		*root = alloc_free(n);
		return n;
	}

	int powervalue = add_power_extract(n);
	add_node(root, powervalue);		

	return powervalue;
}

bool isHappy(int n)
{
	struct tree *root = NULL;
	int pvalue = 0;

	if(!root)
		pvalue = list_add(&root, n);

	if(!root->next)
		pvalue = list_add(&root, pvalue);

	if(!(root->next->next))
		pvalue = list_add(&root, pvalue);

	n = pvalue;

	struct tree *slow = root;
	struct tree *fast = root->next->next;

	if(fast->data == 1 || root->data == 1)
		return true;

	while(n!=1) {
		if(n == 1)
			return true;

		if((slow->data == fast->data))
			return false;
		else {
			int power_value = add_power_extract(n);
			add_node(&root, power_value);
			n = power_value;
		}

		if(fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
	}

	return true;
}

int main()
{
	int n;

	printf("enter the number\n");
	scanf("%d", &n);

	printf("happy number: %s\n", isHappy(n) ? "Yes": "No");

	return 0;
}
