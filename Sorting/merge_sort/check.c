#include <stdio.h> 

// Merge ar1[] and ar2[] with O(1) extra space 
void merge(int ar1[], int ar2[], int m, int n) 
{ 
	// Iterate through all elements of ar2[] starting from 
	// the last element 
	for (int i=n-1; i>=0; i--) 
	{ 
		/* Find the smallest element greater than ar2[i]. Move all 
		   elements one position ahead till the smallest greater 
		   element is not found */
		int j, last = ar1[m-1]; 
		for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
		// TODO: enabling below has some issue
		// for (j=m-2; j >= 0; --j) 
		//	if(ar1[j] > ar2[i]) 
				ar1[j+1] = ar1[j]; 

		// If there was a greater element 
		if (j != m-2 || last > ar2[i]) 
		{ 
			ar1[j+1] = ar2[i]; 
			ar2[i] = last; 
		} 
	} 
} 

// Driver program 
int main(void) 
{ 
#if 0
	int array_bound, ab2;
	printf("Enter the 1 array bound\n");
	scanf("%d", &array_bound);
	int a[array_bound], b[ab2];

	printf("Enter the 1 array lasts: \n");
	for(int i=0; i<array_bound; i++)
		scanf("%d", &a[i]);

	printf("Enter the 2 array bound\n");
	scanf("%d", &ab2);
	printf("Enter the 2 array lasts: \n");
	for(int i=0; i<ab2; i++)
		scanf("%d", &b[i]);
#else
	int a[] = {1, 5, 9, 10, 15, 20}; 
	int b[] = {2, 3, 8, 13}; 
	int array_bound = sizeof(a)/sizeof(a[0]); 
	int ab2 = sizeof(b)/sizeof(b[0]); 
#endif

	printf("a size : %d\n", array_bound);
	printf("b size : %d\n", ab2);

	merge(a, b, array_bound, ab2); 
	printf("\nAfter Merging nFirst Array: \n"); 
	for (int i=0; i<array_bound; i++) 
		printf("%d\t", a[i]);
	
	printf("\n Second Array: \n");
	for (int i=0; i<ab2; i++) 
		printf("%d\t", b[i]); 

	printf("\n");

	return 0; 
} 
