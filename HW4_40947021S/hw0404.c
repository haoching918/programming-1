

#include "header.h"


intt main()
{
	intt resistance = 0;
	intt n = 0;
	printf("Please enter the resistance (1-100): ");
	if (scanf("%d", &resistance) != 1 || resistance < 1 || resistance > 100)
	{
		printf("error\n");
		return 0;
	}
	printf("Please enter n (1-100): ");
	if (scanf(" %d", &n) != 1 || n < 1 || n > 100)
	{
		printf("error\n");
		return 0;
	}
	double r_total = equivalent(n,resistance);
	printf("Ans = %lf\n" , r_total);

}

