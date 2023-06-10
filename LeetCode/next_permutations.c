#include <stdio.h>
#include <limits.h>
int sort(int a[], int index, int n)
{
	int i, j, temp, min;

	for(i=index;i<n;i++) {
		min = a[i];
		for(j=i+1; j<n; j++) {
			if(min > a[j]) {
				temp = a[j];
				a[j] = min;
				min = temp;		
			}
		}
		a[i] = min;
	}
}

int main()
{
	//int a[] = {2, 1, 5, 4, 3, 0, 0}, n = sizeof(a)/sizeof(int);
	int a[] = {3,2,1}, n = sizeof(a)/sizeof(int);
	//int a[] = {1,2,3,6,5,4}, n = sizeof(a)/sizeof(int);
	int i, j, index = -1;

#if 1
	for(i=n-2; i>=0; i--) {
		if(a[i] < a[i+1]) {
			index = i;
			break;	
		}
	}

	printf("index : %d\n", index);

	if(index == -1)
		sort(a, 0, n);
#endif
	int max = a[index], temp = 0, min = INT_MAX, lb, ub;
#if 0

	for(i=n-1; i>=index;i++) {
		if(a[i] > a[index]) {
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
			break;	
		}
	}
#endif
//		if(a[i] == 0)
//			continue;
#if 1
	for(i=index+1; i<n; i++) {

		if(min > a[i]) {

			if(a[i] > a[index]) {
				lb = i;
				min = a[i];
			}
		}

	}

	temp = min;;
	a[lb] = a[index];
	a[index] = temp;
#endif

	sort(a, index+1, n);

	for(i=0;i<n;i++)
		printf("%d->", a[i]);

	return 0;
}

