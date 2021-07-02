#include "hw5.h"

//hw0501
void sort_decrease(intt *array, intt array_size)
{
	for (intt i = 0; i < array_size; i++)
	{
		for (intt k = i; k < array_size; k++)
		{
			intt tmp = array[i];
			if (array[k] > array[i])
			{
				array[i] = array[k];
				array[k] = tmp;
			}
		}
	}
}

void sort_increase(intt *array, intt array_size)
{
	for (intt i = 0; i < array_size; i++)
	{
		for (intt k = i; k < array_size; k++)
		{
			intt tmp = array[i];
			if (array[k] < array[i])
			{
				array[i] = array[k];
				array[k] = tmp;
			}
		}
	}
}

void printArray(intt *array, intt array_size)
{
	for (intt i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

//hw0502
intt arr_det(intt m[4][4])
{

	return m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
		   m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
		   m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
		   m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
		   m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
		   m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
		   m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
		   m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
		   m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
		   m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
		   m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
		   m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];
}

//hw0503
void polynomial_print(intt *pc, intt degree)
{
	if (pc[0] != 0)
	{
		if (pc[0] > 0)
		{
			if (pc[0] == 1)
			{
				printf("x^%d", degree);
			}
			else
			{
				printf("%dx^%d", pc[0], degree);
			}
		}
		else
		{
			if (pc[0] == -1)
			{
				printf("-x^%d", degree);
			}
			else
			{
				printf("%dx^%d", pc[0], degree);
			}
		}
	}
	intt index = 1;

	for (intt i = degree - 1; i >= 0; i--)
	{
		if (pc[index] == 0)
		{
			index++;
			continue;
		}

		if (i == 1)
		{
			if (pc[index] > 0)
			{
				if (pc[index] == 1)
				{
					printf("+x");
				}
				else
				{
					printf("+%dx", pc[index]);
				}
			}
			else
			{
				if (pc[index] == -1)
				{
					printf("-x");
				}
				else
				{
					printf("%dx", pc[index]);
				}
			}
		}
		else if (i == 0)
		{
			if (pc[index] > 0)
			{
				printf("+%d", pc[index]);
			}
			else
			{
				printf("%d", pc[index]);
			}
		}
		else
		{
			if (pc[index] > 0)
			{
				if (pc[index] == 1)
				{
					printf("+x^%d", i);
				}
				else
				{
					printf("+%dx^%d", pc[index], i);
				}
			}
			else
			{
				if (pc[index] == -1)
				{
					printf("-x^%d", i);
				}
				else
				{
					printf("%dx^%d", pc[index], i);
				}
			}
		}
		index++;
	}
	printf("\n");
}

intt max(intt a, intt b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

intt min(intt a, intt b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

//hw0504
double getAverage(double *num_arr, intt arr_size)
{
	double total = 0.0;
	for (intt i = 0; i < arr_size; i++)
	{
		total += num_arr[i];
	}
	double average = total / arr_size;
	return average;
}

//hw0505
void checkInput(intt *input, intt max, intt min)
{
	if (scanf("%d", input) != 1 || *input > max || *input < min)
	{
		printf("\033[40;31merror\n\033[0m");
		exit(1);
	}
}

intt gameinput(intt *input, intt max, intt min)
{
	if (scanf("%d", input) != 1 || *input > max || *input < min)
	{
		printf("\033[40;31merror please try again\n\033[0m");
		return gameinput(input,  max,  min);
	}
}
void UI(intt width)
{
	printf("   ");
	for (intt i = 0; i < width; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	for (intt i = 1; i <= 3 * (width + 1); i++)
	{
		printf("-");
	}
	printf("\n");
	
}

void diffusion(intt *mine, intt *map, intt *open, intt x, intt y, intt h, intt w)
{
	intt *mineloc = mine + y * w + x;
	intt *maploc = map + y * w + x;
	intt *openloc = open + y * w + x;

	*openloc = 1;
	if (*(maploc) == 2)
	{
		*(maploc) = 0; 
	}

	//左上
	if (*(openloc - w - 1) == 0 && y-1 >= 0 && y-1 < h && x-1 >= 0 && x-1 < w)
	{
		if (*(mineloc - w - 1) == 0)
		{
			diffusion(mine, map, open, x - 1, y - 1, h, w);
		}
		else if (*(mineloc - w - 1) != -1)
		{
			*(openloc - w - 1) = 1;
		}
		
	}
	//上
	if (*(openloc - w) == 0 && y-1 >= 0 && y-1 < h && x >= 0 && x < w)
	{
		if (*(mineloc - w ) == 0)
		{
			diffusion(mine, map, open, x , y - 1, h, w);
		}
		else if (*(mineloc - w ) != -1)
		{
			*(openloc - w ) = 1;
		}
		
	}
	//右上
	if (*(openloc - w + 1) == 0 && y-1 >= 0 && y-1 < h && x+1 >= 0 && x+1 < w)
	{
		if (*(mineloc - w + 1) == 0)
		{
			diffusion(mine, map, open, x + 1, y - 1, h, w);
		}
		else if (*(mineloc - w + 1) != -1)
		{
			*(openloc - w + 1) = 1;
		}
		
	}
	//左
	if (*(openloc - 1) == 0 && y >= 0 && y < h && x-1 >= 0 && x-1 < w)
	{
		if (*(mineloc  - 1) == 0)
		{
			diffusion(mine, map, open, x - 1, y, h, w);
		}
		else if (*(mineloc  - 1) != -1)
		{
			*(openloc - 1) = 1;
		}
		
	}
	//右
	if (*(openloc + 1) == 0 && y >= 0 && y < h && x+1 >= 0 && x+1 < w)
	{
		if (*(mineloc + 1) == 0)
		{
			diffusion(mine, map, open, x + 1, y , h, w);
		}
		else if (*(mineloc +1) != -1)
		{
			*(openloc + 1) = 1;
		}
		
	}
	//左下
	if (*(openloc + w - 1) == 0 && y+1 >= 0 && y+1 < h && x-1 >= 0 && x-1 < w)
	{
		if (*(mineloc + w - 1) == 0)
		{
			diffusion(mine, map, open, x - 1, y + 1, h, w);
		}
		else if (*(mineloc + w - 1) != -1)
		{
			*(openloc + w - 1) = 1;
		}
		
	}
	//下
	if (*(openloc + w ) == 0 && y+1 >= 0 && y+1 < h && x >= 0 && x < w)
	{
		if (*(mineloc + w) == 0)
		{
			diffusion(mine, map, open, x , y + 1, h, w);
		}
		else if (*(mineloc + w) != -1)
		{
			*(openloc + w ) = 1;
		}
		
	}
	//右下
	if (*(openloc + w + 1) == 0 && y+1 >= 0 && y+1 < h && x+1 >= 0 && x+1 < w)
	{
		if (*(mineloc + w + 1) == 0)
		{
			diffusion(mine, map, open, x + 1, y + 1, h, w);
		}
		else if (*(mineloc + w + 1) != -1)
		{
			*(openloc + w + 1) = 1;
		}
		
	}
	
}
