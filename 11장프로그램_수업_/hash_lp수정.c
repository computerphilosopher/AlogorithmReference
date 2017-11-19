


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY_SIZE  10
#define TABLE_SIZE 13
#define empty(e) (strlen(e.key)==0)
#define equal(e1,e2) (!strcmp(e1.key,e2.key))

typedef struct {
	char key[KEY_SIZE];
}element;

element hash_table[TABLE_SIZE];

void init_table(element ht[])
{
	int i;
	for(i=0;i<TABLE_SIZE;i++){
		ht[i].key[0]=NULL;
	}
}

int transform(char *key)
{
	int number=0;
	while(*key)
		number+=*key++;
	return number;
}

int hash_function(char *key)
{
	return transform(key)%TABLE_SIZE;
}

int hash_function2(char *key)
{
	return 7-(hash_function(key)%7);
}
void hash_dh_add( element item, element ht[] )
{ 
   int i, hash_value, inc;
   hash_value = i = hash_function( item.key ) ;
   inc = hash_function2( item.key ) ;
   while(!empty(ht[i])){
	   /* 이미 해쉬테이블에 있는 값을 넣으려 할 때*/
		if(equal(item, ht[i])){
	     	fprintf(stderr, "탐색키가 중복되었습니다\n");
	     	return;
		}
		/* 중복값이 아니면 테이블의 다음 자리를 조사 */
	  	i = (i+inc) % TABLE_SIZE;
   	if(i == hash_value){  
	     	fprintf(stderr, "테이블이 가득찼습니다\n");
	     	exit(1);
     }
   }
   ht[i]=item;
}


void hash_qp_add( element item, element ht[] )
{ 
	int i, hash_value, inc=0;
	hash_value = i = hash_function( item.key ) ;
	//printf("hash_address=%d\n", i);
	while(!empty(ht[i])){
   	if(equal(item, ht[i])){
   		fprintf(stderr, "탐색키가 중복되었습니다\n");
 			exit(1);
		}
		i = (i+inc +1) % TABLE_SIZE;
		inc = inc +2;
		if(i == hash_value){  
 			fprintf(stderr, "테이블이 가득찼습니다\n");
   		exit(1);
		}
	}
	ht[i]=item;
}
void hash_lp_add(element item,element ht[])
{
	int i,hash_value;
	hash_value=i=hash_function(item.key);
	while(!empty(ht[i])){
		if(equal(item,ht[i])){
			printf("탐색 키 중복\n");
			return;
		}
		i=(i+1)%TABLE_SIZE;
		if(i==hash_value){
			printf("table is full\n");
			return;
		}
	}
	ht[i]=item;
}
void hash_lp_search(element item,element ht[])
{
	int i,hash_value;
	hash_value=i=hash_function(item.key);
	while(!empty(ht[i])){
		if(equal(item,ht[i])){
			printf("the key is searched in %d\n", i);
			return;
		}
		i=(i+1)%TABLE_SIZE;
		if(i==hash_value){
			printf("key is not on the table\n");
			return;
		}
	}
	printf("key is not on the table\n");
}
void hash_lp_print(element ht[])
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
		printf("[%d]  %s\n",i,ht[i].key);
}

int main()
{/*
	element tmp;
	int op;
	while(1){
		printf("insert the operation you want(0=insert, 1=search,2=finish)=");
		scanf("%d",&op);
		if(op==2) break;
		printf("insert a key\n");

		scanf("%s",tmp.key);
		if(op==0)
			hash_lp_add(tmp,hash_table);
		else if(op==1)
			hash_lp_search(tmp,hash_table);
		hash_lp_print(hash_table);
	}
	*/

	element a[7]={{"do"}, {"for"}, {"if"}, {"case"}, {"else"}, {"return "}, {"function"}};

	int i;
	for(i=0;i<7;i++){
		//hash_lp_add(a[i], hash_table);
		//hash_qp_add(a[i], hash_table);
		hash_dh_add(a[i], hash_table);

       hash_lp_print(hash_table);
	}

	return 0;
}
