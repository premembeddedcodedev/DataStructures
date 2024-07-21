#include<stdio.h>
#include <string.h>

#define MAX 30

int heap[100], offset = 0, heapsize = 0;

void print_heap()
{
	printf("Heap is as follows : \n");

	for(int k = 0; k < heapsize; k++) {
		printf("%d, ", heap[k]);
	}

	printf("\n");
}

void build_heap(int heap[], int value)
{
	if(heapsize>= MAX) //missed from my side
		return;
	
	heap[heapsize] = value;

	int curr = heapsize;

	while(curr > 0 && heap[(curr-1)/2] < heap[curr]) { // N/2-1 we have taken since we started offset from '0'
		int temp = heap[(curr-1)/2];
		heap[(curr-1)/2] = heap[curr];
		heap[curr] = temp;

		curr = (curr-1)/2; //missed from my side.
	}
	heapsize += 1;
}

void heapify(int offset, int bound)
{
        int largest = offset;
        int left = (2*offset);
        int right = (2*offset) + 1;

        if((left <= bound) && (heap[left] > heap[largest]))
                largest = left;
        if((right <= bound) && (heap[right] > heap[largest]))
                largest = right;

        if(largest != offset) {
                int temp = heap[largest];
                heap[largest] = heap[offset];
                heap[offset] = temp;
                heapify(largest, bound);
        }
}

void get_sort_pop()
{
        for(int i = heapsize-1; i>=0 ; --i) {
                int temp = heap[i];
                heap[i] = heap[0];
                heap[0] = temp;
                heapify(0, i-1);
        }
}

void k_sort_merge(int ar_1[], int ar_2[], int ar_3[], int ar1_max, int ar2_max, int ar3_max)
{
	for(int k = 0; k < ar1_max; k++)
		build_heap(heap, ar_1[k]);
	
	for(int k = 0; k < ar2_max; k++)
		build_heap(heap, ar_2[k]);
	
	for(int k = 0; k < ar3_max; k++)
		build_heap(heap, ar_3[k]);

	get_sort_pop();
}

int main()
{
	//TODO: need to define pointer to an array
	int ar_1[MAX], ar_2[MAX], ar_3[MAX], ar1_max = 0, ar2_max = 0, ar3_max = 0;

	printf("Enter the max bound: \n");
	scanf("%d %d %d",&ar1_max, &ar2_max, &ar3_max);

	printf("enter the array %d values: %d \n", 1, ar1_max);
	for(int i = 0; i<ar1_max; i++)
		scanf("%d", &ar_1[i]);
	
	printf("enter the array %d values: %d \n", 2, ar2_max);
	for(int i = 0; i<ar2_max; i++)
		scanf("%d", &ar_2[i]);
	
	printf("enter the array %d values : %d \n", 3, ar3_max);
	for(int i = 0; i<ar3_max; i++)
		scanf("%d", &ar_3[i]);

	printf("sorting has started : \n");
	
	k_sort_merge(ar_1, ar_2, ar_3, ar1_max, ar2_max, ar3_max);

	print_heap();

	return 0;
}
