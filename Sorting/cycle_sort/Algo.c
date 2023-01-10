#include "Algo.h"
//TODO: why cant we move swap to header file
void pswap(int *dest, int *src)
{
	int temp = *dest;
	*dest = *src;
	*src = temp;
}

int main(int argc, char *argv[])
{
	printf("Cycle Sort Algo: \n");

	if(argc!=2) {
		fprintf(stderr, "algo requires inputs as %d values i.e \n", argc);
		exit(-1);
	}

	int ch;
	while(1) {
		printf("select the problem: 1. 268. Missing Number \n");
		scanf("%d", &ch);

		int array_bound, i;
		printf("Enter the array bound \n");
		scanf("%d", &array_bound);
		int C[array_bound];
		printf("Enter the array values \n");
		for(i=0;i<array_bound;i++)
			scanf("%d", &C[i]);
		switch(ch) {
			case 1:
				printf("missedvalue = %d\n",missingNumber(C, array_bound));
				break;
			default:
				break;
		};
	}


	return 0;
}
