
//vertex �� �����Ҵ�
#include <stdio.h>
#include<stdlib.h>

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct {
	int n;
	GraphNode **adj_list;
}GraphType;

void graph_init(GraphType *g, int n)
{
	int v;
	g->n=n;
	//g->adj_list=new GraphNode*[n];
         g->adj_list=(GraphNode**)malloc((sizeof(GraphNode*))*n); //GraphNode�ڿ� *�߰�
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
		printf("�׷���: ���� ��ȣ ����");
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
			//delete node;
                        free(node);
		}
}

		
void main()
{

	GraphType g;
	int n;
	printf("enter the number of vertices\n");
	scanf("%d", &n);
	graph_init(&g,n);


	insert_edge(&g,0,1);
	insert_edge(&g,1,0);
	insert_edge(&g,0,3);
	insert_edge(&g,3,0);
	insert_edge(&g,1,2);
	insert_edge(&g,2,1);
	insert_edge(&g,1,3);
	insert_edge(&g,3,1);
	insert_edge(&g,2,3);
	insert_edge(&g, 3,2);
	print_graph(&g);
	delete_edge(&g,0,1);
	delete_edge(&g,1,0);
	print_graph(&g);
	delete_edge(&g,1,2);
	print_graph(&g);

	destroy_graph(&g);

}

