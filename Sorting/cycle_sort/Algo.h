#ifndef __ALGO_H__
#define __ALGO_H__
#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void pswap(int *dest, int *src);
int missingNumber(int *nums, int numsSize);
int firstMissingPositive(int* nums, int numsSize);
int* findErrorNums(int* nums, int numsSize, int* returnSize);
int findDuplicate(int* nums, int numsSize);
#endif
