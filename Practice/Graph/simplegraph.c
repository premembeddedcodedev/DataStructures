#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct graphnode {
	int vertex;
	struct graphnode *next;
}gnode;

typedef struct graphlist {
	int num_vertices;
	int visited[MAX];
	gnode *list[MAX];
}glist;

typedef struct queue {
	int front;
	int rear;
	int qbuild[MAX];
}Q;

glist *create_graph(int list_count)
{
	glist *graph = (glist *) malloc(sizeof(glist));
	if(!graph)
		return NULL;
	
	return graph;
}

gnode *create_node(int src)
{
	gnode *new = (gnode *) malloc(sizeof(gnode));
	if(!new)
		return NULL;

	new->vertex = src;
	new->next = NULL;

	return new;
}

gnode *add_node(glist *head, int src, int dest)
{
	gnode *new, *prev, *temp = head->list[src];

	new = create_node(dest);

	while(temp) {
		prev = temp;
		temp = temp->next;
	}

	prev->next = new; 
}

void create_sublists(glist *graph, int src, int dest)
{
	if(!graph->list[src]) {
		gnode *new =  create_node(dest);
		graph->list[src] = new;
	} else
		add_node(graph, src, dest);
}

void print(glist *graph, int list_count)
{
	for(int i = 0; i<list_count; i++) {
		gnode *temp = graph->list[i];
		printf("%d node elements are : \n", i);
		while(temp) {
			printf("%d->", temp->vertex);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

bool qfull(Q *qdata, int vertices)
{
	return qdata->rear == vertices ? true : false;
}

bool qempty(Q *qdata)
{
	if(qdata->front <= qdata->rear)
		return false;
	else
		return true;
}

void enqueue(Q *qdata, int limit, int element)
{
	if(!qfull(qdata, limit)) {
		qdata->rear++;
		qdata->qbuild[qdata->rear] = element;
	}
}

int dequeue(Q *qdata)
{
	int dqelement = -1;
	
	if(!qempty(qdata)) {
		qdata->front++;
		dqelement = qdata->front;
	}

	return qdata->qbuild[dqelement];
}

void bfs_traversal(glist *graph, Q *qdata, int count, int offset)
{
	enqueue(qdata, count, offset);
	graph->visited[offset] = 1;

	while(!qempty(qdata)) {
		int check = dequeue(qdata);
		printf("Dequeue: %d\n", check);

		gnode *temp = graph->list[check];
		while(temp) {
			int data = temp->vertex;
			if(graph->visited[data] == 0) {
				graph->visited[data] = 1;
				enqueue(qdata, count, data);
			}
			temp = temp->next;
		}
	}
}

void dfs_traversal(glist *graph, int offset)
{
	gnode *temp = graph->list[offset];
	graph->visited[offset] = 1;

	printf("Looking for vertex : %d\n", offset);

	while(temp) {
		if(graph->visited[temp->vertex] == 0)
			dfs_traversal(graph, temp->vertex);
		temp = temp->next;
	}
}

int main()
{
	int list_count;

	Q qdata;

	printf("Enter the list size\n");
	scanf("%d", &list_count);

	glist *graph = create_graph(list_count);
	if(!graph)
		return -1;

	create_sublists(graph, 0, 1);
	create_sublists(graph, 0, 2);
	create_sublists(graph, 0, 3);
	create_sublists(graph, 1, 0);
	create_sublists(graph, 1, 2);
	create_sublists(graph, 2, 0);
	create_sublists(graph, 2, 1);
	create_sublists(graph, 2, 4);
	create_sublists(graph, 3, 0);
	create_sublists(graph, 4, 2);

	print(graph, list_count);

	qdata.front = -1;
	qdata.rear = -1;

	memset(graph->visited, 0, sizeof(graph->visited));

	bfs_traversal(graph, &qdata, list_count, 2);

	memset(graph->visited, 0, sizeof(graph->visited));
	
	dfs_traversal(graph, 1);
}
