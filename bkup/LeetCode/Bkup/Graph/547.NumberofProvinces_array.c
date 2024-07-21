#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int visited[MAX];

void dfs(int isConnected[][10], int offset, int *cols)
{
	visited[offset] = 1;

	printf(" %d", offset);
	
	for(int i =0; i<cols[offset]; i++) {
		if(visited[isConnected[offset][i]] == 0)
			dfs(isConnected, isConnected[offset][i], cols);
	}
}

int main()
{
	int zeros, rows, col=3, isConnected[10][10], colsize[10];

	printf("You want to start from zero ?\n");
	scanf("%d", &zeros);

	printf("Enter the Rows \n");
	scanf("%d", &rows);

	for(int i = zeros; i<rows+zeros; i++) {
		printf("Enter the %d offset coloumn size and links \n", i);
		scanf("%d", &colsize[i]);
		int temp = colsize[i] - 1;
		while(temp >= 0)
			scanf("%d", &isConnected[i][temp--]);
	}
	
	memset(visited, 0, sizeof(visited)/sizeof(int));

	printf("DFS Traversal is as follows: \n");
	for(int i=zeros; i<rows+zeros; i++) {
		if(visited[i] == 0) {
			printf("Provinces %d : ",  i);
			dfs(isConnected, i, colsize);
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}
