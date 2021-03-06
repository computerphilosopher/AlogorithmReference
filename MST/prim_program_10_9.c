#include<stdio.h>
#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 7
#define INF 1000L 
// INF == infinity 

int weight[MAX_VERTICES][MAX_VERTICES]=
{
	{0,29,INF,INF,INF,10,INF},
    {29,0,16,INF,INF,INF,15},
    {INF,16,0,12,INF,INF,INF},
    {INF,INF,12,0,22,INF,18},
	{INF,INF,INF,22,0,27,25},
	{10,INF,INF,INF,27,0,INF},
	{INF,15,INF,18,25,INF,0}
};

int selected[MAX_VERTICES];
int dist[MAX_VERTICES]; // 현재까지 알려진 최단거리들을 저장한 배열

/* 아직 안 뽑힌 점 중에 가장 가중치가 작은 정점을 뽑는 함수 */

int get_min_vertex(int n)
{
	int v,i;
	for(i=0;i<n;i++){
		/*안 뽑힌 정점을 찾아 기준점으로 삼는다. */
		if(!selected[i])
		{
			v=i;
			break;
		}
	}

	/* 안 뽑힌 정점중에, 기준점보다 짧은 거리를 가진 정점이 있는지 검사*/

	for(i=0;i<n;i++){
		if(!selected[i] && (dist[i]<dist[v])){
			v=i;
		}
	}

	/* 최단거리 정점 리턴*/
	return v;
}

void prim(int s,int n)
{

	int i,u,v;
	for(u=0;u<n;u++){
		dist[u]=INF;
	}
	dist[s]=0;

	
	for(u=0;u<n;u++){
		selected[u]=FALSE;
	}

	for(i=0;i<n;i++){
		
		u=get_min_vertex(n);
		selected[u]=TRUE;
		
		if(dist[u]==INF){
			return;
		}

		printf("%d ",u);
		
		for(v=0;v<n;v++)
			if(weight[u][v]!=INF) // u, v가 연결되어 있고
				if(!selected[v] && weight[u][v]<dist[v]) //현재 u~v가 최단 거리가 아니면
					dist[v]=weight[u][v]; // 최단거리 업데이트
	}
}

int main()
{
	prim(0,MAX_VERTICES);
	return 0;
}
