#include<stdio.h>
#include <limits.h>

#define  ARRAY_SIZE 10
#define KADANES_ALGO 

int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}, i, j, k;

#ifdef BRUTE_FORCE //just to print sub arrays
	for(i=0; i<sizeof(a)/sizeof(int); i++) {
		printf("\n%d offset values: \n", i);
		for(j=i; j<sizeof(a)/sizeof(int); j++) {
			for(k=i;k<j;k++)
				printf("%d, ", a[k]);
			printf("\n");
		}
	}
#endif

#ifdef ON2_APPROACH
	int sum = 0;
	for(i=0; i<sizeof(a)/sizeof(int); i++) {
		printf("\n%d offset values: \n", i);
		sum = 0;
		for(j=i; j<sizeof(a)/sizeof(int); j++) {
			sum += a[j];
			printf("%d, ", sum);
		}
		printf("\n");
	}
#endif

#ifdef KADANES_ALGO
	int sum = 0, max = INT_MIN;
	for(i=0; i<sizeof(a)/sizeof(int); i++) {
		sum += a[i];
		if(sum < 0) {
			sum = 0;	
		} else {
			if(max < sum)
				max = sum;
		}
	}

	printf("max = %d\n", max);
#endif
	return 0;
}
