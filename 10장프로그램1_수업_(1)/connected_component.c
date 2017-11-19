#include <stdio.h>
#define MAX_VERTICES 50
int visited[MAX_VERTICES];
int count;

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct {
	int n;
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;




void graph_init(GraphType *g)
{
	int v;
	g->n=0;
	for(v=0;v<MAX_VERTICES;v++)
		g->adj_list[v]=NULL;
}

void insert_vertex(GraphType *g, int v)
{
	if(((g->n)+1)>MAX_VERTICES){
		printf("�׷���:������ ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge(GraphType *g, int u,int v)
{
	GraphNode *node;
	if(u>=g->n || v>=g->n){
		printf("�׷���: ���� ��ȣ ����");
		return;
	}

	node=new GraphNode;
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
		printf("�׷���: ���� ��ȣ ����");
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
			delete node;
		}
}

void init_visited()
{
	int i;
	for(i=0;i<MAX_VERTICES;i++)
		visited[i]=0;
}

void dfs_list(GraphType *g, int v)
{
	GraphNode *w;
	visited[v]=count;
	printf("%d ",v);
	for(w=g->adj_list[v];w;w=w->link)
		if(!visited[w->vertex])
			dfs_list(g,w->vertex);
}

void find_connected_component(GraphType *g)
{
	int i;
	count=0;
	for(i=0;i<MAX_VERTICES;i++)
		visited[i]=count;
	for(i=0;i<g->n;i++)
		if(!visited[i]){
			count++;
			dfs_list(g,i);
		}
}
	
void main()
{
	int i;
	GraphType g;
	graph_init(&g);

	for(i=0;i<5;i++)
		insert_vertex(&g,i);
	insert_edge(&g,0,1);
	insert_edge(&g,1,0);
	insert_edge(&g,4,3);
	insert_edge(&g,3,4);
	insert_edge(&g,0,2);
	insert_edge(&g,2,0);
	
	print_graph(&g);

//	init_visited();
//	dfs_list(&g,0);
//	printf("\n");
	find_connected_component(&g);
	printf("\n");
	for(i=0;i<g.n;i++)
		printf("%d ", visited[i]);


}
