#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct graph_node {
	int vertex;
	struct graph_node *next;
}gnode_t;

typedef struct graph_map {
	int visted[MAX];
	gnode_t *gph_map[MAX];	
}gmap_t;

typedef struct queue_ds {
	int front;
	int rear;
	int qbuff[MAX];
}Queue;

void print_map(gmap_t *gptr, int vertices)
{
	int i = 0;

	while(i < vertices) {
		gnode_t *temp = gptr->gph_map[i];
		printf("vertice-(%d) : ", i);
		while(temp) {
			printf("%d ->", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
		i++;
	}
}

gnode_t *alloc_node(int value)
{
	gnode_t *new = (gnode_t *) malloc (sizeof(gnode_t));
	if(!new)
		return NULL;

	new->vertex = value;
	new->next = NULL;
}

void add_node(gnode_t *src, int dest)
{
	gnode_t *new = alloc_node(dest);
	gnode_t *temp = src, *prev = NULL;

	while(temp) {
		prev = temp;
		temp = temp->next;
	}

	prev->next = new;
}

void create_graph_links(gmap_t *gptr, int src, int dest)
{
	if(!gptr->gph_map[src]) {
		gptr->gph_map[src] = alloc_node(dest);
		if(!gptr->gph_map[src])
			return;
	} else 
		add_node(gptr->gph_map[src], dest);
}	

bool empty(Queue *qdata)
{
	if(qdata->front < qdata->rear)
		return false;
	else
		return true;
}

bool full(Queue *qdata, int limit)
{
	if(qdata->rear == limit)
		return true;
	else
		return false;
}

void enqueue(Queue *qdata, int offset, int limit)
{
	if(!full(qdata, limit)) {
		qdata->rear++;
		qdata->qbuff[qdata->rear] = offset;
	} else
		return;
}

int dequeue(Queue *qdata)
{
	if(!empty(qdata)) {
		qdata->front++;
		int temp = qdata->qbuff[qdata->front];
		return temp;
	} else
		return -1;
}

void bfs_traversal(gmap_t *gptr, int vertice, Queue *qdata, int limit)
{
	enqueue(qdata, vertice, limit);
	gptr->visted[vertice] = 1;

	while(!empty(qdata)) {
		int element = dequeue(qdata);
		printf("Dequeu element : %d\n", element);
		
		gnode_t *temp = gptr->gph_map[element];
		while(temp) {
			int data = temp->vertex;
			if(gptr->visted[data] == 0) {
				gptr->visted[data] = 1;
				enqueue(qdata, data, limit);
			}
			temp = temp->next;
		}
	}
}

void dfs_traversal(gmap_t *gptr, int offset)
{
	gnode_t *temp = gptr->gph_map[offset];
	gptr->visted[offset] = 1;

	printf("Looking for vertex : %d\n", offset);

	while(temp) {
		int data = temp->vertex;
		if(gptr->visted[data] == 0)
			dfs_traversal(gptr, data);
		temp = temp->next;
	}
}

int main()
{
	int links, src, dest, vertices;
	gmap_t *gptr;

	gptr = (gmap_t *)malloc(sizeof(gmap_t));
	if(!gptr) 
		return -1;

	printf("Number of vertices\n");
	scanf("%d", &vertices);
	
	printf("Number of links\n");
	scanf("%d", &links);

	for(int i = 0; i<links; i++) {
		printf("Enter the src and dest : ");
		scanf("%d %d", &src, &dest);
		create_graph_links(gptr, src, dest);
	}

	print_map(gptr, vertices);

	Queue qdata;

	qdata.front = -1;
	qdata.rear = -1;

	//bfs_traversal(gptr, 2, &qdata, vertices);
	
	

	dfs_traversal(gptr, 2);

	return 0;
}
