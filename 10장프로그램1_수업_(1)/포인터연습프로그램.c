
//program1
#include "stdio.h" 
#define MAX_NUM 5
      
/*     void main()
   {  int a[MAX_NUM]={1,2,3,4,5};
      int *p;
      p=a;//p는 변수 a[0]의 주소를 갖는다.
      int **dp;
      dp=&p;
      printf("%d, %d, %d", *p,p,*dp); //찍히는 값은?
  }
*/


int *f(int n)
{
	int *p;
	p=new int[n];
	for(int i=0;i<n;i++)
		p[i]=i+1;
	return p;
}

void main()
{
	int n=5;
	int *p=f(n);
	for(int i=0;i<n;i++) printf("%d\n",p[i]);
	printf("p=%d,*p= %d\n",p,*p);
	delete []p;
}

//program1 여기까지

//program2

#include "stdio.h"

int  *g(int n)
{
	int *a=new int[n];
	return a;
}
int **f(int n)
{
	int **p=new int*[n];
	return p;
}

void main()
{
	int n=5;

	int *a=g(n);
	for(int i=0;i<n;i++) a[i]=i+1;
	int **p=f(n);
	for( i=0;i<n;i++)
		p[i]=&(a[i]);
	for(i=0;i<n;i++) printf("%d,%d\n", *(p[i]),p[i]);
	printf("p=%d\n",p);
	printf("*p=%d\n",*p);
	delete []a;
	delete []p;
}

//program2여기까지 