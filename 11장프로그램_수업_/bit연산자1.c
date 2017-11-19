#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
 int a=7, b=12;
 char bina[33], binb[33], btmp[33];
 itoa(a, bina, 2);
 printf(" a의 2진수 : %32s\n",bina);
 itoa(~a, binb, 2);
 printf("~a의 2진수 : %32s\n",binb);
 itoa(b, binb, 2);
 printf(" a의 2진수 : %32s\n",bina);
 printf(" b의 2진수 : %32s\n",binb);
 itoa(a&b, btmp, 2);
 printf(" a & b     : %32s\n",btmp);
 itoa(a|b, btmp, 2);
 printf(" a | b     : %32s\n",btmp);
 itoa(a^b, btmp, 2);
 printf(" a ^ b     : %32s\n",btmp);
 return 0;
}
