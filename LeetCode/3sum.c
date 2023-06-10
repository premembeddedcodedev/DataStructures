#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void push_to_array(int temp[], int value, int boundary)
{
	int i;

	for(i = 0; i< boundary; i++)
		temp[i] = value;

}

bool find_in_array(int temp[], int n, int offset, int val, int *check)
{
	int i;

	for(i=offset;i<n;i++) {
		if(temp[i] == val) {
			*check = i;
			return true;
		}
	}

	return false;
}

void push_to_dest(int temp[][3], int or[], int iteration, int i, int j, int k, int *offset)
{
	temp[iteration][*offset] = or[i];
	(*offset)++;
	temp[iteration][*offset] = k;
	(*offset)++;
	temp[iteration][*offset] = or[j];
	(*offset)++;
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
//	printf("Kth largest element : ??\n");
//	scanf("%d", &kthelement);

//	kthelement = numNodes - kthelement + 1;
 
	for(i = numNodes-1; i>=numNodes; i--) {
		int temp = eheap[0];
		eheap[0] = eheap[i];
		eheap[i] = temp;
		heapify(eheap, 0, i);
	}

	printf("Kth largest element is : %d\n", eheap[0]);
}

int main()
{
	//int i, j, a[] = {-1,0,1,2,-1,-4}, hash[100], dest[10][3];
	//int i, j, a[] = {0,0,0}, hash[100], dest[10][3];
	//TODO: Fail:
	int i, j, a[] = {-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2}, hash[100], dest[50][3];
	int iteration = 0, val, hash_off = 0, k=0, dest_off = 0;
	
	printf("Array: \t");

	for(i=0;i<sizeof(a)/sizeof(int);i++)
		printf("%d, ", a[i]);

	printf("\n");

	for(i=0;i<sizeof(a)/sizeof(int); i++) {
		hash_off = 0;
		memset(hash, 0, sizeof(hash)/sizeof(int));
		for(j=i+1;j<sizeof(a)/sizeof(int); j++) {
			dest_off = 0;
			val = -(a[i] + a[j]);
			if(find_in_array(hash, hash_off, 0, val, &k)) {
				push_to_dest(dest, a, iteration++, i, j, hash[k], &dest_off);
				printf("Val: %d\t", val);
				printf("i: %d, j:%d\n", i, j);
			} 
			push_to_array(hash, a[j], hash_off++);
		}
	}

	printf("sets are : %d\n", iteration);

	//for(i=0;i<iteration;i++)
	//	heap_sort(&a[2], 3);

	for(i=0;i<iteration;i++) {
		for(k=0;k<3;k++)
			printf("%d->", dest[i][k]);

		printf("\n");
	}

	return 0;
}
