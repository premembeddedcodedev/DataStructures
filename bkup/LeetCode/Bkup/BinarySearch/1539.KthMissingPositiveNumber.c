#include<stdio.h>

int findKthPositive(int* arr, int arrSize, int k)
{
	//int start = 1, mid = 0, end = arr[arrSize-1] + k; //Because number start from 1 -> end properly. may be lies after max+5
	int start = 1, mid = 0, end = arrSize-1; //Because number start from 1 -> end properly. may be lies after max+5

	while(start <= end){
		
		mid = start + (end-start)/2;

		int missing = arr[mid] - (mid + 1);

		if(missing < k)
			start = mid + 1;
		else
			end = mid - 1;
	}

	//TODO: Not returning any mid like binary search
	//
	//once loop comes out from above while end cross start - its reverse incase of end going beyond the start we may get negative
	//offset so we are calculating as below
	//a[high] + more need to add , but more we will get like k-missing.
	//a[high] + (k-missing) 
	//missing formulae from above loop is arr[mid] - (mid + 1) = once loop comes out mid = high
	//so a[high] + (k-missing) ==> a[high] + k - (a[high] - high - 1) ==> high + 1 + k
	//but low after loop exit will be like high+1, so low+k
	//so returning start+k below

	return start + k;
}

int main()
{
	//int arr[] = {2,3,4,7,11}, k = 5;
	int arr[] = {1,2,3,4}, k = 2;

	printf("Kth positive number is : %d\n", findKthPositive(arr, sizeof(arr)/sizeof(int), k));

	return 0;
}
