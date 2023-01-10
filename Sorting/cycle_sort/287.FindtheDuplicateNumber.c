#include "Algo.h"


int findDuplicate(int* nums, int numsSize)
{
        int temp = 0, i, miss_numbers[5], miss_off[5];

        while(i<numsSize) {
                        temp = nums[i] - 1;
                        if(nums[i] != nums[temp] && ((nums[i] < numsSize) || (nums[temp] < numsSize)))
                                pswap(&nums[i], &nums[temp]);
                        else
                                i++;
        }

        i = 0;
        int j = 0, k=0;

        for(i = 0; i<numsSize; i++) {
                if(nums[i] != i+1) {
                        printf("miss_number: %d, miss_off:%d\n", nums[i], i);
                        miss_numbers[j++] = nums[i];
                        miss_off[k++] = i;
                }
        }
	return nums[i];
}
