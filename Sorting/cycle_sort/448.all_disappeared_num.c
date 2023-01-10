#include "Algo.h"

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
	int cur_offset, i = 0;

	while(i<numsSize) {
		cur_offset = nums[i]-1;
		if(nums[i] != nums[cur_offset] && ((num[i] < numsSize)&&(num[cur_offset] < numsSize)))
			pswap(&nums[i], &nums[cur_offset]);
		else
			i++;
	}
	i = 0;
	while(i<numsSize) {
	
	}
}
