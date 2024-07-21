#include<stdio.h>
#include<limits.h>

int calcnumhrs(int piles[], int n, int pile)
{
	int total = 0, check = 0;

	printf("cal:");
	for(int i = 0; i<n; i++) {
		check = (int)(piles[i]/pile);
		printf("%d,", check);
		total += (int)(piles[i]/pile);
	}
	printf("\n");

	return total;
}

int kokobananas(int piles[], int pilesSize, int hours)
{
	int max_piles = 0, min_piles = INT_MAX;

	for(int i = 0; i<pilesSize; i++) {
		if(max_piles < piles[i])
			max_piles = piles[i];
		if(min_piles > piles[i])
			min_piles = piles[i];
	}

	printf("Max: %d, Min:%d\n", max_piles, min_piles);

	int start = 1, end = max_piles;

	while(start <= end) {
		int mid = (end + start)/2;
		printf("mid: %d, ", mid);
		int numhrs = calcnumhrs(piles, pilesSize, mid);
		printf("%d, ", numhrs);
		if(numhrs <= hours) {
			printf("end change\n");
			end = mid - 1;
		} else {
			printf("start change\n");
			start = mid + 1;
		}
	}

	return start;
}

int main()
{
	//int piles[] = {3, 6, 2, 8}, hours = 5;
	int piles[] = {3, 6, 7, 11}, hours = 8;

	printf("k = %d\n", kokobananas(piles, sizeof(piles)/sizeof(int), hours));

	return 0;
}
