#include <stdio.h>

//i should the ending limit of j and swap the element from j to i incase of greater

void display(int a[], int array_bound)
{
	printf("Enter the array values: \n");
	for(int i=0; i<array_bound; i++)
		printf("%d\t", a[i]);

	printf("\n");
}

void swap(int *src, int *dst)
{
	int temp = *src;
	*src = *dst;
	*dst = temp;
}

void insertion_sort(int a[], int array_bound)
{
	int i, j;

	for(i=1;i<=array_bound; i++) {
		for(j=0; j<=i; j++) {
			if(a[j] > a[i])
				swap(&a[j], &a[i]);
		}
	}
}

int main()
{
	int array_bound;
	printf("Enter the array bound\n");
	scanf("%d", &array_bound);
	int a[array_bound];

	printf("Enter the array values: \n");
	for(int i=0; i<array_bound; i++)
		scanf("%d", &a[i]);

	insertion_sort(a, array_bound - 1);

	display(a, array_bound);

	return 0;
}
