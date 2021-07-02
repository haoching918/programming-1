#include <stdio.h>
#include <stdint.h>

 int main()
{
	int a,b,c,d,e,f;
	printf("Please enter a 5-digits integer:");
	scanf("%d",&a);
	b=a/10000;
	c=(a-10000*b)/1000;
	d=(a-10000*b-1000*c)/100;
	e=(a-10000*b-1000*c-100*d)/10;
	f=(a-10000*b-1000*c-100*d-10*e);
	printf("Result: %d\n",b*c*d*e*f);
	return 0;
}