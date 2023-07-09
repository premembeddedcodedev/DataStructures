#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100

//uint32_t stack[MAX_STACK_SIZE];
//int check_offset = -1;

void display(uint32_t stack[], int stack_offset)
{
	uint8_t iteration = 0;

	printf("values are as follows : \n");

	for(iteration = 0; iteration <= stack_offset; iteration++)
		printf("%d -> ", stack[iteration]);

	printf("\n");
}

bool stack_empty(int offset_track)
{
	if(offset_track == -1)
		return true;
	else
		return false;
}

bool stack_full(int offset_track)
{
	if(offset_track+1 == MAX_STACK_SIZE)
		return true;
	else
		return false;
}

void push(uint32_t stack[], int new_val, int *offset_track)
{
	if(!stack_full(*offset_track)) {
		(*offset_track)++;
		stack[(*offset_track)] = new_val;
	} else
		printf("stack full...!!!!\n");
}

int pop(uint32_t stack[], int *offset_track)
{
	int temp;
	if(!stack_empty(*offset_track)) {
		temp = *offset_track;
		(*offset_track)--;
		//stack[temp] = 99;
		return stack[temp];
	} else {
		printf("Stack empty..!!!!\n");
		return -1;
	}
}

void removeKdigits(int array_val[], int k, int array_offset, int input_array_max)
{
	int stackoffset = -1;
	int kdigit[input_array_max];

	memset(kdigit, 0, sizeof(kdigit));
	while(!stack_full(stackoffset) && (array_offset < input_array_max)) {
		if(stackoffset == -1) {
			push(kdigit, array_val[array_offset], &stackoffset);
			array_offset++;
		} else {
			if (array_val[array_offset] == 0) {
				while(!stack_empty(stackoffset) && k > 0) {
					pop(kdigit, &stackoffset); // 0 is less - iterate reverse
					k--;
				}
				if(stackoffset != -1) // 1230987 --> k = 3 condition is wrong
					push(kdigit, array_val[array_offset], &stackoffset);
				array_offset++;
			} else if(kdigit[stackoffset] > array_val[array_offset]) {
				if(k > 0) {
					k--;
				} else {
					while(array_offset < input_array_max) {
						push(kdigit, array_val[array_offset], &stackoffset);
						array_offset++;
					}
					break;
				}
				pop(kdigit, &stackoffset); // offset value greater than upcoming
				//push(kdigit, array_val[array_offset], &stackoffset);
			} else {
				printf("stackoffset: %d\n", stackoffset);
				push(kdigit, array_val[array_offset], &stackoffset);
				array_offset++;
			}
		}
	}
	while(k!=0) {
		pop(kdigit, &stackoffset);
		k--;
	}	
//	printf("stackoffset = %d\n", stackoffset);
//	printf("array_offset = %d\n", array_offset);
	display(kdigit, stackoffset);
//	display(arr_val, &array_offset);
}

int main()
{
	int arr_max;

	printf("Enter the array size : \n");
	scanf("%d", &arr_max);

	int kdigit[arr_max];
	int i = 0, stackoffset = 0, k = 0;

	memset(kdigit, 0, sizeof(kdigit));

	printf("Enter Array elements: \n");
	for(i = 0; i<arr_max; i++)
		scanf("%d", &kdigit[i]);

	printf("selected Array elements are as follows: \n");
	for(i = 0; i<arr_max; i++)
		printf("%d->", kdigit[i]);

	printf("Enter the how many digits to remove ??\n");
	scanf("%d", &k);

	printf("removing K digits from the array\n");
	int offset = 0;
	removeKdigits(kdigit, k, offset, arr_max);

	return 0;
}

#if 0
int main()
{
	int ch, temp_val = 0;

	while(1) {
		printf("\n Enter the choice : \n \t 1.push \n\t 2.pop \n\t 3.display\n");
		scanf("%d", &ch);
		printf("\n");
		switch(ch) {
			case 1:
				printf("push the value : \n");
				scanf("%d", &temp_val);
				push(stack, temp_val);
				break;
			case 2:
				int temp = pop(stack);
				if(temp >= 0)
					printf("popped element: %d\n", temp);
				break;
			case 3:
				display(stack);
				break;
			default:
				break;
		}
	};

	return 0;
}
#endif
