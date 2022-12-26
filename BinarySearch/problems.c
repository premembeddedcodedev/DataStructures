#include "logic.h"

int main(int argc, char *argv[])
{
	printf("1-arg. selection of input\n");
	printf("2-arg. max array\n");

	if(argc!=4) {
		fprintf(stderr, "./a.out needs parameter %d\n", argc);
		exit(-1);
	}
	/* a.out will be argv[0] so skipped*/
	
	printf("selection: %d\n", atoi(argv[1]));

	int i, max_array, num = atoi(argv[1]);
	max_array = atoi(argv[2]);
	int a[max_array];

	printf("Enter %d array elements\n", max_array);
	for(i=0; i<max_array; i++)
		scanf("%d", &a[i]);

	while(1) {
		switch(num) {
			case 1: // em, s once number dont find by bs algo during searching of given number is not found
				printf("Enter the ceiling target: %d\n", atoi(argv[3]));
				int ceil_target = atoi(argv[3]);
				printf("Ceil Found: %d\n",find_ceiling_number(a, ceil_target, max_array));
				break;
			case 2: // em, s once number dont find by bs algo during searching of given number is not found
				printf("Enter the floor target: %d\n", atoi(argv[3]));
				int floor_target = atoi(argv[3]);
				printf("Floor Found: %d\n",find_flooring_number(a, floor_target, max_array));
				break;
			case 3: //Leet code : 744 - same as case 1 
				printf("Enter the floor target: %d\n", atoi(argv[3]));
				int wrap_target = atoi(argv[3]);
				printf("Wrap Found: %d\n",find_ceil_wrap_number(a, wrap_target, max_array));
				break;
			case 4: //Leet code : 34 - same as case 1 
				printf("Enter the firstandlast target: %d\n", atoi(argv[3]));
				int target = atoi(argv[3]);
				int result[2] = {-1, -1};;
				//search for left variables
				result[0] = findfistandlast(a, target, max_array, true);
				if(result[0] != -1) //search for right variables
					result[1] = findfistandlast(a, target, max_array, false);
				
				printf("firstandlast Found: %d-%d\n",result[0], result[1]);
				break;
			case 5: //Infinite array 
				printf("Enter the infinite value to search: %d\n", atoi(argv[3]));
				int infi_target = atoi(argv[3]);
				printf("infi Found: %d\n",findvalue_infinitearray(a, infi_target));
				break;
			case 6: //852 
				printf("Enter the peak value to search: %d\n", atoi(argv[3]));
				int peak_index = atoi(argv[3]);
				printf("peak Found: %d\n", findpeak(a, max_array));
				break;
			case 7: //1095
				printf("Enter the mountain array value to search: %d\n", atoi(argv[3]));
				int peak_element = atoi(argv[3]);
				printf("peak Found: %d\n", order_agnosticarray(a, peak_element, max_array));
				break;

			default:
				break;
		};
		num = 0;	
	}

	return 0;
}
