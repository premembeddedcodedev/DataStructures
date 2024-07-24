#include<stdio.h>

int searchinsert(int a[], int target, int bound)
{
	int start = 0, mid = 0;	
	
	while(start < bound) {
		mid = (start + bound)/2;
		if(a[mid] >= target)
			bound = mid - 1;
		else
			start = mid + 1;
	}

	return mid;
}

int main()
{
	int a[] = {1,2,4,7}, target = 6;

	printf("searchinsert @ %d\n", searchinsert(a, 6, (sizeof(a)/sizeof(a[0]))-1));

	return 0;
}
