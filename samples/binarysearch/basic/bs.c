#include<stdio.h>

int binary_search(int s[], int search, int lb, int ub)
{
	while(lb <= ub) {
		int mid = lb + (ub-lb)/2;
		if(s[mid] == search)
			return mid;
		if(s[mid] < search)
			lb = mid + 1;
		else	
			ub = mid - 1;
	}

	return -1;
}

int main()
{
	int bound;

	printf("Enter the bound\n");
	scanf("%d", &bound);
	int s[bound];

	printf("enter the values: \n");

	for(int i=0; i<bound; i++)
		scanf("%d", &s[i]);
		
	int find = 0;

	printf("enter element to search : \n");
	scanf("%d", &find);

	if(binary_search(s, find, 0, bound-1) == -1)
		printf("element not found\n");
	else
		printf("element found\n");

	return 0;
}
