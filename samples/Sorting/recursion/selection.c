#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

void swap(int *src1, int *src2)
{
	int temp = *src1;
	*src1 = *src2;
	*src2 = temp;
}

void rec_selectionsort(int a[], int n, int offset, int max)
{
	if(n == 0)
		return;

	if(offset < n) {
		if(a[offset] > a[max])
			rec_selectionsort(a, n, offset+1, offset);
		else
			rec_selectionsort(a, n, offset+1, max);
	} else {
		swap(&a[n-1], &a[max]);
		// reducing bound value with offset 0 to switch to first if condition end of each iteration
		rec_selectionsort(a, n-1, 0, 0); 
	}
}

int main()
{
	int a[] = {4,8,3,7,5,2};

	rec_selectionsort(a, sizeof(a)/sizeof(a[0]), 0, 0);

	printf("Sorted: \t");
	for(int i = 0; i<sizeof(a)/sizeof(a[0]); i++)
		printf("%d, ", a[i]);

	printf("\n");

	return 0;
}
