#include<stdio.h>

#define SIZE 10

int heap[SIZE];
int heapSize = 0;

void display(int bound)
{
	int i = 0;
	printf("Heap Values are : \n");
	while(i<bound)
		printf("%d, ", heap[i++]);

	printf("\n");
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

void heap_from_bootom_top(int bound)
{
	for(int i = (bound/2); i>=0; i--)
		heapify(i, bound);
}

void heap_sort(int bound)
{
	for(int i = bound-1; i>=0 ; --i) {
		int temp = heap[i];
		heap[i] = heap[0];
		heap[0] = temp;
		heapify(0, i-1);
	}
}

int main()
{
	int bound = 0;

	printf("Enter the array bound\n");
	scanf("%d", &bound);

	printf("Array values: \n");
	for(int i=0; i<bound; i++)
		scanf("%d", &heap[i]);

	heap_from_bootom_top(bound);

//	heap_sort(bound);

	display(bound);	

	return 0;
}
