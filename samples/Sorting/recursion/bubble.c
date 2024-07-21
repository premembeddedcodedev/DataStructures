#include<stdio.h>
#include <stdbool.h>
void fact_bubble_sort(int a[], int length, int offset)
{
	if(length == 0)
		return;

	if(offset < length) {
		if(a[offset] > a[offset+1]) {
			int temp = a[offset];
			a[offset] = a[offset+1];
			a[offset+1] = temp;	
		}
		fact_bubble_sort(a, length, offset+1);
	} else {
		fact_bubble_sort(a, --length, 0);
	}
}

int main()
{
	int a[] = {9, 8, 4, 7, 6, 1};

	fact_bubble_sort(a, sizeof(a)/sizeof(int)-1, 0);
	for(int i = 0; i<sizeof(a)/sizeof(int); i++)
		printf("%d, ", a[i]);

	return 0;
}
