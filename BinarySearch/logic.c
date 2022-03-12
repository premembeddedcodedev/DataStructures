#include <stdio.h>

int BinarySearch(int a[], int number, int len)
{
	int start = 0;
	int end = len-1;

	while(start <= end) {
		int mid = start + (end-start)/2;

		if(number < a[mid])
		       end = mid - 1;
		else if(number > a[mid])
			start = mid + 1; 
		else
			return mid;
	}

	return -1;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8}, number = 6, search = 0;

	printf("Found @ %d\n", BinarySearch(a, number, sizeof(a)/sizeof(int)));

	return 0;
}
