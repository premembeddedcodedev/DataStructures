#include <stdio.h>
#include <stdbool.h>

bool is_badversion(int a[], int pos)
{
	if(a[pos] == 0)
		return true;
	else
		return false;
}

int main()
{
	int a[10] = {1,1,1,0,0,0}, low = 0, mid, high = 6;

	while(low <=high) {
		mid = (low + high)/2;
		
		if(is_badversion(a, mid))
			high = mid - 1;
		else
			low = mid + 1;
	}

	printf("mid : %d\n", mid);	

	return 0;
}
