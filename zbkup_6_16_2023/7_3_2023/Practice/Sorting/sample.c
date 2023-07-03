#include <stdio.h>
#include <stdlib.h>

void display(int (*a)[3], int row, int col)
{
	printf("Arrays are as follows: \n");
	for(int i=0; i<row; i++) {
		printf("a[%d] : {", i);
		for(int j=0; j<col; j++) {
			printf("%d->", a[i][j]);
		}
		printf("}\n");
	}
}

void sort(int (*a)[3], int row, int col)
{
	int i = 0, j = 1, temp = 0;
	printf("Arrays are as follows: \n");
	//TODO: Need to see array sizes are in different lengths

	while(i < row) {
		int length = sizeof((*a)[i]) > sizeof((*a)[i+1]) ? sizeof((*a)[i]) : sizeof((*a)[i+1]);
		printf("length Address: %p, valus: %d", &length, length); //need to see every time same address or different address
		while(j < length-1) {
			int temp = a[i][col-1];
			
		}
		i = i+2;
	}
}

void check(int (*a)[3], int row, int col)
{
	int j;
	
	for(int i= col-1; i>=0; i--) {
		printf("length Address: %p, valus: %d\n", &j, j); //need to see every time same address or different address
		int last = a[0][col-1];
		for(j=col-2;j>=0 && (a[0][j] > a[1][i]);j--)
			a[0][j+1] = a[0][j];
		if(j!=col-2 || last > a[1][i]) {
			a[0][j+1] = a[1][i];
			a[1][i] = last;
		}
	}
}

int main()
{
	int row, col;
	printf("Enter the array bound\n");
	scanf("%d%d", &row, &col);	
	int a[row][col];

	printf("Fill the aarrays: \n");
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	display(a, row, col);

	check(a, row, col);

	display(a, row, col);

	return 0 ;
}
