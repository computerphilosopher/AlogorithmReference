#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_STACK_SIZE 100

typedef  int element;
typedef struct{
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;
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
		printf("그래프:정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType *g, int u,int v)
{
	GraphNode *node;
	if(u>=g->n || v>=g->n){
		printf("그래프: 정점 번호 오류");
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
			delete node;
		}
}




void init(StackType *s)
{
	s->top=-1;
}

int is_empty(StackType *s)
{
	return (s->top==-1);
}
int is_full(StackType *s)
{
	return (s->top==MAX_STACK_SIZE-1);
}

void push(StackType *s,element item)
{
	if(is_full(s)){
		printf("stack is full\n");
		return;
	}
	else
		s->stack[++(s->top)]=item;
}
element pop(StackType *s)
{
	if(is_empty(s)){
		printf("stack is empty\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

element peek(StackType *s)
{
	if(is_empty(s)){
		printf("stack is empty\n");
		exit(1);
	}
	else return s->stack[s->top];
}

void topo_sort(GraphType *g)
{
	int i;
	StackType s;
	GraphNode *node;

	int *in_degree=new int[g->n];
	for(i=0;i<g->n;i++)
		in_degree[i]=0;
	for(i=0;i<g->n;i++){
		node=g->adj_list[i];
		while(node!=NULL){
			in_degree[node->vertex]++;
			node=node->link;
		}
	}

	init(&s);
	for(i=0;i<g->n;i++){
		if(in_degree[i]==0) push(&s,i);
	}
	while(!is_empty(&s)){
		int w;
		w=pop(&s);

		printf("%d ",w);

		node=g->adj_list[w];
		while(node!=NULL){
			int u=node->vertex;
			in_degree[u]--;
			if(in_degree[u]==0) push(&s,u);
			node=node->link;
		}
	}
	delete []in_degree;
	
}



void main()
{
	
	GraphType g;
	graph_init(&g);

	for(int i=0;i<6;i++)
		insert_vertex(&g,i);
	insert_edge(&g,0,2);
	insert_edge(&g,0,3);
	insert_edge(&g,1,3);
	insert_edge(&g,1,4);
	insert_edge(&g,2,3);
	insert_edge(&g,2,5);
	insert_edge(&g,3,5);
	insert_edge(&g,4,5);

	print_graph(&g);
	topo_sort(&g);
	printf("\n");
}

