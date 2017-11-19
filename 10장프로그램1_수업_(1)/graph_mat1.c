#include <stdio.h>
#define MAX_VERTICES 50

typedef struct{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g)
{
	int r,c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;r++)
		for(c=0;c<MAX_VERTICES;c++)
			g->adj_mat[r][c]=0;
}

void insert_vertex(GraphType *g,int v)
{
	if(((g->n)+1)> MAX_VERTICES){
		printf("�׷���:������ ���� �ʰ�");
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
//insert edge in undirected graph(������ �׷���)
void insert_edge(GraphType *g, int start, int end)
{
	if(start>=g->n || end>=g->n){
		printf("�׷��� :���� ��ȣ ����");
	}

	g->adj_mat[start][end]=1;
	g->adj_mat[end][start]=1;
}

void delete_edge(GraphType *g, int start, int end)
{
	//
}


void print_graph(GraphType *g)
{
	int r,c;
	for(r=0;r<g->n;r++)
		for(c=0;c<g->n;c++){
			if(g->adj_mat[r][c])
				printf("<%d , %d>",r,c);
		}

		printf("\n");
}

void main()
{
	int i;
	GraphType g;
	graph_init(&g);

	for(i=0;i<4;i++)
		insert_vertex(&g,i);
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
