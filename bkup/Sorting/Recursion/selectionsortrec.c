#include<stdio.h>

void swap(int *src, int *dest)
{
	int temp = *src;
	*src = *dest;
	*dest = temp;
}

void recpattern(int a[], int r, int c, int max)
{
	if(r==0)
		return;

	if(c < r) {
		if(a[c] > a[max])
			max = c;
		recpattern(a, r, c+1, max);
	} else {
		if(a[r] < a[max]) // I dont know why this required but we are getting one extra swap because of this change
			swap(&a[r], &a[max]);
		recpattern(a, r-1, 0, 0);
	}
}

int main()
{
	int i, j, m = 4, n = 4;

	printf("numelements: \n");
	scanf("%d",&n);
	
	int a[n];

	printf("enter the elements:\n");
	
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

#if 0
	for(j=0;j<m;j++) {
		for(i=m-j;i>0;i--) {
			printf("*");
		}
		printf("\n");
	}
#endif

	recpattern(a, n-1, 0, 0);

	printf("Sorted: {");
	for(i=0;i<n;i++)
		printf("%d,", a[i]);
	printf("}\n");

	printf("\n");

	return 0;
}
