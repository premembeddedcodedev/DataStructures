#include "Algo.h"

int firstMissingPositive(int* nums, int numsSize)
{
	int temp = 0, i, miss_numbers[5], miss_off[5];

	while(i<numsSize) {
		temp = nums[i] - 1;
		if(nums[i] > 0 &&nums[i] != nums[temp] && ((nums[i] < numsSize) || (nums[temp] < numsSize)))
			pswap(&nums[i], &nums[temp]);
		else
			i++;
	}

	i = 0;
	int j = 0, k=0;

	if(nums[0] > numsSize) {
		printf("Value %d\n", 1);
		return 1;
	}


	for(i = 0; i<numsSize; i++) {
		if(nums[i] != i+1) {
			printf("miss_number: %d, miss_off:%d\n", nums[i], i+1);
			miss_numbers[j++] = nums[i];
			miss_off[k++] = i;
		}
	}
}
