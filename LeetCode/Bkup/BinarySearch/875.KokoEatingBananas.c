#include<stdio.h>
#include <limits.h>

int find_min(int *piles, int pilesSize, int *max)
{
	int min = INT_MAX;
	*max = INT_MIN;

	for(int i = 0; i<pilesSize; i++) {
		if(min > piles[i])
			min = piles[i];
		if(*max < piles[i])
			*max = piles[i];
	}

	return min;
}

int find_min_h(int *piles, int pilesSize, int mid)
{
	int i = 0, sum = 0, div = 0;

	while(i<pilesSize) {
		div = piles[i] / mid;
		sum += div + 1;
		i++;
	}

	return sum;
}

int minEatingSpeed(int* piles, int pilesSize, int h)
{
	int end, mid;
		
	int min = find_min(piles, pilesSize, &end);

	int start = min;

	printf("Min: %d Max: %d\n", min, end);

	while(start <= end) { // here equals to is mandatory
		mid = start + (end-start)/2;

		int check = find_min_h(piles, pilesSize, mid);

		if(check == h) {
			return mid;
		} else if(check > h) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return end;
}

int main()
{
	//int piles[] = {30, 11, 23, 4, 20}, hours = 6;
	//int piles[] = {30, 11, 23, 4, 20}, hours = 5;
	int piles[] = {3, 6, 7, 11}, hours = 8;

	printf("min hours : %d\n",minEatingSpeed(piles, sizeof(piles)/sizeof(int),  hours));

	return 0;
}
