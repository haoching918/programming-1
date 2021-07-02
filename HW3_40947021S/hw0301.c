#include <stdio.h>
#define int_in32_t

int main()
{
	int width=0;
	int height=0;
	printf("Please enter the width :");
	if(scanf("%d",&width)!=1 || width<1)
	{
		printf("error\n");
		return 1;
	}
	printf("Please enter the height:");
	if (scanf(" %d",&height)!=1 || height<1)
	{
		printf("error\n");
		return 1;
	}
	int array[height][width];
	int product=width*height;
	int counter=1;

	int x=0;
	int y=0;
	int changeWidth=width;
	int changeHeight=height; 
	int xbegining=0;
	int ybegining=0;
	
	while (counter<product)
	{
		for (x; x<changeWidth; x++)
		{
			array[y][x]=counter;
			counter++;
		}
		if (counter>product)
			{
				break;
			}
			
		x--;
		y++;
		for ( y ; y < changeHeight; y++)
		{
			array[y][x]=counter;
			counter++;
		}
		if (counter>product)
			{
				break;
			}
			
		y--;
		x--;
		changeWidth--;
		for (x ; x >= xbegining; x--)
		{
			array[y][x]=counter;
			counter++;
		}
		if (counter>product)
			{
				break;
			}

		xbegining++;	
		x++;
		y--;
		for (y ; y > ybegining; y--)
		{
			array[y][x]=counter;
			counter++;
		}
		if (counter>product)
			{
				break;
			}
			
		ybegining++;
		y++;
		changeHeight--;
		x++;

	}
	
	
	for (int i = 0; i < height; i++) 
	{
    	for (int j = 0; j < width; j++) 
		{
      	printf("%4d", array[i][j]);
    	}
    	printf("\n");
    }
	
	return 0;
}

