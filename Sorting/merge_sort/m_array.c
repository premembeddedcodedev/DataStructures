/* Divide the arrays 2 halves till we reaches 2 elements and compare and swap
*/
#include <stdio.h>
#include <stdlib.h>

void merge_both_halves_sort(int Q[], int start, int mid, int end)
{
	//TODO: gives 0-> m+1 ==> n1 = m - l + 1;
	//TODO: gives m+1-> end ==>  r - m;
	int i = start, j = mid + 1, k = start/*keep track of overall array index which is resultant array*/;
	int b[] = {0};

	//TODO: Swap to use single array

	while(i<=mid && j<=end) {
		/* this loop will copy only elements from first and second half but 
		 * if there is a difference in length - it wont take care*/
		if(Q[i] <= Q[j]) {
			b[k] = Q[i];
			i++;
		} else {
			b[k] = Q[j];
			j++;
		}
		k++;
	}
	if(i>mid) { // 2nd half array has more values than first half
		while(j<=end) {
			b[k] = Q[j];
			j++;
			k++;
		}
	} else { // 1st half array has more values than second half
		while(i<=mid) {
			b[k] = Q[i];
			i++;
			k++;
		}
	}

	for(i=0; i<k; i++)
		Q[i] = b[i];
}

void merge_both_halves_sort1(int arr[], int l, int m, int r)
{
	int i, j, k;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void display(int Q[], int size)
{
	int i;

	for(i=0;i<=size;i++)
		printf("%d\t",Q[i]);
}

void MSort(int Q[], int start, int size)
{
	if(start < size) {
		int m = (start + size)/2;

		//if(m == 0)
		//	return;

		MSort(Q, start, m);
		MSort(Q, m+1, size);
		merge_both_halves_sort(Q, start, m, size);
	}
}

int main(int argc, char *argv[])
{
	if(argc!=2) {
		fprintf(stderr, "./a.out [array size] - %d\n", argc);
		exit(-1);
	}

	int ch, count = atoi(argv[1]), Q[count];

	while(1) {
		printf("Enter the choice: 1.sort 2.display 3. exit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the values:\n");
				int i;
				for(i=0;i<count;i++)
					scanf("%d", &Q[i]);
				MSort(Q, 0, count-1);
				break;
			case 2:
				display(Q, count-1);
				break;
			case 3:
				break;	
			default:
				break;
		};
	}
}


