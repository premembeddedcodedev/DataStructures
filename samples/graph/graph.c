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

	return 0;
}
