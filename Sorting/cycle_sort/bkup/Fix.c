// o(n) and o(1)
#include <stdio.h>

void display(int C[], int array_bound)
{
	int  i;

	for(i=0; i<array_bound; i++)
		printf("%d\t", C[i]);

	printf("\n");
}

void swap(int *dest, int *src)
{
	int temp = *dest;
	*dest = *src;
	*src = temp;
}

void cycle_sort_original(int C[], int array_bound, int offset)
{
	int i = 0, correct = 0;


	while(i<array_bound) {
		//0 indexed elements - value starts from 0
		if(offset == 0)
			correct = C[i];
		else // 1 indexed element - values starts from 1
			correct = C[i] - 1;
	
		//2nd condition in if: if the array element is exceeds the array bound will lead to segfault
		if(C[i] != C[correct] && C[i] < array_bound)
			swap(&C[i], &C[correct]);
		else
			i++;
	}


}
//FIX: Need to fix below code -- if swap happens we are not checking the swapped number in current index is in proper position or not
//if you go for swap again below for loop will increment the i so do with while
void cycle_sort(int C[], int array_bound, int offset)
{
	int temp = 0, i;

	for(i=0; i<array_bound; i++) {
		if(offset == 1) {
			if(C[i] != i-1 && C[i] < array_bound) {
				swap(&C[i], &C[temp]);
			}
		} else {
			if(C[i] != i && C[i] < array_bound) {
				swap(&C[i], &C[temp]);
			}
		}
	}
}

int main()
{
	int array_bound;

	printf("Enter the array bound : \n");
	scanf("%d", &array_bound);
	int C[array_bound], i;
	int offset;

	printf("Enter the  Array Elements: \n");
	for(i=0;i<array_bound;i++)
		scanf("%d",&C[i]);

	printf("offset starts from : \n");
	scanf("%d", &offset);
	
	display(C, array_bound);

	//cycle_sort_original(C, array_bound, offset);
	cycle_sort(C, array_bound, offset);

	display(C, array_bound);

	return 0;
}	
