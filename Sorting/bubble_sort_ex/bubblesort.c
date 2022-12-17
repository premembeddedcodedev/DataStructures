#include <stdio.h>
#include <stdbool.h>

int main()
{
	int a[6] = {4,5,1,3,2,3}, i = 0, j, n, swp, count = 0;
	//int a[6] = {1,2,3,4,5, 6}, i = 0, j, n, swp, count = 0;
	bool swapped;
	n = sizeof(a)/sizeof(int);

	for (i=0; i<n; i++) {
		//Maintaining because to get best case time complexity when we get sorted array as input
		swapped = false;
		//Maintaining j < n-i-1 to not to cover which is at last because its sorted already.
		for(j=0; j<n-i-1; j++) { 
			if(a[j+1] < a[j]) {
				swp = a[j+1];
				a[j+1] = a[j];
				a[j] = swp;
				swapped = true;
			}
			count++;
		}
		if(!swapped) {
			printf("No Swap: So given sorted array: %d\n", count);
			break;
		}
	}
	
	for (i=0; i<n; i++)
		printf(" %d", a[i]);

	return 0;
}
