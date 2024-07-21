#include<stdio.h>

#define MAX_SIZE 10

int heap[MAX_SIZE];
int heapSize = 0;

void print_heap()
{
	printf("values are:\n");
	for(int i = 0; i<heapSize; i++) 
		printf("%d, ", heap[i]);

	printf("\n");
}

void swap(int *src1, int *src2)
{
	int temp = *src1;
	*src1 = *src2;
	*src2 = temp;
}

void int_node_max_offset_to_heapify(int curr)
{
	int largest = curr;
	int left = (2 * curr);
	int right = (2 * curr) + 1;

	if(left <= heapSize && (heap[left] > heap[largest]))
		largest = left;
	if(right <= heapSize && (heap[right] > heap[largest]))
		largest = right;

	if(largest != curr) {
		swap(&heap[largest], &heap[curr]);
		int_node_max_offset_to_heapify(largest);
	}
}

void build_heap(int bound)
{
	for(int i = (bound - 1)/2; i>=0; i--)
		int_node_max_offset_to_heapify(i);
}

int main()
{
	int bound, values;
	printf("Enter the bound \n");
	scanf("%d", &bound);

	heapSize = bound;

	printf("Enter the heap values \n");
	for(int i= 0; i<bound; i++)
		scanf("%d", &heap[i]);

	build_heap(bound);

	print_heap();
}
