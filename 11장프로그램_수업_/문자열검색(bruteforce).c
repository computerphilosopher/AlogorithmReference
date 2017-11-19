
	
//bruteforce 문자열 검색

#include<stdio.h>
#include<string.h>

int BruteForce(char *p, char *t)
{
	int i,j,M=strlen(p), N=strlen(t);
	for(i=0,j=0;j<M && i<N;i++,j++){
		if(t[i]!=p[j]){
			i=i-j+1;
			j=-1;
		}
	}
	if(j==M) return i-M;
	else return i;
}

void main()
{
	char text[100]="ababababcababababcaabbabababcaab";
	char pattern[50]="abababca";

	int M, N, pos, previous=0,i=0;

	M=strlen(pattern);
	N=strlen(text);
	while(1){
		pos=BruteForce(pattern, text+previous);
		pos+=previous;
		i=pos+M;
		if(i<N) printf("패턴이 발생한 위치:%d\n", pos);
		else break;
		previous=pos+1;
	}
	printf("탐색 종료\n");
}
	