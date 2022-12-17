#include <stdio.h>

#define NUM 5

int main()
{
	int a[NUM], num, temp = 0, i=0, j=0;

	printf("Enter the array size: ");
	scanf("%d", &num);

	for(i=0;i<num; i++)
		scanf("%d", &a[i]);

	//index values are interchanging with j offsets
	//j is going left, and i is going right.

	for(i=0; i<num; i++) {
		for(j=i+1; j>0; j--) {
			if(a[j-1] > a[j]) {
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			} else
				break;
		}
	}

	printf("\n Sorted Values are: \t");

	for(i=0;i<num; i++)
		printf("%d ", a[i]);

	return 0;
}
