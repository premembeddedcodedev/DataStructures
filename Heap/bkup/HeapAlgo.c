#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int maxHeapSize = MAX_SIZE;
int heapSize;

int heap[MAX_SIZE];

void init()
{
	heapSize = 0;
}
#if 0
void display()
{
	for(int i=0; i<heapSize; ++i)
		cout << heap[i] << " ";

	cout << "\n";
}
#endif
void swap(int *from, int *to)
{
	int temp = *from;
	*from = *to;
	*to = temp;
}
//percolate algorithm
void heapify_algo()
{
	int curr = 0;
	// Left child 2i+1, Right child = 2i+2 parent = i
	// traverse tree left to right to satisfy the max/min heap rules
	while((2*curr)+1 < heapSize) {
		int child;
		if(2*curr+2 ==  heapSize) //checking only one left child is present
			child = 2*curr+1;
		else //if the left and right childs are present we need to find maximum
			child = (heap[2*curr+1] > heap[2*curr+2]) ? 2*curr+1 : 2*curr+2;

		if(heap[curr] < heap[child]) { //after finding the max of above step swapping
			swap(&heap[curr], &heap[child]);
			curr = child;
		} else
			break;
	}
}

/* pop Algo:
 * 	1. Save the root element
 * 	2. copy the right/heapsize-1 element into root
 * 	3. reduce the heapsize
 */
#if 1
int heap_pop()
{
	if(heapSize <= 0) {
		printf("Heap is underflow\n");
		return -1;
	}

	int popped = heap[0]; // 1st point
	heap[0] = heap[heapSize - 1]; //2nd point
	heapSize -= 1;// 3rd point

	heapify_algo();

	return popped;
}

void heap_push(int element)
{
	if(heapSize >= MAX_SIZE) {
		printf("Heap Overflowed\n");
		return;
	}

	heap[heapSize] = element;
	int curr = heapSize;
	
	// curr-1/2 is the partent curr is the root/leaf based on curr-1/2 result.
	while(curr > 0 && (heap[(curr-1)/2] < heap[curr]))
	{
		int temp = heap[(curr-1)/2];
		heap[(curr-1)/2] = heap[curr];
		heap[curr] = temp;

		curr = (curr-1)/2;
	}

	heapSize += 1;	
}
#endif
/* its rearranging the data in the tree fashion so no return value observed*/
//TODO: Need to see if we pass 2 arguments only - what happenss?
void heapify(int eheap[], int root, int size)
{
	int largest;
	int l = 2*root +1;
	int r = 2*root +2;

	/*L and R should be less than the size and greater element of L/R will be moved as parent*/

	if(l<size && (eheap[l] > eheap[root]))
		largest = l;
	else //if the root node is greater than left and right node then largest = root
		largest = root;

	if(r<size && (eheap[r] > eheap[largest]))
		largest = r;

	//If its leaf node and size of the array is out of bound then below code will run

	if(largest != root) {
		swap(&eheap[root], &eheap[largest]);
		heapify(eheap, largest, size);
	}
}

void build_heap(int eheap[], int size)
{
	// size/2 -1 will give us the height of the heap tree (Binary tree - log2N - so division works here)
	for(int i=size/2 -1; i>=0; i--)
		heapify(eheap, i, 0);
}

void show(int eheap[], int size)
{
	int i = 0;

	for(i=0; i<size;i++)
		printf("%d\t", eheap[i]);

	printf("\n");
}

void heap_sort(int eheap[], int size)
{
	build_heap(eheap, size); // O(N) time complexity
	show(eheap, size);

	/* 1. swap last element to first element
	 * 2. heapify will adjust all elements as per the heap rule */

	for(int i = size-1; i >= 0; i--) {
		swap(&eheap[0], &eheap[i]);
		heapify(eheap, 0, i);
	}
}

/* Max heap -- start*/
void heap_inc_key(int eheap[], int element, int key)
{
	/*TODO: Need to check array counter with element and return
	 * also check how its different from push operation*/
	if (eheap[element] > key) { //ensure we have got higher value than existing value
		printf("heap_inc_key - wrong operation %d\n", eheap[element]);
		return;
	}

	eheap[element] = key;

	// traverse till parent is greater value than current and till reaches 0
	while(element > 0 && eheap[element/2] < eheap[element]) {
		swap(&eheap[element], &eheap[element/2]);
		element /= 2;
	}
}


void heap_dec_key(int eheap[], int element, int key)
{
	/*TODO: Need to check array counter with element and return
	 * also check how its different from pop operation*/
	if(eheap[element] < key)
		return;

	eheap[element] = key;
	heapify(eheap, element, 7);
}
/* Max heap  -- end */

int main(int argc, char *argv[])
{
	init();
	int element, ch, key;
	//vector<int> eheap{ 9,6,8,2,1,4,3}; //max heap
	int eheap[7] = {9,6,8,2,1,4,3}; //max heap

	while(1) {
		printf("\nEnter your choice 1. push, 2.pop, 3.display 4.build 5.heap 6.inc_key 7.dec_key 8.show 9.exit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				//cin>>element;
				//heap_push(element);
			break;
			case 2:
				//cout << heap_pop() << "\t-popped \n";
			break;
			case 3:
				//display();
			break;
			case 4:
				show(eheap, 7);
				build_heap(eheap, 7);
				show(eheap, 7);
			break;
			case 5:
				heap_sort(eheap, 7);
				show(eheap, 7);
			break;
			case 6:
				printf("Enter the position of the element to insert\n");
				scanf("%d", &element);
				printf("Enter the value at the position to insert\n");
				scanf("%d", &key);
				printf("Going with element : %d, key :%d\n", element, key); 
				heap_inc_key(eheap, element, key);
				show(eheap, 7);
				break;
			case 7:
				printf("Enter the position of the element to insert\n");
				scanf("%d",&element);
				printf("Enter the value at the position to insert\n");
				scanf("%d",&key);
				printf("Going with element: %d, key: %d\n", element, key); 
				heap_dec_key(eheap, element, key);
				show(eheap, 7);
				break;
			case 8:
				show(eheap, 7);
			break;
			default:
				exit(-1);
			break;
		}
	}

	return 0;
}

