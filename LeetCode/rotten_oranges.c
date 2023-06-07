
/*Reference : https://leetcode.com/problems/rotting-oranges
 *https://www.youtube.com/watch?v=CxrnOTUlNJE */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_R 1
#define MAX_C 2

struct list {
	int time;
	int x, y;
	struct list *next;
};

void dequeue(int Q[], int *front, int *rear, int size)
{
	if(*front == *rear) {
		printf("Underflow.. !! to reset, select 5\n");
	} else {
		(*front)++;
	}	
}

void display(int Q[], int *front, int *rear)
{
	int i = *front, j= *rear;

	printf("Queue values are : \t\t");

	while(i<=j)
		printf("%d->", Q[i++]);

	printf("\n");
}

void enqueue(int Q[], int size, int value, int *front, int *rear)
{
	if(*rear < (size - 1)) {
		if(*front == -1)
			*front = 0;
		(*rear)++;	
		Q[*rear] = value;
	} else
		printf("Overflow...!\n");
}

void display_q(struct list **head, struct list **front, struct list **rear)
{
	//struct list *temp = *head;
	struct list *temp = *front;

	printf("Q Linkedlist : \t\t");

	while (temp!=NULL) {
		printf("%d->", temp->x);
		temp = temp->next;	
	}
	printf("\n");
}

struct list *dequeue_front(struct list **head, struct list **front, struct list **rear, int size)
{
	struct list *temp;

	if(*front == NULL) {
		printf("Q list is empty\n");
		*head = NULL;
	} else if(*front == *rear) {
		temp = *front;
		*head = (*front)->next;
		*front = NULL;
		*rear = NULL;
	} else {
		temp = *front;
		*front = (*front)->next;
		*head = *front;
	}

	//free(temp);

	return temp;
}

void copy_nodes(struct list **dest, struct list *new)
{
	*dest = new;	
}

void enqueue_last(struct list **head, int size, int value, int value1, int time, struct list **front, struct list **rear)
{
	struct list *new = (struct list *)malloc(sizeof(struct list));
	if(!new)
		return;

	new->time = time;
	new->x = value;
	new->y = value1;
	new->next = NULL;

	printf("New Node: %p\t", new);

	if(!*front){
		copy_nodes(front, new);
		//*front = new;
	}

	if(!*rear) {
		*rear = new;
		*head = new;
	} else {
		//		while((*rear)->next != NULL) {
		//			*rear = (*rear)->next;
		//		}
		(*rear)->next = new;
		*rear = new;
		//if (*front == *rear) {
		//	printf("Queue List is FULL\n");
		//}
	}
}

void scan_process(int a[][MAX_C], struct list **head, struct list **front_ptr, struct list **rear_ptr, int *gtime, int count)
{
	int x, y, variable = 0;
	bool rotten = false;

	if(!(*front_ptr) || count == 0) {
		printf("Queue is empty, count : %d\n", count);
		return;
	}
	
	printf("gtime: %d, count : %d\n", *gtime, count);

	while(count > 0) {
		struct list *temp = dequeue_front(head, front_ptr, rear_ptr, 5);
		if(((temp->x) - 1) >= 0) {
			if(a[(temp->x)-1][temp->y] == 1) {
				x = temp->x - 1;
				y = temp->y;
				a[x][y] = 2;
				rotten = true;
				variable++;
				enqueue_last(head, 5, x, y, *gtime, front_ptr, rear_ptr);
				printf("x: %d\t, y:%d\n", x, y);
			}
		}

		if(((temp->y) - 1) >=0) {
			if(a[temp->x][(temp->y) - 1] == 1) {
				x = temp->x;
				y = temp->y - 1;
				a[x][y] = 2;
				rotten = true;
				variable++;
				enqueue_last(head, 5, x, y, *gtime, front_ptr, rear_ptr);
				printf("x: %d\t, y:%d\n", x, y);
			}
		} 

		if(((temp->x) + 1) < MAX_C) {
			if(a[(temp->x)+1][temp->y] == 1) {
				x = temp->x + 1;
				y = temp->y;	
				a[x][y] = 2;
				rotten = true;
				variable++;
				enqueue_last(head, 5, x, y, *gtime, front_ptr, rear_ptr);
				printf("x: %d\t, y:%d\n", x, y);
			}
		}

		if(((temp->y) + 1) < MAX_C) {
			if(a[temp->x][(temp->y)+1] == 1) {
				x = temp->x;
				y = temp->y + 1;	
				a[x][y] = 2;
				rotten = true;
				variable++;
				enqueue_last(head, 5, x, y, *gtime, front_ptr, rear_ptr);
				printf("x: %d\t, y:%d\n", x, y);
			}
		}

		count--;
	}

	if(rotten)
		(*gtime)++;

	scan_process(a, head, front_ptr, rear_ptr, gtime, variable);
}

#if 1
int main()
{
	//int a[3][5] = {{2,1,0,2,1}, {0,0,1,2,1}, {1,0,0,2,1}};
	//int a[MAX_R][MAX_C] = {{2,1,1},{1,1,0},{0,1,1}};
	//int a[MAX_R][MAX_C] = {{2,1,1},{0,1,1},{1,0,1}};
	int a[MAX_R][MAX_C] = {{0,2}};
	int arr_size = sizeof(a)/sizeof(int);

	struct list *head = NULL;
	struct list *front_ptr = NULL;
	struct list *rear_ptr = NULL;
	int count = 0;

	int i = 0, j = 0;

	for(i=0; i<MAX_R; i++) {
		for(j=0;j<MAX_C;j++) {
			if(a[i][j] == 2) {
				enqueue_last(&head, arr_size, i, j, 0, &front_ptr, &rear_ptr);
				printf("x: %d, y:%d \t", i, j);
				printf("\n");
				count++;
			}
		}
	}

	printf("head : %p, front: %p, rear: %p\n", head, front_ptr, rear_ptr);

	printf("\nscanning...! \n");
	int gtime = 0;
	scan_process(a, &head, &front_ptr, &rear_ptr, &gtime, count);

        for(i=0; i<MAX_R; i++) {
                for(j=0;j<MAX_C;j++) {
                        if(a[i][j] == 1)
				printf("There are good mangoes -1\n");
                }
        }
	
	printf("time: %d\n", gtime);

	return 0;
}
#else
int main()
{
	int front= -1, rear = -1;
	int ch, arr_size, i = 0, value;

	printf("Queue # of elements: \n");
	scanf("%d", &arr_size);

	int Q[arr_size];
	struct list *head = NULL;
	struct list *front_ptr = NULL;
	struct list *rear_ptr = NULL;

	while(1) {
		printf("Enter the choice : \n1.enqueue\n 2.dequeue\n 3.display\n 4.overflow\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter the Queue values : \n");
				for(i = 0; i<arr_size; i++) {
					scanf("%d", &value);
					//enqueue(Q, arr_size, value, &front, &rear);
					enqueue_last(&head, arr_size, value, 0 , 1, &front_ptr, &rear_ptr);
				}
				printf("head : %p, front: %p, rear: %p\n", head, front_ptr, rear_ptr);
				break;
			case 2:
				//dequeue(Q, &front, &rear, arr_size);
				dequeue_front(&head, &front_ptr, &rear_ptr, arr_size);
				break;
			case 3:
				//display(Q, &front, &rear);
				display_q(&head, &front_ptr, &rear_ptr);
				break;
			case 4: //generate_overflow
				int temp;
				printf("Enter the max value greater than queue size\n");
				scanf("%d", &temp);
				for(i = 0; i<temp; i++) {
					scanf("%d", &value);
					enqueue(Q, arr_size, value, &front, &rear);
				}
				break;
			case 5: //generate_underflow
				front = rear = -1;
				break;
			case 6: //reset the front when front reaches rear
				front = rear = -1;
				break;
			case 7: //reset the front when front reaches rear
				printf("Enter the Queue values : \n");
				scanf("%d", &value);
				enqueue_last(&head, arr_size, value, 0, 1, &front_ptr, &rear_ptr);
				break;
			default:
				break;
		}
	}

	return 0;
}
#endif
#if 0
int main()
{
	int front= -1, rear = -1;
	int ch, arr_size, i = 0, value;

	printf("Queue # of elements: \n");
	scanf("%d", &arr_size);

	int Q[arr_size];

	while(1) {
		printf("Enter the choice : \n1.enqueue\n 2.dequeue\n 3.display\n 4.overflow\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter the Queue values : \n");
				for(i = 0; i<arr_size; i++) {
					scanf("%d", &value);
					enqueue(Q, arr_size, value, &front, &rear);
				}
				break;
			case 2:
				dequeue(Q, &front, &rear, arr_size);
				break;
			case 3:
				display(Q, &front, &rear);
				break;
			case 4: //generate_overflow
				int temp;
				printf("Enter the max value greater than queue size\n");
				scanf("%d", &temp);
				for(i = 0; i<temp; i++) {
					scanf("%d", &value);
					enqueue(Q, arr_size, value, &front, &rear);
				}
				break;
			case 5: //generate_underflow
				front = rear = -1;
				break;
			case 6: //reset the front when front reaches rear
				front = rear = -1;
				break;
			default:
				break;
		}
	}

	return 0;
}
#endif
