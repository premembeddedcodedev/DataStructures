#include <stdio.h>

void display(int a[], int array_bound)
{
	printf("Enter the array lasts: \n");
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

void offsets_merge_sort(int ar1[], int ar2[], int m, int n)
{
	int i, j, last = 0;

	for(i = n-1; i>=0; i--) {

		last = ar1[m-1];

		//for(j=m-2; j>=0 && (ar1[j]>ar2[i]); j--) {
		for(j=m-2; j>=0; j--) {
			if(ar1[j]>ar2[i])
			ar1[j+1] = ar1[j];
		}
		if(j!=m-2 || (last > ar2[i])) {
			ar1[j+1] = ar2[i];
			ar2[i] = last;
		}

	}
}

int main()
{
#if 0
	int array_bound, ab2;
	printf("Enter the 1 array bound\n");
	scanf("%d", &array_bound);
	int a[array_bound], b[ab2];

	printf("Enter the 1 array lasts: \n");
	for(int i=0; i<array_bound; i++)
		scanf("%d", &a[i]);

	printf("Enter the 2 array bound\n");
	scanf("%d", &ab2);
	printf("Enter the 2 array lasts: \n");
	for(int i=0; i<ab2; i++)
		scanf("%d", &b[i]);
#else
	int a[] = {1, 5, 9, 10, 15, 20}; 
	int b[] = {2, 3, 8, 13}; 
	int array_bound = sizeof(a)/sizeof(a[0]); 
	int ab2 = sizeof(b)/sizeof(b[0]); 
#endif
	offsets_merge_sort(a, b, array_bound, ab2);

	display(a, array_bound);
	display(b, ab2);

	return 0;
}
