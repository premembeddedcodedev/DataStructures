#include <stdio.h>
#include <stdbool.h>

#define BETTER

bool linearsearch(int a[], int n, int val)
{
	for(int i=0; i<n; i++) {
		if(a[i] == val)
			return true;
	
	}
	
	return false;
}

void swap(int *src, int *dst)
{
	int temp = *src;
	*src = *dst;
	*dst = temp;
}

void insertion_sort(int a[], int array_bound)
{
	int i, j;

	for(i=1;i<=array_bound; i++) {
		for(j=0; j<=i; j++) {
			if(a[j] > a[i])
				swap(&a[j], &a[i]);
		}
	}
}

int main()
{
        int array_size;

        printf("enter array size: \n");
        scanf("%d", &array_size);

        int a[array_size], i, j, count = 1, x = 0;

        printf("enter the array values: \n");
        for(i=0;i<array_size; i++)
                scanf("%d",&a[i]);

#ifdef BRUTE_FORCE
	for(i=0; i<array_size; i++) {
		x = a[i];
		count = 1;

		while(linearsearch(a, array_size, x+1) == true)
		{
			x = x + 1;
			count += 1;
		}
	}	
#endif
	
#ifdef BETTER
	insertion_sort(a, array_size);
	for(i=0; i<array_size; i++)
		printf("%d->", a[i]);
	
	x = 0;
	int diff = 0;

	for(i=1; i<array_size; i++) {
		if(a[i] == a[i-1])
			continue;
		else if(a[i]-1 == a[i-1]) {
			count += 1;
			if(x < count)
				x = count;	
		} else {
			diff++;
			//TODO: need to see how to keep other values:
			count = 1;
		}
	}

	if(diff > 0)
		count = x;

#endif

	printf("\n %d", count);

	printf("\n");
	
	return 0;
}
