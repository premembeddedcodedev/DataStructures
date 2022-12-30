#include <stdio.h>
#include <stdlib.h>

/* logic: at the end of partition your pivot will be middle and left side values are less right side values are greater
 * 1. select the pivot element
 * 2. keep start variable @start and end variable @size-1
 * 3. compare the start variable position with pivot which should be less than and increment the start
 * 4. compart the end variable position with pivot which should be greater than and decrement the end
 * 5. if the start and end are not intersecting/exceeding the end then swap the start with end
 * 6. otherwise simply continue the process
 * 7. at the end we need to swap the pivot element with end because somewhere end should be crossed with start
 * 8. so finally pivot will be placed in middle and values will be left side is less and right side is greater
 */

void swap(int *from, int *to)
{
	int temp = *from;
	*from = *to;
	*to  = temp;
}

int partition(int Q[], int lb, int ub)
{
	int start = lb, end = ub, pivot = Q[lb];

	while(start < end) {
		while(Q[start] <= pivot)
			start++;
		while(Q[end] >= pivot)
			end--;
		if(start < end)
			swap(&Q[start], &Q[end]);
	}

	swap(&Q[lb], &Q[end]); //updating pivot with end because end crosses the start

	return end;
}

void QSort(int Q[], int lb, int ub)
{
	if(lb < ub) {
		int loc = partition(Q, lb, ub);
		QSort(Q, lb, loc - 1); // location you will get in middle(i.e) so skipping pivot element from partitioning again
		QSort(Q, loc+1, ub); // location you will get in middle(i.e) so skipping pivot element from partitioning again
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
				QSort(Q, 0, arraybound-1);
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
