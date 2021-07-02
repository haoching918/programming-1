#include<stdio.h>
#define int_int32_t

int main()
{
	float a,b,c;
	printf("Please enter a quadratic polynomial (a,b,c):");
	if (scanf("(%f,%f,%f)", &a,&b,&c) != 3)
	{
		printf("error.\n");
		return 1;
	}
	if (b*b-4*a*c>0)
	{
		printf("Two distinct real roots.\n");
	}
	else if (b*b-4*a*c==0)
	{
		printf("One real root.\n");
	}
	else if (b*b-4*a*c<0)
	{
		printf("No real roots.\n");
	}
	return 0;
}