#include <stdio.h>
#include <stdlib.h>

/* u, v : vertex, weight: weight
 */
typedef struct EdgeType{
	
	int u;
	int v;
	int weight;
}EdgeType;

void set_init(int n, int *parent_of, int *set_size)
{
	int i;
	for(i=0;i<n;i++){
		parent_of[i]=-1;
		set_size[i]=1;
	}
}
/* 소속된 집합의 대표 숫자를 리턴 */
int set_find(int vertex, int *parent_of)
{
	int p,s,i=-1;
	for(i=vertex;(p=parent_of[i])>=0;i=p)
		;
	s=i;
	for(i=vertex;(p=parent_of[i])>=0;i=p)
		parent_of[i]=s;
	return s;
}

void set_union(int s1,int s2, int *parent_of, int *set_size)
{
	if(set_size[s1]<set_size[s2]){
		parent_of[s1]=s2;
		set_size[s2]+=set_size[s1];
	}
	else{
		parent_of[s2]=s1;
		set_size[s1]+=set_size[s2];
	}
}

int compare(const void *arg1, const void *arg2)
{
	EdgeType *p1=(EdgeType *)arg1;
	EdgeType *p2=(EdgeType *)arg2;
	return(p1->weight-p2->weight);
}

void kruskal(EdgeType arr[],int vertices_count, int edges_count)
{
	int added_edge_count=0;
	int i=0;
	
	int uset,vset;
	
	EdgeType shortest_edge;
	
	int *parent_of= (int*)malloc(sizeof(int)*vertices_count);
	int *set_size= (int*)malloc(sizeof(int)*vertices_count);
	
	set_init(vertices_count,parent_of, set_size);
	qsort(arr, edges_count ,sizeof(EdgeType), compare);

	while(added_edge_count < vertices_count-1)
	{
		shortest_edge=arr[i];
		uset=set_find(shortest_edge.u, parent_of);
		vset=set_find(shortest_edge.v, parent_of);
		if(uset!=vset){
			printf("(%d ,%d) %d\n",shortest_edge.u, shortest_edge.v, shortest_edge.weight);
			added_edge_count++;
			set_union(uset,vset,parent_of,set_size);
		}
		i++;
	}
	free(parent_of);
	free(set_size);
}

int  main()
{
	EdgeType arr[9]={{0,1,29},{1,2,16},{2,3,12},{3,4,22},{4,5,27},{5,0,10},{6,1,15},
		{6,3,18},{6,4,25}};
	int vertices_count=7;//number of verteices
	int edges_count=9;//number of edges
	kruskal(arr,vertices_count,edges_count);
	return 0;
}



