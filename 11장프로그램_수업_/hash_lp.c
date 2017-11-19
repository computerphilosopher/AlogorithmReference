#include <stdio.h>
#include <string.h>
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
void hash_lp_add(element item,element ht[])
{
	int i,hash_value;
	hash_value=i=hash_function(item.key);
	while(!empty(ht[i])){
		if(equal(item,ht[i])){
			printf("Ž�� Ű �ߺ�\n");
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
{
	element tmp;
	int op;
	while(1){
		printf("insert the operation you want(0=insert, 1=search,2=finish)=");
		scanf("%d",&op);
		if(op==2) break;
		printf("insert a key");

		scanf("%s",tmp.key);
		if(op==0)
			hash_lp_add(tmp,hash_table);
		else if(op==1)
			hash_lp_search(tmp,hash_table);
		hash_lp_print(hash_table);
	}
}
