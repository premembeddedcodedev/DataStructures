#include<stdio.h>
#include<limits.h>

#define MAX 10

#define max(a,b) a > b ? a : b
#define min(a,b) a < b ? a : b


int find_min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

# if 0
int maxpathsum(int a[][MAX], int roff, int coff, int rows, int cols)
{
	if((roff < 0) || (roff >= rows))
		return 0;
	
	if((coff < 0) || (coff >= cols))
		return 0;

	
	return  a[roff][coff] + maxpathsum(a, roff, coff + 1, rows, cols) + maxpathsum(a, roff + 1, coff, rows, cols);
}

int maxpathsum(int a[][MAX], int roff, int coff, int rows, int cols)
{
        if((roff < 0) || (roff >= rows))
                return 0;

        if((coff < 0) || (coff >= cols))
                return 0;

        int up = a[roff][coff] + maxpathsum(a, roff + 1, coff, rows, cols);
	int down = a[roff][coff] + maxpathsum(a, roff, coff+1, rows, cols);

	return max(up, down);
}

int minpathsum(int a[][MAX], int rows, int cols)
{
        if((rows == 0) && (cols == 0))
		return a[rows][cols];

        if((rows < 0) || (cols < 0))
		return INT_MAX;

        int up = a[rows][cols] + minpathsum(a, rows-1, cols);
        int down = a[rows][cols] + minpathsum(a, rows, cols-1);

        return min(up, down);
}

int path2sum(int a[][MAX], int rows, int cols)
{
//	if(rows == 0 || cols == 0)
//		return 1;

        if((rows < 0) || (cols < 0))
                return 0;

        int up = minpathsum(a, rows, cols-1) + minpathsum(a, rows-1, cols);

        return up;
}

int dp_pathsum(int a[][MAX], int dp[][MAX], int rows, int cols)
{
	for(int i = rows-1; i>=0; i--) {
		for(int j = cols-1; j>=0; j--) {
			if((i == rows-1) || (j != cols-1))
				dp[i][j] = a[i][j] + dp[i][j+1];
			else if(j == cols-1 || (i != rows-1))
				dp[i][j] = a[i][j] + dp[i+1][j];
			else if((i != rows-1) && (j!=cols-1))
				dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i][j+1]);
			else
				dp[i][j] = a[i][j];
		}
	}

	return dp[0][0];
}
#endif

int memopathsum(int a[][MAX], int dp[][MAX], int rows, int cols, int max_rows, int max_cols)
{
        if((rows == max_rows) && (cols == max_cols))
                return a[rows][cols];

        if((rows > max_rows) || (cols > max_cols))
                return INT_MAX;

        if(dp[rows][cols] != 0)
                return dp[rows][cols];

        int side = memopathsum(a, dp, rows, cols+1, max_rows, max_cols);
        int down = memopathsum(a, dp, rows+1, cols, max_rows, max_cols);

        dp[rows][cols] = a[rows][cols] + find_min(side, down);

        return a[rows][cols] + find_min(side, down);
}

int recpathsum(int a[][MAX], int rows, int cols, int max_rows, int max_cols)
{
        if((rows == max_rows) && (cols == max_cols))
                return a[rows][cols];

        if((rows > max_rows) || (cols > max_cols))
                return INT_MAX;

        int side = recpathsum(a, rows, cols+1, max_rows, max_cols);
        int down = recpathsum(a, rows+1, cols, max_rows, max_cols);

	return a[rows][cols] + find_min(side, down);
}

int main()
{
	int a[MAX][MAX], rows = 0, cols = 0;

	printf("Enter the rows: \n");
	scanf("%d", &rows);

	printf("Enter the cols: \n");
	scanf("%d", &cols);


	for(int i = 0; i<rows; i++) {
		for(int j=0; j<cols; j++)
			scanf("%d,", &a[i][j]);
	}
	
	for(int i = 0; i<rows; i++) {
		printf("{");
		for(int j=0; j<cols; j++)
			printf("%d,", a[i][j]);
		printf("}\n");
	}

	printf("\n");

	int dp[MAX][MAX] = {0};

	printf("memo: min path sum: %d\n", memopathsum(a, dp, 0, 0, rows-1, cols-1));
	printf("rec: min path sum: %d\n", recpathsum(a, 0, 0, rows-1, cols-1));

	return 0;
}
