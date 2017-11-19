#include <stdio.h>
#include <stdlib.h>
char* itoa(int val, char * buf, int radix) {

	char* p = buf;

	while(val) {

		if(radix <= 10)
			*p++ = (val % radix) + '0';

		else {
			int t = val % radix;
			if (t <= 9)
				*p++ = t + '0';
			else
				*p++ = t - 10 + 'a';
		}

		val /= radix;
	}

	*p = '\0';
	//reverse(buf);

	return buf;
}

int main(void)
{
 int a=16, b=2;
 char bin[17];
 printf("변수 a의 값  : %3d\n", a);
 printf("a>>2(10진수) : %3d\n", a>>2);
 printf("변수 b의 값  : %3d\n", b);
 printf("b<<2(10진수) : %3d\n", b<<2);
 printf("\n");
 itoa(a, bin, 2);
 printf("a의 2진수 : %8s\n", bin);
 itoa(a>>2, bin, 2);
 printf("a>>2 결과 : %8s\n", bin);
 itoa(b, bin, 2);
 printf("b의 2진수 : %8s\n", bin);
 itoa(b<<2, bin, 2);
 printf("b<<2 결과 : %8s\n", bin);
 return 0;
}
