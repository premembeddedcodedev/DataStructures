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
void cycle_sort_first(int C[], int array_bound, int offset)
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

void duplicate_number(int C[], int array_bound, int offset)
{
	int temp = 0, i, miss_numbers[5], miss_off[5];

	while(i<array_bound) {
		if(offset == 1) { // value - 1 we are doing because we need to store the values from 0th offset
			temp = C[i] - 1;
			if(C[i] != C[temp] && ((C[i] < array_bound) || (C[temp] < array_bound)))
				swap(&C[i], &C[temp]);
			else
				i++;
		} else {
			temp = C[i];
			if(C[i] != C[temp] && ((C[i] < array_bound) || (C[temp] < array_bound)))
				swap(&C[i], &C[temp]);
			else
				i++;
		}
	}

	i = 0;
	int j = 0, k=0;

	for(i = 0; i<array_bound; i++) {
		if(C[i] != i+1) {
			printf("miss_number: %d, miss_off:%d\n", C[i], i);
			miss_numbers[j++] = C[i];
			miss_off[k++] = i;
		}
	}
}

void find_all_missing_numbers(int C[], int array_bound, int offset)
{
	int temp = 0, i, miss_numbers[5], miss_off[5];

	while(i<array_bound) {
		if(offset == 1) { // value - 1 we are doing because we need to store the values from 0th offset
			temp = C[i] - 1;
			if(C[i] != C[temp] && ((C[i] < array_bound) || (C[temp] < array_bound)))
				swap(&C[i], &C[temp]);
			else
				i++;
		} else {
			temp = C[i];
			if(C[i] != C[temp] && ((C[i] < array_bound) || (C[temp] < array_bound)))
				swap(&C[i], &C[temp]);
			else
				i++;
		}
	}

	i = 0;
	int j = 0, k=0;

	for(i = 0; i<array_bound; i++) {
		if(C[i] != i+1) {
			printf("miss_number: %d, miss_off:%d\n", C[i], i);
			miss_numbers[j++] = C[i];
			miss_off[k++] = i;
		}
	}
}

void first_missing_positive(int C[], int array_bound, int offset)
{
	int temp = 0, i, miss_numbers[5], miss_off[5];

	while(i<array_bound) {
		if(offset == 1) { // value - 1 we are doing because we need to store the values from 0th offset
			temp = C[i] - 1;
			if(C[i] > 0 &&C[i] != C[temp] && ((C[i] < array_bound) || (C[temp] < array_bound)))
				swap(&C[i], &C[temp]);
			else
				i++;
		} else {
			temp = C[i];
			if(C[i] != C[temp] && ((C[i] < array_bound) || (C[temp] < array_bound)))
				swap(&C[i], &C[temp]);
			else
				i++;
		}
	}

	i = 0;
	int j = 0, k=0;
	
	if(C[0] > array_bound) {
		printf("Value %d\n", 1);
		return;
	}


	for(i = 0; i<array_bound; i++) {
		if(C[i] != i+1) {
			printf("miss_number: %d, miss_off:%d\n", C[i], i+1);
			miss_numbers[j++] = C[i];
			miss_off[k++] = i;
		}
	}
}

void set_mismatch(int C[], int array_bound, int offset)
{
	int temp = 0, i, miss_numbers[5], miss_off[5];

	while(i<array_bound) {
		if(offset == 1) { // value - 1 we are doing because we need to store the values from 0th offset
			temp = C[i] - 1;
			if(C[i] != C[temp] && ((C[i] < array_bound) || (C[temp] < array_bound)))
				swap(&C[i], &C[temp]);
			else
				i++;
		} else {
			temp = C[i];
			if(C[i] != C[temp] && ((C[i] < array_bound) || (C[temp] < array_bound)))
				swap(&C[i], &C[temp]);
			else
				i++;
		}
	}

	i = 0;
	int j = 0, k=0;

	for(i = 0; i<array_bound; i++) {
		if(C[i] != i+1) {
			printf("miss_number: %d, miss_off:%d\n", C[i], i+1);
			miss_numbers[j++] = C[i];
			miss_off[k++] = i;
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
	//duplicate_number(C, array_bound, offset);
	//set_mismatch(C, array_bound, offset);
	first_missing_positive(C, array_bound, offset);

	display(C, array_bound);

	return 0;
}	
