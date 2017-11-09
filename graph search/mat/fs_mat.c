#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fs_mat.h"


void graph_init(GraphType *g){
	int r,c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;r++)
		for(c=0;c<MAX_VERTICES;c++)

			g->adj_mat[r][c]=0;
}

void init_visited(int visited[], int size){
	int i;

	for(i=0; i<size; i++){
		visited[i]=0;
	}
}

void insert_vertex(GraphType *g,int v)
{
	if( (g->n)+1 > MAX_VERTICES){
		printf("그래프:정점의 개수 초과");
		return;
	}
	g->n++;
}

void delete_vertex(GraphType *g, int v)
{
	if(v>=g->n || v<0){
		printf("error\n");
		return;
	}
	g->n--;
}
//insert edge in undirected graph(무방향 그래프)
void insert_edge(GraphType *g, int start, int end)
{
	if(start>=g->n || end>=g->n){
		printf("그래프 :정점 번호 오류");
	}

	g->adj_mat[start][end]=true;
	g->adj_mat[end][start]=true;
}

void delete_edge(GraphType *g, int start, int end)
{
	if(start>=g->n || end>=g->n){
		printf("그래프 :정점 번호 오류");
	}

	g->adj_mat[start][end]=false;
	g->adj_mat[end][start]=false;
}


void print_graph(GraphType *g)
{
	int r,c;
	for(r=0;r<g->n;r++){
		for(c=0;c<g->n;c++){
			printf("%d",g->adj_mat[r][c]);
		}

		printf("\n");
	}

	printf("\n");
}


void dfs_mat(GraphType *g, int v, int visited[]){
	int w;
	int n = g->n;

	visited[v]=true;

	printf("%d ", v);

	for(w=0;w<g->n;w++){
		if(g->adj_mat[v][w] && !visited[w]){
			dfs_mat(g, w,visited);
		}
	}

}

void bfs_mat(GraphType *g, int v){

	int w, i;
	QueueType q;
	int n = g->n;

	int *visited = (int*)malloc(sizeof(int)*n);
	init_visited(visited, n);

	visited[v] = true;
	
	init(&q);

	printf("%d", v);
	enqueue(&q, v);

	while(!is_empty(&q)){
		v=dequeue(&q);
		for(w=0; w<n; w++){
			if(g->adj_mat[v][w] && !visited[w]){
				visited[w] = true;
				printf("%d", w);
				enqueue(&q, w);
			}
		}
	}

	free(visited);


}


/* 예제 그래프는 교재 415p에 있음
*/
int main()

{
	int i;
	GraphType g;
	graph_init(&g);

	for(i=0;i<5;i++){
		insert_vertex(&g,i);
	}
	insert_edge(&g,0,1);
	insert_edge(&g,0,2);
	insert_edge(&g,0,4);
	insert_edge(&g,1,2);
	insert_edge(&g,2,3);
	insert_edge(&g,2,4);
	insert_edge(&g,3,4);
	
	int *visited = (int*)malloc(sizeof(int)* g.n );
	init_visited(visited, g.n);

	print_graph(&g);

	//dfs_mat(&g,0);
	printf("\n");
	//delete_edge(&g,0,1);
	printf("\n dfs result\n");
	dfs_mat(&g,0,visited);
	printf("\n bfs result\n");

	bfs_mat(&g, 0);
	printf("\n");

	//print_graph(&g);

	return 0;
}


