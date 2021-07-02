#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define intt int32_t

//hw0401
void romanTransfer(intt integer)
{
	intt thousands = integer / 1000;
	intt hundreds = (integer / 100) % 10;
	intt tens = (integer % 100) / 10;
	intt units = integer % 10;

	for (size_t i = 0; i < thousands; i++)
	{
		printf("M");
	}
	
	if (hundreds <= 3)
	{
		for (size_t i = 0; i < hundreds; i++)
		{
			printf("C");
		}

	}
	else if (hundreds == 4)
	{
		printf("CD");
	}
	else if (hundreds >= 5 && hundreds != 9)
	{
		printf("D");
		for (size_t i = 0; i < hundreds - 5; i++)
		{
			printf("C");
		}
		
	}
	else
	{
		printf("CM");
	}
	
	if (tens <= 3)
	{
		for (size_t i = 0; i < tens; i++)
		{
			printf("X");
		}

	}
	else if (tens == 4)
	{
		printf("XL");
	}
	else if (tens >= 5 && tens != 9)
	{
		printf("L");
		for (size_t i = 0; i < tens - 5; i++)
		{
			printf("X");
		}
		
	}
	else
	{
		printf("XC");
	}
	
	if (units <= 3)
	{
		for (size_t i = 0; i < units; i++)
		{
			printf("I");
		}

	}
	else if (units == 4)
	{
		printf("IV");
	}
	else if (units >= 5 && units != 9)
	{
		printf("V");
		for (size_t i = 0; i < units - 5; i++)
		{
			printf("I");
		}
		
	}
	else
	{
		printf("IX");
	}
	printf("\n");
}

//hw0402
intt even_or_odd(intt disk_num)
{
	if (disk_num % 2 == 0)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
void hanoi_recursion(intt disk_num, intt control, intt k)
{
	if (control == 2)
	{
		if (k == 0)
		{
			intt temp = disk_num - k;
			intt count = 0;
			while (temp % 2 != 1)
			{
				count++;
				temp /= 2;
			}
			printf("put disk %d to rod %d\n",count + 1,((disk_num - k | disk_num - k - 1) + 1) % 3 + 1);
		}	
		else
		{	
			intt temp = disk_num - k;
			intt count = 0;
			while (temp % 2 != 1)
			{
				count++;
				temp /= 2;
			}
			printf("put disk %d to rod %d\n",count + 1,((disk_num - k | disk_num - k - 1) + 1) % 3 + 1);
			return hanoi_recursion(disk_num , control, k - 1);
		}
	}
	else
	{
		intt move_to_rod = ((disk_num - k | disk_num - k - 1) + 1) % 3 + 1;
		if (move_to_rod == 2)
		{
			move_to_rod = 3;
		}			
		else if (move_to_rod == 3)
		{
			move_to_rod = 2;
		}    
		     
		if (k == 0)
		{
			intt temp = disk_num - k;
			intt count = 0;
			while (temp % 2 != 1)
			{
				count++;
				temp /= 2;
			}
			printf("put disk %d to rod %d\n",count + 1,move_to_rod);
		}	
		else
		{	
			intt temp = disk_num - k;
			intt count = 0;
			while (temp % 2 != 1)
			{
				count++;
				temp /= 2;
			}
			printf("put disk %d to rod %d\n",count + 1,move_to_rod);
			return hanoi_recursion(disk_num , control, k - 1);
		}
	}
	
}

void hanoi(intt disk_num, intt control)
{
	disk_num = pow(2,disk_num);
	if (control == 2)
	{
		for (intt m = 1; m < disk_num; m++)
		{
			intt temp = m;
			intt count = 0;
			while (temp % 2 != 1)
			{
				count++;
				temp /= 2;
			}
			printf("put disk %d to rod %d\n",count + 1,((m | m - 1) + 1) % 3 + 1);
		}
	}
	else
	{
		for (intt m = 1; m < disk_num; m++)
		{
			intt temp = m,count = 0;
			while (temp % 2 != 1)
			{
				count++;
				temp /= 2;
			}
			intt move_to_rod = ((m | m - 1) + 1) % 3 + 1 ;
			if (move_to_rod == 2)
			{
				move_to_rod = 3;
			}
			else if (move_to_rod == 3)
			{
				move_to_rod = 2;
			}         
			printf("put disk %d to rod %d\n",count + 1, move_to_rod);
		}
	}
}

//hw0403
double factorial(intt num)
{
	if (num == 1 || num == 0)
	{
		return 1;
	}
	return num * factorial(num-1); 
}

double get_ans(intt k)
{
	double ans = 2.0;
	for (intt i = 2; i <= k ; i++)
	{
		ans += 1.0 / factorial(i);
	}
	return ans;
}

//hw0404
double equivalent(intt n,intt r)
{
	
	if (n == 1)
	{
		return r * 2;
	}
	
	return r + 1/(1/(equivalent(n - 1, r) ) + 1/r);
} 

//hw0405
intt get_result()
{
	srand(time(NULL));
	intt input = rand() % 10000;
	intt n1 = input / 1000;
	intt n2 = (input - n1 * 1000) / 100;
	intt n3 = input % 100 / 10;
	intt n4 = input % 10;

	if (n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4 )
	{
		return -1;
	}
	else
	{
		return input;
	}
}

intt check_input(intt input)
{
	intt n1 = input / 1000;
	intt n2 = (input - n1 * 1000) / 100;
	intt n3 = input % 100 / 10;
	intt n4 = input % 10;

	if (n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4 ||  input > 9999 || input < 1)
	{
		return -1;
	}
	else
	{
		return input;
	}
}

void int_to_str(intt *str,intt integer)
{
	intt n1 = integer / 1000;
	intt n2 = (integer - n1 * 1000) / 100;
	intt n3 = integer % 100 / 10;
	intt n4 = integer % 10;

	str[0] = n1;
	str[1] = n2;
	str[2] = n3;
	str[3] = n4;

}

intt game(intt *guess, intt *result)
{
	intt A = 0;
	intt B = 0;
	for (intt i = 0; i < 4; i++)
	{
		for (intt j = 0; j < 4; j++)
		{
			if ((guess[i] == result[j]) && i == j)
			{
				A++;
			}
			else if (guess[i] == result[j])
			{
				B++;
			}
		}
	}
	if (A == 4)
	{
		return 1;
	}
	printf("\033[40;32m%dA\033[0m", A);
	printf("\033[40;34m%dB\n\033[0m", B);
}