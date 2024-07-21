#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct graph_node {
	int data;
	struct graph_node *link;
}gnode;

typedef struct graph {
	int visited[10];
	gnode *list[MAX];
}graph_t;

void print(graph_t *graph, int list_count)
{
	for(int i = 0; i<list_count; i++) {
		gnode *temp = graph->list[i];
		printf("%d node elements are : \n", i);
		while(temp) {
			printf("%d->", temp->data);
			temp = temp->link;
		}
		printf("NULL\n");
	}
}

void create_graph(graph_t **graph)
{
	*graph = (graph_t *) malloc (sizeof(graph_t));
}

gnode *create_nodes(int data)
{
	gnode *new = (gnode *) malloc(sizeof(gnode));
	new->data = data;
	new->link = NULL;

	return new;
}

void create_nodes_edges(graph_t *graph, int offset, int node_value)
{
	if(!graph->list[offset]) {
		graph->list[offset] = create_nodes(node_value);
		if(!graph->list[offset])
			return;
	} else {
		gnode *new = create_nodes(node_value);
		gnode *prev, *temp = graph->list[offset];
		while(temp) {
			prev = temp;
			temp = temp->link;
		}
		prev->link = new;
	}	
}

void dfs(graph_t *graph, int offset)
{
	graph->visited[offset] = 1;

	printf(" %d", offset);
	gnode *temp = graph->list[offset];

	while(temp) {
		if(graph->visited[temp->data] == 0)
			dfs(graph, temp->data);
		temp = temp->link;
	}
}

int findCircleNum(graph_t *graph, int vertexes, int zero)
{
	printf("DFS Traversal is as follows: \n");
	for(int i = zero; i<vertexes+zero; i++) {
		if(graph->visited[i] == 0) {
			printf("Province %d : ", i);
			dfs(graph, i);
			printf("\n");
		}
	}
	printf("\n");
}

int main()
{
	graph_t *graph = NULL;
	int offset, node2, links, zero, vertexes;
	create_graph(&graph);

	printf("create number of edges\n");
	scanf("%d", &links);
	
	printf("offset starts from 0 or 1\n");
	scanf("%d", &zero);

	printf("Enter number of vertexes\n");
	scanf("%d", &vertexes);
	
	for(int i = zero; i<links+zero; i++) {
		printf("create nodes edges\n");
		scanf("%d%d", &offset, &node2);
		create_nodes_edges(graph, offset, node2);
	}

	print(graph, vertexes);

	memset(graph->visited, 0, sizeof(graph->visited)/sizeof(int));

	printf("DFS Traversal: \n");
	dfs(graph, 0);
	printf("\n");
	
	memset(graph->visited, 0, sizeof(graph->visited)/sizeof(int));
	
	findCircleNum(graph, vertexes, zero);

	return 0;
}
