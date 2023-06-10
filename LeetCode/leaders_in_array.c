#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int main()
{
	int array_size;

	printf("enter array size: \n");
	scanf("%d", &array_size);

	int a[array_size], i, j;
	bool leader = true;
	
	printf("enter the array values: \n");
	for(i=0;i<array_size; i++)
		scanf("%d",&a[i]);
	
	
#if 0
	for(i=0;i<array_size; i++) {
		leader = true;
		for(j=i+1; j<array_size; j++) {
			if(a[i] < a[j]) {
				leader = false;	
			}
		}
		if(leader == true)
			printf("%d,", a[i]);
	}
#endif
	int max = INT_MIN;

	for(i=array_size-1;i>=0; i--) {
		if(a[i] > max) {
			max = a[i];
			printf("%d->", max);
		}
	}
		
	printf("\n");
	return 0;
}
