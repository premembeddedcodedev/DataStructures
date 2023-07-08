#include<stdio.h>

void swap(int *src, int *dest)
{
	int temp = *src;
	*src = *dest;
	*dest = temp;
}

void recpattern(int a[], int r, int c)
{
	if(r==0)
		return;

	if(c < r) {
		if(a[r] < a[c])
			swap(&a[r], &a[c]);	
		recpattern(a, r, c+1);
	} else {
		recpattern(a, r-1, 0);
	}
}

int main()
{
	int i, j, m = 4, n = 4, a[5] = {5, 4,3,2,1};
#if 0
	for(j=0;j<m;j++) {
		for(i=m-j;i>0;i--) {
			printf("*");
		}
		printf("\n");
	}
#endif

	recpattern(a, 4, 0);

	printf("Sorted: {");
	for(i=0;i<5;i++)
		printf("%d,", a[i]);
	printf("}\n");

	printf("\n");

	return 0;
}
