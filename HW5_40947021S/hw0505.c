#include "hw5.h"

intt main()
{
	intt width = 0;
	intt height = 0;
	intt mine_num = 0;
	printf("Please enter the width       (10-16): ");
	checkInput(&width, 16, 10);
	printf("Please enter the height      (10-16): ");
	checkInput(&height, 16, 10);
	printf("Please enter the mine number (30-90): ");
	checkInput(&mine_num, 90, 30);
	
	intt map[height][width];//game map & flag
	intt open[height][width];//if the position is open
	intt mine[height][width];//mine position & number of mine around
	//initialization
	for (intt i = 0; i < height; i++)
	{
		for (intt j = 0; j < width; j++)
		{
			map[i][j] = 0;
			open[i][j] = 0;
			mine[i][j] = 0;
		}
	}

	//place mine
	srand(time(NULL));
	intt mineCounter = mine_num;
	intt mx = 0;
	intt my = 0;
	while (mineCounter != 0)
	{
		mx = rand()%width;
		my = rand()%height;
		if (mine[my][mx] == 0)
		{
			mine[my][mx] = -1;
			mineCounter--;
		}
		
	}
	
	for (intt i = 0; i < height; i++)
	{
		for (intt j = 0; j < width; j++)
		{
			if (mine[i][j] != -1)
			{
				intt mineCount = 0;
				if (mine[i][j+1] == -1 && j+1 < width)
				{
					mineCount++;
				}
				if (mine[i-1][j+1] == -1 && j+1 < width && i-1 >= 0)
				{
					mineCount++;
				}
				if (mine[i-1][j] == -1 && i-1 >= 0)
				{
					mineCount++;
				}
				if (mine[i-1][j-1] == -1 && i-1>=0 && j-1>=0)
				{
					mineCount++;
				}
				if (mine[i][j-1] == -1 && j-1>=0)
				{
					mineCount++;
				}
				if (mine[i+1][j-1] == -1 && i+1 < height && j-1 >=0)
				{
					mineCount++;
				}
				if (mine[i+1][j] == -1 && i+1 < height)
				{
					mineCount++;
				}
				if (mine[i+1][j+1] == -1 && i+1 < height && j+1 < width)
				{
					mineCount++;
				}
				mine[i][j] = mineCount;
				
			}
			
		}
		
	}
	
	
	intt result = 1;
	intt mine_flagged = 0;
	while (result == 1)
	{
		intt x = 0;
		intt y = 0; 
		//print map
		UI(width);
		for (intt i = 0; i <height; i++)
		{
			printf("%2d|",i);
			for (intt j = 0; j < width; j++)
			{
				if (open[i][j] == 1)
				{
					if (map[i][j] == 2)
					{
						printf("\033[40;31m F \033[0m");
					}					
					else if (mine[i][j] == 0)
					{
						printf("   ");
					}
					else
					{
						printf("%2d ", mine[i][j]);
					}					
				}
				else
				{
					printf(" * ");
				}				
			}
			printf("\n");
		}
		intt option = 0;
		printf("Your Option (1:Open, 2: Flag):  ");
		gameinput(&option, 2, 1);
		printf("Position (row,column): ");
		gameinput(&y, height-1, 0);
		gameinput(&x, width-1, 0);
		if (open[y][x] == 1 && (map[y][x] != 2 && option != 2))
		{
			printf("\033[40;31malready opened\n\033[0m");
			continue;
		}
		else
		{
			open[y][x] = 1;
		}
		
		if (option == 1)
		{
			if (mine[y][x] == -1)
			{
				result = -1;
				break;
			}
			else if (mine[y][x] == 0)
			{			
				diffusion(&mine[0][0], &map[0][0], &open[0][0], x, y, height, width);
			}
			
		}
		else
		{
			if (map[y][x] == 2)
			{
				map[y][x] = 0;
				open[y][x] = 0;
			}
			else if (mine[y][x] == -1)
			{
				mine_flagged++;
				map[y][x] = 2;
			}
			else
			{
				map[y][x] = 2;
			}		
		}
		if (mine_flagged == mine_num)
		{
			result = 2;
		}
	
	}
	
	if (result == -1)
	{
		printf("\033[40;34mLOSER\n\033[0m");
	}
	else
	{
		printf("\033[40;33mYou Win!\n\033[0m");
	}
	return 0;
}