//행렬을 이용한 그래프 표현 (동적할당)

#include <stdio.h>
//#define MAX_VERTICES 50
#include<stdlib.h>

typedef struct{
	int n;
	int* adj_mat;
}GraphType;

void graph_init(GraphType *g, int n)
{
	int r,c;
	g->n=n;

	//g->adj_mat=(int *) malloc(sizeof(int)*n*n);
	g->adj_mat=new int[n*n];
	for(r=0;r<n;r++)
		for(c=0;c<n;c++)
			g->adj_mat[r*n+c]=0;
			
}

/*
void insert_vertex(GraphType *g,int v)
{
	if(((g->n)+1)> MAX_VERTICES){
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
*/
//insert edge in undirected graph(무방향 그래프)
void insert_edge(GraphType *g, int start, int end)
{
	if(start>=g->n || end>=g->n){
		printf("그래프 :정점 번호 오류");
	}

	//g->adj_mat[start][end]=1;
	//g->adj_mat[end][start]=1;
	g->adj_mat[start*(g->n)+end]=1;
	g->adj_mat[end*(g->n)+start]=1;
}

void delete_edge(GraphType *g, int start, int end)
{
	if(start>=g->n || end>=g->n){
		printf("그래프 :정점 번호 오류");
	}

	g->adj_mat[start*(g->n)+end]=0;
	g->adj_mat[end*(g->n)+start]=0;
}


void print_graph(GraphType *g)
{
	int r,c;
	for(r=0;r<g->n;r++)
		for(c=0;c<g->n;c++){
			if(g->adj_mat[r*(g->n)+c])
				printf("<%d , %d>",r,c);
		}

		printf("\n");
}

void main()
{
	//int i;
	GraphType g;
	graph_init(&g,4);

	//for(i=0;i<4;i++)
	//	insert_vertex(&g,i);
	insert_edge(&g,0,1);
//	insert_edge(&g,1,0);
	insert_edge(&g,0,3);
	insert_edge(&g,1,2);
	insert_edge(&g,1,3);
	insert_edge(&g,2,3);
	print_graph(&g);
	delete_edge(&g,0,1);
	print_graph(&g);

}
