#include <stdio.h>
#include <stdlib.h>
/*
 * 			-------------------------------------
 *delete from here <---front	|   1	|   2	|   3	|	rear---> Add from here
 *  			-------------------------------------
 * Conditions : 1. Full condition : rear reaches last and not deleting single element from front
 * 		2. rear is starting from size - 1 and front is just deleted one element rear + 1 = front
 * 		3. after emptying the array both  are in middle of the array like rear == front - keep them as -1st position
 * 		4. displaying would be checking like rear != front
 * 		5. display last element after rear!=front because rear=front we are not showing in the while loop
 */

#define MAXSIZE 5

int size = MAXSIZE;

int front = -1;
int rear = -1; //because of this condition we are incrementing the front and then store/pop

void display(int Q[])
{
	int i = front, j = rear;

	printf("\t\t\t\t Q Elements are : \n");

	if(front == -1 && rear == -1) { // TODO: front == rear == -1 is different from this instruction
		printf("\t\t\t\t Q is Empty\n");
		return;
	}

	while(i!=j) {
		printf("%d\t", Q[i]);
		i = (i+1) % size;	
	}
	printf("%d\n", Q[i]); //last element of the Q printing here
}

void dequeue(int Q[])
{
	if((front == -1 && rear == -1)) {
		printf("\t\t\t\tQ is Empty\n");
		return;	
	} else if(rear == front) {
	       printf("\t\t\t\t D'Qd Element : %d\n", Q[front]);
	       rear = front = -1;
	}	       
	else {
		printf("D'Qd Element : %d\n", Q[front]);
		if(front < size - 1)
			front++;
		else
			front = (front + 1) % size;
	}
}

void enqueue(int Q[], int data)
{
	if((front == 0 && rear == size -1) || ((rear + 1) == front)) {
		printf("\t\t\t\t Q is Full\n\n");
		return;
	} else if (front == -1 && rear == -1) {
		front = rear = 0;
	} else {
		if(rear < size - 1)
			rear++;
		else
			rear = (rear + 1) % size;

	}
	Q[rear] = data;
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "arguements are not matching ./a.out [size] [choice] %d", argc);
		return -1;
	}

	int ch, data;
	int arr_boundary = atoi(argv[1]), i;
	int Q[arr_boundary];

	while(1) {
		printf("Enter the choice : 1. enqueue 2.Dequeue 3.display 4.exit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				size = arr_boundary;
				printf("Enqueuing value \n");
				//for(i=0;i<arr_boundary;i++) {
					scanf("%d", &data);
					enqueue(Q, data);
				//}
				break;
			case 2:
				dequeue(Q);
				break;
			case 3:
				display(Q);
				break;
			default:
				break;
		}

	}

	return 0;
}

