#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "fs_list.h"



void graph_init(GraphType *g, int n)
{
	int v;
	g->n=n;
	//g->adj_list=new GraphNode*[n];
	g->adj_list=(GraphNode**)malloc((sizeof(GraphNode*))*n);
	for(v=0;v<n;v++)
		g->adj_list[v]=NULL;
}


void destroy_graph(GraphType *g)
{
	int i;
	for(i=0;i<g->n;i++){
		GraphNode *node=g->adj_list[i];
		while(node!=NULL){
			GraphNode *temp=node->link;
			//delete node;
			free(node);
			node=temp;
		}
	}
	//delete[] g->adj_list;
	free(g->adj_list);
}
void insert_edge(GraphType *g, int u,int v)
{
	GraphNode *node;
	if(u>=g->n || v>=g->n){
		printf("그래프: 정점 번호 오류");
		return;
	}

	//node=new GraphNode;
	node=(GraphNode*)malloc(sizeof(GraphNode));
	node->vertex=v;
	node->link=g->adj_list[u];
	g->adj_list[u]=node;
}

void print_graph(GraphType *g)
{
	int i;
	GraphNode *node;
	printf("List of edges:\n");
	for(i=0;i<g->n;i++){
		node=g->adj_list[i];
		while(node!=NULL){
			printf("<%d, %d>",i,node->vertex);
			node=node->link;
		}
		printf("\n");
	}
	printf("\n");
}

GraphNode *findNode(GraphNode *node, int vertex)
{
	while(node!=NULL){
		if(node->vertex==vertex) 
			return node;
		node=node->link;
	}
	return node;
}

void delete_edge(GraphType *g,int u,int v)
{
		if(u>=g->n || v>=g->n){
		printf("그래프: 정점 번호 오류");
		return;
	}
		GraphNode *node;
		node=findNode(g->adj_list[u],v);
		if(node!=NULL){
			if(g->adj_list[u]!=node){
				GraphNode *temp=g->adj_list[u];
				while(temp->link!=node)
					temp=temp->link;
				temp->link=node->link;
			}
			else{
				g->adj_list[u]=node->link;
			}
			//delete node;
			free(node);
		}
}

bool *dfs_init(GraphType *g)
{
	int i;
	bool *visited=(bool*)malloc((sizeof(bool))*g->n);
	for(i=0;i<g->n;i++)	visited[i]=0;
	return visited;
}

void destroy_visited(bool *visited)
{
	//delete[] visited;
	free(visited);
}

void dfs_list( GraphType *g, bool *visited, int v){

	GraphNode *w;
	visited[v]=true;
	printf("%d ",v);

	for(w=g->adj_list[v]; w; w=w->link){
		if(!visited[w->vertex]){
			dfs_list(g, visited, w->vertex);
		}
	}
}

void bfs_list(GraphType *g, int v)
{
	GraphNode *w;
	QueueType q;
	bool *visited = (bool*)malloc(sizeof(bool)*g->n);
	init(&q);
	visited[v]=true;
	printf("%d ",v);
	enqueue(&q,v);
	while(!is_empty(&q)){
		v=dequeue(&q);
		for(w=g->adj_list[v];w;w=w->link)
			if(!visited[w->vertex]){
				visited[w->vertex]=true;
				printf("%d ",w->vertex);
				enqueue(&q, w->vertex);
			}
	}
}

void find_connected_component(GraphType *g, bool *visited, int *count)
{
	int i;
	(*count)=0;
	for(i=0;i<MAX_VERTICES;i++)
		visited[i]=(*count);
	for(i=0;i<g->n;i++)
		if(!visited[i]){
			(*count)++;
			dfs_list(g,visited, i);
		}
}

int main()
{
	GraphType g;
	graph_init(&g,5);

	insert_edge(&g,4,3);
	insert_edge(&g,4,2);
	insert_edge(&g,4,0);

	insert_edge(&g,3,4);
	insert_edge(&g,3,2);

	insert_edge(&g,2,4);
	insert_edge(&g,2,3);
	insert_edge(&g,2,1);
	insert_edge(&g,2,0);
	

	insert_edge(&g,1,2);
	insert_edge(&g,1,0);

	insert_edge(&g,0,4);
	insert_edge(&g,0,2);
	insert_edge(&g,0,1);

	print_graph(&g);

	printf("depth_first_search\n");
    bool *visited= dfs_init(&g);
	dfs_list(&g, visited, 0);

	printf("\nbreadth first search\n");
	bfs_list(&g, 0);
	destroy_visited(visited);
	printf("\n");
	
	
	destroy_graph(&g);

	return 0;
	
}


