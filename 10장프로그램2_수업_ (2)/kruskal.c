#include <stdio.h>
#include <stdlib.h>

/* u, v : vertex, key: weight
 */
typedef struct element{
	
	int u;
	int v;
	int key;
}element;

void set_init(int n, int *parent, int *num)
{
	int i;
	for(i=0;i<n;i++){
		parent[i]=-1;
		num[i]=1;
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

void set_union(int s1,int s2, int *parent, int *num)
{
	if(num[s1]<num[s2]){
		parent[s1]=s2;
		num[s2]+=num[s1];
	}
	else{
		parent[s2]=s1;
		num[s1]+=num[s2];
	}
}

int compare(const void *arg1, const void *arg2)
{
	element *p1=(element *)arg1;
	element *p2=(element *)arg2;
	return(p1->key-p2->key);
}

void kruskal(element A[],int n, int m)
{
	int edge_accepted=0;
	int i=0;
	int uset,vset;
	element e;
	int *parent= (int*)malloc(sizeof(int)*n);
	int *num= (int*)malloc(sizeof(int)*n);
	set_init(n,parent, num);
	qsort(A,m,sizeof(element), compare);
	while(edge_accepted<n-1)
	{
		e=A[i];
		uset=set_find(e.u,parent);
		vset=set_find(e.v,parent);
		if(uset!=vset){
			printf("(%d ,%d) %d\n",e.u,e.v,e.key);
			edge_accepted++;
			set_union(uset,vset,parent,num);
		}
		i++;
	}
	free(parent);
	free(num);
}

int  main()
{
	element A[9]={{0,1,29},{1,2,16},{2,3,12},{3,4,22},{4,5,27},{5,0,10},{6,1,15},
	{6,3,18},{6,4,25}};
	int n=7;//number of verteices
        int m=9;//number of edges
	kruskal(A,n,m);
	return 0;
}

		

