#include <stdio.h>
#include <stdbool.h>

int main()
{
	int a[6] = {4,5,1,3,2,3}, i = 0, j, n, swp, count = 0, lastoff = 0, maxoff = 0;
	//int a[6] = {1, 2, 3, 4, 5, 6}, i = 0, j, n, swp, count = 0, lastoff = 0, maxoff = 0;
	bool swapped;
	n = sizeof(a)/sizeof(int);

	for (i=0; i<n; i++) {
		lastoff = n-i;
		//findmaxoffset here
		for(j=0; j<=lastoff; j++) {
			//maxoff will update if the number is lessthan subsequent number in the array
			if(a[maxoff] < a[j])
				maxoff = j;
		}
		swp = a[maxoff];
		a[maxoff] = a[lastoff];
		a[lastoff] = swp;
		maxoff = 0;
	}

	for (i=0; i<n; i++)
		printf(" %d", a[i]);

	return 0;
}
