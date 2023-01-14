#include <stdio.h>
#include <stdlib.h>

/*
 * Heap: Complete binary tree
 * left child located @ 2i + 1 where i is root of particular that sub tree
 * right child located @ 2i + 2 where i is root of particular that sub tree
 * Max heap - Descending order - where root is greater than all the elements of the tree
 * Min heap - Ascending order - where root is smaller than all the elements of the tree
 * Operations: 
 * 	1. build heap from array
 * 	2. heapify to maintain heap properties like minheap and max heap
 * 	3. extract max
 * 		a. find max 0(1)
 * 		b. delete max - O(logN)
 * 	4. increase key - key is nothing but value of the node - where user want to change the value - O(logN)
 * 	5. decrease key - key is nothing but value of the node - where user want to change the value - O(logN)
 * 	6. insert key - O(logN)
 * 	7. find min - O(N)
 * 	8. delete min - need to see
 * 	9. insert new value - O(logN)
 * 	10. delete random element - O(N)
 * 	11. search random element - O(N)
 * 	12. to compare the value with parent - i-1/2.
 * */


void show_heap(int heap[], int size)
{
	printf("Elements are : \n");
	
	for(int i = 0; i<size; i++)
		printf("%d\t", heap[i]);

	printf("\n");
}

void heapify(int heap[], int curr_root, int numNodes)
{
	int l, r, child;

	l = 2*curr_root+1;
	r = 2*curr_root+2;
	// Binary tree starts from left side so taking l should be less than number of Nodes
	// if left is less than number of Nodes then its leaf node you can return;
	while(l < numNodes) {
		if(r == numNodes) //if the right child is not present then right node = number of Nodes
			child = l;
		else {
			if(heap[l]>heap[r])
				child = l;
			else
				child = r;
		}
		// here we are checking current root node is less than L and R above so swapping
		if(heap[curr_root] < heap[child]) {
			int temp = heap[curr_root];
			heap[curr_root] = heap[child];
			heap[child] = temp;

			curr_root = child; // we need to restart from child because its maximum
		} else
			break;
		l = 2*curr_root+1;
		r = 2*curr_root+2;
	}
}

void heap_sort(int eheap[], int numNodes)
{
	int kthelement, i;
	printf("Kth largest element : ??\n");
	scanf("%d", &kthelement);

	kthelement = numNodes - kthelement + 1;
 
	for(i = numNodes-1; i>=kthelement; i--) {
		int temp = eheap[0];
		eheap[0] = eheap[i];
		eheap[i] = temp;
		heapify(eheap, 0, i);
	}

	printf("Kth largest element is : %d\n", eheap[0]);
}

void build_min_heap(int heap[], int key, int *numNodes)
{
	heap[*numNodes] = key;
	int curr = *numNodes;

	//check overflow condition i.e maxheapsize may exceed heapsize while inserting element

	// every level of tree's left and right only compared with root not with global root
	// we have taken curr-1/2 because array starts from 0 and checking leafs parent only not global parent
	while((curr > 0) && (heap[(curr-1)/2]) > heap[curr]) {
		int temp = heap[(curr-1)/2];
		heap[(curr-1)/2] = heap[curr];
		heap[curr] = temp;
		curr = (curr-1)/2;
	}
	*numNodes += 1;
}

void build_max_heap(int heap[], int key, int *numNodes)
{
	heap[*numNodes] = key;
	int curr = *numNodes;

	//check overflow condition i.e maxheapsize may exceed heapsize while inserting element

	// every level of tree's left and right only compared with root not with global root
	// we have taken curr-1/2 because array starts from 0 and checking leafs parent only not global parent
	while((curr > 0) && (heap[(curr-1)/2]) < heap[curr]) {
		int temp = heap[(curr-1)/2];
		heap[(curr-1)/2] = heap[curr];
		heap[curr] = temp;
		curr = (curr-1)/2;
	}
	*numNodes += 1;
}

void swap(int *src, int *dest)
{
	int temp = *src;
	*src = *dest;
	*dest = *src;
}

void heapify_v1(int eheap[], int root, int size)
{
	int smallest;// = curr;
	int l = 2*root +1;
	int r = 2*root +2;

	/*L and R should be less than the size and greater element of L/R will be moved as parent*/

	if(l<size && eheap[l] < eheap[root])
		smallest = l;
	else 
		smallest = root;
	if(r<size && eheap[r] < eheap[smallest])
		smallest = r;

	if(smallest != root) {
		swap(&eheap[root], &eheap[smallest]);
		heapify(eheap, smallest, size);
	}
}

void heap_pop(int heap[], int *numNodes)
{
	//check underflow

	int temp = heap[0];
	heap[0] = heap[*numNodes-1];
	*numNodes -= 1;

	heapify(heap, 0, *numNodes);
	
	printf("pooped element : %d\n", temp);
}

int main(int argc, char *argv[])
{
	int eheap[1000];
	int element, ch, key, array_bound = 0;

	while(1) {
		printf("\nEnter your choice 1. build_max_heap, 2.pop, 3.display 4.heapify 5.sort 6.heap_v1 7.min_heap 8.show 9.exit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				scanf("%d", &key);
				build_max_heap(eheap, key, &array_bound);
			break;
			case 2:
				heap_pop(eheap, &array_bound);
			break;
			case 3:
				show_heap(eheap, array_bound);
			break;
			case 4:
				//TODO: give some random array and check if you build with build_heap funtion it wont give any
				// we can heapify from any offset but giving from 0
				heapify(eheap, 0,array_bound/2);
			break;
			case 5:
				heap_sort(eheap, array_bound);
				show_heap(eheap, array_bound);
			break;
			case 6:
				heapify_v1(eheap, 0, array_bound);
			break;
			case 7:
				scanf("%d", &key);
				build_min_heap(eheap, key, &array_bound);
			break;
			case 8:
			break;
			default:
				exit(-1);
			break;
		}
	}

	return 0;
}

