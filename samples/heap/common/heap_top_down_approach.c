#include<stdio.h>

#define MAX_SIZE 10

int maxHeapSize = MAX_SIZE;
int heapSize;

void display(int heap[])
{
	printf("\nHeap: \n");

	for(int i=0; i<heapSize; ++i)
		printf("%d, ",heap[i]);

	printf("\n");
}

void swap(int *src1, int *src2)
{
	int temp = *src1;
	*src1 = *src2;
	*src2 = temp;
}

void from_zero_offset_heapify(int heap[], int input_bound)
{
	printf("enter the value to insert : \n");
	for(int i=0; i<input_bound; i++) {
		int temp;
		scanf("%d", &temp);

		heap[heapSize] = temp;

		if(heapSize >= MAX_SIZE)
			return;

		int curr = heapSize;

		//internal nodes only (means only nodes has children) - not leaf nodes (0->n/2-1)
		while((curr > 0) && ((heap[(curr-1)/2]) < heap[curr])) {
			swap(&heap[(curr-1)/2], &heap[curr]);
			curr = (curr-1)/2;
			printf("%d-> ", curr);
		}

		heapSize += 1;
	}
}

int main()
{
	int heap[] = {3,6,2,0,8,5,1,9};
	int bound;

	heapSize = 0;

	printf("array bound: \n");
	scanf("%d", &bound);

	from_zero_offset_heapify(heap, bound);

	display(heap);

	return 0;
}
