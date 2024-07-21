#include <stdio.h>
#include <stdbool.h>

void swap(int *src, int *dest)
{
	int temp = *src;
	*src = *dest;
	*dest = temp;
}
/*  9 1 8 5 3 2 
 *  9 | 1 8 5 3 2 window size is 1, swaping in 2nd condition
 *  1 9 | 8 5 3 2 unsorted outside widow value is less, so swap in 2nd loop till we reach greater in window, place and break
 *  1 8 9 | 5 3 2 again less value outside of window, so swap positions till we reach less value with current temp, place&break
 *  1 5 8 9 | 3 2
 *  1 3 5 8 9 | 2
 *  1 2 3 5 8 9 --> 
 * */


void insertionsort(int *a, int size)
{
	int  j = 0;

	for(int i = 1; i<size; i++) {
		j = i - 1;
		int temp = a[i];
		// control will enter into this loop only when the value is less than unsorted array max element
		while(temp < a[j] && j >= 0) {
			if(temp > a[j]) {
				//once we find the element from unsorted window is greaterthan sorted window element thats the right place to keep the new element from unsorted list.
				swap(&temp, &a[j]);
				break;
			} else {
				//swapping sorted window position elements till we get right place for new value from unsorted window
				swap(&a[j+1], &a[j]);
			}
			j--;
		}
	}
}

int checkplace(int *stall, int size, int value)
{
	int i = 1; //0th offset must have cow so starting from 1
	int count = 1; //first slot should be calculated

	while(i <= size-1) {
		if(value <= (stall[i] - stall[i-1]))
			count++;
		i++;
	}
	
	printf("We can place with %d distance\n", value);

	return count;
}

int aggressiveCows(int *stall, int size, int cows)
{
	insertionsort(stall, size);
	printf("Sorted Arrays: \n");
	for(int i = 0; i<size; i++)
		printf("%d", stall[i]);
	printf("\n");
	
	int start = 0, end = stall[size-1], mid = 0;

	while(start <= end) {
		mid = start + (end-start)/2;

		if(checkplace(stall, size, mid) >= cows)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return mid;
}

int main()
{
	//int stall[] = {0, 3, 4, 7, 11, 9}, cows = 4;	
	int stall[] = {10, 1, 2, 7, 5}, cows = 3;	
	//int stall[] = {1, 2, 4, 8, 9}, cows = 3;	
	//int stall[] = {9, 1, 8, 5, 3, 2}, cows = 4;	

	printf("Arrays: \n");
	for(int i = 0; i<sizeof(stall)/sizeof(int); i++)
		printf("%d", stall[i]);
	printf("\n");
	
	printf("Max of min arrangement is %d\n", aggressiveCows(stall, sizeof(stall)/sizeof(int), cows));
	
	return 0;
}
