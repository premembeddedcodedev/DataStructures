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


Qnode *create_node(int data)
{
	Qnode *new = (Qnode *) malloc();

}


void MSort(int Q[], int lb, int ub)
{
	if(lb < ub) {
	}
}

void display(int Q[], int ub)
{
	int i;

	printf("Sorted Elements are: \n");

	for(i=0;i<ub;i++) {
		printf("%d\t", Q[i]);
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "./a.out requires 2 variables : %d\n", argc);
		exit(-1);
	}
	int ch, i = 0, arraybound = atoi(argv[1]);
	int Q[arraybound];

	while(1) {
		printf("Enter the choice:\n 1.Sort\n 2.display\n 3.exit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the array values: \n");
				for(i=0;i<arraybound;i++)
					scanf("%d", &Q[i]);
				MSort(Q, 0, arraybound-1);
				break;
			case 2:
				display(Q, arraybound-1);
				break;
			case 3:
				break;
			default:
				break;
		
		};	
	}

	return 0;
}
