#ifndef _LOGIC_H_
#define _LOGIC_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int check_greater_element_than_array(int a[], int len, int number)
{
	if(number > a[len])
		return -1;

	return 0;
}

int find_flooring_number(int a[], int number, int len)
{
	int start = 0;
	int end = len-1;
	
	if(check_greater_element_than_array(a, len, number) < 0)
		return -1;

	while(start <= end) {
		int mid = start + (end-start)/2;

		if(number < a[mid])
		       end = mid - 1;
		else if(number > a[mid])
			start = mid + 1; 
		else
			return mid;
	}
	// em, s once number dont find by bs algo during searching of given number is not found
	//logic is same till here similar binary search only returning is changing
	return a[end];
}

int find_ceiling_number(int a[], int number, int len)
{
	int start = 0;
	int end = len-1;
	
	if(check_greater_element_than_array(a, len, number) < 0)
		return -1;

	while(start <= end) {
		int mid = start + (end-start)/2;

		if(number < a[mid])
		       end = mid - 1;
		else if(number > a[mid])
			start = mid + 1; 
		else
			return mid;
	}
	// em, s once number dont find by bs algo during searching of given number is not found
	//logic is same till here similar binary search only returning is changing
	return a[start];
}

int find_ceil_wrap_number(int a[], int number, int len)
{
	int start = 0;
	int end = len-1;
	
	while(start <= end) {
		int mid = start + (end-start)/2;

		if(number < a[mid])
		       end = mid - 1;
		else
			start = mid + 1; 
	}
	// em, s once number dont find by bs algo during searching of given number is not found
	//logic is same till here similar binary search only returning is changing
	int temp = start % len;

	return a[temp];
}

int findfistandlast(int a[], int number, int len, bool firsthalfsearch)
{
	int start = 0;
	int end = len-1;
	int ans;

	while(start <= end) {
		int mid = start + (end-start)/2;

		if(number < a[mid])
		       end = mid - 1;
		else if(number > a[mid])
			start = mid + 1; 
		else {
			ans = mid;
			if(firsthalfsearch)
				end = mid - 1;
			else
				start = mid + 1;
	
		}
	}

	printf("ans: %d\n", ans);

	return ans;
}

int BinarySearch(int a[], int number, int start, int len)
{
	int end = len-1;
	
	if(check_greater_element_than_array(a, len, number) < 0)
		return -1;

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

int findvalue_infinitearray(int a[], int number)
{
	int start = 0;
	int end = 1;

	if(a[start] == number)
		return start;

	// start with 2, 4, 8, 16, 32 and so on. if we dont get any array length

	while(number >= a[end]) {
		int temp = end + 1;
		end = end + (end - start + 1) * 2;
		start = temp;
	}

	return BinarySearch(a, number, start, end);
}

int findpeak(int a[], int len)
{
	int mid, start = 0;
	int end = len - 1;

	while(start < end) {
		mid = start + (end - start)/2;

		if(a[mid] > a[mid+1])
			end = mid; // we are in descending part of array
		else
			start = mid + 1; // we are in ascending part of array

	}

	//finally only one element we get - so you can return any one (start/end)
	return start;
}

int order_agnosticarray(int a[], int number, int len)
{
	int peak = findpeak(a, len);
	int end, start = 0;
	if(number < a[peak])
		end = peak - 1;
	else
		start = peak + 1;
	
	return BinarySearch(a, number, start, end);
}

#if 0
int main()
{
	int a[] = {1,2,3,4,5,6,7,8}, number = 6, search = 0;

	printf("Found @ %d\n", BinarySearch(a, number, sizeof(a)/sizeof(int)));

	return 0;
}
#endif
#endif
