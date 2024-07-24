#include<stdio.h>
#include<limits.h>


int findminrotsortedarray(int a[], int low, int end)
{
	int min = INT_MAX;

	while(low <= end) { 
		int mid = (low + end)/2;

		if(a[low] <= a[mid]) {
			if(a[low] < min)
				min = a[low];
			low = mid + 1;
		} else {
			end = mid - 1;
			if(a[mid] < min)
				min = a[mid];
		}
	}
	return min;
}

int main()
{
	int array[] = {4,5,6,7,0,1,2};
	//int array[] = {4,5,6,7,1,2,3};

	int bound = 0;

	printf("min value at : %d\n", findminrotsortedarray(array, 0, (sizeof(array)/sizeof(array[0]))-1));	

	return 0;
}
