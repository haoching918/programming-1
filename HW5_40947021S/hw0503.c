#include "hw5.h"

int main()
{
	intt p1d = 0;
	printf("Please enter p1 degree:");
	if (scanf("%d", &p1d) != 1 || p1d < 0)
	{
		printf("error\n");
		return 1;
	}
	intt p1c[p1d + 1];
	printf("Please enter p1 coefficients:");
	for (intt i = 0; i < p1d + 1; i++)
	{
		if (scanf("%d", &p1c[i]) != 1 || p1c[0] == 0)
		{
			printf("error\n");
			return 1;
		}
	}

	intt p2d = 0;
	printf("Please enter p2 degree:");
	if (scanf("%d", &p2d) != 1 || p2d < 0)
	{
		printf("error\n");
		return 1;
	}
	intt p2c[p2d + 1];
	printf("Please enter p2 coefficients:");
	for (intt i = 0; i < p2d + 1; i++)
	{
		if (scanf("%d", &p2c[i]) != 1 || p2c[0] == 0)
		{
			printf("error\n");
			return 1;
		}
	}
	
	printf("P1: ");
	polynomial_print(p1c, p1d);
	
	printf("P2: ");
	polynomial_print(p2c, p2d);

	printf("P1 + P2: ");
	intt sum[max(p1d + 1, p2d + 1)];
	for (intt i = 0; i < max(p1d + 1, p2d + 1); i++)
	{
		if (p1d > p2d)
		{
			sum[i]= p1c[i];
		}
		else
		{
			sum[i]= p2c[i];
		}  
		
	}
	for (intt i = 0; i < min(p1d + 1, p2d + 1); i++)
	{
		if (p1d > p2d)
		{
			sum[i + (p1d - p2d)] = p1c[i + (p1d - p2d)] + p2c[i]; 
		}
		else if (p1d == p2d)
		{
			sum[i] = p1c[i] + p2c[i]; 
		}
		else
		{
			sum[i + (p2d - p1d)] = p1c[i] + p2c[i + (p2d - p1d)];
		}
			  
	}
	polynomial_print(sum, max(p1d, p2d));
	
	printf("P1 - P2: ");
	intt difference[max(p1d + 1, p2d + 1)];
	for (intt i = 0; i < max(p1d + 1, p2d + 1); i++)
	{
		if (p1d > p2d)
		{
			difference[i]= p1c[i];
		}
		else
		{
			difference[i]= p2c[i];
		}  
		
	}
	for (intt i = 0; i < min(p1d + 1, p2d + 1); i++)
	{
		if (p1d > p2d)
		{
			difference[i + (p1d - p2d)] = p1c[i + (p1d - p2d)] - p2c[i]; 
		}
		else if (p1d == p2d)
		{
			difference[i] = p1c[i] - p2c[i]; 
		}
		else
		{
			difference[i + (p2d - p1d)] = p1c[i] - p2c[i + (p2d - p1d)];
		}
			  
	}
	polynomial_print(difference, max(p1d, p2d));
	
	printf("P1 * P2: ");
	intt product[100] = {0};
	
	intt product_degree = p1d + p2d;
	for (intt i = 0; i < p1d + 1; i++)
	{
		intt p1d_index = p1d - i;
		for (intt j = 0; j < p2d + 1; j++)
		{
			intt p2d_index = p2d - j;
			product[product_degree - (p1d_index + p2d_index)] += p1c[i] * p2c[j];			
		}
		
	}	
	polynomial_print(product, p1d + p2d);

	return 0;
}