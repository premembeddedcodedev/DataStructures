#include <stdio.h>
#include <stdbool.h>

#define NUM 8

void sort_offsets(int a[], int num, bool yes)
{
	int correct = 0, i = 0, temp;

	while(i<num){
		correct = a[i] - 1;
		if(a[i] != a[correct]) {
			temp = a[correct];
			a[correct] = a[i];
			a[i] = temp;
		} else
			i++;
	}
}

void disappered_offsets(int a[], int num, bool yes)
{
	int correct = 0, i = 0, temp;
	
	sort_offsets(a, num, true);

	i = 0;
	printf("missing offsets are : \t");
	while(i<num){
		correct = i+1;
		if(a[i] != correct)
			printf("%d \t", i+1);
		i++;
	}
}

void missed_offsets(int a[], int num, bool yes)
{
	int correct = 0, i = 0, temp;
	
	sort_offsets(a, num, true);

	i = 0;
	printf("missing offsets are : \t");
	while(i<num){
		correct = i+1;
		if(a[i] != correct)
			printf("%d \t", i+1);
		i++;
	}
}

int main()
{
	int a[NUM] = {4,3,2,7,8,2,3,1}, num=8, temp = 0, i=0, j=0;
//	int a[NUM] = {4,0,2, 1}, num=8, temp = 0, i=0, j=0;

	//printf("Enter the array size: ");
	//scanf("%d", &num);
	for(i=0;i<num; i++)
		printf("%d ", a[i]);
	
	printf("\n");

	/*	for(i=0;i<num; i++)
		scanf("%d", &a[i]);
		*/	
	disappered_offsets(a, sizeof(a)/sizeof(int), false);
	// 268. missing number
//	missed_offsets(a, 4, true);

	printf("\n Sorted Values are: \t");

	for(i=0;i<num; i++)
		printf("%d ", a[i]);

	return 0;
}
