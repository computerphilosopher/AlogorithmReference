#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7
#define INF 1000

int weight[MAX_VERTICES][MAX_VERTICES]=
{
	{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}};

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n,int found[])
{
	int i,min,minpos;
	min=INT_MAX;
	minpos=-1;
	for(i=0;i<n;i++)
		if(distance[i]<min && !found[i]){
			min=distance[i];
			minpos=i;
		}

		return minpos;
}

void shortest_path(int start, int n)
{
	int i,u,w;
	for(i=0;i<n;i++)
	{
		distance[i]=weight[start][i];
		found[i]=FALSE;
	}

	found[start]=TRUE;
	distance[start]=0;
	for(i=0;i<n-2;i++){
		u=choose(distance,n,found);
		found[u]=TRUE;
		/*정점 u를 거치면 거리가 더 짧아지는지 점검하는 루프*/
		for(w=0;w<n;w++)
			if(!found[w])
				if(distance[u]+weight[u][w]<distance[w])
					distance[w]=distance[u]+weight[u][w];
				}
}

/*교재에 없음*/
void print_distance(int start,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("distance: %d ---> %d = %d\n", start, i, distance[i]);
}

void floyd(int n, int arr[MAX_VERTICES][MAX_VERTICES]){
	
	int i, j, k;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			arr[i][j] = weight[i][j];
		}
	}

	for(k=0; k<n; k++){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(arr[i][k] + arr[k][j] < arr[i][j]){
					arr[i][j] = arr[i][k]+arr[k][j];
				}
			}
		}
	}
}


int main()
{
	shortest_path(0,MAX_VERTICES);
	print_distance(0,MAX_VERTICES);
	return 0;
}
