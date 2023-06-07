#include <stdio.h>

#define MAX_R 4
#define MAX_C 5
#if 0
void scan_process(int a[][MAX_C], int x, int y, int r, int c)
{
	if(x<0 || x>=r || y<0 || y>=c || a[x][y] != 1) {
		printf("\t\t exit: x: %d, y:%d r:%d, c:%d\n", x, y, r, c);
		return;
	}

	a[x][y] = 2;

	printf("C: x: %d, y: %d\n", x, y);
	//down
	scan_process(a, x+1, y, r, c); 
	printf("Dexit: x: %d, y: %d\n", x, y);
	//right
	scan_process(a, x, y+1, r, c); 
	printf("Rexit: x: %d, y: %d\n", x, y);
	//top
	scan_process(a, x-1, y, r, c);
	printf("Texit: x: %d, y: %d\n", x, y);
	//left
	scan_process(a, x, y-1, r, c);
	printf("Lexit: x: %d, y: %d\n", x, y);
}
#else
void scan_process(int a[][MAX_C], int x, int y, int r, int c)
{
                if((x - 1) >= 0) {
                        if(a[(x)-1][y] == 1) {
                                x = x - 1;
                                y = y;
                                a[x][y] = 2;
                        }
                }

                if(((y) - 1) >= 0) {
                        if(a[x][(y) - 1] == 1) {
                                x = x;
                                y = y - 1;
                                a[x][y] = 2;
                        }
                }

                if(((x) + 1) <= MAX_C) {
                        if(a[(x)+1][y] == 1) {
                                x = x + 1;
                                y = y;
                                a[x][y] = 2;
                        }
                }

                if(((y) + 1) <= MAX_C) {
                        if(a[x][(y)+1] == 1) {
                                x = x;
                                y = y + 1;
                                a[x][y] = 2;
                        }
                }

}
#endif
int bfs_to_find_islands(int a[][MAX_C], int r, int c)
{
	int num_islands = 0, i, j;

	if(r == 0)
		return 0;
	
	for(i = 0; i<MAX_R; i++) {
		for(j=0; j<MAX_C; j++) {
			if(a[i][j] == 1) {
				scan_process(a, i, j, MAX_R, MAX_C);
				num_islands += 1;	
			}
		}
		printf("\n");
	}

	return num_islands;	
}

int main()
{
	//int a[MAX_R][MAX_C] = {{1,1,1,1,0}, {1,1,0,1,0}, {1,1,0,0,0}, {0,0,0,0,0}};	
	int a[MAX_R][MAX_C] = {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,1}};	
	int i=0, j;
	
	printf("Before: \n");
	for(i = 0; i<MAX_R; i++) {
		for(j=0; j<MAX_C; j++)
			printf("%d->", a[i][j]);
		printf("\n");
	}

	printf("No.of Islands : %d\n", bfs_to_find_islands(a, MAX_R, MAX_C));

	printf("After: \n");
	for(i = 0; i<MAX_R; i++) {
		for(j=0; j<MAX_C; j++)
			printf("%d->", a[i][j]);
		printf("\n");
	}

	return 0;
}
