#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a[10];
	int **b;

	int *ptr = malloc(4);

	printf(" malloc : %p \n", ptr);

	a[0] = ptr;

	*ptr = 10;

	//printf(" stack : %p \n", *a[0]);
	//printf(" stack : %d \n", *ptr);

	int n[4] = {1,2,3,4};
	int *pr, *pr2;

	pr = malloc(0);
	pr2 = malloc(0);

	pr[0] = 10;
	pr[1] = 20;
	pr[2] = 30;
	pr[3] = 40;
	
	pr2[0] = 10;
	pr2[1] = 20;
	pr2[2] = 30;
	pr2[3] = 40;

	printf("%d %d %d %d \n", pr[0], pr[1], pr[2], pr[3]);
	printf("%d %d %d %d \n", pr2[0], pr2[1], pr2[2], pr2[3]);
}
