#include "Algo.h"


int missingNumber(int *nums, int numsSize)
{
	 int i = 0, temp;
	
	while(i < numsSize) {
		temp = nums[i];
		if((nums[i] != nums[temp]) && ((nums[i] < numsSize) || (nums[temp] < numsSize)))
			pswap(&nums[i], &nums[temp]);			
		else 
			i++;
	}

	i = 0;

	while(i<numsSize) {
		if(nums[i] != i)
			return i;
		i++;
	}

	return numsSize;
}
