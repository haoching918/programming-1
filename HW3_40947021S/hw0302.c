#include <stdio.h>
#define int_in32_t
#include <string.h>

int main()
{
	unsigned int num=0;
	printf("Please enter a natural number :");
	if(scanf("%u", &num)!=1 || num<0)
	{
		printf("error\n");
		return 1;
	}
	char swap;
	char numString[11];

	snprintf(numString, 11, "%u",num);

	swap=numString[0];
	numString[0]=numString[strlen(numString)-1];
	numString[strlen(numString)-1]=swap;

	printf("%s\n", numString);
	return 0;
}