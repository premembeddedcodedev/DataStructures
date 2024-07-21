#include <stdio.h>

int finddiv(int *nums, int numsSize, int limit)
{
	int i = 0, count = 0;

	while(i < numsSize && nums[i] != 0) {
		// This is the ceiling of integer division
		count += (1 + (nums[i]-1)/limit);
		i++;
	}

	printf("finding for %d, sum : %d\n", limit, count);

	return count;
}

void selection_sort()
{



}

int FindSmallDivisor(int *nums, int numsSize, int threshold)
{
	int start = 1, end = nums[numsSize-1], mid = 0;

	while(start <= end) {
		mid = start + (end - start)/2;
		if(finddiv(nums, numsSize, mid) >= threshold)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return mid;
}

int main()
{
	int nums[] = {1, 2, 5, 9}, threashold = 6;
	//int nums[] = {44, 22, 33, 11, 1}, threashold = 5;
	//int nums[] = {1, 11, 22, 33, 44}, threashold = 5;

	printf("Here's the Divisor : %d\n", FindSmallDivisor(nums, sizeof(nums)/sizeof(int), threashold));

	return 0;
}
