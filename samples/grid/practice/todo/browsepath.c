#include<stdio.h>
#include<limits.h>

#define COL 10
#define ROW 10

#define MIN(a,b) (((a)>(b))?(a):(b))

int minpathsum(int matrix[][COL], int i, int j, int m, int n)
{
	int sum = 0, rs = 0, cs = 0;
	
	if((i == m-1) && (j == n-1))
		return matrix[i][j];

	if(i == m-1)
		return matrix[i][j] + minpathsum(matrix, i, j+1, m, n);
		
	else if(j == n - 1)
		return matrix[i][j] + minpathsum(matrix, i+1, j, m, n);
	
	else
		return matrix[i][j] + MIN(minpathsum(matrix, i+1, j, m, n), minpathsum(matrix, i, j+1, m, n));
}

int main()
{
	//int matrix[3][4] = {{11,12,13,14}, {15,16,17,18}, {19,20,21,22}};
	//int matrix[3][3] = {{1,3,1}, {1,5,1}, {4,2,1}};
	//int matrix[2][3] = {{1,2,3}, {4,5,6}};
	int matrix[COL][ROW];
	int row, col;

	printf("Enter the col and rows\n");
	scanf("%d %d", &row, &col);

	printf("array values: ");

	for(int i = 0; i<row; i++) {
		for(int j = 0; j < col; j++)
			scanf("%d", &matrix[i][j]);
	}

	printf("minpath sum: %d", minpathsum(matrix, 0, 0, row, col));

	return 0;
}
