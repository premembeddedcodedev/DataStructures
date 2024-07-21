#include<stdio.h>

int find_minsumfrommax(int a[], int n, int m)
{
	int low = 0, high = n, max = 0, sum = 0;

	for(int i = 0; i<n; i++) {
		max = max < a[i] ? a[i]: max;
		sum += a[i];
	}

	printf("max: %d, sum : %d\n", max, sum);

	int start = max, end = sum;

	while(start <= end) {
		int mid = start + (end-start)/2;
		int calcsum = 0, count = 1;
		for(int i = 0; i<n; i++) {
			if(calcsum+a[i] > mid) { 
				count++;
				calcsum = a[i];
			} else {
				calcsum += a[i];
			}		
		}
		if(count > m)
			start = mid + 1;
		else
			end = mid -1;
	}

	return start;
}

int main()
{
	int a[] = {7,2,5,8,10};

	printf("sum : %d\n", find_minsumfrommax(a, sizeof(a)/sizeof(int), 2));

	return 0;
}
