#include<stdio.h>
#include <string.h>
void main()
{
	char c;
	c='a';
	printf("%d, %c\n", c,c);

	
	char aa[20];
	
	strcpy(aa, "return");

	printf("%s\n", aa);
	char *p=aa;
	while(*p){
		printf("%c, %d\n", *p, *p);
		p++;
	}

	
}