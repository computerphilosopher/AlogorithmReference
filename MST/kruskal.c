#include <stdio.h>
#include <stdlib.h>

/* u, v : vertex, key: weight
 */
typedef struct element{
	
	int u;
	int v;
	int key;
}element;

void set_init(int n, int *parent, int *set_size)
{
	int i;
	for(i=0;i<n;i++){
		parent[i]=-1;
		set_size[i]=1;
	}
}
/* 소속된 집합의 대표 숫자를 리턴 */
int set_find(int vertex, int *parent)
{
	int p,s,i=-1;
	for(i=vertex;(p=parent[i])>=0;i=p)
		;
	s=i;
	for(i=vertex;(p=parent[i])>=0;i=p)
		parent[i]=s;
	return s;
}

void set_union(int s1,int s2, int *parent, int *set_size)
{
	if(set_size[s1]<set_size[s2]){
		parent[s1]=s2;
		set_size[s2]+=set_size[s1];
	}
	else{
		parent[s2]=s1;
		set_size[s1]+=set_size[s2];
	}
}

int compare(const void *arg1, const void *arg2)
{
	element *p1=(element *)arg1;
	element *p2=(element *)arg2;
	return(p1->key-p2->key);
}

void kruskal(element arr[],int vertices_count, int edges_count)
{
	int edge_accepted=0;
	int i=0;
	int uset,vset;
	element e;
	int *parent= (int*)malloc(sizeof(int)*vertices_count);
	int *set_size= (int*)malloc(sizeof(int)*vertices_count);
	set_init(vertices_count,parent, set_size);
	qsort(arr, edges_count ,sizeof(element), compare);
	while(edge_accepted<vertices_count-1)
	{
		e=arr[i];
		uset=set_find(e.u,parent);
		vset=set_find(e.v,parent);
		if(uset!=vset){
			printf("(%d ,%d) %d\n",e.u,e.v,e.key);
			edge_accepted++;
			set_union(uset,vset,parent,set_size);
		}
		i++;
	}
	free(parent);
	free(set_size);
}

int  main()
{
	element arr[9]={{0,1,29},{1,2,16},{2,3,12},{3,4,22},{4,5,27},{5,0,10},{6,1,15},
		{6,3,18},{6,4,25}};
	int vertices_count=7;//number of verteices
	int edges_count=9;//number of edges
	kruskal(arr,vertices_count,edges_count);
	return 0;
}



